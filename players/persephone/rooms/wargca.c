inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
int t;
reset(int arg){
 if(!present("warg")) {
  for(t=0;t<8;t++){
   move_object(clone_object("players/persephone/monster/warg"), TOB);
  }
 }
 if(!present("leader")) {
  move_object(clone_object("players/persephone/monster/warglea"), TOB);
 }
 if(!arg){
  set_light(0);
  short_desc="A Dark Cave";
  long_desc="This is the stronghold of a band of evil wargs and perhaps\n" +
            "you should not have entered it. Strewn around this hideous\n" +
            "and vile smelling cave is all sorts of carrion and bones.\n" +
            "Perhaps you should leave if you can\n" +
            "\n";
  items=({"wargs","These are extremely hideous and vile creatures that\n" +
                  "you should avoid at all costs",
          "carrion","This is the remains of the wargs last meals.\n" +
                    "Much of the carrion is in various states of\n" +
                    "decomposition",
          "floor","The floor is extremely rough and is covered with\n" +
                  "carrion and bones",
          "walls","The walls are made of some sort of unidentifiable stone",
          "ceiling","The ceiling appears to absorb all your light",
        });
  dest_dir=({"players/persephone/rooms/warglr","up",
           });
 }
}
init(){
 ::init();
  add_action("search1","search");
  add_action("search1","rummage");
}
search1(str){
 if(str=="carrion" || str=="bones" || str=="bone"){
  write("As you search the carrion and bones you start to feel\n" +
        "extremely ill.\n");
  say(CAPTPLNM + " begins to search the carrion but doubles over and pukes\n");
 return 1;
 }
 write("You search the room carefully but find nothing other than bones,\n" +
       "carrion and general filth.\n");
 say(CAPTPLNM + " searches the room in vain\n");
 return 1;
}
