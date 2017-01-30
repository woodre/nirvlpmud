inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int whichplayer;
realm() { return "NT"; }
reset(arg) {
   whichplayer = random(4);
   if(!present("alumni"))  {
      if(whichplayer == 0) {
      MOCO("/players/jenny/wings/mobs/closed/konstantinov.c"),TO);}

      if(whichplayer == 1) {
      MOCO("/players/jenny/wings/mobs/closed/showe.c"),TO);}

      if(whichplayer == 2) {
      MOCO("/players/jenny/wings/mobs/closed/goodfellow.c"),TO);}

      if(whichplayer == 3) {
      MOCO("/players/jenny/wings/mobs/closed/stewart.c"),TO);}}
    if(arg) return;
    set_light(1);
     set_smell(BOLD+"The smell of cigar smoke permeates the air."+NORM);
long_desc=
"This large and elegant room is reserved for former Red Wing players.\n"+
"It is a place for them to get together and talk about the good ole days.\n"+      
"It has thick red carpet and cream colored walls, which are decorated\n"+
"with lots of pictures.  This section of the room has a large wooden bar,\n"+
"with bar stools in front of it, and shelves full of liquor, and a large\n"+
"refrigerator behind it.\n";
items = ({
"carpet","This is plush thick red carpet is very nice",
"walls","The cream colored walls have wood trim, and lots of pictures",
"pictures","Throughout the room are team photos of every Detroit Red\n"+
                  "Wings team",
"bar","An elegant wooden bar, made of walnut.  It has a few beer taps\n"+
          "rising from it, and an ashtray and small cedar box laying on\n"+
          "top of it",
"taps","Three brass beer taps rising up from the bar",
"ashtray","A thick crystal ashtray",
"box","A small cedar cigar box", 
"shelves","A large wooden shelving unit behind the bar is well stocked\n"+
               "with hard liquor",
"liquor","There are bottles of every kind of liquor imaginable",
"stools","Four padded wooden stools are pulled up next to the bar",
"refrigerator","A large tan refrigerator and freezer is behind the bar",
});

dest_dir = ({
 "/players/jenny/wings/rooms/alumni3","north",
 "/players/jenny/wings/rooms/alumni2","east",
 "/players/jenny/wings/rooms/s3","leave",
});
}
short() {
return BOLD+RED+"Alumni Room"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
