#include "/players/maledicta/ansi.h"

#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define guard7 "/players/maledicta/town/mobs/guard7.c"
inherit "room/room";

reset(arg) {
if(!find_object(guard7)){
move_object(guard7, this_object());
}	
if(!present("civilian", this_object())) {
      move_object(clone_object("/players/maledicta/town/mobs/civilian.c"),
      this_object());
    }
  if(arg) return;
set_light(1);

short_desc = ""+HIG+"Derellia IV"+NORM+"";
long_desc =
"   This is the southwest corner of Derellia.  The road here continues\n"+
"to the north and east. Along the road are a few small houses and shops,\n"+
"as well as several trees. The defense wall is directly to your south\n"+
"and west. A large turret can be seen mounted to the top of the wall.\n"+
"The road leads east to the main gate or north into the town.\n";

items = ({
  "road",
  "A well-kept road made of carefully laid stone. It is very clean",
  "houses",
  "Looking about you see a few small houses lining the street. They are made\n"+
  "of white stone",
  "shops",
  "Small white stone shops that serve to provide for the people of Derellia",
  "trees",
  "Large healthy trees with full canopies of leaves",
  "wall",
  "A stone and steel defense wall. It glimmers with the power of an energy field",
  "turret",
  "A large turret used in the defense of the town. It is painted to a blue tint\n"+
  "and carries a solid punch from a high energy laser beam",
  "gate",
  "The towns main gate, located to the east",
  "field",
  "A high powered field of energy. It is nearly unbreakable" 
  
  
});

dest_dir = ({
  "/players/maledicta/town/rooms/t16.c","north",
  "/players/maledicta/town/rooms/t1.c" ,"east",
});

}
init(){
  ::init();
  this_player()->set_fight_area();
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }
	