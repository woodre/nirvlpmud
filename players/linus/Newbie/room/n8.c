#include "/players/linus/def.h"
inherit "/room/room.c";
  reset(arg){
  if(!present("rabbit",TO)) {
 MO(CO("/players/linus/Newbie/NPC/Rabbit.c"), TO); }
    set_light(1);
    short_desc = GRN+"The hundred acre wood"+NORM;
    long_desc = GRN+
  "The dirt path stops at a large oak tree here.  There is a small\n"+
  "door built into the tree, and a small window to the left of the door.\n"+
  "A small sign on the door reads: Rabit's howse.  To the south of the\n"+
  "tree, a small white fence surrounds an incredible garden.  A small\n"+
  "open gate leads into the garden.\n"+NORM;
    items = ({
      "tree","There is a door and window built into the large oak tree",
      "window","There is a small window built into the tree",
      "oak tree","There is a door and window built into the large oak tree",
      "oak","There is a door and window built into the large oak tree",
      "sign","A small sign with some scribbling on it.  You could probably read it",
      "door","The door appears to be locked",
      "garden","Many fine vegetables grow here",
      "vegetables","Carrots, lettuce, radishes, and other vegetables grow in Rabbit's garden",
      "carrots","Some of the largest carrots you've ever seen",
      "lettuce","Great big heads of green lettuce",
      "radishes","Delicious looking radishes that grow in Rabbit's garden",
      "footpath","Brown dirt where grass will no longer grow",
      "dirt path","Brown dirt where grass will no longer grow",
         "path","Brown dirt where grass will no longer grow",
      "fence","A small white picket fence that surrounds Rabbit's garden.  The gate is open",
      "gate","You could 'enter' the 'garden' through the gate"  });
     dest_dir = ({ NEWB+"n7.c","east" });
 }
init() {
 ::init();
 add_action("enter_garden","enter");
 add_action("read_stuff","read");
 add_action("Listen","listen");
}
enter_garden(str) {
 if(!str || str!="garden"){ FAIL("Enter what?\n"); return 0; }
 if(str=="garden") {
write("You pass through the gate and enter the garden.\n");
 TP->move_player("into the garden#"+NEWB+"n8a.c");
return 1;
}
}
read_stuff(string str) {
    if(!str || str!="sign") {FAIL("Read what?\n"); return 0; }
    if(str=="sign") {
     write("The sign reads: Rabit's Howse.\n");
     return 1;
}
}
Listen() {
  write("The chirping songs of birds from within the forest can be heard.\n");
 return 1;
}
