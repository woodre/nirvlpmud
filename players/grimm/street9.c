#include "/players/grimm/header"
inherit "room/room";

reset(arg) {
  monster();
  if (arg) return;
  short_desc="Old Street";
  long_desc="You are in the town circle.  You can see a shop in the northeast\n"+
         "direction and the way back to the entrance of the circle is to\n"+
   	 "the northwest.  You see a clock tower to the northeast of you but\n"+
         "there doesn't seem to be any entrances from here.\n";
  dest_dir=({ROOT(street3),"northwest",
          ROOT(street8),"east"});
  set_light(0);
}
monster() {
int count;
   object vampire;
   if(!present("vampire")) {
      while(count<4) { count += 1;
      vampire = clone_object(DIR8(townvamp));
      move_object(vampire, this_object());
      }
   }
}
