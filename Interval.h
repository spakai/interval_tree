#pragma once

class Interval {
  public:

    Interval() {
      this->start = 0;
      this->end   = 0;
    }

    Interval(long int start, long int end) {
      this->start = start;
      this->end = end;
    }

    bool doTheyOverlap(Interval interval) {                           
      if (this->start <= interval.end &&                                                            
        interval.start <=this->end) {                                                               
        return true;                                                                                              
      } else {                                                                                                    
        return false;                                                                                           
      }                                                                                                           
    }   

  long int getStart() {
    return start;
  }      

  long int getEnd() {
    return end;
  } 

  private:
    long int start;
    long int end;
};
