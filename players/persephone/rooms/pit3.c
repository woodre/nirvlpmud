inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(int arg){
 if(!present("alligator")) {
  move_object(clone_object("players/persephone/monster/alligator"), TOB);
 }
 if(!arg){
  set_light(1);
  short_desc="Wet Tunnel";
  long_desc="You are in a wet cold tunnel system which runs east to west,\n" +
            "while to the north and the south you see an old storm water\n" +
            "drain system perhaps that is why the water is up to your ankles.\n" +
            "\n";
  items=({"tunnel","You presume it is a service tunnel to the old drainage\n" +
                   "system of Stormhold",
          "stormhold","You cannot see stormhold from in the tunnel",
          "drains","The drains look to be in disrepair and you doubt you could enter them",
          "water","It is water you know that stuff that is wet, however, there\n" +
                  "are rats and cats floating in it",
          "ceiling","It is unremarkable just the ceiling of a tunnel",
          "walls","The walls look as if they have been hewn out of stone and\n" +
                  "consequently are extremely rough as well as being covered in\n" +
                  "an irridescent fungus or algea",
          "floor","There is no possible way you can see the floor under all\n" +
                  "this water",
          "fungus","Just an irredescent form of toxic blue-green algea",
        });
  dest_dir=({"players/persephone/rooms/pit2","west",
             "players/persephone/rooms/und_gr1","east",
           });
 }
}
init(){
 ::init();
  add_action("north","north");
  add_action("north","n");
  add_action("south","south");
  add_action("south","s");
}
north(){
 write("What are you trying to do get killed\n");
 say(CAPTPLNM + " thinks of going north but then chickens out.\n");
 return 1;
}
south(){
 write("You try to go south but quake in fear as you take your first step.\n");
 say(CAPTPLNM + " takes a step to the south but then thinks better about it.\n");
 return 1;
}
