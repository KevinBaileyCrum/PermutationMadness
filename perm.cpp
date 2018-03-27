#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main(int argc, char** argv){
    if( argc<2 ){
        cout<<"usage: ./perm filename"<<endl;
        exit( EXIT_FAILURE );
    }
    
    string line;
    string opps;
    ifstream inFile( argv[1] );
        getline( inFile, line );
        cout<<line<<endl;
        cout<<line[1]<<endl;

        getline( inFile, opps );
        cout<<opps<<endl;
}
