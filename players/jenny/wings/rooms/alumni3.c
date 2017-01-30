inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int whichplayer;
realm() { return "NT"; }
reset(arg) {
   whichplayer = random(4);
   if(!present("alumni"))  {
      if(whichplayer == 0) {
      MOCO("/players/jenny/wings/mobs/closed/kelly.c"),TO);}

      if(whichplayer == 1) {
      MOCO("/players/jenny/wings/mobs/closed/adams.c"),TO);}

      if(whichplayer == 2) {
      MOCO("/players/jenny/wings/mobs/closed/pronovost.c"),TO);}

      if(whichplayer == 3) {
      MOCO("/players/jenny/wings/mobs/closed/ullman.c"),TO);}}
    if(arg) return;
    set_light(1);
     set_smell(BOLD+"The smell of cigar smoke permeates the air."+NORM);
long_desc=
"This large and elegant room is reserved for former Red Wing players.\n"+
"It is a place for them to get together and talk about the good ole days.\n"+      
"It has thick red carpet and cream colored walls, which are decorated\n"+
"with lots of pictures.  This section of the room has a poker table and\n"+
"some chairs.  A fan hangs down from the ceiling.\n";
items = ({
"carpet","This is plush thick red carpet is very nice",
"walls","The cream colored walls have wood trim, and lots of pictures",
"pictures","Throughout the room are team photos of every Detroit Red\n"+
                  "Wings team",
"table","A very nice poker table with a green felt top.  It has an ashtray\n"+
          "and a deck of cards on top of it",
"ceiling","Cream colored ceiling tiles, with a fan handing down from them",
"ashtray","A thick crystal ashtray",
"cards","A deck of 52 playing cards", 
"fan","A four bladed ceiling fan turns very slowly",
"chairs","Six well padded chairs pulled up to the table",
});

dest_dir = ({
 "/players/jenny/wings/rooms/alumni1","south",
 "/players/jenny/wings/rooms/alumni4","east",
});
}
short() {
return BOLD+RED+"Alumni Room"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
