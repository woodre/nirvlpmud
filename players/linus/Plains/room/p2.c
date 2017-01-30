#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
 if(!arg) {
 set_light(1);
 set_short(HIY+"Celestial Plains"+NORM);
 set_long(
 "A reddish orange rock protrudes from the barren dirt, pushed up\n"+
 "by natural forces.  Clumps of tall grass dart the barren dirt\n"+
 "of the landscape.  A haze covers the area, making objects in\n"+
  "the distance nothing more than faint outlines and shadows.\n");
 add_listen("main","The wind whistles in your ears");
 set_chance(5);
 add_msg("A haze rolls over the area...\n");
 add_item("clumps","Tall grass that grows in clumps throughout the plains");
 add_item("grass","Tall grass that grows in clumps throughout the plains");
 add_item("ground","Clumps of grass grow here and there, but mostly barren dirt");
 add_item("dirt","Dry dirt that makes up the ground of the plains");
 add_item("barren dirt","Dry dirt that makes up the ground of the plains");
 add_item("shadows","Blurred images of objects off in the distance");
 add_item("outlines","Blurred images of objects off in the distance");
 add_item("objects","Blurred images of objects off in the distance");
 add_item("images","Blurred images of objects off in the distance");
 add_item("haze","A haze that makes vision difficult");
 add_item("rock","A large rust-colored rock");
 add_exit(PLAIN+"p1.c","southeast");
 add_exit(PLAIN+"p3.c","north");
 add_exit(PLAIN+"p4.c","west");
}
}
