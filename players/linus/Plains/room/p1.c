#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
 if(!arg) {
 set_light(1);
 set_short(HIY+"Celestial Plains"+NORM);
 set_long(
 "Tall clumps of grass grow sporadically here, but the majority\n"+
 "of the ground is barren dirt.  A haze blankets the area, leaving\n"+
 "faint shadows and outlines of objects off in the distance.\n");
 add_listen("main","The wind whistles in your ears");
 set_chance(5);
 add_msg("Clouds roll over the area...\n");
 add_item("clumps","Tall grass that grows in clumps throughout the plains");
 add_item("grass","Tall grass that grows in clumps throughout the plains");
 add_item("ground","Clumps of grass grow here and there, but mostly barren dirt");
 add_item("dirt","Dry dirt that makes up the ground of the plains");
 add_item("barren dirt","Dry dirt that makes up teh ground of the plains");
 add_item("shadows","Blurred images of objects off in the distance");
 add_item("outlines","Blurred images of objects off in the distance");
 add_item("objects","Blurred images of objects off in the distance");
 add_item("images","Blurred images of objects off in the distance");
 add_item("haze","A haze that makes vision difficult");
 add_exit(PLAIN+"p2.c","northwest");
 add_exit("/players/linus/workroom.c","south");
}
}
