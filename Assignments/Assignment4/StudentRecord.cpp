#include "StudentRecord.h"


///////////////////////////
// I provide these functions
///////////////////////////
StudentRecord::StudentRecord(){}

std::string StudentRecord::firstname() const { return firstname_; }

std::string StudentRecord::lastname() const { return lastname_; }

double StudentRecord::score() const { return score_; }

std::ostream & operator<<( std::ostream & out, StudentRecord const &right ){ right.print(out); return out; }

std::istream & operator>>( std::istream & in, StudentRecord  &right ){ right.input(in); return in; }


///////////////////////////
// You provide these functions
///////////////////////////

bool StudentRecord::operator>( StudentRecord const & right ) const {
  return true; /// YOUR CODE GOES HERE
};

bool StudentRecord::operator>=( StudentRecord const & right ) const {
  return true; /// YOUR CODE GOES HERE
};

bool StudentRecord::operator<( StudentRecord const & right ) const {
  return true; /// YOUR CODE GOES HERE
};

bool StudentRecord::operator<=( StudentRecord const & right ) const {
  return true; /// YOUR CODE GOES HERE
};

void StudentRecord::compute_score(void) {
  /// YOUR CODE GOES HERE
}

void StudentRecordPhysics::print( std::ostream & out ) const  {
  /// YOUR CODE GOES HERE
}

bool StudentRecordPhysics::input( std::istream & in )  {
  /// YOUR CODE GOES HERE
  return true; 
}

void StudentRecordLiterature::print( std::ostream & out ) const  {
  /// YOUR CODE GOES HERE
}

bool StudentRecordLiterature::input( std::istream & in )  {
  /// YOUR CODE GOES HERE
  return true;  
}

void StudentRecordHistory::print( std::ostream & out ) const  {
  /// YOUR CODE GOES HERE
}

bool StudentRecordHistory::input( std::istream & in )  {
  /// YOUR CODE GOES HERE
  return true;
}

