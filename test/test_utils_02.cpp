#include <csignal>
#include <fstream>
#include <string>
//#include <iostream>

#include <utils/log.hpp>
#include <utils/arguments.hpp>

volatile std::sig_atomic_t done = 0;

void signal_handler(int signal)
{
	done = 1;
}

struct Options {
	// bool flag_print = false;
	bool flag_vxi11 = false;
	std::pair<std::string, std::string> host_device;
	
	std::string path_arg;
	std::string data;
	std::string line ;
};

void loop(Options options) {
	// Code here.
	std::ifstream filein;
	std::cout << "Arquivo: " << options.path_arg << std::endl;

	if(options.flag_vxi11 == true){
		std::cout << '\n' << options.host_device.first << '\n';
		std::cout << '\n' << options.host_device.second << '\n';
	}
	

	done = true;
}

int main (int argc, char **argv)
{
	std::signal(SIGINT, signal_handler);
	std::signal(SIGTERM, signal_handler);

	try {
		Options options;
		Arguments arguments;
		arguments.add_optional_callback('p',"print", "prints to terminal at start", [](){
			std::cout << "Início do programa " << program_invocation_short_name << std::endl;});
		
		arguments.add_optional_callback<std::string>('l',"pprint", "prints to terminal at start", [&](std::string t){options.path_arg = t;});

		arguments.add_optional<std::string>('r', "read", "start of reading in terminal:\n", options.path_arg, "");

		arguments.add_optional_callback<std::string>('v', "vxi11", "host:device", [&](std::string t)
														 {options.flag_vxi11 = true; 
														size_t pos = t.find_first_of(":");
														if (pos == std::string::npos) {
															exit(EXIT_FAILURE);
														}
														options.host_device.first = t.substr(0, pos);
														t.erase(0, pos + 1);
														options.host_device.second = t;	});
		
		log_info() << "flag_vxi11: " << ((options.flag_vxi11) ? "True" : "False") << std::endl;
		
		//arguments.add_mandatory("file_path", options.path_arg);

		//arguments.add_example("~/Documents/test.txt");
		arguments.add_example("-p ~/Documents/test.txt");
		arguments.add_example("-r=~/Documents/test.txt");
		arguments.add_example("-v 172.16.13.152:gpib0,10");
		

		arguments.parse(argc, argv);

		log_info() << "flag_vxi11: " << ((options.flag_vxi11) ? "True" : "False") << std::endl;

		while (!done) {
			try {
				loop(options);
			} catch (std::exception& e) {
				log_exception() << e.what() << std::endl;
			}
		}
	} catch (std::exception& e) {
		log_exception() << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}