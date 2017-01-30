#include "defs.h"
inherit "/room/room.c";
#define MY_NAME "zone"
#define CAP_NAME capitalize(MY_NAME)
#define LEVEL call_other(this_player(),"query_level")
int shld;
reset(arg) {
   if(arg) R TO(ME, "Game has just reset.\n");
   shld = 1000000;
   short_desc = CAP_NAME+"'s little nook";
   long_desc = short_desc+CR+
"You are in Zone's comfey nook.  This is where he goes to get away from it\n"+
"all and put up his feet for a few days.  The room is very comfortable,\n"+
"with a lived in feeling that only comes from a long and loving occupancy\n"+
"In the corner is a comfortable looking wicker couch covered with futon\n"+
"padding.  The clutter is, well, a little messy, but basicly clean.\n";
    dest_dir =
	({
	"room/church", "church",
	"players/buddha/workroom", "buddha",
	"players/bern/town/shop", "shop",
	"players/magnum/workroom", "magnum",
	"players/azane/workroom", "azane",
	"players/blackadder/workroom", "black",
	"players/deathmonger/workroom", "death",
	"players/silent/workroom", "silent",
	"players/deathmonger/ASSASSIN/catapault", "catapault",
	});
    set_light(10);
}
init() {
   if(Mqrn == MY_NAME) {
      ACT("set_shield","sh");
      ACT("invite","invite");
   }
   else {
      if(allowed(M)) {
	TO(M,"Welcome to "+CAP_NAME+"'s little nook.\n"+CR);
      }
      else {
	TO(M,""+CAP_NAME+" is so relaxed that he fell asleep.\n");
        MO(M,"/room/void");
	R TO(ME, M+" has tried to enter your workroom.\n");
        R 1;
      }
   }
  ::init();
}

long(str) { ::long();   if(SELF) W(CR+shld+CR);}

set_shield(arg){
  int temp;
  if(!arg) { W("Workroom shields are currently at level "+shld+"."+CR); R 1; }
  if(sscanf(arg, "%d", temp)) {
    if(temp >= 0) {
      W("Workroom shields are changed.\n");
      W("Access is allowed to levels > " + temp + "\n");
      shld = temp;
    }
    else { W(arg + " is an invalid paramter.\n"); }
  }
  R 1;
}

invite(str) {
  int tmp;
  if(!str) { W("Who shall I invite?\n");  R 1; }
  if (!V) { W(CAP(str)+" is not around.\n");  R 1; }
  tmp = shld;    shld = 0;
  TO(V,"You have been invited into Zone's little nook.\n");
 V->move_player(V->query_mmsgout()+"players/zone/workroom");

  W("You have invited "+V->QN+" to your workroom.\n");
  shld = tmp;   R 1;
}

allowed(who) {
if(who->query_level() > shld) return 1;
}
