#include <ansi.h>

int filen;
int nroom;
string rtype;
string dirlist;
int snum;
int newx;
int ldang;
int ddang;
int e1;
string et1;
int e2;
string et2;
int e3;
string et3;
int e4;
string et4;
string *room_num;

status id(string str)
{
  return str=="rtool";
}

void init()
{
  object ob;

  ob=environment();

  if(!ob || (int)ob->query_level() < 20)
  {
    return destruct(this_object());
  }
  add_action("make_it", "make");
  add_action("set_up_array", "setarray");
}

void set_up_array()
{
  room_num = ({ "X",
 "~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~",
 "~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~",
 "~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~",
 "~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~",
 "~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~",
 "~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~",
 "~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~",
 "~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","M","M","~","~","~","~","~","~",
 "~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","M","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~",
 "~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","M","M","M","~","M","M","M","M","~","~","~","~","~",
 "~","~","~","~","#","#","#","~","~","~","~","~","~","~","~","~","~","n","n","n","M","M","M","M","n","n","M","M","~","~","~","~",
 "~","~","~","#","@","@","@","#","#","~","~","~","~","~","~","@","@","@","@","n","n","n","M","n","n","n","n","M","M","~","~","~",
 "~","~","#","#","@","@","@","#","#","#","#","~","~","~","#","#","@","@","@","@","@","n","n","n","#","#","#","n","n","n","~","~",
 "~","~","n","n","n","@","@","@","@","#","@","@","@","~","~","~","#","#","@","@","@","@","@","n","@","@","#","#","#","~","~","~",
 "~","~","~","~","M","n","@","@","@","#","@","@","@","#","~","~","#","@","@","#","@","@","@","@","n","@","#","#","#","~","~","~",
 "~","~","~","M","M","n","n","#","@","@","@","#","#","#","~","~","#","@","@","@","#","#","#","n","@","@","@","#","#","#","~","~",
 "~","~","M","M","M","n","n","#","#","@","@","#","~","~","~","#","@","@","@","@","@","#","n","M","n","@","@","#","#","~","~","~",
 "~","~","~","M","M","M","M","n","n","#","#","#","=","#","@","@","@","@","@","#","#","#","#","n","#","#","#","#","~","~","~","~",
 "~","~","~","M","M","M","n","M","n","n","~","~","~","#","@","@","@","@","#","@","@","#","#","#","#","#","#","#","#","~","~","~",
 "~","~","#","#","M","M","n","n","~","~","~","~","#","#","~","#","@","~","~","@","@","#","#","#","#","#","~","#","#","~","~","~",
 "~","~","~","#","#","n","M","n","#","~","n","~","~","~","#","n","#","#","~","#","#","#","#","#","#","#","#","~","~","~","~","~",
 "~","~","~","~","~","#","#","#","#","~","~","~","~","n","#","n","n","n","~","#","#","#","#","#","#","#","#","#","~","~","~","~",
 "~","~","~","~","~","~","~","~","~","~","~","~","~","n","n","n","n","~","~","~","#","#","#","#","#","#","~","~","~","~","~","~",
 "~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","#","#","#","#","#","~","~","~","~","~",
 "~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~",
 "~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~",
 "~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~",
 "~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~",
 "~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~",
 "~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~",
 "~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~",
});

}

void reset(status arg) {
  if(arg) return;
  set_up_array();
}

check31(int x){
     if(room_num[nroom - 61] == "~") return BLU+room_num[nroom - 61]+NORM;
else if(room_num[nroom - 61] == "M") return HBWHT+room_num[nroom - 61]+NORM;
else if(room_num[nroom - 61] == "n") return HIW+room_num[nroom - 61]+NORM;
else if(room_num[nroom - 61] == "@") return HIC+room_num[nroom - 61]+NORM;
else if(room_num[nroom - 61] == "#") return CYN+room_num[nroom - 61]+NORM;
else if(room_num[nroom - 61] == "=") return HIW+room_num[nroom - 61]+NORM;
else return HIW+room_num[nroom - 61]+NORM;
}

