#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm> 

using namespace std;

int convertToInt( char chr ){ 
    stringstream str;
    str << chr;
    int newFront;
    str >> newFront;
    return newFront;
}

void spin( vector<char> &NewList, int newFront ){
    // handle invalid spin sN s.t. N>OGList.length()
    if( newFront > NewList.size()-1 || newFront < 0 ){
        cout<<" Spin called on invalid operand: S"<<newFront<<endl;
        exit( EXIT_FAILURE );
    }
    if( newFront == 0) { // do nothing
        return;
    }
    
    cout<<"spin: on "<<newFront<<endl;
    for( int i=0; i<NewList.size(); ++i ){
        cout<<NewList[i];
    }
    cout<<endl;
    
    // push char onto temp vector
    vector<char> temp;
    for( int i=NewList.size()-newFront; i<NewList.size(); ++i ){
        temp.push_back( NewList[i] );
    }
    
    cout<<"temp"<<endl;
    for( int i=0; i<temp.size(); ++i ){
        cout<<temp[i];
    }
    cout<<endl;
    
    // shift NewList char by |newFront|
    for( int i=NewList.size()-newFront; i>=0; --i ){
        NewList[ i+newFront ] = NewList[i];
    }   

    // place temp char back on front
    for( int i=0; i<temp.size(); ++i ){
        NewList[i] = temp[i];
    }

    cout<<"post tate"<<endl;
    for( int i=0; i<NewList.size(); ++i ){
        cout<<NewList[i];
    }
    cout<<endl;
}

void exchange( vector<char> &NewList, int aPos, int bPos ){
    char temp = NewList[ aPos ];
    NewList[ aPos ] = NewList[ bPos ];
    NewList[ bPos ] = temp;
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
    for( int i=0; i<NewList.size(); ++i) {
        cout<<"NewList "<<NewList[i]<<endl;
    }
    getline( inFile, opps );
    cout<<"OPPS LIST "<<opps<<endl;
    for( int i=0; i<opps.length(); ++i ){
        // parse 's' for spin
        // this will fail on double digit
        if( opps[i] == 's' ){
            cout<<"s found: "<<i<<endl;
            ++i;
            // TODO: get has_second_digit 
            cout<<" opps ascii "<<opps[i]<<endl;
            int newFront = convertToInt( opps[i] );
            spin( NewList, newFront );
            for( int i=0; i<NewList.size(); ++i ){
                cout<< NewList[i];
            }
            cout<<"\nnew i counter at: "<<i<<endl;
        }
        // parse 'x' for exchange
        if( opps[i] == 'x' ){
            cout<<"exchange mode called on ";
            ++i;
            int aPos = convertToInt( opps[i] );
            cout<<opps[i]<<" and ";
            ++i; ++i;
            int bPos = convertToInt( opps[i] );
            cout<<opps[i]<<endl;
            exchange( NewList, aPos, bPos );
            // print exchange for debugging purposes
            cout<<"post exchange "<<endl;
            for( int i=0; i<NewList.size(); ++i ){
                cout<<NewList[i];
            }
            cout<<endl;
        }
    }

    return 0;
}

