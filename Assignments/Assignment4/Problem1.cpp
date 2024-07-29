#include "StudentRecord.h"
#include <iostream>
#include <fstream>
#include <tuple>
#include <numeric>



// We are writing a program that:
/*
"Student Records" indicate student performance in their courses. 
These records are input as a text file with the following values separated by commas: 
- Name of course 
- Last name
- First name
- List of scores for the course and their weights. 
Each course will have a different number of scores and weights. 

Example: 
Physics,Tip,Q,87.3,95.0
Literature,Dawg,Phife,95.0,85.0,98.0
Physics,Muhammad,Ali Shaheed,97.0,80.0
History,White,Jarobi,85.0,84.0

There are three courses: Physics, History, and Literature. 

Physics course should have two scores: homework (80% of grade) and lab (20% of grade).
History course should have two scores: exam1 and exam2. The higher grade is weighted 60% and the lower grade is weighted 40%.
Literature course should have three scores: analytic (40%), creative (40%), and commentary (20%).



The assignment is to: 

Input the values in a csv record that is specified on the command line. 
Print the list of students in each course separately, as well as their overall averages. 
Print the total averages for each course.  


*/

int main(int argc, char * argv[]){

  // First we create some shorthand typedefs of SMART pointers to our records.
  // This will allow us to store a vector of the records regardless of their type. 
  typedef std::shared_ptr<StudentRecord> StudentRecordPtr;
  typedef std::vector<StudentRecordPtr> StudentRecordColl;


  // Input the file from the command line
  if ( argc < 2 ) {
    std::cout << "Usage: " << argv[0] << "records.txt" << std::endl;
    return 0;
  }
  std::ifstream fin( argv[1] );

  // We create records for the various classes that
  // correspond to the different courses. 
  StudentRecordColl records, physics, literature, history;

  // We loop through the file and read each record. Depending
  // on the first string for the course, we add a different
  // type (StudentRecordPhysics, etc). 
  bool valid = true;
  while( valid ) {
    std::string line;
    std::getline( fin, line, ',');
    if ( line == "" ) 
      break;

    if ( line == "Physics" ) {
      StudentRecordPtr irecord( new StudentRecordPhysics() );
      valid = irecord->input(fin);
      if ( valid ) {
	records.push_back( irecord );
	physics.push_back( irecord );
      }
      else
	break;
    } else if ( line == "Literature" ) {
      StudentRecordPtr irecord( new StudentRecordLiterature() );
      valid = irecord->input(fin);
      if ( valid ) {
	records.push_back( irecord );
	literature.push_back( irecord );
      }
      else
	break;
    } else if ( line == "History" ) {
      StudentRecordPtr irecord( new StudentRecordHistory() );
      valid = irecord->input(fin);
      if ( valid ) {
	records.push_back( irecord );
	history.push_back( irecord );
      }
      else
	break;
    } else {
      std::cout << "Invalid input, ignoring" << std::endl;
      continue;
    }

  }

  // Now we have our primary code.
  // I will make this a bit easier on you and start the
  // loop over all of the various categories. That way,
  // IF YOU HAVE IMPLEMENTED THE CODE CORRECTLY,
  // all of the various classes can be treated identically.
  // I've used a bunch of advanced features here, but
  // you just need to know the types of "name" and "vals"
  // to solve the rest. 

  auto groups = { std::make_tuple("All", &records),
		  std::make_tuple("Physics", &physics),
		  std::make_tuple("History", &history),
		  std::make_tuple("Literature", &literature)};


  for ( auto group : groups ) {
    auto name = std::get<0>( group );      /// string
    auto & vals = std::get<1>( group );    /// acts like vector<StudentRecord *> but intelligently

    // YOUR CODE GOES HERE. 
    
  }

  
}
