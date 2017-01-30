#include "/players/mythos/closed/guild/def.h"
inherit "obj/treasure";
object ob, con;
reset(arg) {
  if(arg) return;
    set_id("control");
    set_short("Searcher Control");
    set_long("Just command the searcher to go where you wish <go <dir>>\n"+
             "Also, type see <name> to look at an object in the room\n"+
             "And, type assess <name> to know the creature.\n"+
             "To call off the knowing type <know_off>\n");
    set_weight(0);
    set_value(0);
}
 init() {
   ::init();
   add_action("go","go");
   add_action("sees","see");
   add_action("assess","assess");
   add_action("know_off","know_off");
   }
   
drop() { return 1;}
get() { return 0;}

set_con(ob) { con = ob; }

go(str) {
int h, i;
string dire;
  if(!str) { write("Usage: go <dir>\n"); return 1;}
  dire = environment(con)->query_dest_dir();
  if(dire) {
  h = 1;
  i = 0;
    while(h < sizeof(dire)) {
	if (query_verb() == dire[i]) {
	    i = 1;}
	h += 2; }
	if(i == 0) {
	  write("That direction does not exist.\n");
    return 1;}
  else {
    h = 1;
    while(h < sizeof(dire)) {
	if (query_verb() == dire[i]) {
	    move_object(con,dire[i-1]);
	    return 1; }
	h += 2;
    }
  }
  con->seea(); }
return 1;}

sees(str) {
if(!str) { con->seea(); return 1;}
con->sees(str);
return 1;}

assess(str) {
if(!str) { write("Usage: assess <name>\n"); return 1;}
con->assess(str);
return 1;}

know_off() { con->off(); destruct(this_object()); return 1;}