check1(int x){
     if(room_num[nroom - 62] == "~") return BLU+room_num[nroom - 62]+NORM;
else if(room_num[nroom - 62] == "M") return HBWHT+room_num[nroom - 62]+NORM;
else if(room_num[nroom - 62] == "n") return HIW+room_num[nroom - 62]+NORM;
else if(room_num[nroom - 62] == "@") return HIC+room_num[nroom - 62]+NORM;
else if(room_num[nroom - 62] == "#") return CYN+room_num[nroom - 62]+NORM;
else if(room_num[nroom - 62] == "=") return HIW+room_num[nroom - 62]+NORM;
else return HIW+room_num[nroom - 62]+NORM;
}
check2(int x){
     if(room_num[nroom - 63] == "~") return BLU+room_num[nroom - 63]+NORM;
else if(room_num[nroom - 63] == "M") return HBWHT+room_num[nroom - 63]+NORM;
else if(room_num[nroom - 63] == "n") return HIW+room_num[nroom - 63]+NORM;
else if(room_num[nroom - 63] == "@") return HIC+room_num[nroom - 63]+NORM;
else if(room_num[nroom - 63] == "#") return CYN+room_num[nroom - 63]+NORM;
else if(room_num[nroom - 63] == "=") return HIW+room_num[nroom - 63]+NORM;
else return HIW+room_num[nroom - 63]+NORM;
}
check3(int x){
     if(room_num[nroom - 64] == "~") return BLU+room_num[nroom - 64]+NORM;
else if(room_num[nroom - 64] == "M") return HBWHT+room_num[nroom - 64]+NORM;
else if(room_num[nroom - 64] == "n") return HIW+room_num[nroom - 64]+NORM;
else if(room_num[nroom - 64] == "@") return HIC+room_num[nroom - 64]+NORM;
else if(room_num[nroom - 64] == "#") return CYN+room_num[nroom - 64]+NORM;
else if(room_num[nroom - 64] == "=") return HIW+room_num[nroom - 64]+NORM;
else return HIW+room_num[nroom - 64]+NORM;
}

check4(int x){
     if(room_num[nroom - 65] == "~") return BLU+room_num[nroom - 65]+NORM;
else if(room_num[nroom - 65] == "M") return HBWHT+room_num[nroom - 65]+NORM;
else if(room_num[nroom - 65] == "n") return HIW+room_num[nroom - 65]+NORM;
else if(room_num[nroom - 65] == "@") return HIC+room_num[nroom - 65]+NORM;
else if(room_num[nroom - 65] == "#") return CYN+room_num[nroom - 65]+NORM;
else if(room_num[nroom - 65] == "=") return HIW+room_num[nroom - 65]+NORM;
else return HIW+room_num[nroom - 65]+NORM;
}

check5(int x){
     if(room_num[nroom - 66] == "~") return BLU+room_num[nroom - 66]+NORM;
else if(room_num[nroom - 66] == "M") return HBWHT+room_num[nroom - 66]+NORM;
else if(room_num[nroom - 66] == "n") return HIW+room_num[nroom - 66]+NORM;
else if(room_num[nroom - 66] == "@") return HIC+room_num[nroom - 66]+NORM;
else if(room_num[nroom - 66] == "#") return CYN+room_num[nroom - 66]+NORM;
else if(room_num[nroom - 66] == "=") return HIW+room_num[nroom - 66]+NORM;
else return HIW+room_num[nroom - 66]+NORM;
}

check26(int x){
     if(room_num[nroom - 67] == "~") return BLU+room_num[nroom - 67]+NORM;
else if(room_num[nroom - 67] == "M") return HBWHT+room_num[nroom - 67]+NORM;
else if(room_num[nroom - 67] == "n") return HIW+room_num[nroom - 67]+NORM;
else if(room_num[nroom - 67] == "@") return HIC+room_num[nroom - 67]+NORM;
else if(room_num[nroom - 67] == "#") return CYN+room_num[nroom - 67]+NORM;
else if(room_num[nroom - 67] == "=") return HIW+room_num[nroom - 67]+NORM;
else return HIW+room_num[nroom - 67]+NORM;
}

