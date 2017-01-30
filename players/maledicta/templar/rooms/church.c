#define tp this_player()
#include "/players/maledicta/ansi.h"
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
object owner;
reset(arg) {
	if(!present("templar_priest")){
	owner = clone_object("/players/maledicta/templar/mobs/highpriest.c");
	move_object(owner, this_object());
	}
  if(arg) return;
set_light(1);

short_desc = "Church of the Templars "+HIW+"["+NORM+GRN+"Fortress Stone"+HIW+"]"+NORM+"";
long_desc =
"   You stand within a beautiful temple.  Lining the walls are\n"+
"numerous thin pillars, each trimmed in fine gold.  The ceiling\n"+
"is made of a colorful glass, its form shaped into a dome. A\n"+
"large marble altar stands near the west wall, a bright red\n"+
"carpet leading up to it.  The cross of the Templars can be\n"+
"found carved into the back wall, its form filled in with some\n"+
"type of metal. To the east lies the main hall of the castle. A\n"+
"small door leads to the north into the donation chamber of the\n"+
"Templars.\n";

items = ({
"walls",
"Beautiful white stone walls",
"pillars",
"Thin marble pillars that lend support to the domed ceiling\n"+
"overhead",
"ceiling",
"A large beautiful domed ceiling that allows sunlight to filter\n"+
"into the churches open room.  A thin sliver of light reflects\n"+
"downward straight upon the altar",
"dome",
"A large beautiful domed ceiling that allows sunlight to filter\n"+
"into the churches open room.  A thin sliver of light reflects\n"+
"downward straight upon the altar",
"wall",
"A beautiful white stone wall",
"carpet",
"A bright red carpet",
"cross",
"A huge segment of the wall carved out to resemble the Templar\n"+
"cross.  It is filled in with a shining metal",
"altar",
"A large beautiful Altar made of white marble",
});

dest_dir = ({
  "/players/maledicta/templar/rooms/donation","north",
  "/players/maledicta/templar/rooms/main","east"
});

}

init(){
::init();
   this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }



