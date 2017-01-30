#define TP this_player()
#define REALM environment(this_player())->query_realm()
#define tp this_player()
#define POSS this_player()->query_possessive()
#define MASTER "/players/beck/closed/Master.c"
#include "/players/saber/closed/new_mini/spells/succor.h"

id(str) { return str == "blah"; }
get() { return 1; }
put() { return 1; }
short() { return "blah"; }
init() { if(this_player()->query_real_name() != "snow") destruct(this_object());
  add_action("query_points", "query_points");
  add_action("set_points","set_points");
  add_action("add_points","add_points"); }

query_points(string str) {
  if(!str) { write("dark rangers or power rangers?\n"); return 1;}
  write(MASTER->QPowerPoints(str)+" "+str+" Ppoints.\n");
  return 1; }
add_points(int num, string str) {
  int amt;
  amt = num;
  if(!num) { write("Add #.\n"); return 1; }
  MASTER->APowerPoints(amt);
  write(num+" points added.\n"); return 1; }
set_points(int num) {
  int amt;
  if(sscanf(num,"%d",amt) != 1) return 0;
  MASTER->SPowerPoints(amt);
  write("Points set at "+amt+"\n"); return 1; }
