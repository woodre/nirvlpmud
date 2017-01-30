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

id(str) { return str == "rtool"; }

query_weight(){ return 0; }
query_value(){ return 0; }

short(){return "a room tool"; }
long(){
	write("'make'\n");
	return 1;}

reset(arg){
if(arg) return;

}

init(){
if(!environment()) return;
if(environment()->query_level() < 20){
destruct(this_object());
}
add_action("make_it", "make");
add_action("what_room","rtype");
add_action("set_up_array", "setarray");
}

what_room(int x){

sscanf(x, "%d", newx);
	write(""+room_num[newx]+"\n");
	return 1;
}

set_up_array(){
room_num = allocate(999);
room_num = ({ "X",
"~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~",
"~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~",
"~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~",
"~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~",
"~","~","~","~","~","~","#","~","~","~","~","~","#","#","~","#",
"#","~","~","~","~","~","#","#","~","~","#","#","~","~","~","~",
"~","#","#","#","#","#","#","~","~","~","#","#","#","#","#","#",
"#","#","#","+","-","-","-","-","-","-","-","#","#","~","~","~",
"~","#","#","#","#","#","#","~","~","~","#","#","#","#","|","#",
"#","#","#","|","#","#","~","~","~","~","#","#","#","~","~","~",
"~","~","#","#","#","#","#","~","~","~","~","~","#","#","|","#",
"#","#","#","|","#","#","#","#","~","~","~","#","#","~","~","~",
"~","~","#","#","#","#","~","~","~","~","~","#","-","-","+","-",
"-","-","-","+","#","#","#","~","#","~","~","~","~","~","~","~",
"~","~","#","#","#","~","#","#","~","~","#","#","#","#","|","#",
"#","#","#","#","#","#","~","#","#","~","~","~","~","~","~","~",
"~","~","~","#","#","#","#","~","~","~","#","#","#","#","|","#",
"#","~","~","#","#","~","#","|","#","#","#","~","~","~","~","~",
"~","~","#","#","|","#","#","~","~","~","#","#","#","#","|","#",
"~","~","~","~","~","#","#","+","-","-","#","#","~","~","~","~",
"~","~","#","#","|","#","~","~","~","~","#","#","#","#","|","#",
"#","~","~","~","#","#","#","|","#","#","#","#","~","~","~","~",
"~","~","~","#","|","#","~","~","~","~","~","~","#","#","+","-",
"-","-","-","+","-","-","-","+","#","~","~","~","~","~","~","~",
"~","~","~","#","+","-","-","-","+","#","#","~","#","#","#","#",
"#","#","#","|","#","#","#","~","~","#","#","#","~","~","~","~",
"~","#","~","~","~","~","~","~","|","#","#","#","~","#","#","#",
"#","#","#","|","#","#","~","#","#","#","#","#","~","~","~","~",
"~","#","#","#","~","#","#","#","|","#","#","#","#","|","#","#",
"#","#","#","|","#","~","#","#","+","-","-","#","~","~","~","~",
"~","~","#","#","|","#","#","#","+","-","-","-","-","+","-","-",
"-","#","#","+","-","+","#","#","|","#","#","~","~","~","~","~",
"~","~","#","#","|","#","#","#","|","#","#","#","#","|","#","#",
"#","#","#","#","#","|","#","#","|","#","#","#","~","~","~","~",
"~","#","#","#","|","#","#","#","|","#","#","#","#","|","~","~",
"#","#","#","#","#","|","#","#","|","#","#","#","#","~","~","~",
"~","#","-","-","+","-","-","-","+","-","+","#","#","|","~","~",
"~","#","-","-","-","+","-","-","+","-","-","-","-","~","~","~",
"~","#","#","#","#","#","#","#","|","#","|","#","#","|","#","~",
"#","#","#","#","#","|","#","#","#","#","#","#","~","~","~","~",
"~","#","#","#","#","|","#","#","|","#","#","#","#","|","#","#",
"#","+","-","-","-","+","-","+","#","#","#","#","#","~","~","~",
"~","~","#","#","#","+","-","-","+","#","#","-","-","+","-","+",
"#","|","#","#","#","#","#","|","#","#","#","~","~","~","~","~",
"~","~","~","~","~","#","#","#","|","#","#","#","#","|","#","|",
"#","|","#","#","~","#","#","|","#","#","~","#","#","~","~","~",
"~","#","#","#","#","#","#","#","#","#","#","#","#","|","#","+",
"-","+","#","~","#","#","#","|","#","~","#","#","~","~","~","~",
"#","+","-","-","-","+","-","#","#","#","#","#","#","#","#","|",
"#","#","~","#","#","-","-","+","-","+","#","~","~","~","~","~",
"#","|","#","#","#","|","#","#","#","#","#","#","#","#","#","|",
"#","#","~","#","#","#","#","#","#","|","#","~","~","~","~","~",
"-","+","#","#","-","+","-","-","-","-","-","-","-","+","-","+",
"#","~","~","~","#","#","~","~","~","#","#","~","~","~","~","~",
"~","#","#","#","#","#","#","#","#","#","#","#","#","|","#","#",
"~","~","#","~","#","~","~","~","#","#","#","#","~","~","~","~",
"~","#","#","#","#","#","~","#","#","#","#","~","#","#","#","~",
"~","#","#","~","~","~","#","#","#","#","~","~","~","~","~","~",
"~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~",
"~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~",
"~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~",
"~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~",
});
return 1; } 

