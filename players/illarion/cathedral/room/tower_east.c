#include "../def.h"

inherit "/players/illarion/room";

void reset(status arg) {
  if(arg) return;
  
  set_short("The Cathedral's Eastern Tower");

  set_light(1);

  set_long("\
The cathedral's eastern tower room is a large hollow cube of stone, with open, arched windows \
opening in each of the cardinal directions.  Each window has a bench set in front of it, \
and at the top of the room hangs a large bell.  To the north is the cathedral's roof \
and the dome above the crossing, and across the roof to the west is a nearly identical \
tower.  To the south and east are verdant green countryside.  The stairs back down into \
the cathedral are tucked away into one corner.\
");

  add_item("bench","The benches are low but wide, and have padded seats and backs.");
  add_item("tower","You're inside one.  The eastern one, in fact.  The other tower looks to have glass in its windows.");
  add_item("windows","The windows are open to the warm air and sunlight.  Despite the height, the breeze they let in is warm and refreshing.");
  add_item("roof","A steeply-sloped expanse of stone tiles.");
  add_item("dome","The dome is sheathed in white marble, and has a ring of stained glass windows around the base.");
  add_item("windows","Patterned stained glass.  The effect might be better on the inside.");
  add_item("countryside","Verdant and green.  But fairly generic, really.");
  add_item("stairs","Narrow, dark stairs, leading back down into the cathedral.");
  
  add_exit("down",ROOM+"nave_aisle_east");

  set_etime_const(600);
  set_etime_rand(120);
  add_room_emote("A warm breeze blows through the tower.");
  add_room_emote("Somewhere below, a bird sings.");
  
}

void init() {
  ::init();
}