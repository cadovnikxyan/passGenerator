#include <iostream>
#include <boost/thread.hpp>
#include <boost/algorithm/string.hpp>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

void fileread(const char* filepath,vector<string>* instr){
		 std::string str((std::istreambuf_iterator<char>(*(std::auto_ptr<std::ifstream>(new std::ifstream(filepath))).get())), std::istreambuf_iterator<char>()
	    );
	    boost::split(*instr,str,boost::is_any_of("||"));
}



string passGen(char* s){
	
	string pass;
	for(int i=0;i<12;i++){
		int gen=rand()%65;
		pass+=s[gen];
	}
	
	return pass;
			
		
}

void filewrite(const char* filepath,vector<string>* out){
	ofstream fout(filepath,std::ios::app);
		for(size_t i=0;i<out->size();i++){
			fout<<out->at(i)<<"\n";
		}
}

int main(int argc, char* argv[]) {
	


	char s[]="qQwWeErRtTyYuUiIoOpPaAsSdDfFgGhHjJkKlLzZxXcCvVbBnNmM1234567890!@#";
		srand(time(NULL));

		if(argc>1){
			vector<string> instr;
			vector<string> outstr;
			fileread(argv[1],&instr);
			for(size_t i=0;i<instr.size();i++){
				if(instr.at(i)!=""){
				
					string out=instr.at(i);
					string buf;
					buf=passGen(s);					
				
					cout<<buf<<endl;
					out.append(buf);
					buf.clear();
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
				outstr.push_back(out);
				}
			}
			filewrite("out.txt",&outstr);
		}


	return 0;
}
