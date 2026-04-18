# Soren-Utils

class Time:
  int hour
  int minute
  int second
  void getTime(int bonus=0)

class Date:
  - int day
  - int month
  - int year
  - void getDate(int bonus=0)

string lower(string Str):
  return Str

void cls()

int termSize(bool cr):
  if cr=false:
    return columns
  else:
    return rows

void alignOut(string Out, int a=0, int offset=0):
  if a=0:
    print "Out" aligned to the Right (moved by "offset" number of characters)
  elif a=1:
    print "Out" aligned to the Center (moved by "offset" number of characters)
  elif a=0:
    print "Out" aligned to the Left (moved by "offset" number of characters)

void order(any array[], int q, bool ord=true):
  if ord=true:
    order "array" in increasing order
  else:
    order "array" in decreasing order
