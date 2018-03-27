#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char** argv){
    // cmndln args error handling
    if( argc<2 ){
        cout<<"usage: ./perm filename"<<endl;
        exit( EXIT_FAILURE );
    }
    
    // Get OG string: OGList
    // store in temp string: NewList
    string OGList;
    string opps;
    ifstream inFile( argv[1] );
        getline( inFile, OGList );
        cout<<OGList<<endl;
        
        vector<char> NewList;
        for( int i=0; i<OGList.length(); ++i ){
            NewList.push_back( OGList[i] );
        }

        getline( inFile, opps );
        cout<<opps<<endl;
}
