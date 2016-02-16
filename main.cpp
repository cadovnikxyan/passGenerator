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

string passGen(){
	
	char s[]="qQwWeErRtTyYuUiIoOpPaAsSdDfFgGhHjJkKlLzZxXcCvVbBnNmM1234567890!@#";		
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

void generator(const char* filepath,const char* fileout){
	
			vector<string> instr;
			vector<string> outstr;
			fileread(filepath,&instr);
			for(size_t i=0;i<instr.size();i++){
				if(instr.at(i)!=""){
				                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
				outstr.push_back(instr.at(i)+" "+passGen());
				}
			}
			filewrite(fileout,&outstr);
			
}
void help(){
				cout<<"this programm for generated passwords"<<endl
				<<"flag description:"<<endl
				<<"flag -I enter input file text data  "<<endl
				<<"file structure is "<<endl
				<<"Full name - department -||"<<endl
				<<"flag -O if you want to customize output file name"<<endl
				<<"flag -S generated single password"<<endl;
}

int main(int argc, char* argv[]) {
			
		srand(time(NULL));

		if(argc>1){
			if(argc>3){
				if(strcmp(argv[3],"-O")==0){
					generator(argv[2],argv[4]);	
					cout<<"passwords generated!"<<endl;	
				}
				
			}else if(strcmp(argv[1],"-I")==0){					
				generator(argv[2],"out.txt");	
				cout<<"passwords generated!"<<endl;	
										
			}else if(strcmp(argv[1],"-S")==0){
				cout<<"Single password generated!"<<endl;
				cout<<passGen()<<endl;
			}else if(strcmp(argv[1],"-h")==0){
				help();
			}else{
				help();
			}
		}else{
			help();			
		}
				
	return 0;
}





