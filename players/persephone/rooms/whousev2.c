inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
int t;
 reset(arg){
 if(!present("pirate")) {
  for(t=0;t<3;t++){
   move_object(clone_object("players/persephone/monster/piratv"), TOB);
  }
 }
 if(!present("vvladimir")){
  move_object(clone_object("players/persephone/monster/vvlad"), TOB);
 }
 if(!arg) {
  set_light(0);
  short_desc="Pirates Headquarters";
  long_desc="You just made a very bad mistake and walked into the pirates headquarters\n" +
           "while a meeting was going on. There appears to be about ten pirates\n" +
           "sitting around a rather large table. Unfortuantely they noticed you\n" +
           "enter the room. To the east you cannot see much but you know that is the\n" +
           "way out. Also scattered around this room are many boxes and a large chest.\n";
  items=({"headquarters","This is where one group of pirates have set up operations",
          "meeting","The meeting is now over you sort of stopped it in its tracks",
          "pirates","They look mean and you do not want to mess with any more of them",
          "table","A large rectangular boardroom table with a huge black chair\n" +
                  "at the end of the table. That must have been the leaders chair",
          "chair","The chair looks extremely comfortable but you feel you should\n" +
                  "not sit in it",
          "chest","It is one of those big pirates chests but unfortunately\n" +
                  "it seems to be locked",
          "boxes","Just shipping crates they appear to be of no interest.\n" +
                  "Wait a second one of them has a label on it",
          "label","A bright orange lable with orange print, perhaps you should read it",
        });
  dest_dir=({"players/persephone/rooms/whousev1","east"
   });
 }
}
realm() { return "NT"; }
