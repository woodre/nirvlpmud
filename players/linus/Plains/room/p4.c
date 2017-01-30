#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
 if(!arg) {
 set_light(1);
 set_short(HIY+"Celestial Plains"+NORM);
 set_long(
 "The barren dirt is a reddish orange color, mostly due to the many\n"+
 "rocks that surround the area.  A few stray clumps of grass grow\n"+
 "between the rocks.  A haze covers most of the area, making the\n"+
 "large rocks that surround the area nothing more than shadows.\n");
 add_listen("main","The wind whistles in your ears");
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
 add_exit(PLAIN+"p2.c","east");
 add_exit(PLAIN+"p5.c","north");
}
}
