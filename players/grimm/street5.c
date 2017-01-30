#include "/players/grimm/header"
inherit "room/room";

reset(arg) {
  monster();
  if(arg) return;
  short_desc="Sacred Blood";
  long_desc="You are in the town circle.  You can see a shop in the northern\n"+
         "direction and the way back to the entrance of the circle is to\n"+
   	 "the southwest.  You see a clock tower to the southeast of you but\n"+
         "there don't seem to be any entrances from here.\n";
  dest_dir=({ROOT(street3),"southwest",
             ROOT(street6),"east"});
  set_light(0);
}
monster() {
int count;
   object vampire;
   if(!present("vampire")) {
      vampire = clone_object(DIR8(townvamp));
      move_object(vampire, this_object());
   }
}
