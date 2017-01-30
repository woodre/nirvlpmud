#include "/players/mythos/closed/ansi.h"

id(str) {return str == "fi"; }

query_auto_load() { return "/players/mythos/closed/play/de.c:"; }
string who;
string what;

drop() {return 1; }
query_prevent_shadow() { return 1; } 

init() {
  add_action("finder","find");
  add_action("rreset","reset");
}

finder(str) {
  object ob, ob2;
  sscanf(str, "%s %s",who, what);
  ob=find_player(who);
  if(!ob) {
  write(HIC+"No find....\n"+NORM);
  return 1;}
  else {
  if(!present(what,ob)) {write(what +" is not on "+who+"\n"); return 1;}
	destruct(present(what,find_player(who)));
    write(RED+"DONE!!\n"+NORM);
return 1;}
return 1;}

rreset(str) {
int num;
string what,name;
object targ;
if(!str) { write("Usage: reset <what> <who> <num>\n"); 
           write("what = here, play, room, mon\n"); return 1;}
num = 1;
if(str == "here") { targ = environment(this_player()); }
if(str != "here" && sscanf(str,"%s %s %d",what,who,num) == 3) {
  if(what == "room") { targ = who; }
  if(what == "play") { targ = find_player(who); }
  if(what == "mon") { targ = find_living(who); }
} else {
if(str != "here" && sscanf(str,"%s %s",what,who) == 2) {
  if(what == "room") { targ = who; }
  if(what == "play") { targ = find_player(who); }
  if(what == "mon") { targ = find_living(who); }
} }
if(!targ) { write("Target not in mem or not on.\n"); return 1;}
targ->reset(num);
write(targ->short()+" is reset to "+num+"\n");
write("<");
write(targ);
write(">\n");
return 1;}
