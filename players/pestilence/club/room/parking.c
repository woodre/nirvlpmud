#include "/open/ansi.h"
#define TP this_player()
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;

if (!present("jim")) {
  move_object(clone_object("/players/pestilence/club/mob/jim.c"),
        this_object()); }
short_desc = "outside "+HIK+"Pesty's"+NORM+"";
long_desc =
  "    This is the parking lot for the famous strip club called\n"+
  "Pesty's.  There are several cars parked here.  The building is to\n"+
  "the west, with a flashing neon sign reading Pesty's Strip Club.\n"+
  "The building is a very large brick building.\n"+
  ""+BLINK+""+WHT+"NOTICE:\n"+
  "No one under 18 should enter this club.  Violaters will be PUNISHED."+NORM+"\n";
add_property("NT");
add_property("PK");
set_light(1);

items = ({
  "cars","A lot of cars, mainly sports cars of all makes",
  "building","A large brick building with few windows",
  "sign",""+BLINK+""+YEL+"("+RED+"*"+YEL+")"+YEL+"("+RED+"*"+YEL+")"+HIW+"Pesty's Strip Club  "+NORM+" "+BLINK+""+YEL+" ( | )"+NORM+"",
  "lot","A parking lot with a few empty spaces, with mostly sports cars",
  "parking lot","A parking lot with a few empty spaces, with mostly sports cars",
  "sports cars","Several Camaros, Firebirds and some Mustangs are parked in the lot",
  "brick","Small red bricks",
});
dest_dir = ({
"/players/pestilence/club/room/inside.c","west",
"/players/pestilence/hall.c","back",
});

}

init() {
  ::init();
add_action("stop","quit");
add_action("club","west");
}
stop() {
if(TP->query_ghost() == 1) { return 0; }
else{
write("You can't quit from here.\n");
return 1; }
}

club() {
  TP->move_player("west#/players/pestilence/club/room/inside.c");
write_file("/players/pestilence/club/room/log",""+TP->query_real_name()+" "+TP->query_level()+"+"+TP->query_extra_level()+" entered the Strip club -> "+ctime(time())+"\n");
  return 1; }