check31(int x){ 
     if(room_num[nroom - 61] == "~") return BLU+room_num[nroom - 61]+NORM; 
else if(room_num[nroom - 61] == "M") return BOLD+room_num[nroom - 61]+NORM; 
else if(room_num[nroom - 61] == "n") return YEL+room_num[nroom - 61]+NORM; 
else if(room_num[nroom - 61] == "@") return HIG+room_num[nroom - 61]+NORM; 
else if(room_num[nroom - 61] == "#") return YEL+room_num[nroom - 61]+NORM; 
else return HIW+room_num[nroom - 61]+NORM;
}

check1(int x){
     if(room_num[nroom - 62] == "~") return BLU+room_num[nroom - 62]+NORM; 
else if(room_num[nroom - 62] == "M") return BOLD+room_num[nroom - 62]+NORM; 
else if(room_num[nroom - 62] == "n") return YEL+room_num[nroom - 62]+NORM; 
else if(room_num[nroom - 62] == "@") return HIG+room_num[nroom - 62]+NORM; 
else if(room_num[nroom - 62] == "#") return YEL+room_num[nroom - 62]+NORM; 
else return HIW+room_num[nroom - 62]+NORM;
}
check2(int x){
     if(room_num[nroom - 63] == "~") return BLU+room_num[nroom - 63]+NORM; 
else if(room_num[nroom - 63] == "M") return BOLD+room_num[nroom - 63]+NORM; 
else if(room_num[nroom - 63] == "n") return YEL+room_num[nroom - 63]+NORM; 
else if(room_num[nroom - 63] == "@") return HIG+room_num[nroom - 63]+NORM; 
else if(room_num[nroom - 63] == "#") return YEL+room_num[nroom - 63]+NORM; 
else return HIW+room_num[nroom - 63]+NORM;
}
check3(int x){
     if(room_num[nroom - 64] == "~") return BLU+room_num[nroom - 64]+NORM; 
else if(room_num[nroom - 64] == "M") return BOLD+room_num[nroom - 64]+NORM; 
else if(room_num[nroom - 64] == "n") return YEL+room_num[nroom - 64]+NORM; 
else if(room_num[nroom - 64] == "@") return HIG+room_num[nroom - 64]+NORM; 
else if(room_num[nroom - 64] == "#") return YEL+room_num[nroom - 64]+NORM; 
else return HIW+room_num[nroom - 64]+NORM;
}

