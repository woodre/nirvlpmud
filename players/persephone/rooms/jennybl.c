inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if (arg) return;
  set_light(0);
  short_desc="A Narrow Dark Corridor";
  long_desc="You are in a dark and narrow corridor that appears to stop suddenly\n" +
            "to your west and opens up into a room to the east. It seems as if there\n" +
            "are many footprints on the floor going both east and west and as you\n" +
            "breathe dust swirls around everywhere.\n" +
            "\n";
  items=({"floor","The floor is extremely dusty and there are many footprints going\n" +
                 "in both an easterly and westerly direction",
         "dust","Dust is probably not the right word for this stuff soot is more apt\n" +
                "as this stuff is black and sticks to your clothes very quickly",
         "footprints","These footprints look as if they were made by many different\n" +
                      "people however, you can tell at least on of them was female\n" +
          "walls","The walls here are totally black and that may explain why light\n" +
                 "just seems to be absorbed here",
         "ceiling","The ceiling is just not visible perhaps it is the soot in here",
         "room","You cannot really make out the room to the east",
});
  dest_dir=({"players/persephone/rooms/jennylr","east",
             "players/persephone/rooms/jennysrm","west",
  });
}
realm() { return "NT"; }
init(){
  ::init();
    add_action("snazzle","east");
     add_action("snazzle","e");
}
snazzle(){
if(!present("womblestart",TPL)){
    write("As you try to move east you start to shake in your shoes and cannot proceed\n");
  return 1;
  }
}
