inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int whichplayer;
realm() { return "NT"; }
reset(arg) {
   whichplayer = random(4);
   if(!present("alumni"))  {
      if(whichplayer == 0) {
      MOCO("/players/jenny/wings/mobs/closed/lindsay.c"),TO);}

      if(whichplayer == 1) {
      MOCO("/players/jenny/wings/mobs/closed/sawchuk.c"),TO);}

      if(whichplayer == 2) {
      MOCO("/players/jenny/wings/mobs/closed/abel.c"),TO);}

      if(whichplayer == 3) {
      MOCO("/players/jenny/wings/mobs/closed/delvecchio.c"),TO);}}
    if(arg) return;
    set_light(1);
     set_smell(BOLD+"The smell of cigar smoke permeates the air."+NORM);
     set_listen(BOLD+"You hear the pre-game show on the television set."+NORM);
long_desc=
"This large and elegant room is reserved for former Red Wing players.\n"+
"It is a place for them to get together and talk about the good ole days.\n"+      
"It has thick red carpet and cream colored walls, which are decorated\n"+
"with lots of pictures.  This section of the room has three couches,\n"+
"arranged in a U pattern.  A large glass coffee table is between the couches,\n"+
"and a big screen television is against the wall.\n";
items = ({
"carpet","This is plush thick red carpet is very nice",
"walls","The cream colored walls have wood trim, and lots of pictures",
"wall","The cream colored walls have wood trim, and lots of pictures",
"pictures","Throughout the room are team photos of every Detroit Red\n"+
                  "Wings team",
"table","A large coffee table, made of brass and glass.  It has a magazine\n"+
          "sitting on top of it",
"magazine","The latest issue of The Hockey News",
"couches","Three comfortable couches, arranged in a U pattern.  Two of them\n"+
                  "are red, the middle one is white",
"television","A big screen television set.  It is usually used for watching hockey\n"+
                    "games.  It is turned to channel 9, the Hockey Night in Canada\n"+
                    "pre-game show",
});

dest_dir = ({
 "/players/jenny/wings/rooms/alumni4","north",
 "/players/jenny/wings/rooms/alumni1","west",
});
}
short() {
return BOLD+RED+"Alumni Room"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