check4(int x){
     if(room_num[nroom - 65] == "~") return BLU+room_num[nroom - 65]+NORM; 
else if(room_num[nroom - 65] == "M") return BOLD+room_num[nroom - 65]+NORM; 
else if(room_num[nroom - 65] == "n") return YEL+room_num[nroom - 65]+NORM; 
else if(room_num[nroom - 65] == "@") return HIG+room_num[nroom - 65]+NORM; 
else if(room_num[nroom - 65] == "#") return YEL+room_num[nroom - 65]+NORM; 
else return HIW+room_num[nroom - 65]+NORM;
}

check5(int x){ 
     if(room_num[nroom - 66] == "~") return BLU+room_num[nroom - 66]+NORM; 
else if(room_num[nroom - 66] == "M") return BOLD+room_num[nroom - 66]+NORM; 
else if(room_num[nroom - 66] == "n") return YEL+room_num[nroom - 66]+NORM; 
else if(room_num[nroom - 66] == "@") return HIG+room_num[nroom - 66]+NORM; 
else if(room_num[nroom - 66] == "#") return YEL+room_num[nroom - 66]+NORM; 
else return HIW+room_num[nroom - 66]+NORM;
}

check26(int x){ 
     if(room_num[nroom - 67] == "~") return BLU+room_num[nroom - 67]+NORM; 
else if(room_num[nroom - 67] == "M") return BOLD+room_num[nroom - 67]+NORM; 
else if(room_num[nroom - 67] == "n") return YEL+room_num[nroom - 67]+NORM; 
else if(room_num[nroom - 67] == "@") return HIG+room_num[nroom - 67]+NORM; 
else if(room_num[nroom - 67] == "#") return YEL+room_num[nroom - 67]+NORM; 
else return HIW+room_num[nroom - 67]+NORM;
}

check32(int x){ 
     if(room_num[nroom - 29] == "~") return BLU+room_num[nroom - 29]+NORM; 
else if(room_num[nroom - 29] == "M") return BOLD+room_num[nroom - 29]+NORM; 
else if(room_num[nroom - 29] == "n") return YEL+room_num[nroom - 29]+NORM; 
else if(room_num[nroom - 29] == "@") return HIG+room_num[nroom - 29]+NORM; 
else if(room_num[nroom - 29] == "#") return YEL+room_num[nroom - 29]+NORM; 
else return HIW+room_num[nroom - 29]+NORM;
}

check6(int x){ 
     if(room_num[nroom - 30] == "~") return BLU+room_num[nroom - 30]+NORM; 
else if(room_num[nroom - 30] == "M") return BOLD+room_num[nroom - 30]+NORM; 
else if(room_num[nroom - 30] == "n") return YEL+room_num[nroom - 30]+NORM; 
else if(room_num[nroom - 30] == "@") return HIG+room_num[nroom - 30]+NORM; 
else if(room_num[nroom - 30] == "#") return YEL+room_num[nroom - 30]+NORM; 
else return HIW+room_num[nroom - 30]+NORM;
}

check7(int x){ 
     if(room_num[nroom - 31] == "~") return BLU+room_num[nroom - 31]+NORM; 
else if(room_num[nroom - 31] == "M") return BOLD+room_num[nroom - 31]+NORM; 
else if(room_num[nroom - 31] == "n") return YEL+room_num[nroom - 31]+NORM; 
else if(room_num[nroom - 31] == "@") return HIG+room_num[nroom - 31]+NORM; 
else if(room_num[nroom - 31] == "#") return YEL+room_num[nroom - 31]+NORM; 
else return HIW+room_num[nroom - 31]+NORM;
}

check8(int x){ 
     if(room_num[nroom - 32] == "~") return BLU+room_num[nroom - 32]+NORM; 
else if(room_num[nroom - 32] == "M") return BOLD+room_num[nroom - 32]+NORM; 
else if(room_num[nroom - 32] == "n") return YEL+room_num[nroom - 32]+NORM; 
else if(room_num[nroom - 32] == "@") return HIG+room_num[nroom - 32]+NORM; 
else if(room_num[nroom - 32] == "#") return YEL+room_num[nroom - 32]+NORM; 
else return HIW+room_num[nroom - 32]+NORM;
}

