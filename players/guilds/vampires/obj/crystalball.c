
#include "/players/eurale/closed/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
inherit "obj/treasure";
string str;

reset(arg) {
  if(arg) return;
set_id("ball");
set_alias("crystal ball");
set_short("A "+GRY+"large crystal ball"+NORM);
set_long(
  "A large, crystal-clear ball of some unknown material.  It sparkles\n"+
  "from within as if controled by some mystical force.  If one were to\n"+
  "gaze into it, it might tell them their weapon and armor readiness.\n");
set_value(0);
set_weight(10000);
}


init() {
  ::init();
  add_action("look_at_mirror", "gaze");
}

look_at_mirror(str) {
string strW,strA;
if(!str) { write("Gaze?\n"); return 1; }
if(str == "ball" || str == "crystal ball") {
  say(capitalize(TPN)+" examines "+TP->query_objective()+
      "self carefully in the crystal ball.\n");
  write("As you gaze into the crystal ball, it ripples\n"+
  "and faint letters appear on the glassy surface:\n\n");

if(TP->query_wc() >= 20) strW = "godlike";
  else if(TP->query_wc() >= 18) strW = "awesome";
  else if(TP->query_wc() >= 16) strW = "excellent";
  else if(TP->query_wc() >= 14) strW = "really good";
  else if(TP->query_wc() >= 12) strW = "fair";
  else if(TP->query_wc() >= 10) strW = "poor";
  else if(TP->query_wc() >= 8) strW = "not very good";
  else if(TP->query_wc() < 8) strW = "lousy";
write("     Your "+BOLD+"weapon"+NORM+" appears to be "+HIR+strW+NORM+".\n");

if(TP->query_ac() >= 16) strA = "godlike";
  else if(TP->query_ac() >= 14) strA = "awesome";
  else if(TP->query_ac() >= 12) strA = "excellent";
  else if(TP->query_ac() >= 10) strA = "good";
  else if(TP->query_ac() >= 7) strA = "fair";
  else if(TP->query_ac() >= 5) strA = "poor";
  else if(TP->query_ac() < 5) strA = "terrible";
write("     Your "+BOLD+"armor"+NORM+" appears to be "+HIR+strA+NORM+".\n");
return 1; }
}

get() {
  write("It is secured to the ground.\n");
  return; }

id(str) { return (str=="ball" || str=="crystal ball"); }