check32(int x){
     if(room_num[nroom - 29] == "~") return BLU+room_num[nroom - 29]+NORM;
else if(room_num[nroom - 29] == "M") return HBWHT+room_num[nroom - 29]+NORM;
else if(room_num[nroom - 29] == "n") return HIW+room_num[nroom - 29]+NORM;
else if(room_num[nroom - 29] == "@") return HIC+room_num[nroom - 29]+NORM;
else if(room_num[nroom - 29] == "#") return CYN+room_num[nroom - 29]+NORM;
else if(room_num[nroom - 67] == "=") return HIW+room_num[nroom - 67]+NORM;
else return HIW+room_num[nroom - 29]+NORM;
}

check6(int x){
     if(room_num[nroom - 30] == "~") return BLU+room_num[nroom - 30]+NORM;
else if(room_num[nroom - 30] == "M") return HBWHT+room_num[nroom - 30]+NORM;
else if(room_num[nroom - 30] == "n") return HIW+room_num[nroom - 30]+NORM;
else if(room_num[nroom - 30] == "@") return HIC+room_num[nroom - 30]+NORM;
else if(room_num[nroom - 30] == "#") return CYN+room_num[nroom - 30]+NORM;
else if(room_num[nroom - 30] == "=") return HIW+room_num[nroom - 30]+NORM;
else return HIW+room_num[nroom - 30]+NORM;
}

check7(int x){
     if(room_num[nroom - 31] == "~") return BLU+room_num[nroom - 31]+NORM;
else if(room_num[nroom - 31] == "M") return HBWHT+room_num[nroom - 31]+NORM;
else if(room_num[nroom - 31] == "n") return HIW+room_num[nroom - 31]+NORM;
else if(room_num[nroom - 31] == "@") return HIC+room_num[nroom - 31]+NORM;
else if(room_num[nroom - 31] == "#") return CYN+room_num[nroom - 31]+NORM;
else if(room_num[nroom - 31] == "=") return HIW+room_num[nroom - 31]+NORM;
else return HIW+room_num[nroom - 31]+NORM;
}

check8(int x){
     if(room_num[nroom - 32] == "~") return BLU+room_num[nroom - 32]+NORM;
else if(room_num[nroom - 32] == "M") return HBWHT+room_num[nroom - 32]+NORM;
else if(room_num[nroom - 32] == "n") return HIW+room_num[nroom - 32]+NORM;
else if(room_num[nroom - 32] == "@") return HIC+room_num[nroom - 32]+NORM;
else if(room_num[nroom - 32] == "#") return CYN+room_num[nroom - 32]+NORM;
else if(room_num[nroom - 32] == "=") return HIW+room_num[nroom - 32]+NORM;
else return HIW+room_num[nroom - 32]+NORM;
}

check9(int x){
     if(room_num[nroom - 33] == "~") return BLU+room_num[nroom - 33]+NORM;
else if(room_num[nroom - 33] == "M") return HBWHT+room_num[nroom - 33]+NORM;
else if(room_num[nroom - 33] == "n") return HIW+room_num[nroom - 33]+NORM;
else if(room_num[nroom - 33] == "@") return HIC+room_num[nroom - 33]+NORM;
else if(room_num[nroom - 33] == "#") return CYN+room_num[nroom - 33]+NORM;
else if(room_num[nroom - 33] == "=") return HIW+room_num[nroom - 33]+NORM;
else return HIW+room_num[nroom - 33]+NORM;
}

check10(int x){
     if(room_num[nroom - 34] == "~") return BLU+room_num[nroom - 34]+NORM;
else if(room_num[nroom - 34] == "M") return HBWHT+room_num[nroom - 34]+NORM;
else if(room_num[nroom - 34] == "n") return HIW+room_num[nroom - 34]+NORM;
else if(room_num[nroom - 34] == "@") return HIC+room_num[nroom - 34]+NORM;
else if(room_num[nroom - 34] == "#") return CYN+room_num[nroom - 34]+NORM;
else if(room_num[nroom - 34] == "=") return HIW+room_num[nroom - 34]+NORM;
else return HIW+room_num[nroom - 34]+NORM;
}

