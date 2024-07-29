#ifndef STUDENTRECORD_H
#define STUDENTRECORD_H

#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

//////////
// This is the base class for the records of all the courses
//////////

class StudentRecord {
 public:
  // I provide these functions. 
  StudentRecord();
  ~StudentRecord(){}

  // I provide these functions.  
  std::string firstname() const;
  std::string lastname() const;
  double score() const;

  // For the abstract base class, these functions do not exist.
  // Implement them in the derived classes. 
  virtual void print ( std::ostream & out = std::cout ) const = 0;
  virtual bool input ( std::istream & in ) = 0;

  // You code these functions.
  // They should sort based on the total score the student
  // acheives. 
  bool operator>( StudentRecord const & right ) const;
  bool operator<( StudentRecord const & right ) const;
  bool operator>=( StudentRecord const & right ) const;
  bool operator<=( StudentRecord const & right ) const;

  // I provide these functions. 
  // These functions will call the "print" and "input" methods
  // you created above. These cannot be derived since they are
  // friend classes.
  friend std::ostream & operator<<( std::ostream & out, StudentRecord const & );
  friend std::istream & operator>>( std::istream & in , StudentRecord const &);


 protected:

  // These are the protected data members: 
  std::string firstname_;              // first name of student
  std::string lastname_;               // last name of student
  std::vector<double> scores_;         // set of scores for the student
  std::vector<double> weights_;        // set of weights for the student
  double score_;                       // average score

  // You code this function. It should be protected.  
  void compute_score(void);            // protected function to compute the score
};

//////////
// These are the derived classes for the different courses. 
//////////

class StudentRecordPhysics : public StudentRecord {
 public:
  StudentRecordPhysics(){}
  virtual ~StudentRecordPhysics(){}
  
  // Overload these functions. 
  virtual void print( std::ostream & out = std::cout ) const;
  virtual bool input( std::istream & in );
};


class StudentRecordLiterature : public StudentRecord {
 public:
  StudentRecordLiterature(){}
  virtual ~StudentRecordLiterature(){}

  // Overload these functions. 
  virtual void print( std::ostream & out = std::cout ) const;
  virtual bool input( std::istream & in );
};


class StudentRecordHistory : public StudentRecord {
 public:
  StudentRecordHistory(){}
  virtual ~StudentRecordHistory(){}

  // Overload these functions. 
  virtual void print( std::ostream & out = std::cout ) const;
  virtual bool input( std::istream & in );
};

#endif
