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
        char value;
    //public:
        Program ( int, char );
    // void set_OG
        // void get_OG
        // void something key related.
};

Program::Program ( int a, char b ){
    OGpos = a;
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
    
    // shift NewList char by |newFront|
    for( int i=ProgVect.size()-newFront; i>=0; --i ){
        ProgVect[ i+newFront ] = ProgVect[i];
    }   

    // place temp char back on front
    for( int i=0; i<temp.size(); ++i ){
        ProgVect[i] = temp[i];
    }
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
    
    // push char onto temp vector
    vector<char> temp;
    for( int i=NewList.size()-newFront; i<NewList.size(); ++i ){
        temp.push_back( NewList[i] );
    }
    
    // shift NewList char by |newFront|
    for( int i=NewList.size()-newFront; i>=0; --i ){
        NewList[ i+newFront ] = NewList[i];
    }   

    // place temp char back on front
    for( int i=0; i<temp.size(); ++i ){
        NewList[i] = temp[i];
    }

}


void exchange( vector<Program> &ProgVect, int aPos, int bPos ){
    Program temp = ProgVect[ aPos ];
    ProgVect[ aPos ] = ProgVect[ bPos ];
    ProgVect[ bPos ] = temp;
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

    // store into a vector of Program class
    vector<Program> ProgVect;
    for( int i=0; i<OGList.length(); ++i ){
        Program p( i, OGList[i] ); // create object called p
        ProgVect.push_back(p);     // push on vector
    }
    // print current custom vector
    for( int i=0; i<ProgVect.size(); ++i ){
        cout<<"progVect pos: "<<ProgVect[i].OGpos<<
        " val: "<<ProgVect[i].value<<endl;
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
            // add spin on our progvect
            spin( ProgVect, newFront );
            cout<<"newlist:"<<endl;
            for( int i=0; i<NewList.size(); ++i ){
                cout<< NewList[i];
            }

            // print test of progvect
            
            for( int i=0; i<ProgVect.size(); ++i ){
                cout<<"progVect pos: "<<ProgVect[i].OGpos<<
                " val: "<<ProgVect[i].value<<endl;
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
        
            // progvect test
            cout<<"prog vect swap ";
            exchange( ProgVect, aPos, bPos );
                   
            for( int i=0; i<ProgVect.size(); ++i ){
                cout<<"progVect pos: "<<ProgVect[i].OGpos<<
                " val: "<<ProgVect[i].value<<endl;
            }
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

