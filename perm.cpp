#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


void spin( vector<char> &NewList, int newFront ){
    // handle invalid spin sN s.t. N>OGList.length()
     
    cout<<" opps ascii in spin "<<newFront<<endl;
    cout<< newFront;
    if( newFront > NewList.size()-1 || newFront < 0 ){
        cout<<" Spin called on invalid operand: S"<<newFront<<endl;
        exit( EXIT_FAILURE );
    }
    cout<<"spin: "<<newFront<<endl;
    vector<char> Temp; 
    for( int i=0; i<newFront; ++i ){
        Temp.push_back( NewList[i] ); 
    }
    
    // push chars onto temp vector
    for( int i=0; i<Temp.size(); ++i ){  
        cout<<Temp[i]<<endl;
    }
    
    // shift char remaining char to front
    for( int i=newFront; i<NewList.size(); ++i ){
        NewList[i] = NewList[i-newFront];
    }
}


int main(int argc, char** argv){
    // cmndln args error handling
    if( argc<2 ){
        cout<<"usage: ./perm filename"<<endl;
        exit( EXIT_FAILURE );
    }
    
    // Get OG string: OGList
    string OGList;
    string opps;
    ifstream inFile( argv[1] );
    getline( inFile, OGList );
    cout<<"OGLIST "<<OGList<<endl;
    cout<<"OGList.length() "<<OGList.length();
    // store in temp string: NewList
    // vector manipulation will happen here
    vector<char> NewList;
    for( int i=0; i<OGList.length(); ++i ){
        NewList.push_back( OGList[i] );
    }

    getline( inFile, opps );
    cout<<"OPPS LIST "<<opps<<endl;
    for( int i=0; i<opps.length(); ++i ){
        // this will fail on double digit
        if( opps[i] == 's' ){
            cout<<"s found: "<<i<<endl;
            ++i;
            // TODO: get has_second_digit 
            cout<<" opps ascii "<<opps[i]<<endl;
            // convert ascii to int
            stringstream str;
            str << opps[i];
            int newFront;
            str >> newFront;
            spin( NewList, newFront );
            cout<<"new i counter at: "<<i<<endl;
        }
    }

    return 0;
}

