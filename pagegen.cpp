#include<iostream>
#include<fstream>
#include<string>

void suggest_pagestart(std::string str_filename) {
	const char *filename = str_filename.c_str();
	std::ifstream suggest_template;
	suggest_template.open("s_template_start");
	std::ofstream pagefile;
	pagefile.open(filename);
	std::string line;
	while (getline (suggest_template,line) ) {
		pagefile << line;
	}
	suggest_template.close();
	std::string unique_inputs;
	std::cout << "What would you like the question to say?" << std::endl;
	std::getline(std::cin,unique_inputs);
	pagefile << unique_inputs;
	std::ifstream suggest_template2;
	suggest_template2.open("s_template_2");
	while (getline (suggest_template,line) ) {
		pagefile << line;
	}
	while(true) {
		std::cout << "Enter the url the button should take you to." << std::endl;
		std::getline(std::cin,unique_inputs);
		pagefile << unique_inputs;
		suggest_template.open("s_template_3");
		while (getline (suggest_template,line) ) {
			pagefile << line;
		}
		std::cout << "The filename of the button png? Include the extension but exclude the folder(it's in images, right? if it's not, it should be!)." << std::endl;
		std::getline(std::cin,unique_inputs);
		pagefile << unique_inputs;
		pagefile << "\" alt=\"";
		std::cout << "Alt text?" << std::endl;
		std::getline(std::cin,unique_inputs);
		pagefile << unique_inputs;
		pagefile << "\" height=\"50\"></a>";
		std::string y_n;
		std::cout << "Do you want another button (y/n)?" << std::endl;
		std::getline(std::cin,y_n);
		if (y_n == "n" || y_n == "N" || y_n == "no" || y_n == "No" || y_n == "NO") {
			break;
		}
		pagefile << "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n<a href=\"";
	}
	suggest_template.open("foot_template");
	while (getline (suggest_template,line) ) {
		pagefile << line;
	}
	pagefile.close();
}

void refine_pagestart(std::string filename) {
	suggest_pagestart(filename);
}

int main() {
	std::string output_filename;
	std::cout << "Name the file to be generated (including extension)." << std::endl;
	std::getline(std::cin,output_filename);
	while(true) {
		std::string y_n;
		std::cout << "Is it a suggestion question (y/n)?" << std::endl;
		std::getline(std::cin,y_n);
		if (y_n == "y" || y_n == "Y" || y_n == "yes" || y_n == "Yes" || y_n == "YES") {
			suggest_pagestart(output_filename);
			return 0;
		}
		else if (y_n == "n" || y_n == "N" || y_n == "no" || y_n == "No" || y_n == "NO") {
			refine_pagestart(output_filename);
			return 0;
		}
		else {
			std::cout << "Try again." << std::endl;
		}
	}
	return 0;
}
