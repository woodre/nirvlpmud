#include "/players/grimm/header"
inherit "room/room";
reset(arg) {
   monster();
   if(arg)
      return;
short_desc="Old Hardware Store";
long_desc="This is an old hardware store.  Not much is left here, i am sure\n"+
          "the vampires would have destroyed this place cause of all the\n"+
          "wooden stakes they use to manufacture.\n";
dest_dir=({ROOT(street7),"west"});
set_light(1);
}
monster() {
   object man, shovel;
   if(!present("hardware man")) {
      man = clone_object(DIR8(hardwareman));
      shovel = clone_object(DIR2(shovel));
      move_object(shovel,man);
      move_object(man,this_object());
      return 1;
   }
}