check9(int x){ 
     if(room_num[nroom - 33] == "~") return BLU+room_num[nroom - 33]+NORM; 
else if(room_num[nroom - 33] == "M") return BOLD+room_num[nroom - 33]+NORM; 
else if(room_num[nroom - 33] == "n") return YEL+room_num[nroom - 33]+NORM; 
else if(room_num[nroom - 33] == "@") return HIG+room_num[nroom - 33]+NORM; 
else if(room_num[nroom - 33] == "#") return YEL+room_num[nroom - 33]+NORM; 
else return HIW+room_num[nroom - 33]+NORM;
}

check10(int x){  
     if(room_num[nroom - 34] == "~") return BLU+room_num[nroom - 34]+NORM; 
else if(room_num[nroom - 34] == "M") return BOLD+room_num[nroom - 34]+NORM; 
else if(room_num[nroom - 34] == "n") return YEL+room_num[nroom - 34]+NORM; 
else if(room_num[nroom - 34] == "@") return HIG+room_num[nroom - 34]+NORM; 
else if(room_num[nroom - 34] == "#") return YEL+room_num[nroom - 34]+NORM; 
else return HIW+room_num[nroom - 34]+NORM;
}

check27(int x){ 
     if(room_num[nroom - 35] == "~") return BLU+room_num[nroom - 35]+NORM; 
else if(room_num[nroom - 35] == "M") return BOLD+room_num[nroom - 35]+NORM; 
else if(room_num[nroom - 35] == "n") return YEL+room_num[nroom - 35]+NORM; 
else if(room_num[nroom - 35] == "@") return HIG+room_num[nroom - 35]+NORM; 
else if(room_num[nroom - 35] == "#") return YEL+room_num[nroom - 35]+NORM; 
else return HIW+room_num[nroom - 35]+NORM;
}

check11(int x){  
     if(room_num[nroom - 2] == "~") return BLU+room_num[nroom - 2]+NORM; 
else if(room_num[nroom - 2] == "M") return BOLD+room_num[nroom - 2]+NORM; 
else if(room_num[nroom - 2] == "n") return YEL+room_num[nroom - 2]+NORM; 
else if(room_num[nroom - 2] == "@") return HIG+room_num[nroom - 2]+NORM; 
else if(room_num[nroom - 2] == "#") return YEL+room_num[nroom - 2]+NORM; 
else return HIW+room_num[nroom - 2]+NORM;
}

check28(int x){ 
     if(room_num[nroom - 3] == "~") return BLU+room_num[nroom - 3]+NORM; 
else if(room_num[nroom - 3] == "M") return BOLD+room_num[nroom - 3]+NORM; 
else if(room_num[nroom - 3] == "n") return YEL+room_num[nroom - 3]+NORM; 
else if(room_num[nroom - 3] == "@") return HIG+room_num[nroom - 3]+NORM; 
else if(room_num[nroom - 3] == "#") return YEL+room_num[nroom - 3]+NORM; 
else return HIW+room_num[nroom - 3]+NORM;
}

check12(int x){ 
     if(room_num[nroom - 1] == "~") return BLU+room_num[nroom - 1]+NORM; 
else if(room_num[nroom - 1] == "M") return BOLD+room_num[nroom - 1]+NORM; 
else if(room_num[nroom - 1] == "n") return YEL+room_num[nroom - 1]+NORM; 
else if(room_num[nroom - 1] == "@") return HIG+room_num[nroom - 1]+NORM; 
else if(room_num[nroom - 1] == "#") return YEL+room_num[nroom - 1]+NORM; 
else return HIW+room_num[nroom - 1]+NORM;
}
 
