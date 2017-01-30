#include "/players/wocket/closed/ansi.h"
#include "/players/fred/defines.h"
#define PATH "/players/tallos/7tigers/rooms"
inherit "/players/fred/closed/std/room";
reset(arg) {
  if(arg) return;
short_desc = HIY+"7 Tigers Inn"+NORM+":"+HIC+" "+HIC+" C"+HIB+"e"+HIC+"l"+HIB+"e"+HIC+"s"+HIB+"t"+HIC+"i"+HIB+"a"+HIC+"l"+HIC+" Room 2"+NORM;
long_desc = "    "+NORM+""+MAG+"The best rooms in the hotel for sure.  A marvelous\n"+
            ""+HIC+"C"+HIB+"e"+HIC+"l"+HIB+"e"+HIC+"s"+HIB+"t"+HIC+"i"+HIB+"a"+HIC+"l "+HIG+"pa"+HIM+"ra"+HIR+"di"+HIY+"se"+NORM+""+NORM+""+MAG+".  A flowing wall of "+HIC+"s"+HIB+"p"+HIC+"a"+HIB+"r"+HIC+"k"+HIB+"l"+HIC+"i"+HIB+"n"+HIC+"g"+NORM+""+NORM+""+MAG+" "+HIB+"water"+NORM+""+MAG+"\n"+
            "takes up the far back wall. A "+NORM+""+YEL+"button"+MAG+" on one side turns\n"+ 
            "the sound on and off. A huge soft "+HIM+"silk "+NORM+""+MAG+"draped"+HIM+" bed"+NORM+""+MAG+" sits\n"+
            "in the center of the room.  A wondrous "+HIG+"ga"+NORM+""+NORM+""+HIY+"rd"+NORM+""+NORM+""+GRN+"en"+MAG+" takes up\n"+
            "bulk of the rest.  "+HIG+"P"+NORM+""+GRN+"l"+HIG+"a"+NORM+""+GRN+"n"+HIG+"t"+NORM+""+GRN+"s"+NORM+""+NORM+""+MAG+" from all sorts of planes are\n"+
            "here. The fragrance of hundreds of "+HIR+"f"+HIM+"l"+HIY+"o"+HIB+"w"+HIR+"e"+HIM+"r"+HIY+"s"+NORM+""+NORM+""+MAG+" soothes the\n"+
            "thoughts of the most violent of creatures.\n"+
            "   "+HIB+"Portal \"north\""+NORM+""+NORM+"\n";
    add_object("/players/tallos/7tigers/mobs/asimar1.c");            
items = ({
  "inn",
  "The 7 Tigers Inn is one of the most famous hotels in all of the Forgotten\n"+
  "Realms.  It links itself to many different planes and appears there as it\n"+
  "does here", 
  "bed",
  "A silken draped bed stuffed with soft celestial eagle feathers",
  "silk",
  "It drapes the bed soft and comfortable",
  "paradise",
  "Truly a "+HIC+"C"+HIB+"e"+HIC+"l"+HIB+"e"+HIC+"s"+HIB+"t"+HIC+"i"+HIB+"a"+HIC+"l "+HIG+"pa"+HIM+"ra"+HIR+"di"+HIY+"se"+NORM+" you have never seen the like", 
  "water",
  "It takes up the enter back wall. It provides a place for bathing and relaxing. A button is beside it",
  "button",
  "A button on the wall by the water fall that turns the sound on and off",
  "flowers",
  "They are beautiful and surround the room giving off a wonderous fragrance",
  "plants",
  "They are vibrant and full of life. They fill the room",
  "garden",
  "All the plants in room create a wondrous garden of beauty",
  });
  add_smell("main","The wonderful smell of flowers of all kinds");
  add_smell("flowers","They are soft and fragrant but not overpowering");
  add_listen("main","The sound of water falling from the back wall.");
  add_listen("water","The water fall adds a soothing white noise to the room.");
  add_item("wall","The far wall is entirely taken up by a water fall with a button\n"+
                  "to the side.");
set_light(2);
}
init() {
  ::init();
  add_action("north","north");
}
north() {
  string str;
  str= PATH+"/cqhall2.c";
  move_object(this_player(), PATH+"/cqhall2.c");
  command("look",this_player());
  return 1;
}