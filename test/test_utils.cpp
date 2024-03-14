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
	std::string path_arg;
	std::string data;
	std::string line ;
};

void loop(Options options) {
	// Code here.
	std::ifstream filein; 

	filein.open (options.path_arg) ;

	if ( filein.is_open () ){
    	std::cout << "O arquivo, " << "\"" << options.path_arg << "\"" << ", foi aberto corretamente.\n\n";
    	while ( getline ( filein , options.line ) ){
        		std::cout<< options.line << '\n';
    	}
		filein.close () ;   
	}
	else{
    	std::cout << "O arquivo, " << "\"" << options.path_arg << "\"" << ", não pode ser aberto.\n";
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
			std::cout << "Início do " << program_invocation_short_name << std::endl;
		});
		
		arguments.add_mandatory("file_path", options.path_arg);

		arguments.add_example("~/Documents/test.txt");

		//std::cout << "required_str: " << options.path_arg << std::endl;

		arguments.parse(argc, argv);

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