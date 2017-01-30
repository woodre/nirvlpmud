inherit "obj/monster.c";
#include "/players/wocket/closed/ansi.h"

string cmd;
object mage;
string one,two,three,four,five;
reset(arg){
  ::reset();
  if(arg) return;
set_alt_name("telemover");
}

query_invis(){ return 70; }
tele(string str){
one = two = three = four = five = 0;
if(sscanf(str,"%s,%s,%s,%s,%s",one,two,three,four,five) != 5)
if(sscanf(str,"%s,%s,%s,%s",one,two,three,four) != 4)
if(sscanf(str,"%s,%s,%s",one,two,three) != 3)
if(sscanf(str,"%s,%s",one,two) != 2)
one = str;
do_cmds();
}

do_cmds(){
cmd = one;
while(cmd){
  cmd = filter_cmd(cmd);
  init_command(cmd);
  cmd = two;
  two = three;
  three = four;
  four = five;
  five = 0;
}
move_object(mage,environment(this_object()));
destruct(this_object());
}

filter_cmd(string str){
if(str == "e") return "east";
if(str == "w") return "west";
if(str == "n") return "north";
if(str == "s") return "south";
if(str == "u") return "up";
if(str == "d") return "down";
if(str == "enter") return "enter";
if(str == "out") return "out";
if(str == "in") return "in";
if(str == "leave") return "leave";
return "nocommand";
}
set_mage(ob){ mage = ob; }
