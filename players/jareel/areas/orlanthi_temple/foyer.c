/* 10/07/05 - Earwax - Changed present() check from 'infantry' to
 *           'initiate' because it was wrong, resulting in lots and
 *            lots of initiates being in the room.
 */

inherit "/players/jareel/room";
#include "/players/jareel/define.h"

reset(arg) {
if(!present("plaque"))  {
MOCO("/players/jareel/general_stuff/orlanth_plaque.c"),this_object()); }
if(!present("initiate"))  {
MOCO("/players/jareel/monsters/town/orlanthi_infantry.c"),this_object()); }
    if(arg) return;
    set_light(1);

short_desc=(BLU+"Orlanth "+NORM+"Temple");

long_desc=
  
  "     The vast entrance of the "+BLU+"Orlanthi"+NORM+" Temple, washes a calmness\n"+
  "washes over your soul as you take a breath.  The open ceiling lets\n"+
  "the cool wind race around the immense marble pillars.  The stone\n"+
  "floor leads deeper into the temple, and the door to the west leads\n"+
  "back out to the road.\n";

items = ({

  "marble pillars","The pillars are ornately covered in runes of Air and Motion",
  "marble pillar","The pillars are ornately covered in runes of Air and Motion",
  "pillar","The pillars are ornately covered in runes of Air and Motion",
  "runes","The runes seem to signify the god to whom this temple worships",
  "pillars","The pillars are ornately covered in runes of Motion and Air",
  "sky","The light crystal blue sky lies over head",
  "stone","Large flat gray stones line the floor",
  "floor","Large gray flat stones line the floor",
  "door","The door leads back out to the road",
  "entrance","The entrance is a arched to catch the wind",
  "ceiling","The ceiling is open to let in the elements",
  "wind","The wind washes over your face",
  "wall","The walls are built to channel the wind throughout the temple",
  "temple","This is a temple to worship the elements of Air and Motion",

});

dest_dir = ({
"/players/jareel/areas/entrance/road10","west",
"/players/jareel/areas/orlanthi_temple/shrine","east",
});
}
int peeps;void init() {
  ::init();
    if(!this_player())
    return;
add_action("Search","search");
    peeps++;
  if(find_call_out("wind") == -1)
  call_out("wind", random(10) + 3);
  }void exit() {  peeps--;
  if(peeps <= 0)    while(remove_call_out("wind") != -1) ;
  }void wind() {  object ob,next;
  string msg;
  switch(random(2)) {    case 0: msg= "The wind howls as it races in the temple.\n";
  break;
  case 1: msg= "The wind whistles in your ear.\n";
  break;
  }  tell_room(this_object(),msg);
  while(remove_call_out("wind") != -1);
  call_out("wind", random(10) + 3);
  }

Search(str) {
if(!str) { write("Search what?\n"); return 1; }
  write("You search the "+str+" but find nothing special.\n");
  say(this_player()->query_name()+" searches around for something.\n");
  return 1;
}
