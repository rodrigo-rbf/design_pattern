#include <cmath>
#include <iostream>
#include <vector>

#include <cfloat>

#include <utils/log.hpp>
#include <utils/quantities.hpp>
//#include "log.hpp"
//#include "quantities.hpp"

constexpr qty::Distance _d1 = 100_km * -1;
constexpr qty::Distance _d2 = 100.0_km;
constexpr bool test = (_d1 == _d2);

int main ()
{

	std::cout << std::endl << "=======   Testing unit converstion   =======" << std::endl;
	std::cout << "qty::convert(qty::Prefix::m, qty::Prefix::base) " << qty::convert(qty::Prefix::m, qty::Prefix::base, 1) << std::endl;
	std::cout << "qty::convert(qty::Prefix::k, qty::Prefix::u) " << qty::convert(qty::Prefix::k, qty::Prefix::u, 1) << std::endl;
	std::cout << "qty::convert_from(qty::Prefix::giga)" << qty::convert_from(qty::Prefix::giga, 1) << std::endl;
	std::cout << "qty::convert_to(qty::Prefix::micro, 2)" << qty::convert_to(qty::Prefix::micro, 2) << std::endl;

	std::cout << "qty::convert(qty::unit::Distance::nm, qty::unit::Distance::yd)" << qty::convert(qty::unit::Distance::nm, qty::unit::Distance::yd, 1) << std::endl;


	std::cout << std::endl << "=======   Testing distance   =======" << std::endl;

	qty::Distance d1 = 10.0_km;
	qty::Distance d2(500_m);
	// auto a1 = d1*d2;

	// std::cout << "_d1 == _d2 = " << test << std::endl;

	std::cout << "d1: " << d1 << std::endl;
	std::cout << "d2: " << d2 << std::endl;
	std::cout << "d1 + d2 = " << (d1 + d2) << std::endl;
	std::cout << "d1 - d2 = " << (d1 - d2) << std::endl;
	std::cout << "d1 / d2 = " << (d1 / d2) << std::endl;
	std::cout << "d1 * d2 = " << (d1 * d2) << std::endl;
	std::cout << "d2 * 5 = " << (d2 * 5) << std::endl;
	std::cout << "5 * d2 = " << (5 * d2) << std::endl;
	std::cout << "d2 / 5 = " << (d2 / 5) << std::endl;
	std::cout << "1 / d2 = " << (1 / d2) << std::endl;
	std::cout << "5 * (2 / d2) = " << (5 * (2 / d2)) << std::endl;
	std::cout << "1/ (d1 * d2) = " << (1/(d1 * d2)) << std::endl;
	std::cout << "pow<0.5>(d1 * d2) = " << qty::pow<0.5f>(d1 * d2) << std::endl;
	std::cout << "pow<3.5>(d1 * d2) = " << qty::pow<3.5f>(d1 * d2) << std::endl;

	std::cout << "d1 == d2 = " << (d1 == d2) << std::endl;
	std::cout << "d1 != d2 = " << (d1 != d2) << std::endl;
	std::cout << "d1 > d2 = " << (d1 > d2) << std::endl;
	std::cout << "d1 < d2 = " << (d1 < d2) << std::endl;
	std::cout << "d1 >= d2 = " << (d1 >= d2) << std::endl;
	std::cout << "d1 <= d2 = " << (d1 <= d2) << std::endl;
	std::cout << "d2 > d2 = " << (d2 > d2) << std::endl;
	std::cout << "d2 < d2 = " << (d2 < d2) << std::endl;
	std::cout << "d2 >= d2 = " << (d2 >= d2) << std::endl;
	std::cout << "d2 <= d2 = " << (d2 <= d2) << std::endl;

	// std::cout << "a1 / d1 = " << show_result((a1 / d1), (a1.get_value() / d1.get_value())) << std::endl;

	d1 += d2;
	std::cout << "d1 += d2 = " << d1 << std::endl;
	d1 -= d2;
	std::cout << "d1 -= d2 = " << d1 << std::endl;
	d1 *= 3;
	std::cout << "d1 *= 3 = " << d1 << std::endl;
	d1 /= 3;
	std::cout << "d1 /= 3 = " << d1 << std::endl;


	std::cout << std::endl << "=======   Testing time   =======" << std::endl;

	qty::Time t1 = 500_ms;
	qty::Time t2 = 1_s;
	qty::Frequency f1 = 60_hz;
	qty::Frequency f2 = 2_khz;

	std::cout << "f1 = " << f1 << std::endl;
	std::cout << "f1.get_rpm() = " << f1.get_rpm() << std::endl;
	std::cout << "f2 = " << f2 << std::endl;
	std::cout << "f2.get_hz() = " << f2.get_hz() << std::endl;
	std::cout << "f2.to_string(qty::unit::Frequency::rpm, qty::Prefix::m) = " << f2.to_string(qty::unit::Frequency::rpm, qty::Prefix::m) << std::endl;
	std::cout << "(1/f1) = " << (1/f1) << std::endl;

	std::cout << "t1 = " << t1 << std::endl;
	std::cout << "t2 = " << t2 << std::endl;
	std::cout << "t1 + t2 = " << (t1 + t2) << std::endl;
	std::cout << "t1 - t2 = " << (t1 - t2) << std::endl;
	std::cout << "t1 / t2 = " << (t1 / t2) << std::endl;
	std::cout << "(2 / t2) = " << (2 / t2) << std::endl;
	std::cout << "1/ (1/t1): " << (1/ (1/t1)) << std::endl;
	std::cout << "f1 / t1 = " << f1 / t1 << std::endl;

	struct timespec timespec = qty::Time::ms(10).get_timespec();
	std::cout << "10 ms => tv_sec: " << timespec.tv_sec << " tv_nsec: " << timespec.tv_nsec << std::endl;
	timespec = qty::Time::ms(1000).get_timespec();
	std::cout << "1000 ms => tv_sec: " << timespec.tv_sec << " tv_nsec: " << timespec.tv_nsec << std::endl;
	timespec = qty::Time::ms(1010).get_timespec();
	std::cout << "1010 ms => tv_sec: " << timespec.tv_sec << " tv_nsec: " << timespec.tv_nsec << std::endl;

	struct timeval timeval = qty::Time::ms(10).get_timeval();
	std::cout << "10 ms => tv_sec: " << timeval.tv_sec << " tv_usec: " << timeval.tv_usec << std::endl;
	timeval = qty::Time::ms(1000).get_timeval();
	std::cout << "1000 ms => tv_sec: " << timeval.tv_sec << " tv_usec: " << timeval.tv_usec << std::endl;
	timeval = qty::Time::ms(1010).get_timeval();
	std::cout << "1010 ms => tv_sec: " << timeval.tv_sec << " tv_usec: " << timeval.tv_usec << std::endl;

	std::cout << std::endl << "=======   Testing timestamp   =======" << std::endl;

	qty::Timestamp ts1;
	qty::sleep(10_ms);
	qty::Timestamp ts2;

	std::cout << "ts1: " << ts1 << std::endl;
	std::cout << "ts2: " << ts2 << std::endl;
	std::cout << "ts1 - ts2 = " << (ts1 - ts2) << std::endl;
	std::cout << "ts2 - ts1 = " << (ts2 - ts1) << std::endl;


	std::cout << std::endl << "=======   Testing speed   =======" << std::endl;
	qty::Speed s1(500_m_s);
	qty::Speed s2 = qty::Speed::knot(5);

	std::cout << "s1: " << s1 << std::endl;
	std::cout << "s2: " << s2 << std::endl;
	// std::cout << "s1 == d2 = " << (s1 == d2) << std::endl;
	std::cout << "t1: " << t1 << std::endl;
	std::cout << "d1: " << d1 << std::endl;
	std::cout << "t1 * s1 = " << (t1 * s1) << " -> " << utils::get_class_name(t1 * s1) << std::endl;
	std::cout << "s1 * t1 = " << (s1 * t1) << " -> " << utils::get_class_name(s1 * t1) << std::endl;
	std::cout << "d1 / t1 = " << (d1 / t1) << " -> " << utils::get_class_name(d1 / t1) << std::endl;
	std::cout << "d1 / s1 = " << (d1 / s1) << " -> " << utils::get_class_name(d1 / s1) << std::endl;

	// std::cout << "(s1*s1) * (t1*t1) = " << ((s1*s1) * (t1*t1)) << " -> " << utils::get_class_name((s1*s1) * (t1*t1)) << std::endl;

	std::cout << std::endl << "=======   Testing acceleration   =======" << std::endl;
	qty::Acceleration ac1 = qty::Acceleration::m_s2(10);

	std::cout << "ac1 = " << ac1 << std::endl;
	std::cout << "qty::Speed::m_s(10)/qty::Time::s(5) = " << qty::Speed::m_s(10)/qty::Time::s(5) << std::endl;

	std::cout << "qty::Distance::m(10)/qty::Time::s(5)/qty::Time::s(1) = " << qty::Distance::m(10)/qty::Time::s(5)/qty::Time::s(1) << std::endl;
	std::cout << "qty::Distance::m(10)/(qty::Time::s(5)*qty::Time::s(1)) = " << qty::Distance::m(10)/(qty::Time::s(5)*qty::Time::s(1)) << std::endl;

	std::cout << std::endl << "=======   Testing angles    =======" << std::endl;

	qty::DMS dms = qty::DMS::by_degree(20.5);
	std::cout << "DMS[" << dms.degree << "," << dms.minute << "," << dms.second << "]: " << dms.get_degree() << " -> " << dms.to_string() << std::endl;

	qty::DMS dms2 = qty::DMS::by_degree(-43.6474);
	std::cout << "DMS[" << dms2.degree << "," << dms2.minute << "," << dms2.second << "]: " << dms2.get_degree() << " -> " << dms2.to_string() << std::endl;
	
	qty::DMS dms3 = qty::DMS::by_string(dms.to_string() + "W");
	std::cout << "DMS[" << dms3.degree << "," << dms3.minute << "," << dms3.second << "]: " << dms3.get_degree() << " -> " << dms3.to_string(1) << std::endl;

	qty::Angle a1 = qty::Angle::deg(355);
	std::cout << "355 = " << a1 << " -> " << a1.to_deg_string() << std::endl;

	qty::Angle a2 = qty::Angle::rad(1.5*M_PI);
	std::cout << "1.5*M_PI = " << a2 << " -> " << a2.to_deg_string() << std::endl;

	qty::Bearing a3 = 355_eccw_deg;
	std::cout << "355 " << a3 << std::endl;

	qty::Bearing a4 (370_eccw_deg);
	std::cout << "370 " << a4 << std::endl;

	qty::Bearing a5 = qty::Bearing::eccw_deg(-10);
	std::cout << "-10 " << a5 << std::endl;

	qty::Bearing a6 = qty::Bearing::eccw_deg(-355);
	std::cout << "-355 " << a6 << std::endl;

	qty::Bearing a7 = qty::Bearing::eccw_deg(-370);
	std::cout << "-370 " << a7 << std::endl;

	qty::Bearing a8a = qty::Bearing::eccw_deg(325.4);
	std::cout << "325.4 " << a8a << std::endl;

	qty::Bearing a9a = qty::Bearing::eccw_deg(325.6);
	std::cout << "325.6 " << a9a << std::endl;

	qty::Bearing b8 = 185_ncw_deg;
	std::cout << "ncw_deg(185) " << b8 << " " << b8.get_ncw_deg() << " " << b8.get_eccw_deg() << std::endl;

	qty::Bearing b9 = qty::Bearing::ncw_deg(175);
	std::cout << "ncw_deg(175) " << b9 << " " << b9.get_ncw_deg() << " " << b9.get_eccw_deg() << std::endl;

	qty::Bearing a8 = a6+a7;
	std::cout << "-355 + (-370) " << a8 << std::endl;

	qty::Bearing a9(a1+a2);
	std::cout << "355 + 370 " << a9 << std::endl;


	std::cout << "10 + 10 " << qty::Bearing(qty::Bearing::eccw_deg(10) + qty::Bearing::eccw_deg(10)) << std::endl;
	std::cout << "10 + 350 " << qty::Bearing(qty::Bearing::eccw_deg(10) + qty::Bearing::eccw_deg(350)) <<
 std::endl;
	std::cout << "10 + 355 " << qty::Bearing(qty::Bearing::eccw_deg(10) + qty::Bearing::eccw_deg(355)) <<
 std::endl;
	std::cout << "10 + (-5) " << qty::Bearing(qty::Bearing::eccw_deg(10) + qty::Bearing::eccw_deg(-5)) <<
 std::endl;
	std::cout << "10 + (-25) " << qty::Bearing(qty::Bearing::eccw_deg(10) + qty::Bearing::eccw_deg(-25)) <<
 std::endl;

	std::cout << "10 - 10 " << qty::Bearing(qty::Bearing::eccw_deg(10) - qty::Bearing::eccw_deg(10)) << std::endl;
	std::cout << "10 - (-10) " << qty::Bearing(qty::Bearing::eccw_deg(10) - qty::Bearing::eccw_deg(-10)) << std::endl;
	std::cout << "10 - 15 " << qty::Bearing(qty::Bearing::eccw_deg(10) - qty::Bearing::eccw_deg(15)) << std::endl;
	std::cout << "10 - (-15) " << qty::Bearing(qty::Bearing::eccw_deg(10) - qty::Bearing::eccw_deg(-15)) << std::endl;

	log_debug() << "=============" << std::endl;

	std::cout << "5 - 345 " << qty::Bearing(qty::Bearing::eccw_deg(5) - qty::Bearing::eccw_deg(345)) << std::endl;
	std::cout << "345 - 5 " << qty::Bearing(qty::Bearing::eccw_deg(345) - qty::Bearing::eccw_deg(5)) << std::endl;

	std::cout << "5 - 25 " << qty::Bearing(qty::Bearing::eccw_deg(5) - qty::Bearing::eccw_deg(25)) << std::endl;
	std::cout << "25 - 5 " << qty::Bearing(qty::Bearing::eccw_deg(25) - qty::Bearing::eccw_deg(5)) << std::endl;

	std::cout << "345 - 25 " << qty::Bearing(qty::Bearing::eccw_deg(345) - qty::Bearing::eccw_deg(25)) << std::endl;
	std::cout << "25 - 345 " << qty::Bearing(qty::Bearing::eccw_deg(25) - qty::Bearing::eccw_deg(345)) << std::endl;
	
	log_debug() << "=============" << std::endl;

	std::cout << "90-90 " << qty::Bearing(qty::Bearing::eccw_deg(90) - qty::Bearing::eccw_deg(90)).get_deg() << std::endl;

	std::cout << "360 " << qty::Bearing(qty::Bearing::eccw_deg(360)) << std::endl;

	std::cout << "360 " << qty::Bearing(qty::Bearing::eccw_deg(360)).get_deg() << std::endl;

	std::cout << "360 - 360 " << qty::Bearing(qty::Bearing::eccw_deg(360) - qty::Bearing::eccw_deg(360)) << std::endl;
	std::cout << "0 - 0 " << qty::Bearing(qty::Bearing::eccw_deg(0) - qty::Bearing::eccw_deg(0)) << std::endl;

	std::cout << "360 - 0 " << qty::Bearing(qty::Bearing::eccw_deg(360) - qty::Bearing::eccw_deg(0)) << std::endl;

	std::cout << "360.0001 - 0 " << (qty::Bearing::eccw_deg(360.000000000000001) - qty::Bearing::eccw_deg(0)) << std::endl;
	std::cout << "359.9999 - 0 " << (qty::Bearing::eccw_deg(359.999999999999999) - qty::Bearing::eccw_deg(0)) << " " << qty::Bearing(qty::Bearing::eccw_deg(359.999999999999999) - qty::Bearing::eccw_deg(0)).get_deg() << std::endl;
	
	std::cout << "0 - 360 " << qty::Bearing(qty::Bearing::eccw_deg(0) - qty::Bearing::eccw_deg(360)) << std::endl;

	std::cout << "180 - 180 " << qty::Bearing(qty::Bearing::eccw_deg(180) - qty::Bearing::eccw_deg(180)) << std::endl;
	std::cout << "270 + 90 " << qty::Bearing(qty::Bearing::eccw_deg(270) + qty::Bearing::eccw_deg(90)) << std::endl;

	log_debug() << "======= Testing coordinates =======" << std::endl;

	qty::Point point = qty::Point::deg(-22.874828, -43.1333848);

	std::cout << point << std::endl;
	std::cout << point.to_string(1) << std::endl;

	point = qty::Point::deg(-90.0, -40.25);

	std::cout << point << std::endl;
	std::cout << point.to_string(3) << std::endl;

	log_debug() << "======= Testing angular velocity =======" << std::endl;

	qty::Angular_velocity av1 = qty::Angular_velocity::rad_s(2*M_PI);
	qty::Angular_velocity av2 = qty::Angular_velocity::deg_s(180);

	std::cout << "av1 = " << av1 << std::endl;
	std::cout << "av2 = " << av2 << std::endl;
	std::cout << "av1 + av2 = " << av1 + av2 << std::endl;
	std::cout << "av1/av2 = " << av1/av2 << std::endl;
	std::cout << "av1*av2 = " << av1*av2 << std::endl;

	qty::Angular_velocity av3 = qty::Angle::rad(M_PI)/qty::Time::s(2);

	std::cout << "av3 = " << av3 << std::endl;

	std::cout << "av1/qty::Angle::rad(M_PI) = " << av1/qty::Angle::rad(M_PI) << std::endl;



// 	qty::Vector<qty::Distance> v = p1 - p2;
// 	std::cout << std::setprecision(20) << v.get_magnitude() << " " << qty::rad2deg(v.get_direction().get_rad()) << "°" << std::endl;

// 	if (v.get_direction().get_rad() >= 0) {
// 		std::cout << v.get_direction().get_rad() << std::endl;
// 	} else {
// 		std::cout << qty::Bearing::eccw_rad(2 * M_PI + v.get_direction().get_rad()) << std::endl;

// 	}
// 	std::cout << std::endl;

// 	qty::Point p2b = p1 + v;
// 	std::cout << p2b.get_str_dms(6) << std::endl;
// 	std::cout << p2b.get_str_rad() << std::endl;


	log_debug() << std::endl << "======= Testing vector =======" << std::endl;
	// qty::Vector v1(3.0, qty::Bearing::eccw_deg(45));
	// qty::Vector v2(4.0, qty::Bearing::eccw_deg(225));

	// log_debug() << "v1: " << v1 << std::endl;
	// log_debug() << "v2: " << v2 << std::endl;
	// log_debug() << "v1+v2: " << (v1+v2) << std::endl;
	// log_debug() << "v1-v2: " << (v1-v2) << std::endl;
	// log_debug() << "(v1+v2) projetado em 0º: " << ((v1+v2).project(qty::Bearing::eccw_deg(0))) << std::endl;

	qty::Vector v3(qty::Distance::m(3), qty::Bearing::eccw_deg(45));
	qty::Vector v4(qty::Distance::m(4), qty::Bearing::eccw_deg(225));

	log_debug() << "v3: " << v3 << std::endl;
	log_debug() << "v4: " << v4 << std::endl;
	log_debug() << "v3+v4: " << (v3+v4) << std::endl;
	log_debug() << "v3-v4: " << (v3-v4) << std::endl;
	log_debug() << "(v3+v4) projetado em 0º: " << ((v3+v4).project(qty::Bearing::eccw_deg(0))) << std::endl;

	log_debug() << "(v3*2): " << (v3*2) << std::endl;
	log_debug() << "(4*v3): " << (4*v3) << std::endl;
	log_debug() << "(v3/2.8): " << (v3/2.8) << std::endl;
	v3*=2;
	log_debug() << "v3*2: " << v3 << std::endl;
	v3/=2;
	log_debug() << "v3: " << v3 << std::endl;
	v3+=v4;
	log_debug() << "v3+v4: " << (v3+v4) << std::endl;
	v3-=v4;
	log_debug() << "v3-v4: " << (v3-v4) << std::endl;

	qty::Vector v5(qty::Distance::m(4), qty::Distance::m(0));
	log_debug() << "Vector(m(4), m(0)): " << v5 << std::endl;

	qty::Vector v6(qty::Distance::m(0), qty::Distance::m(4));
	log_debug() << "Vector(m(4), m(0)): " << v6 << std::endl;

	qty::Vector v7(qty::Distance::m(0), qty::Distance::m(0));
	log_debug() << "Vector(m(0), m(0)): " << v7 << std::endl;


	qty::Vector v8(qty::Speed::m_s(3), qty::Bearing::eccw_deg(45));
	log_debug() << "t1: " << (t1) << std::endl;
	log_debug() << "v8: " << (v8) << std::endl;
	log_debug() << "v8*t1: " << (v8*t1) << std::endl;
	log_debug() << "(v8*t1)/t1: " << ((v8*t1)/t1) << std::endl;

// 	log_debug() << std::endl << "======= Testing speed =======" << std::endl;
// 	qty::Speed ms = qty::Speed::m_s(1);
// 	qty::Speed kmh = qty::Speed::km_h(1);
// 	qty::Speed knot = qty::Speed::knot(1);

// 	log_debug() << "ms: " << ms << "\tkmh: " << ms.get_kmh() << "\tknot: " << ms.get_knot() << std::endl;
// 	log_debug() << "ms: " << kmh << "\tkmh: " << kmh.get_kmh() << "\tknot: " << kmh.get_knot() << std::endl;
// 	log_debug() << "ms: " << knot << "\tkmh: " << knot.get_kmh() << "\tknot: " << knot.get_knot() << std::endl;

// 	qty::Distance distance = qty::Distance::m(20);
// 	qty::Distance distance2 = qty::Distance::kyd(0.5);
// 	qty::Speed speed = qty::Speed::m_s(3);
// 	qty::Speed speed2 = qty::Speed::knot(1);

// 	log_debug() << "Travelling " << distance << " in 2 seconds: " << distance.get_speed(2) << std::endl;
// 	log_debug() << "Travelling " << distance2 << " in 0.5 seconds: " << distance2.get_speed(0.5) << std::endl;
// 	log_debug() << "Travelling at " << speed << " after 3 seconds: " << speed.get_distance(3) << std::endl;
// 	log_debug() << "Travelling at " << speed2 << " after 2 seconds: " << speed2.get_distance(2) << std::endl;

// 	log_debug() << speed << " after 2 seconds: " << speed.get_distance(2) << " in 2 seconds: " << speed.get_distance(2).get_speed(2) << std::endl;
// 	log_debug() << speed2 << " after 2 seconds: " << speed2.get_distance(2) << " in 2 seconds: " << speed2.get_distance(2).get_speed(2) << std::endl;

// 	qty::Distance scale_distance = qty::Distance::m(20);
// 	log_debug() << "Scaling<"<< scale_distance << "> by 5.5: " << (scale_distance*5.5) << std::endl;

// 	log_debug() << distance << " + " << distance2 << ": " << (distance+distance2) << std::endl;
// 	log_debug() << distance << " - " << distance2 << ": " << (distance-distance2) << std::endl;

// 	qty::Speed scale_speed = qty::Speed::m_s(10);
// 	log_debug() << "Scaling<"<< scale_speed << "> by 5.5: " << (5.5*scale_speed) << std::endl;

// 	log_debug() << speed << " + " << speed2 << ": " << (speed+speed2) << std::endl;
// 	log_debug() << speed << " - " << speed2 << ": " << (speed-speed2) << std::endl;
	
// 	log_debug() << std::endl << std::endl;
	
// 	qty::Time t = qty::Time::s(10);
// 	qty::Speed s = qty::Speed::m_s(10);
// 	qty::Distance d = t*s;
	
// 	log_debug() << t << " * " << s << " = " << d << std::endl;
	
// 	qty::Latitude lat = qty::Latitude::dms(-22,-53.50,0);
// 	log_debug() << lat << " -> " << lat.get_hemisphere().first << ";" << lat.get_hemisphere().second << std::endl;
	
// 	qty::Longitude lon = qty::Longitude::dms(-47,-06.23,0);
// 	log_debug() << lon << " -> " << lon.get_hemisphere().first << ";" << lon .get_hemisphere().second << std::endl;

// 	std::vector<std::string> dms_str = {lat.get_dms().to_string(), "47°06'13.800\" S", "47°06'13.800\" N", "50.2°01'"};

// 	for(std::string dms : dms_str) {
// 		auto[_d, _m, _s] = qty::Angle::str_to_dms(dms);
// 		log_debug() << "Latitude convertida [" << dms << "]: " << _d << "° " << _m << "' " << _s << "\"" << std::endl;
// 	}

	qty::Velocity velocity(qty::Bearing::deg(179.55), qty::Speed::m_s(10.2889));
	qty::Displacement cartesian(qty::Bearing::deg(90), qty::Distance::km(3.65763));
	qty::Displacement moved = cartesian + velocity * qty::Time::s(1);

	log_debug() << "\tVelocity: " << velocity << std::endl;
	log_debug() << "\tcartesian: " << cartesian << std::endl;
	log_debug() << "\toffset: " << (velocity * qty::Time::s(1)) << std::endl;
	log_debug() << "\tmoved: " << moved << std::endl;
	log_debug() << "\tmoved: " << moved.get_direction() << " " << moved.get_magnitude() << std::endl;


	qty::Displacement cartesian3(qty::Distance::m(-1), qty::Distance::km(3.65763));
	log_debug() << "\tcartesian3: " << cartesian3 << std::endl;

	std::vector<qty::Speed> speeds(1e6);
	log_debug() << "std::vector<qty::Speed>(1e6);" << std::endl;
	std::vector<qty::Speed> speedss(1e6, qty::Speed::knot(2));
	log_debug() << "std::vector<qty::Speed>(1e6, qty::Speed::knot(2));" << std::endl;
	std::vector<double> speedoubles(1e6);
	log_debug() << "std::vector<double>(1e6);" << std::endl;

	// qty::Distance aux = qty::Distance::m(15e3);

	// qty::Timestamp ts0;
	// double ret = 0;
	// for(size_t i = 0; i < 1e7; i++){
	// 	ret += aux.get_m();
	// }
	// ts1 = qty::Timestamp();
	// log_debug() << "[" << (ts1 - ts0) << "]get_m(): " << ret << std::endl;

	// ts0 = qty::Timestamp();
	// for(size_t i = 0; i < 1e7; i++){
	// 	ret += aux.get_km();
	// }
	// ts1 = qty::Timestamp();
	// log_debug() << "[" << (ts1 - ts0) << "]get_km(): " << ret << std::endl;

	// ts0 = qty::Timestamp();
	// for(size_t i = 0; i < 1e7; i++){
	// 	ret += aux.get_yd();
	// }
	// ts1 = qty::Timestamp();
	// log_debug() << "[" << (ts1 - ts0) << "]get_yd(): " << ret << std::endl;

	// ts0 = qty::Timestamp();
	// for(size_t i = 0; i < 1e7; i++){
	// 	ret += aux.get_kyd();
	// }
	// ts1 = qty::Timestamp();
	// log_debug() << "[" << (ts1 - ts0) << "]get_kyd(): " << ret << std::endl;


	qty::Timestamp ts0 = qty::Timestamp();
	double ret = 0;
	for(size_t i = 0; i < 1e5; i++){
		ret += qty::convert_to<qty::Prefix>(qty::Prefix::M, 1);
	}
	ts1 = qty::Timestamp();
	log_debug() << "[" << (ts1 - ts0) << "] convert_to: " << ret << std::endl;
	

	return EXIT_SUCCESS;
}