check27(int x){
     if(room_num[nroom - 35] == "~") return BLU+room_num[nroom - 35]+NORM;
else if(room_num[nroom - 35] == "M") return HBWHT+room_num[nroom - 35]+NORM;
else if(room_num[nroom - 35] == "n") return HIW+room_num[nroom - 35]+NORM;
else if(room_num[nroom - 35] == "@") return HIC+room_num[nroom - 35]+NORM;
else if(room_num[nroom - 35] == "#") return CYN+room_num[nroom - 35]+NORM;
else if(room_num[nroom - 35] == "=") return HIW+room_num[nroom - 35]+NORM;
else return HIW+room_num[nroom - 35]+NORM;
}

check11(int x){
     if(room_num[nroom - 2] == "~") return BLU+room_num[nroom - 2]+NORM;
else if(room_num[nroom - 2] == "M") return HBWHT+room_num[nroom - 2]+NORM;
else if(room_num[nroom - 2] == "n") return HIW+room_num[nroom - 2]+NORM;
else if(room_num[nroom - 2] == "@") return HIC+room_num[nroom - 2]+NORM;
else if(room_num[nroom - 2] == "#") return CYN+room_num[nroom - 2]+NORM;
else if(room_num[nroom - 2] == "=") return HIW+room_num[nroom - 2]+NORM;
else return HIW+room_num[nroom - 2]+NORM;
}

check28(int x){
     if(room_num[nroom - 3] == "~") return BLU+room_num[nroom - 3]+NORM;
else if(room_num[nroom - 3] == "M") return HBWHT+room_num[nroom - 3]+NORM;
else if(room_num[nroom - 3] == "n") return HIW+room_num[nroom - 3]+NORM;
else if(room_num[nroom - 3] == "@") return HIC+room_num[nroom - 3]+NORM;
else if(room_num[nroom - 3] == "#") return CYN+room_num[nroom - 3]+NORM;
else if(room_num[nroom - 3] == "=") return HIW+room_num[nroom - 3]+NORM;
else return HIW+room_num[nroom - 3]+NORM;
}

check12(int x){
     if(room_num[nroom - 1] == "~") return BLU+room_num[nroom - 1]+NORM;
else if(room_num[nroom - 1] == "M") return HBWHT+room_num[nroom - 1]+NORM;
else if(room_num[nroom - 1] == "n") return HIW+room_num[nroom - 1]+NORM;
else if(room_num[nroom - 1] == "@") return HIC+room_num[nroom - 1]+NORM;
else if(room_num[nroom - 1] == "#") return CYN+room_num[nroom - 1]+NORM;
else if(room_num[nroom - 1] == "=") return HIW+room_num[nroom - 1]+NORM;
else return HIW+room_num[nroom - 1]+NORM;
}

check14(int x){
     if(room_num[nroom + 1] == "~") return BLU+room_num[nroom + 1]+NORM;
else if(room_num[nroom + 1] == "M") return HBWHT+room_num[nroom + 1]+NORM;
else if(room_num[nroom + 1] == "n") return HIW+room_num[nroom + 1]+NORM;
else if(room_num[nroom + 1] == "@") return HIC+room_num[nroom + 1]+NORM;
else if(room_num[nroom + 1] == "#") return CYN+room_num[nroom + 1]+NORM;
else if(room_num[nroom + 1] == "=") return HIW+room_num[nroom + 1]+NORM;
else return HIW+room_num[nroom + 1]+NORM;
}

check33(int x){
     if(room_num[nroom + 3] == "~") return BLU+room_num[nroom + 3]+NORM;
else if(room_num[nroom + 3] == "M") return HBWHT+room_num[nroom + 3]+NORM;
else if(room_num[nroom + 3] == "n") return HIW+room_num[nroom + 3]+NORM;
else if(room_num[nroom + 3] == "@") return HIC+room_num[nroom + 3]+NORM;
else if(room_num[nroom + 3] == "#") return CYN+room_num[nroom + 3]+NORM;
else if(room_num[nroom + 1] == "=") return HIW+room_num[nroom + 1]+NORM;
else return HIW+room_num[nroom + 3]+NORM;
}

