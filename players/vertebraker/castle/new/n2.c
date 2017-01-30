#include "../../define.h"
#define PATH "/players/vertebraker/castle/new/"
inherit ROOM;

reset(arg) {
if(arg) return;
set_short("A darkened forest");
set_long(
"    Trees stand as sentinels above your head, rising above the\n"+
"darkened night and piercing the soft mist.  The earth around\n"+
"your feet seems to have been disturbed recently, as if someone\n"+
"was just here.  Pine needles have been littered all over the\n"+
"forest floor, providing a thin carpet.\n");
add_item(({"pine needles","needles"}),
"Thin pine needles that have been strewn carelessly about the ground");
add_item("trees",
"Tall oak and maple trees that rise above your head");
add_item(({"soft mist","mist"}),
"The gloomy mist rises faintly above your head, and swirls around\n"+
"the area, providing a dim atmosphere");
add_item("earth","You can make out a few footprints here");
add_item("footprints",
"They seem to have been made by a medium-sized sole.  The footprints\n"+
"continue for a few yards, and then abruptly stop.  Bloodstains cake\n"+
"the earth on the outside of these prints.  The footprints point north");
add_object(PATH+"scroll");
add_exit(PATH+"maze","north");
add_exit(PATH+"n1","south"); }

init() {
::init();
add_action("initiate_maze","north"); }

initiate_maze() {
object room;
room = CO(PATH+"maze");
write("You bravely enter the dark forest.\n");
MO(TP,room);
tell_room(this_object(),TPN+" enters the dark forest.\n");
command("look",TP);
return 1; }
