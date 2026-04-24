# Soren-Utils

## struct Color:
  - string t_bk
  - string t_rd
  - string t_gn
  - string t_yw
  - string t_be
  - string t_ma
  - string t_cn
  - string t_we
  - string tb_bk
  - string tb_rd
  - string tb_gn
  - string tb_yw
  - string tb_be
  - string tb_ma
  - string tb_cn
  - string tb_we
  - string b_bk
  - string b_rd
  - string b_gn
  - string b_yw
  - string b_be
  - string b_ma
  - string b_cn
  - string b_we
  - string bb_bk
  - string bb_rd
  - string bb_gn
  - string bb_yw
  - string bb_be
  - string bb_ma
  - string bb_cn
  - string bb_we
  - string cl

## class Time:
  - int hour
  - int minute
  - int second
  - void getTime(int bonus=0)


## class Date:
  - int day
  - int month
  - int year
  - void getDate(int bonus=0)


## string lower(string Str):
  - return Str


## void cls()


## int termSize(bool cr):
  - if cr=false:
    - return columns
  - else:
    - return rows


## void alignOut(string Out, short int a=0, int offset=0):
  - if a=0:
    - print "Out" aligned to the Right (moved by "offset" number of characters)
  - elif a=1:
    - print "Out" aligned to the Center (moved by "offset" number of characters)
  - elif a=0:
    - print "Out" aligned to the Left (moved by "offset" number of characters)


## string alignIn(string In, short int a=0, int offset=0): // WINDOWS ONLY!
  - if a=0:
    - print "In"+input aligned to the Right (moved by "offset" number of characters)
  - elif a=1:
    - print "In"+input aligned to the Center (moved by "offset" number of characters)
  - elif a=0:
    - print "In"+input aligned to the Left (moved by "offset" number of characters)
  - return input


## void order(any array[], int q, any field, bool ord=true):
  - if ord=true:
    - order "array" in increasing order
  - else:
    - order "array" in decreasing order


## void wait(int sec, bool show)
  - if show=true:
    - print countup