check15(int x){
     if(room_num[nroom + 2] == "~") return BLU+room_num[nroom + 2]+NORM;
else if(room_num[nroom + 2] == "M") return HBWHT+room_num[nroom + 2]+NORM;
else if(room_num[nroom + 2] == "n") return HIW+room_num[nroom + 2]+NORM;
else if(room_num[nroom + 2] == "@") return HIC+room_num[nroom + 2]+NORM;
else if(room_num[nroom + 2] == "#") return CYN+room_num[nroom + 2]+NORM;
else if(room_num[nroom + 2] == "=") return HIW+room_num[nroom + 2]+NORM;
else return HIW+room_num[nroom + 2]+NORM;
}

check16(int x){
     if(room_num[nroom + 30] == "~") return BLU+room_num[nroom + 30]+NORM;
else if(room_num[nroom + 30] == "M") return HBWHT+room_num[nroom + 30]+NORM;
else if(room_num[nroom + 30] == "n") return HIW+room_num[nroom + 30]+NORM;
else if(room_num[nroom + 30] == "@") return HIC+room_num[nroom + 30]+NORM;
else if(room_num[nroom + 30] == "#") return CYN+room_num[nroom + 30]+NORM;
else if(room_num[nroom + 30] == "=") return HIW+room_num[nroom + 30]+NORM;
else return HIW+room_num[nroom + 30]+NORM;
}

check29(int x){
     if(room_num[nroom + 29] == "~") return BLU+room_num[nroom + 29]+NORM;
else if(room_num[nroom + 29] == "M") return HBWHT+room_num[nroom + 29]+NORM;
else if(room_num[nroom + 29] == "n") return HIW+room_num[nroom + 29]+NORM;
else if(room_num[nroom + 29] == "@") return HIC+room_num[nroom + 29]+NORM;
else if(room_num[nroom + 29] == "#") return CYN+room_num[nroom + 29]+NORM;
else if(room_num[nroom + 29] == "=") return HIW+room_num[nroom + 29]+NORM;
else return HIW+room_num[nroom + 29]+NORM;
}

check17(int x){
     if(room_num[nroom + 31] == "~") return BLU+room_num[nroom + 31]+NORM;
else if(room_num[nroom + 31] == "M") return HBWHT+room_num[nroom + 31]+NORM;
else if(room_num[nroom + 31] == "n") return HIW+room_num[nroom + 31]+NORM;
else if(room_num[nroom + 31] == "@") return HIC+room_num[nroom + 31]+NORM;
else if(room_num[nroom + 31] == "#") return CYN+room_num[nroom + 31]+NORM;
else if(room_num[nroom + 31] == "=") return HIW+room_num[nroom + 31]+NORM;
else return HIW+room_num[nroom + 31]+NORM;
}

check18(int x){
     if(room_num[nroom + 32] == "~") return BLU+room_num[nroom + 32]+NORM;
else if(room_num[nroom + 32] == "M") return HBWHT+room_num[nroom + 32]+NORM;
else if(room_num[nroom + 32] == "n") return HIW+room_num[nroom + 32]+NORM;
else if(room_num[nroom + 32] == "@") return HIC+room_num[nroom + 32]+NORM;
else if(room_num[nroom + 32] == "#") return CYN+room_num[nroom + 32]+NORM;
else if(room_num[nroom + 32] == "=") return HIW+room_num[nroom + 32]+NORM;
else return HIW+room_num[nroom + 32]+NORM;
}

check19(int x){
     if(room_num[nroom + 33] == "~") return BLU+room_num[nroom + 33]+NORM;
else if(room_num[nroom + 33] == "M") return HBWHT+room_num[nroom + 33]+NORM;
else if(room_num[nroom + 33] == "n") return HIW+room_num[nroom + 33]+NORM;
else if(room_num[nroom + 33] == "@") return HIC+room_num[nroom + 33]+NORM;
else if(room_num[nroom + 33] == "#") return CYN+room_num[nroom + 33]+NORM;
else if(room_num[nroom + 33] == "=") return HIW+room_num[nroom + 33]+NORM;
else return HIW+room_num[nroom + 33]+NORM;
}