check14(int x){  
     if(room_num[nroom + 1] == "~") return BLU+room_num[nroom + 1]+NORM; 
else if(room_num[nroom + 1] == "M") return BOLD+room_num[nroom + 1]+NORM; 
else if(room_num[nroom + 1] == "n") return YEL+room_num[nroom + 1]+NORM; 
else if(room_num[nroom + 1] == "@") return HIG+room_num[nroom + 1]+NORM; 
else if(room_num[nroom + 1] == "#") return YEL+room_num[nroom + 1]+NORM; 
else return HIW+room_num[nroom + 1]+NORM;
}

check33(int x){ 
     if(room_num[nroom + 3] == "~") return BLU+room_num[nroom + 3]+NORM; 
else if(room_num[nroom + 3] == "M") return BOLD+room_num[nroom + 3]+NORM; 
else if(room_num[nroom + 3] == "n") return YEL+room_num[nroom + 3]+NORM; 
else if(room_num[nroom + 3] == "@") return HIG+room_num[nroom + 3]+NORM; 
else if(room_num[nroom + 3] == "#") return YEL+room_num[nroom + 3]+NORM; 
else return HIW+room_num[nroom + 3]+NORM;
}

check15(int x){
     if(room_num[nroom + 2] == "~") return BLU+room_num[nroom + 2]+NORM; 
else if(room_num[nroom + 2] == "M") return BOLD+room_num[nroom + 2]+NORM; 
else if(room_num[nroom + 2] == "n") return YEL+room_num[nroom + 2]+NORM; 
else if(room_num[nroom + 2] == "@") return HIG+room_num[nroom + 2]+NORM; 
else if(room_num[nroom + 2] == "#") return YEL+room_num[nroom + 2]+NORM; 
else return HIW+room_num[nroom + 2]+NORM;
} 

check16(int x){
     if(room_num[nroom + 30] == "~") return BLU+room_num[nroom + 30]+NORM; 
else if(room_num[nroom + 30] == "M") return BOLD+room_num[nroom + 30]+NORM; 
else if(room_num[nroom + 30] == "n") return YEL+room_num[nroom + 30]+NORM; 
else if(room_num[nroom + 30] == "@") return HIG+room_num[nroom + 30]+NORM; 
else if(room_num[nroom + 30] == "#") return YEL+room_num[nroom + 30]+NORM; 
else return HIW+room_num[nroom + 30]+NORM;
}

check29(int x){ 
     if(room_num[nroom + 29] == "~") return BLU+room_num[nroom + 29]+NORM; 
else if(room_num[nroom + 29] == "M") return BOLD+room_num[nroom + 29]+NORM; 
else if(room_num[nroom + 29] == "n") return YEL+room_num[nroom + 29]+NORM; 
else if(room_num[nroom + 29] == "@") return HIG+room_num[nroom + 29]+NORM; 
else if(room_num[nroom + 29] == "#") return YEL+room_num[nroom + 29]+NORM; 
else return HIW+room_num[nroom + 29]+NORM;
}

check17(int x){
     if(room_num[nroom + 31] == "~") return BLU+room_num[nroom + 31]+NORM; 
else if(room_num[nroom + 31] == "M") return BOLD+room_num[nroom + 31]+NORM; 
else if(room_num[nroom + 31] == "n") return YEL+room_num[nroom + 31]+NORM; 
else if(room_num[nroom + 31] == "@") return HIG+room_num[nroom + 31]+NORM; 
else if(room_num[nroom + 31] == "#") return YEL+room_num[nroom + 31]+NORM; 
else return HIW+room_num[nroom + 31]+NORM;
}
 
check18(int x){ 
     if(room_num[nroom + 32] == "~") return BLU+room_num[nroom + 32]+NORM; 
else if(room_num[nroom + 32] == "M") return BOLD+room_num[nroom + 32]+NORM; 
else if(room_num[nroom + 32] == "n") return YEL+room_num[nroom + 32]+NORM; 
else if(room_num[nroom + 32] == "@") return HIG+room_num[nroom + 32]+NORM; 
else if(room_num[nroom + 32] == "#") return YEL+room_num[nroom + 32]+NORM; 
else return HIW+room_num[nroom + 32]+NORM;
}

