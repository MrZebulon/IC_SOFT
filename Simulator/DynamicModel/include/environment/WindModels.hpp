//
// Created by Samuel on 21/06/2023.
//

#ifndef IC_SOFT_ATMOSPHERE_HPP
#define IC_SOFT_ATMOSPHERE_HPP

#include <cmath>
#include <random>
#include <Eigen/Dense>

#include "Noise.hpp"

namespace icarus::simulator::env {

	class HorizontalWindModel {
	public:
		explicit HorizontalWindModel(double dt, double wind_from_deg, double mean_vel):
				_wind_from_rad{wind_from_deg * M_PI / 180}, _mean_vel{mean_vel}, _max_delta_rad{5 * dt} {}

		void update(){
			_wind_from_rad += noise.get_value_in_range(-_max_delta_rad, _max_delta_rad);
		}

		Eigen::Vector3d get_wind_direction_NED(){
			update();
			return {-_mean_vel * cos(_wind_from_rad), -_mean_vel * sin(_wind_from_rad), 0};
		}

	private:
		double _wind_from_rad;
		double _mean_vel;
		double _max_delta_rad;
		WhiteNoise noise;

	};

	class GustModel {
	public:
		explicit GustModel(double dt, double wind_from_deg, double mean_vel):
		_dt{dt}, _wind_from_rad{wind_from_deg * M_PI / 180}, _mean_vel{mean_vel} {}

		void update(){
			_gust_vel = _nominal_vel * get_gust_profile(t_now - _start_in);

			if(t_now - _start_in > _total_duration) {
				t_now = 0;
				is_scheduled = false;
				is_active = false;
			}
		}

		Eigen::Vector3d get_wind_direction_NED(){
			if(is_scheduled && t_now >= _start_in){
				is_active = true;
			}

			if(is_active){
				update();
			}

			t_now += _dt;
			return {-_gust_vel * cos(_wind_from_rad), -_gust_vel * sin(_wind_from_rad), 0};
		}

	private:
		double get_gust_profile(double t) const {
			if(t < 0)
				return 0;

			if(t <= _io_duration)
				return sin((M_PI / 2) * (t / _io_duration));

			if(t - _io_duration <= _nominal_duration)
				return 1;

			if(t - (_io_duration + _nominal_duration) <= _io_duration)
				return sin((M_PI / 2) * ((1 - t) / _io_duration));

			return 0;
		}

		void schedule_gust(){
			_nominal_vel = _mean_vel*( 1 + noise.get_value_in_range(-_delta_vel, _delta_vel));

			_total_duration = 5 + 4./_delta_vel * (_mean_vel - _nominal_vel);
			_nominal_duration = _total_duration * (0.7 + noise.get_value_in_range(-_delta_duration, _delta_duration));
			_io_duration = (_total_duration - _nominal_duration) / 2;

			_start_in = t_now + noise.get_value_in_range(_delta_start[0], _delta_start[1]);
		}

	private:
		double _dt;
		double _wind_from_rad;
		double _mean_vel;

		double t_now = 0;
		bool is_scheduled = false;
		bool is_active = false;

		double _delta_vel = 0.3;
		double _delta_duration = 0.1;
		double _delta_start[2] = {0.4, 5};

		double _gust_vel = 0;

		double _nominal_vel = 0;
		double _total_duration = 0;
		double _nominal_duration = 0;
		double _io_duration = 0;
		double _start_in = 0;

		WhiteNoise noise;
	};

}

#endif //IC_SOFT_ATMOSPHERE_HPP
