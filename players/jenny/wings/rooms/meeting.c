inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int whichplayer;
realm() { return "NT"; }
reset(arg) {
   whichplayer = random(100);
   if(!present("player"))  {
      if(whichplayer < 55) {
      MOCO("/players/jenny/wings/mobs/players/kozlov.c"),TO);}

      if(whichplayer > 54) {
      MOCO("/players/jenny/wings/mobs/players/holmstrom.c"),TO);}}
if(!present("smith"))  {
MOCO("/players/jenny/wings/mobs/staff/smith.c"),TO); }
    if(arg) return;
    set_light(1);
long_desc=
"This is a room that the Red Wings coaching staff uses for team\n"+      
"meetings.  It is a fairly big room, with thirty chairs, arranged in\n"+
"rows of six.  The floor is covered with thin red carpet, and the\n"+
"walls are white with the Wings logo painted on the far wall.  A\n"+
"chalkboard is on the wall in the front of the room, with a big\n"+
"screen television sitting in front of it.\n";
items = ({
"carpet","This thin red carpet was just put in last year",
"walls","The walls are painted white",
"chairs","There are 30 folding chairs, arranged in rows of six",
"rows","Six rows of chairs",
"floor","It is covered with red carpet",
"logo","This logo is a winged wheel.  It is painted in red and white",
"chalkboard","A black chalkboard in the front of the room.  The\n"+
                       "coaches use it to draw diagrams",
"television","This is a big screen television that the coaching staff uses to\n"+
                        "go over game tapes with the players",
});

dest_dir = ({
 "/players/jenny/wings/rooms/i4","out",
});
}
short() {
return BOLD+RED+"meeting room"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