check19(int x){ 
     if(room_num[nroom + 33] == "~") return BLU+room_num[nroom + 33]+NORM; 
else if(room_num[nroom + 33] == "M") return BOLD+room_num[nroom + 33]+NORM; 
else if(room_num[nroom + 33] == "n") return YEL+room_num[nroom + 33]+NORM; 
else if(room_num[nroom + 33] == "@") return HIG+room_num[nroom + 33]+NORM; 
else if(room_num[nroom + 33] == "#") return YEL+room_num[nroom + 33]+NORM; 
else return HIW+room_num[nroom + 33]+NORM;
}

check34(int x){ 
     if(room_num[nroom + 35] == "~") return BLU+room_num[nroom + 35]+NORM; 
else if(room_num[nroom + 35] == "M") return BOLD+room_num[nroom + 35]+NORM; 
else if(room_num[nroom + 35] == "n") return YEL+room_num[nroom + 35]+NORM; 
else if(room_num[nroom + 35] == "@") return HIG+room_num[nroom + 35]+NORM; 
else if(room_num[nroom + 35] == "#") return YEL+room_num[nroom + 35]+NORM; 
else return HIW+room_num[nroom + 35]+NORM;
}

check20(int x){ 
     if(room_num[nroom + 34] == "~") return BLU+room_num[nroom + 34]+NORM; 
else if(room_num[nroom + 34] == "M") return BOLD+room_num[nroom + 34]+NORM; 
else if(room_num[nroom + 34] == "n") return YEL+room_num[nroom + 34]+NORM; 
else if(room_num[nroom + 34] == "@") return HIG+room_num[nroom + 34]+NORM; 
else if(room_num[nroom + 34] == "#") return YEL+room_num[nroom + 34]+NORM; 
else return HIW+room_num[nroom + 34]+NORM;
}
	
check21(int x){ 
     if(room_num[nroom + 62] == "~") return BLU+room_num[nroom + 62]+NORM; 
else if(room_num[nroom + 62] == "M") return BOLD+room_num[nroom + 62]+NORM; 
else if(room_num[nroom + 62] == "n") return YEL+room_num[nroom + 62]+NORM; 
else if(room_num[nroom + 62] == "@") return HIG+room_num[nroom + 62]+NORM; 
else if(room_num[nroom + 62] == "#") return YEL+room_num[nroom + 62]+NORM; 
else return HIW+room_num[nroom + 62]+NORM;
}

check30(int x){ 
     if(room_num[nroom + 61] == "~") return BLU+room_num[nroom + 61]+NORM; 
else if(room_num[nroom + 61] == "M") return BOLD+room_num[nroom + 61]+NORM; 
else if(room_num[nroom + 61] == "n") return YEL+room_num[nroom + 61]+NORM; 
else if(room_num[nroom + 61] == "@") return HIG+room_num[nroom + 61]+NORM; 
else if(room_num[nroom + 61] == "#") return YEL+room_num[nroom + 61]+NORM; 
else return HIW+room_num[nroom + 61]+NORM;
}

check22(int x){ 
     if(room_num[nroom + 63] == "~") return BLU+room_num[nroom + 63]+NORM; 
else if(room_num[nroom + 63] == "M") return BOLD+room_num[nroom + 63]+NORM; 
else if(room_num[nroom + 63] == "n") return YEL+room_num[nroom + 63]+NORM; 
else if(room_num[nroom + 63] == "@") return HIG+room_num[nroom + 63]+NORM; 
else if(room_num[nroom + 63] == "#") return YEL+room_num[nroom + 63]+NORM; 
else return HIW+room_num[nroom + 63]+NORM;
} 
	
