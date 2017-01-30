#include "/players/linus/def.h"
#define ESWORD RED+"~"+BLU+" Ele"+GRN+"men"+HIW+"tal S"+NORM+GRN+"wo"+BLU+"rd"+RED+" ~"+NORM
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
 if(!arg);
 set_light(-2);
 set_short("room");
 set_long(
"  An eerie fog hovers over the ground, leaving the floor virtually\n"+
"invisible.  Tapestries hang from the stone walls, each depicting\n"+
"different scenes of Bone's quest for legendary status.  In the center\n"+
"of the room a granite table stands, a blood red sheet covering it.\n"+
"An onyx coffin rests upon the table, its lid sealed and locked. The\n"+
"only way out is west, through a narrow doorway.\n");
 add_item("fog","An eerie fog that hovers above the ground");
 add_item("tapestries","Blood red in color, these tapestries hang from the walls and feature\n"+
                                             "pictures of various events in Bone's life");
 add_item("north wall","The tapestry bears pictures of Bone fighting the creatures of the\n"+
                                            "elemental test, and of him raising the "+ESWORD+" above his\n"+
                                            "head in victory");
 add_item("east wall","The tapestry bears a picture of Bone fighting a fiery phoenix, the\n"+
                                           "mighty Hinotori.  A second picture shows Bone drinking from a pool\n"+
                                           "of blood near the fallen beast");
 add_item("south wall","The tapestry bears a picture of Bone and his family celebrating at a feast");
 add_item("wall","Which wall are you looking at? (north wall, south wall or east wall");
 add_item("walls","Which wall are you looking at? (north wall, south wall or east wall");
 add_item("table","A table made from granite");
 add_item("sheet","A blood red sheet, made of fine silk");
 add_item("coffin","A large coffin made from onxy.  It is closed, and its lid is sealed and locked");
 add_item("doorway","You can leave the room through the doorway to the west");
 set_chance(5);
 add_msg("The fog swirls around your feet...");
}
init() {
 ::init();
 add_action("piss_off","open");
 add_action("piss_off","enter");
 add_action("piss_off","touch");
}
piss_off(str) {
 if(!str || str !="coffin") { notify_fail("What?\n"); return 0; }
 if(str == "coffin") {
  write("A deep voice growls: You must not touch the coffin of Bone.\n"+
            RED+"      You flee in panic!\n"+NORM);
   this_player()->move_player("out of the room in fear!#/players/jareel/areas/statue/hall2.c");
return 1;
}
}
