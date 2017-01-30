#include "/players/grimm/header"
inherit "room/room";
object demon, cross;
reset(arg) {
   monster();
  if(arg) return;
short_desc="Winding Caverns";
long_desc="As you travel through the caverns you can't tell where you came\n"+
          "from!  All the directions look the same!  This is not a place to\n"+
          "be lost in!\n";
dest_dir=({"players/grimm/caverns/cavern16","south"});
set_light(0);
}
monster() {
   if(!present("demon")) {
      demon = clone_object("players/grimm/monster/guardian");
      move_object(demon,this_object());
/*
   move_object(clone_object("/players/grimm/object/cross"),demon);
*/
   }
}