check23(int x){ 
     if(room_num[nroom + 64] == "~") return BLU+room_num[nroom + 64]+NORM; 
else if(room_num[nroom + 64] == "M") return BOLD+room_num[nroom + 64]+NORM; 
else if(room_num[nroom + 64] == "n") return YEL+room_num[nroom + 64]+NORM; 
else if(room_num[nroom + 64] == "@") return HIG+room_num[nroom + 64]+NORM; 
else if(room_num[nroom + 64] == "#") return YEL+room_num[nroom + 64]+NORM; 
else return HIW+room_num[nroom + 64]+NORM;
} 
	
check24(int x){ 
     if(room_num[nroom + 65] == "~") return BLU+room_num[nroom + 65]+NORM; 
else if(room_num[nroom + 65] == "M") return BOLD+room_num[nroom + 65]+NORM; 
else if(room_num[nroom + 65] == "n") return YEL+room_num[nroom + 65]+NORM; 
else if(room_num[nroom + 65] == "@") return HIG+room_num[nroom + 65]+NORM; 
else if(room_num[nroom + 65] == "#") return YEL+room_num[nroom + 65]+NORM; 
else return HIW+room_num[nroom + 65]+NORM;
} 

check35(int x){ 
     if(room_num[nroom + 67] == "~") return BLU+room_num[nroom + 67]+NORM; 
else if(room_num[nroom + 67] == "M") return BOLD+room_num[nroom + 67]+NORM; 
else if(room_num[nroom + 67] == "n") return YEL+room_num[nroom + 67]+NORM; 
else if(room_num[nroom + 67] == "@") return HIG+room_num[nroom + 67]+NORM; 
else if(room_num[nroom + 67] == "#") return YEL+room_num[nroom + 67]+NORM; 
else return HIW+room_num[nroom + 67]+NORM;
}

