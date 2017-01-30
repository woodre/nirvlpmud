#include "/players/guilds/Rangers/RangerDefs.h"

inherit "room/room";
inherit "/players/guilds/Rangers/Room/RangerRoom.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("Angel Grove Park");
   long_desc=
   "This is Angel Grove Park.\n"+
   "There are trees, flowers, and sunshine filling your visual senses.\n"+
   "This is perhaps the most beautiful place you've ever seen.\n"+
   "There is a small playground on the western side.\n"+
   "It's a nice place to have a picnic.\n"+
   "",
   items=
   ({
    });
   dest_dir=
   ({
"players/beck/room/play.c","playground",
"players/beck/room/street4.c","street",
    });
   if(!present("balloon", this_object())){
      move_object("/players/beck/object/balloon.c", this_object());}
   if(!present("soccadillo", this_object())){
      move_object("/players/beck/monster/soccadillo.c", this_object());}
if(!find_living("ranger_tommy")){
move_object("/players/guilds/Rangers/Npc/Tommy.c", this_object());}
}
