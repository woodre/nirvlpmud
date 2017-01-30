#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Above the "+HIW+"Clouds"+NORM+"";
long_desc =
"  A large, white, puffy cloud floats slowly above the realm\n"+
"of Nirvana.  Flocks of birds gracefully fly by cloud.  The\n"+
"deep blue sky seems endless, with puffs of clouds floating\n"+
"in scattered patterns.  On the edges of this large cloud are\n"+
"a series of "+HIW+"steps"+NORM+" which lead over the side.\n";

items = ({
  "cloud","A large mass of evaporated water floating in the sky",
  "birds","A flock of gulls flying briskly in the wind",
  "steps","Steps off of the cloud leading to the "+HIW+"church"+NORM+", "+HIW+"lockers"+NORM+"\nand "+HIW+"Third Earth"+NORM+".\nYou can "+HIW+"step"+NORM+" to any of those areas",
});

}
init() {

::init();

add_action("step_out","step");
}

step_out(arg){
if(arg == "lockers"){
write("A breeze of wind floats you down to the lockers.\n");
this_player()->move_player("to the lockers#/players/catwoman/tl");
return 1; }
if(arg == "church"){
write("A breeze of wind floats you down to the church.\n");
this_player()->move_player("to the church#/room/church");
return 1; }
if(arg == "third" || arg == "third earth"){
write("A breeze of wind floats you down to Third Earth.\n");
this_player()->move_player("to Third Earth#/players/jaraxle/3rd/warrior/rooms/entrance");
return 1; }
write("Enter what?\n");
return 1; }


