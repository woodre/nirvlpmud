#include "/players/persephone/rooms.h"
inherit "/players/persephone/closed/thingys.c";
reset(arg){
 if(!arg) {
  set_light(1);
  short_desc="Harbour Center";
  long_desc="As you walk around the center of the chief Harbour of Nirvana you notice\n" +
            "that this is unlike any other port you have visited in your journeys\n" +
            "Both to the east and to the West the Port of Stormhold continues while\n" +
            "to the South you see a road leading to the small eerie town of Stormhold.\n" +
            "and at the beginning of the road you see a sign\n";
  items=({"sign","An old sign perhaps you should read it",
          "road","The road seems to lead towards the town and appears\n" +
                 "to be in good condition",
          "port","Really it is just another port in the storm",
         });
  dest_dir=({"players/persephone/rooms/harba","west",
             "players/persephone/rooms/road1a","south",
             "players/persephone/rooms/harbc","east",
             "players/persephone/rooms/pier2a","northeast"
   });
 }
}
realm(){ return "NT"; }
init(){
 ::init();
  add_action("read1","read");
}
read1(str){
 if(str=="sign"){
  write("                       Stormhold Gateway to Fun\n" +
        "                       and Entertainment. The\n" +
        "                       Shining Light of Nirvana\n" +
        "                       Population 30,000\n\n");
  say(CAPTPLNM + " reads the sign.\n\n");
  return 1;
 }
 write("What are you trying to read\n");
 return 1;
}
