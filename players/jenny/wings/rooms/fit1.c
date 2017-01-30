inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int whichplayer;
realm() { return "NT"; }
reset(arg) {
   whichplayer = random(100);
   if(!present("player"))  {
      if(whichplayer < 50) {
      MOCO("/players/jenny/wings/mobs/players/verbeek.c"),TO);}

      if(whichplayer > 49) {
      MOCO("/players/jenny/wings/mobs/players/draper.c"),TO);}}
    if(arg) return;
    set_light(1);
     set_listen(BOLD+"You hear stock market reports on the television."+NORM);
     set_smell(BOLD+"The smell of sweat hangs in the air."+NORM);
     set_search(BOLD+"You notice a water cooler in the corner."+NORM);
long_desc=
"This is the fitness room inside of Joe Louis Arena.  It is used\n"+      
"by the Red Wing players to help maintain peak physical condition.\n"+
"It is pretty big, and can be used by many players at once.  The\n"+
"thin red carpet is unstained and looks fairly new.  The walls are\n"+
"painted white, with pictures all around the room.  This section\n"+
"of the room has eight exercise bikes sitting in front of a\n"+
"television set.\n";
items = ({
"carpet","This thin red carpet was just put in last year",
"walls","The walls are painted white, and have pictures on them",
"pictures","These are pictures of Detroit's Stanley Cup winning teams.\n"+
                  "This section of the room has pictures of the 1936 and 1937\n"+
                   "Stanley Cup champions",
"bikes","These are eight exercise bikes which the players use to keep\n"+
              "their legs in shape.  They are the modern machines.  You\n"+
              "can program the time, mileage, and vary resistance levels\n"+
               "to simulate riding in hilly terrain",
"television","A 36 inch television which the players often watch while\n"+
                    "riding the exercise bikes.  It is turned on", 
"cooler","A refrigerated water cooler, which the players use re-hydrate\n"+
               "themselves after a workout",
});

dest_dir = ({
 "/players/jenny/wings/rooms/fit3","north",
 "/players/jenny/wings/rooms/fit2","west",
 "/players/jenny/wings/rooms/i3","out",
});
}
short() {
return BOLD+RED+"Fitness Room"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
