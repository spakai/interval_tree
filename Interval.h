#pragma once
class IntervalBuilder;

class Interval {
  public:

    friend IntervalBuilder;

    Interval() {
      this->start = 0;
      this->end = 0;
    }

    Interval(long int start, long int end) {
      this->start = start;
      this->end = end;
    }

    bool doTheyOverlap(Interval& interval) {
      bool b1 = this->start <= interval.end;
      bool b2 = interval.start <=this->end;
      return b1 && b2;
    }

    bool operator==(const Interval &i1){
        return (this->start == i1.start && this->end == i1.end);
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

class IntervalBuilder {
  public:
    IntervalBuilder& greaterThanOrEqual(long int i) {
      interval.start = i;
      return *this;
    }

    IntervalBuilder& lessThan(long int i) {
      interval.end = i - 1;
      return *this;
    }

    IntervalBuilder& greaterThan(long int i) {
      interval.start = i + 1;
      return *this;
    }

    IntervalBuilder& lessThanOrEqual(long int i) {
      interval.end = i;
      return *this;
    }

    Interval build() {
      return std::move(interval);
    }

    private:
      Interval interval;
};
