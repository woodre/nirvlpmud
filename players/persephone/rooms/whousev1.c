inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset (arg){
 if (!arg) {
  set_light(-1);
  short_desc="Evil warehouse";
  long_desc="This is an extremely evil and dark looking warehouse. As you entered\n" +
           "this wharehouse you thought you heard the sound of rustling behind\n" +
           "some boxes. As you gaze around your imediate area you can see that it\n" +
           "might be possible to leave the wharehouse through a crack in some boards.\n" +
           "To the west you think you hear some whispering or murmering.\n";
  items=({"boxes","Well maybe they aren't boxes after all but large crates",
          "crates","The crates are stacked up to the ceiling nearly, but I would\n" +
                   "be careful if I investigated them as they look like they could\n" +
                   "fall if disturbed",
          "crack","Just a crack in some boards but it looks like the only exit\n" +
          "ceiling","The ceiling is quite plain there are some rafters holding it\n" +
                    "up and skylights in it",
          "skylights","The skylights are glass and let the darkness in beautifully",
          "rafters","They are just normal wooden rafters supporting the ceiling",
          "floor","The floor is extremely dusty",
          "rustling","How can you look at rustling maybe it is just some rats",
          "rats","There are no rats here, Perhaps you should leave you don't\n" +
                 "feel safe here",
        });
  dest_dir=({"players/persephone/rooms/whousev2","west",
           "players/persephone/rooms/square1","leave"
  });
 }
}
init(){
  ::init();
    add_action("west","west");
     add_action("west","w");
}
realm() { return "NT"; }
west(){
  if(!present("womblestart",TPL)){
    write("You feel to much fear to proceed West!!!\n");
  return 1;
  }
}
