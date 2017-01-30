#include "/players/maledicta/ansi.h"

#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int i;
reset(arg) {
if(!present("civilian", this_object())) {
    for(i=0; i < 3; i++) {
      move_object(clone_object("/players/maledicta/town/mobs/civilian.c"),
      this_object());
    }
  }	
  if(arg) return;
set_light(1);

short_desc = ""+HIG+"Derellia IV"+NORM+"";
long_desc =
"   Here the road continues to the west and east. A path decorated with\n"+
"shrubs and small trees leads north into what looks to be a small park\n"+
"area. The road here is strangely devoid of houses and businesses, as\n"+
"if something is revered or holy about this place. You feel a sense of\n"+
"peace.\n";

items = ({
  "road",
  "Well kept and often used, it is made of carefully laid stones and is very\n"+
  "old",
  "path",
  "A small brick path that is leads into a small park",
  "shrubs",
  "Planted a long time ago, they are well trimmed and cared for",
  "trees",
  "Shorter than most of the trees in the area, these look as if they were\n"+
  "brought in to this town to be specifically planted here",
  "park",
  "A small woodland park. It looks as though many visitors have walked its\n"+
  "paths",
  
  
});

dest_dir = ({
  "/players/maledicta/town/rooms/t20.c","north",
  "/players/maledicta/town/rooms/t14.c","west",
  "/players/maledicta/town/rooms/t12.c","east",
});

}
init(){
  ::init();
  this_player()->set_fight_area();
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }
	