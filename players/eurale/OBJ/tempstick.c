#define tpn this_player()->query_name()
#define tp this_player()
#include "/players/eurale/closed/ansi.h"
object player;

reset(arg) {
  if(arg) return;
}

long() { write(
	"This thin glass tempstick can be inserted rectally and will\n"+
	"determine which maladies have you in their throws.  All you\n"+
	"need to do is [insert tempstick] to determine your condition.\n"+
	"This is a limited use utensil so use it wisely.\n");
	}

short() { return "A thin glass tempstick"; }

query_weight() { return 1; }

query_value() { return 250; }

init() {
  add_action("insert","insert");
}

insert(str) {
if(!str) { write("Insert what?\n"); return 1; }
if(str == "tempstick") {
  write("\n");
  write("You look around to make sure no one is watching.....\n"+
	"You loosen your britches and bend over.......\n"+
	"And then ever so gently.....\n"+
	"insert the cold glass tempstick.....\n\n");
  say(tpn+" bends over and ever so carefully inserts the cold\n"+
	"tempstick up "+this_player()->query_possessive()+" hiney.......smiling!\n");
  player = this_player();
  call_out("condition",1);
  return 1; }
}

get() { return 1; }

id(str) { return str == "tempstick"; }

condition() {
tell_object(player,
  "         ~~*~~\n"+
  HIR+"         BODY TEMPSTICK"+NORM+"\n"+
  "\nThe tempstick indicates the following:\n\n");
if(!present("poison",player) &&
  !present("scorptox",player) &&
  !present("toadtox",player) &&
  !present("hcl",player) &&
  !present("toxin",player) &&
  !present("toxin2",player) &&
  !present("toxin3",player) &&
  !present("crotchrot",player) &&
  !present("rabies",player)) {
  tell_object(player,"Your body is afflicted with:  NOTHING\n");
  tell_object(player,"\n             ~~*~~\n");
  destruct(this_object());
  return 1; }

if(present("scorptox",player))
  tell_object(player,"Your body is afflicted with:  SCORPION VENOM\n");
if(present("toadtox",player))
  tell_object(player,"Your body is afflicted with:  TOAD POISON\n");
if(present("hcl",player))
  tell_object(player,"Your body is afflicted with:  ACID BURNS\n");
if(present("toxin",player) || present("toxin2",player)
  || present("toxin3",player) || present("poison",player))
  tell_object(player,"Your body is afflicted with:  POISON\n");
if(present("rabies",player))
  tell_object(player,"Your body is afflicted with:  RABIES\n");

if(present("aidsvirus",player))
  tell_object(player,
    "Your body is afflicted with:  "+HIR+"Crotchrot (TERMINAL)"+NORM+"\n");

if(present("crotchrot",player))
  tell_object(player,
    "Your body is afflicted with:  VENEREAL DISEASE\n");
tell_object(player,"\n             ~~*~~\n");
destruct(this_object());
}