check34(int x){
     if(room_num[nroom + 35] == "~") return BLU+room_num[nroom + 35]+NORM;
else if(room_num[nroom + 35] == "M") return HBWHT+room_num[nroom + 35]+NORM;
else if(room_num[nroom + 35] == "n") return HIW+room_num[nroom + 35]+NORM;
else if(room_num[nroom + 35] == "@") return HIC+room_num[nroom + 35]+NORM;
else if(room_num[nroom + 35] == "#") return CYN+room_num[nroom + 35]+NORM;
else if(room_num[nroom + 35] == "=") return HIW+room_num[nroom + 35]+NORM;
else return HIW+room_num[nroom + 35]+NORM;
}

check20(int x){
     if(room_num[nroom + 34] == "~") return BLU+room_num[nroom + 34]+NORM;
else if(room_num[nroom + 34] == "M") return HBWHT+room_num[nroom + 34]+NORM;
else if(room_num[nroom + 34] == "n") return HIW+room_num[nroom + 34]+NORM;
else if(room_num[nroom + 34] == "@") return HIC+room_num[nroom + 34]+NORM;
else if(room_num[nroom + 34] == "#") return CYN+room_num[nroom + 34]+NORM;
else if(room_num[nroom + 34] == "=") return HIW+room_num[nroom + 34]+NORM;
else return HIW+room_num[nroom + 34]+NORM;
}

check21(int x){
     if(room_num[nroom + 62] == "~") return BLU+room_num[nroom + 62]+NORM;
else if(room_num[nroom + 62] == "M") return HBWHT+room_num[nroom + 62]+NORM;
else if(room_num[nroom + 62] == "n") return HIW+room_num[nroom + 62]+NORM;
else if(room_num[nroom + 62] == "@") return HIC+room_num[nroom + 62]+NORM;
else if(room_num[nroom + 62] == "#") return CYN+room_num[nroom + 62]+NORM;
else if(room_num[nroom + 62] == "=") return HIW+room_num[nroom + 62]+NORM;
else return HIW+room_num[nroom + 62]+NORM;
}

check30(int x){
     if(room_num[nroom + 61] == "~") return BLU+room_num[nroom + 61]+NORM;
else if(room_num[nroom + 61] == "M") return HBWHT+room_num[nroom + 61]+NORM;
else if(room_num[nroom + 61] == "n") return HIW+room_num[nroom + 61]+NORM;
else if(room_num[nroom + 61] == "@") return HIC+room_num[nroom + 61]+NORM;
else if(room_num[nroom + 61] == "#") return CYN+room_num[nroom + 61]+NORM;
else if(room_num[nroom + 61] == "=") return HIW+room_num[nroom + 61]+NORM;
else return HIW+room_num[nroom + 61]+NORM;
}

check22(int x){
     if(room_num[nroom + 63] == "~") return BLU+room_num[nroom + 63]+NORM;
else if(room_num[nroom + 63] == "M") return HBWHT+room_num[nroom + 63]+NORM;
else if(room_num[nroom + 63] == "n") return HIW+room_num[nroom + 63]+NORM;
else if(room_num[nroom + 63] == "@") return HIC+room_num[nroom + 63]+NORM;
else if(room_num[nroom + 63] == "#") return CYN+room_num[nroom + 63]+NORM;
else if(room_num[nroom + 63] == "=") return HIW+room_num[nroom + 63]+NORM;
else return HIW+room_num[nroom + 63]+NORM;
}

check23(int x){
     if(room_num[nroom + 64] == "~") return BLU+room_num[nroom + 64]+NORM;
else if(room_num[nroom + 64] == "M") return HBWHT+room_num[nroom + 64]+NORM;
else if(room_num[nroom + 64] == "n") return HIW+room_num[nroom + 64]+NORM;
else if(room_num[nroom + 64] == "@") return HIC+room_num[nroom + 64]+NORM;
else if(room_num[nroom + 64] == "#") return CYN+room_num[nroom + 64]+NORM;
else if(room_num[nroom + 64] == "=") return HIW+room_num[nroom + 64]+NORM;
else return HIW+room_num[nroom + 64]+NORM;
}

