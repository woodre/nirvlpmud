inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if (!present("wimbledon")){
  move_object(clone_object("players/persephone/monster/wimble"), TOB);
 }
 if(!arg) {
  set_light(1);
  short_desc="A Living Room";
  long_desc="A small living room with a broken TV and small\n" +
            "couch in the middle of the room. Scatterred around\n" +
            "the rest of the rooms are some chairs a table\n" +
            "and some old sporting equipment none of the big people\n" +
            "seem to want. \n\n";
  items=({"couch","it seems to have seen better days you would not\n" +
                 "want to sit in it",
          "TV","The TV is definately broken but the Wombles like it",
          "equipment","Just an old hockey stick and a cricket bat",
        });    
  dest_dir=({ 
             "players/persephone/rooms/hala","east",
           });
 }
}
realm() { return "NT"; }
