inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if (!arg) {
  set_light(1);
  short_desc="The Boardwalk";
  long_desc="The Boardwalk ends abruptly here, there are large walls to the North,\n" +
            "West and South while to the East you can see the main intersection of\n" +
            "Stormhold. Along this part of the board walk however you see large\n" +
            "street lights\n";
  items=({"walls","The wall are made of sandstone and there is some\n" +
                  "graffiti scrawled on them",
          "graffiti","Just scribbling along the walls no real wall art\n" +
                     "Jeny's pirates rool.\n" +
                     "No they don't\n" +
                     "Hey what is that there is also another scrawl here\n" +
                     "perhaps you can decipher it",
          "lights","They are gas powered street lamps most peculiar",
          "boardwalk","The Boardwalk is in poor condition many of the boards\n" +
                      "seem rotten but you cannot get under the Boardwalk",
          "intersection","Just an intersection between two streets\n" +
                         "you cannot quite make it out",
          "sky","The sky above you is perfectly clear",
          "sandstone","It is very soft and looks like ity is decaying with age\n" +
                      "but you can only see one crack which you are not sure\n" +
                      "you can enter",
        });

  dest_dir=({"players/persephone/rooms/road1a","east",
  });
 }
}
realm() { return "NT"; }
