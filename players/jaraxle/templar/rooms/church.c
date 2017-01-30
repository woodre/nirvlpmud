#define tp this_player()
#include "/players/jaraxle/ansi.h"
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
object owner;
reset(arg) {
	if(!present("templar_priest")){
	owner = clone_object("/players/jaraxle/templar/mobs/highpriest.c");
	move_object(owner, this_object());
	}
  if(arg) return;
set_light(1);

short_desc = "Church of the Templars "+HIW+"["+NORM+GRN+"Fortress Stone"+HIW+"]"+NORM+"";
long_desc =
  "  The beautiful temple has a peaceful appearance. Thick pillars\n"+
  "of white marble laced with blue veins encircle the benches. The\n"+
  "dome ceiling is painted with a bright scene of the heavens and\n"+
  "it seems as though several figures are reaching into the temple.\n"+
  "A marble altar near the northern wall is draped with a fine,\n"+
  "red cloth trimmed in gold. Candles are lit and ceremoniously\n"+
  "sit upon the altar. A massive cross has been carved in the wall\n"+
  "behind the altar. A small chamber lies to the west.\n";

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
  "/players/jaraxle/templar/rooms/donation","west",
  "/players/jaraxle/templar/rooms/garden","out"
});

}

init(){
::init();
   this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }



