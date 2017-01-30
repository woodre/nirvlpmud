#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
 if(!arg) {
 set_light(1);
 set_short(HIY+"Celestial Plains"+NORM);
 set_long(
 "Large rocks form a sort of natural corridor here, allowing travel\n"+
 "only in a north or south direction.  Reddish orange colored dirt\n"+
 "makes up the ground with an occasional clump of grass.  There are\n"+
 "several holes in the rocks.\n");
 set_chance(5);
 add_msg("A haze rolls over the area...\n");
 add_item("clumps","Tall grass that grows in clumps throughout the plains");
 add_item("grass","Tall grass that grows in clumps throughout the plains");
 add_item("ground","Clumps of grass grow here and there, but mostly barren dirt");
 add_item("dirt","Reddish orange colored dirt that makes up the ground of the plains");
 add_item("barren dirt","Reddish orange colored dirt that makes up the ground of the plains");
 add_item("shadows","Blurred images of objects off in the distance");
 add_item("outlines","Blurred images of objects off in the distance");
 add_item("objects","Blurred images of objects off in the distance");
 add_item("images","Blurred images of objects off in the distance");
 add_item("haze","A haze that makes vision difficult");
 add_item("rocks","Large reddish orange rocks that form natural walls to the west and south");
 add_item("walls","Large reddish orange rocks that form natural walls to the west and south");
 add_exit(PLAIN+"p4.c","south");
 add_exit(PLAIN+"p6.c","north");
}
}
cmd_search(str)
{
   if(str == "hole")
      {
      write("As you reach into the hole, something bites you!.\n");
     TP->hit_player(5+random(10));
   }
   else ::cmd_search(str);
   return 1;
}