check24(int x){
     if(room_num[nroom + 65] == "~") return BLU+room_num[nroom + 65]+NORM;
else if(room_num[nroom + 65] == "M") return HBWHT+room_num[nroom + 65]+NORM;
else if(room_num[nroom + 65] == "n") return HIW+room_num[nroom + 65]+NORM;
else if(room_num[nroom + 65] == "@") return HIC+room_num[nroom + 65]+NORM;
else if(room_num[nroom + 65] == "#") return CYN+room_num[nroom + 65]+NORM;
else if(room_num[nroom + 65] == "=") return HIW+room_num[nroom + 65]+NORM;
else return HIW+room_num[nroom + 65]+NORM;
}

check35(int x){
     if(room_num[nroom + 67] == "~") return BLU+room_num[nroom + 67]+NORM;
else if(room_num[nroom + 67] == "M") return HBWHT+room_num[nroom + 67]+NORM;
else if(room_num[nroom + 67] == "n") return HIW+room_num[nroom + 67]+NORM;
else if(room_num[nroom + 67] == "@") return HIC+room_num[nroom + 67]+NORM;
else if(room_num[nroom + 67] == "#") return CYN+room_num[nroom + 67]+NORM;
else if(room_num[nroom + 67] == "=") return HIW+room_num[nroom + 67]+NORM;
else return HIW+room_num[nroom + 67]+NORM;
}

check25(int x){
     if(room_num[nroom + 66] == "~") return BLU+room_num[nroom + 66]+NORM;
else if(room_num[nroom + 66] == "M") return HBWHT+room_num[nroom + 66]+NORM;
else if(room_num[nroom + 66] == "n") return HIW+room_num[nroom + 66]+NORM;
else if(room_num[nroom + 66] == "@") return HIC+room_num[nroom + 66]+NORM;
else if(room_num[nroom + 66] == "#") return CYN+room_num[nroom + 66]+NORM;
else if(room_num[nroom + 66] == "=") return HIW+room_num[nroom + 66]+NORM;
else return HIW+room_num[nroom + 66]+NORM;
}




