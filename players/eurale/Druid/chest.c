#include "DEFS.h"

#define MAX_WEIGTH 100000

add_weight(w) { return 1; }

id(str) { return
  str == "chest" ||
  str == "ornate chest" ||
  str == "druid chest"; }

short() { return HIG+"Ornate Druid Chest"+NORM; }

long() { write(
	"This ornate chest was made from the wood of the Ironwood tree\n"+
	"in which it now rests.  Inlaid into the top of it's curved lid\n"+
	"is the crest of the Druids and the words 'Druids Only'.  The\n"+
	"chest has been sanded and waxed to a mirror sheen and the brass\n"+
	"hardware shines in the light.  You can put items into the chest\n"+
	"with 'put <item> in chest' or donate your whole inventory at\n"+
	"one time with [donate all].\n");
}
can_put_and_get() { return 1; }

init() {
  add_action("donate","donate");
}

donate(str) {
if(!str) { write("Donate what?\n"); return 1; }
if(str == "all") {
  write_file("/players/eurale/Druid/chest.log",
    CTPRN+" donated "+TPPOS+" inventory.\n");
  move_object(TP,TO);
  command("drop all",TP);
  write(
    "So kind of you to donate your entire inventory....\n"+
    "Those Druids less fortunate then yourself will appreciate it..\n"+
    "And your kindness will not go unnoticed.....\n");
  move_object(TP,ETO);
  return 1; }
return 0;
}

catch_tell(str) {
  object from;
  string a,b,c;
  object next_dest;
  string next_out;
  from=this_player();
if(!from) return 1;
if(sscanf(str, "%s gets %s from chest",a,b) == 2) {
  write_file("/players/eurale/Druid/chest_out.log",
    (this_player()->query_name())+" took something from the chest.\n");
  return 1; }
}
