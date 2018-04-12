# Motivation
Two problems at work that required a data structure that validate

i) if a row of record with start and end date is valid at a given point of time.

ii) if a record is active at a certain interval.


# Design
i) Builder pattern to build an interval that supports open and closed intervals.

ii) Self balancing interval tree build on top of a binary search tree.

iii) Retrieve all matching intervals.
