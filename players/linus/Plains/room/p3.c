#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
 if(!arg) {
 set_light(1);
 set_short(HIY+"Celestial Plains"+NORM);
 set_long(
 "A howling wind blows through, sending swirls of dust through the\n"+
 "the air.  The tall grass that grows here bends as if evading the\n"+
 "dusty wind.  Something stands to the east, but is difficult to\n"+
 "see, due to the heavy amounts of dust in the air.\n");
 add_listen("main","The wind howls in your ears");
 set_chance(5);
 add_msg("Dust blows over the area...\n");
 add_listen("main","The wind whistles in your ears");
 set_chance(5);
 add_msg("Clouds roll over the area...\n");
 add_item("clumps","Tall grass that grows in clumps throughout the plains");
 add_item("grass","Tall grass that grows in clumps throughout the plains");
 add_exit(PLAIN+"r1.c","northeast");
 add_item("ground","Clumps of grass grow here and there, but mostly barren dirt");
 add_item("dirt","Dry dirt that makes up the ground of the plains");
 add_item("barren dirt","Dry dirt that makes up teh ground of the plains");
 add_item("shadows","Blurred images of objects off in the distance");
 add_item("outlines","Blurred images of objects off in the distance");
 add_item("objects","Blurred images of objects off in the distance");
 add_item("images","Blurred images of objects off in the distance");
 add_item("haze","A haze that makes vision difficult");
 add_exit(PLAIN+"p2.c","south");
}
}