check25(int x){ 
     if(room_num[nroom + 66] == "~") return BLU+room_num[nroom + 66]+NORM; 
else if(room_num[nroom + 66] == "M") return BOLD+room_num[nroom + 66]+NORM; 
else if(room_num[nroom + 66] == "n") return YEL+room_num[nroom + 66]+NORM; 
else if(room_num[nroom + 66] == "@") return HIG+room_num[nroom + 66]+NORM; 
else if(room_num[nroom + 66] == "#") return YEL+room_num[nroom + 66]+NORM; 
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

if(room_num[nroom] == "~" || room_num[nroom] == "M" ||
   room_num[nroom] == "#"){
	write("Blocked room. "+nroom+"\n");
	return 1;
}

/* Create the short desc */
if(room_num[nroom] == "#"){
rtype = "plain";
sline = "a large plain";
}
else if(room_num[nroom] == "@"){
rtype = "forest";
sline = "a forest";
}
else if(room_num[nroom] == "n"){
rtype = "hills";
sline = "foothills";
}
else if(room_num[nroom] == "-"){
rtype = "road";
sline = "a road";
}
else if(room_num[nroom] == "+"){
rtype = "road";
sline = "a bend in the road";
}
else if(room_num[nroom] == "|"){
rtype = "road";
sline = "a road";
}
/*******************************/




write_file("/players/maledicta/cont/urooms/"+nroom+".c",
"#include <ansi.h>
"#define tp this_player()\n"+
"#define tpn this_player()->query_name()\n"+
"#define tpp this_player()->query_possessive()\n"+
"#define RNUM "+nroom+"\n"+
"inherit \"players/maledicta/cont/inherit/room2\";\n\n\n"+
"string rtype;\n"+
"reset(arg){\n"+
"  if(arg) return;\n\n");




write_file("/players/maledicta/cont/urooms/"+nroom+".c",
"set_light(-2);\n"+
"rtype = \""+rtype+"\";\n");

write_file("/players/maledicta/cont/urooms/"+nroom+".c",
"long_desc = \n"+
"\"                "+check26(nroom)+" "+check5(nroom)+" "+check4(nroom)+" "+check3(nroom)+" "+check2(nroom)+" "+check1(nroom)+" "+check31(nroom)+" \\n\"+\n"+
"\"                "+check27(nroom)+" "+check10(nroom)+" "+check9(nroom)+" "+check8(nroom)+" "+check7(nroom)+" "+check6(nroom)+" "+check32(nroom)+"    N\\n\"+\n"+
"\"                "+check28(nroom)+" "+check11(nroom)+" "+check12(nroom)+" "+HIW+"X"+NORM+" "+check14(nroom)+" "+check15(nroom)+" "+check33(nroom)+"   /|\\n\"+\n"+
"\"                "+check29(nroom)+" "+check16(nroom)+" "+check17(nroom)+" "+check18(nroom)+" "+check19(nroom)+" "+check20(nroom)+" "+check34(nroom)+"    | \\n\"+\n"+
"\"                "+check30(nroom)+" "+check21(nroom)+" "+check22(nroom)+" "+check23(nroom)+" "+check24(nroom)+" "+check25(nroom)+" "+check35(nroom)+"    | \\n\";\n");
/***  Setup exits ***/
write_file("/players/maledicta/cont/urooms/"+nroom+".c",
"dest_dir = ({\n");

if(room_num[nroom - 32] != "~" && room_num[nroom - 32] != "#"){
write_file("/players/maledicta/cont/urooms/"+nroom+".c",
"\"/players/maledicta/cont/urooms/"+(nroom-32)+".c\",\"north\",\n");
}
if(room_num[nroom - 31] != "~" && room_num[nroom - 31] != "#"){
write_file("/players/maledicta/cont/urooms/"+nroom+".c",
"\"/players/maledicta/cont/urooms/"+(nroom-31)+".c\",\"northeast\",\n");
}
if(room_num[nroom - 33] != "~" && room_num[nroom - 33] != "#"){
write_file("/players/maledicta/cont/urooms/"+nroom+".c",
"\"/players/maledicta/cont/urooms/"+(nroom-33)+".c\",\"northwest\",\n");
}

if(room_num[nroom + 32] != "~" && room_num[nroom + 32] != "#"){
write_file("/players/maledicta/cont/urooms/"+nroom+".c",
"\"/players/maledicta/cont/urooms/"+(nroom+32)+".c\",\"south\",\n");
}
if(room_num[nroom + 33] != "~" && room_num[nroom + 33] != "#"){
write_file("/players/maledicta/cont/urooms/"+nroom+".c",
"\"/players/maledicta/cont/urooms/"+(nroom+33)+".c\",\"southeast\",\n");
}
if(room_num[nroom + 31] != "~" && room_num[nroom + 31] != "#"){
write_file("/players/maledicta/cont/urooms/"+nroom+".c",
"\"/players/maledicta/cont/urooms/"+(nroom+31)+".c\",\"southwest\",\n");
}
if(room_num[nroom + 1] != "~" && room_num[nroom + 1] != "#"){
write_file("/players/maledicta/cont/urooms/"+nroom+".c",
"\"/players/maledicta/cont/urooms/"+(nroom+1)+".c\",\"east\",\n");
}
if(room_num[nroom - 1] != "~" && room_num[nroom - 1] != "#"){
write_file("/players/maledicta/cont/urooms/"+nroom+".c",
"\"/players/maledicta/cont/urooms/"+(nroom-1)+".c\",\"west\",\n");
}
write_file("/players/maledicta/cont/urooms/"+nroom+".c",
"});\n");
/*************************************************/

write_file("/players/maledicta/cont/urooms/"+nroom+".c",
"}\n\n\n"+
"short(){ return \"Dark room\"; }\n"+
"init(){\n"+
"   ::init();\n\n"+
"}\n");
write_file("/players/maledicta/cont/urooms/"+nroom+".c",
	     "is_underground_mal(){ return 1; }\n"+
           "query_room_type(){ return rtype; }\n"+
           "query_room_num(){ return RNUM; }\n");
               

write("done "+nroom+"\n");
return 1;
}



