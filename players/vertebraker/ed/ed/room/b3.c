#include "/players/vertebraker/define.h"
#include "/players/vertebraker/ed/paths.h"
inherit ROOM;
int grabbed;
reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "A basement storage area";
  long_desc =
"     You stand in a dead-end to an earthen cave.  There is a small\n"+
" table on the side of the room.  A small trickle of water runs from the\n"+
"cooled western wall.  Light shines in through a hole in the ceiling- \n"+
"shining upon a piece of paper nailed to the table.\n";
  items = ({
"table","The small table is cluttered with items",
"trickle","A small drip of water is springing from a pinhole in the western wall",
"pinhole","A hole the size of a pin is dripping water",
"wall","The western wall is trickling water",
"light","A bright light is shining from a whole in the wooden boards above",
"boards","Thin wooden boards lie above your head",
"hole", "Pitch black darkness above your head",
"paper","A small notepad-sized piece of paper that you can 'read'",
"items","A scepter lying on the table looks as though it could be grabbed",
});
  dest_dir = ({
ED1ROOM+"b2","southwest",
});
  }

init() {
  ::init();
  add_action("search","search");
  add_action("grab","grab");
  add_action("read","read");
 }

read(arg) {
  if(!arg) { write("Read what?\n"); return 1; }
  if(arg == "paper") {
    write("The paper reads:\n\n"+
"      To whomever should find this -\n"+
"My name is Ash.  And I am a prisoner of this infernal cabin and these woods.\n"+
"I came here with my sister, Cheryl, my girlfriend, Linda, my friend Scotty\n"+ 
"and his girlfriend Shelly.  It wasn't long before things began to go wrong\n"+
"however.  Now my friends are gone and I am in hiding- If you have found this\n"+
"note, your only chance of escape lies in the opening of the infernal book\n"+
"these evil machinations have wrought- But please...retrieve Linda's\n"+
"pendant...  And give it to me.. I can't see my friends like this...\n"+
"any longer.  I am hidden in the shed outside the cabin.. Please.. hurry!\n\n");
say(TPN+" reads the paper.\n");
  return 1; }
  }

grab(arg) {
  if(!arg) { write("Grab what?\n"); return 1; }
  if(arg == "scepter") {
    if(grabbed) { write("You can't grab the scepter after all.\n");
      return 1; }
    write("You grab the skull-headed scepter from the table!\n");
    say(TPN+" grabs a scepter from the table!\n");
    MOCO(ED1OBJ+"skull_scepter"),TP);
    grabbed = 1;
    return 1; }
 }

search(arg) {
    if(!arg) { write("Your general search of the area turns up nothing.\n"); return 1; }
    if(arg) { write("You search "+arg+", but you turn up nothing.\n"); return 1; }
    return 1; }

realm() { return "NT"; }

status
okay_follow() { return 1; }