make_it(str){
string sline;
string line1;
string line2;
string line3;
string line4;
string item1;
string item11;
string item2;
string item22;
string item3;
string item33;
string item4;
string item44;

sscanf(str,"%d", nroom);

if(!nroom){
write("duh.\n");
return 1;
}

if(room_num[nroom] == "~" || room_num[nroom] == "M"){
  write("Blocked room. "+nroom+"\n");
  return 1;
}

/* Create the short desc */
if(room_num[nroom] == "#"){
rtype = "glacier";
sline = "a large glacier";
}
else if(room_num[nroom] == "@"){
rtype = "ice sheet";
sline = "an ice sheet";
}
else if(room_num[nroom] == "n"){
rtype = "icy hill";
sline = "ice hill";
}
else if(room_num[nroom] == "-"){
rtype = "icy road";
sline = "an icy road";
}
else if(room_num[nroom] == "+"){
rtype = "icy road";
sline = "a bend in the icy road";
}
else if(room_num[nroom] == "|"){
rtype = "icy road";
sline = "an icy road";
}
else if(room_num[nroom] == "="){
rtype = "a frozen bridge";
sline = "a frozen bridge";
}
/*******************************/




write_file("/players/vertebraker/cont/frostgard/"+nroom+".c",
"#include <ansi.h>\n\n"+
"#define RNUM "+nroom+"\n"+
"inherit \"players/vertebraker/cont/inherit/fgard_room\";\n\n\n"+
"string rtype;\n\n"+
"reset(arg){\n"+
"  ::reset(arg);\n"+
"  if(arg) return;\n\n");

write_file("/players/vertebraker/cont/frostgard/"+nroom+".c",
"short_desc = \""+sline+"\";\n"+
"set_light(1);\n"+
"rtype = \""+rtype+"\";\n");

write_file("/players/vertebraker/cont/frostgard/"+nroom+".c",
"long_desc = \n"+
"\"                "+check26(nroom)+" "+check5(nroom)+" "+check4(nroom)+" "+check3(nroom)+" "+check2(nroom)+" "+check1(nroom)+" "+check31(nroom)+" \\n\"+\n"+
"\"                "+check27(nroom)+" "+check10(nroom)+" "+check9(nroom)+" "+check8(nroom)+" "+check7(nroom)+" "+check6(nroom)+" "+check32(nroom)+"    N\\n\"+\n"+
"\"                "+check28(nroom)+" "+check11(nroom)+" "+check12(nroom)+" "+HIW+"X"+NORM+" "+check14(nroom)+" "+check15(nroom)+" "+check33(nroom)+"   /|\\n\"+\n"+
"\"                "+check29(nroom)+" "+check16(nroom)+" "+check17(nroom)+" "+check18(nroom)+" "+check19(nroom)+" "+check20(nroom)+" "+check34(nroom)+"    | \\n\"+\n"+
"\"                "+check30(nroom)+" "+check21(nroom)+" "+check22(nroom)+" "+check23(nroom)+" "+check24(nroom)+" "+check25(nroom)+" "+check35(nroom)+"    | \\n\";\n");
/***  Setup exits ***/
write_file("/players/vertebraker/cont/frostgard/"+nroom+".c",
"dest_dir = ({\n");

if(room_num[nroom - 32] != "~" && room_num[nroom - 32] != "M"){
write_file("/players/vertebraker/cont/frostgard/"+nroom+".c",
"\"/players/vertebraker/cont/frostgard/"+(nroom-32)+".c\",\"north\",\n");
}
if(room_num[nroom - 31] != "~" && room_num[nroom - 31] != "M"){
write_file("/players/vertebraker/cont/frostgard/"+nroom+".c",
"\"/players/vertebraker/cont/frostgard/"+(nroom-31)+".c\",\"northeast\",\n");
}
if(room_num[nroom - 33] != "~" && room_num[nroom - 33] != "M"){
write_file("/players/vertebraker/cont/frostgard/"+nroom+".c",
"\"/players/vertebraker/cont/frostgard/"+(nroom-33)+".c\",\"northwest\",\n");
}

if(room_num[nroom + 32] != "~" && room_num[nroom + 32] != "M"){
write_file("/players/vertebraker/cont/frostgard/"+nroom+".c",
"\"/players/vertebraker/cont/frostgard/"+(nroom+32)+".c\",\"south\",\n");
}
if(room_num[nroom + 33] != "~" && room_num[nroom + 33] != "M"){
write_file("/players/vertebraker/cont/frostgard/"+nroom+".c",
"\"/players/vertebraker/cont/frostgard/"+(nroom+33)+".c\",\"southeast\",\n");
}
if(room_num[nroom + 31] != "~" && room_num[nroom + 31] != "M"){
write_file("/players/vertebraker/cont/frostgard/"+nroom+".c",
"\"/players/vertebraker/cont/frostgard/"+(nroom+31)+".c\",\"southwest\",\n");
}
if(room_num[nroom + 1] != "~" && room_num[nroom + 1] != "M"){
write_file("/players/vertebraker/cont/frostgard/"+nroom+".c",
"\"/players/vertebraker/cont/frostgard/"+(nroom+1)+".c\",\"east\",\n");
}
if(room_num[nroom - 1] != "~" && room_num[nroom - 1] != "M"){
write_file("/players/vertebraker/cont/frostgard/"+nroom+".c",
"\"/players/vertebraker/cont/frostgard/"+(nroom-1)+".c\",\"west\",\n");
}
write_file("/players/vertebraker/cont/frostgard/"+nroom+".c",
"});\n");

write_file("/players/vertebraker/cont/frostgard/"+nroom+".c",
"}\n\n");


write_file("/players/vertebraker/cont/frostgard/"+nroom+".c",
       "status is_cont_frostgard(){ return 1; }\n"+
           "string query_room_type(){ return rtype; }\n"+
           "int query_room_num(){ return RNUM; }\n");


write("done "+nroom+"\n");
return 1;
}



