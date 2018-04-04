#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm> 

using namespace std;


class Program {
    public:
        int OGpos;
        int currPos;
        char value;
        Program ( int, char );
};

Program::Program ( int a, char b ){
    OGpos = a;
    currPos = a;
    value = b;
}

int convertToInt( char chr ){ 
    stringstream str;
    str << chr;
    int newFront;
    str >> newFront;
    return newFront;
}

void spin( vector<Program> &ProgVect, int newFront ){
    // handle invalid spin sN s.t. N>OGList.length()
    if( newFront > ProgVect.size()-1 || newFront < 0 ){
        cout<<" Spin called on invalid operand: S"<<newFront<<endl;
        exit( EXIT_FAILURE );
    }
    if( newFront == 0) { // do nothing
        return;
    }
    
    cout<<"new spin happening"<<endl;
    // push char onto temp vector
    vector<Program> temp;
    for( int i=ProgVect.size()-newFront; i<ProgVect.size(); ++i ){
        temp.push_back( ProgVect[i] );
    }
    
    // shift elements over and update current pos
    for( int i=ProgVect.size()-newFront; i>=0; --i ){
        ProgVect[ i+newFront ] = ProgVect[i];
    }   

    // place temp char back on front and update current pos
    for( int i=0; i<temp.size(); ++i ){
        ProgVect[i] = temp[i];
    }
}

void exchange( vector<Program> &ProgVect, int aPos, int bPos ){
    Program temp = ProgVect[ aPos ];
    ProgVect[ aPos ] = ProgVect[ bPos ];
    ProgVect[ bPos ] = temp;
    cout<<"progvector testM"<<endl;
    for( int i=0; i<ProgVect.size(); ++i ){
        cout<<"prog val "<<ProgVect[i].value
            <<"prog OG "<<ProgVect[i].OGpos
            <<"prog curr "<<ProgVect[i].currPos
            <<endl;
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
    
    // vector manipulation will happen here
    // store into a vector of Program class
    vector<Program> ProgVect;
    for( int i=0; i<OGList.length(); ++i ){
        Program p( i, OGList[i] ); // create object called p
        ProgVect.push_back(p);     // push on vector
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
            
            // add spin on our progvect
            spin( ProgVect, newFront );
            
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
            // print exchange for debugging purposes
            cout<<"post exchange "<<endl;
        
            // progvect test
            cout<<"prog vect swap "<<endl;
            exchange( ProgVect, aPos, bPos );
                   
        }
        // parse 'p' for partner
        if( opps[i] == 'p' ){
            cout<<"partner found on ";
            ++i;
            int aPos = convertToInt( opps[i] );
            cout<<opps[i]<<" and ";
            ++i; ++i;
            int bPos = convertToInt( opps[i] );
            cout<<opps[i]<<endl;
        }
    }

    return 0;
}

