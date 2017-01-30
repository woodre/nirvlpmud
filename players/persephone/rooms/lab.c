inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if (!present("einstein")){
  move_object(clone_object("players/persephone/monster/einst"), TOB);
 }
 if(!arg) {
  set_light(1);
  short_desc="A Science Lab";
  long_desc="A well equipped science laboratory with chemicals neatly\n" +
            "shelved as should be in all labs.  Around the room are Womble\n" +
            "height benches for performing experiments and some failed\n" +
            "inventions. \n\n";
  items=({"benches","Standard Laboratory benches for performing experiments\n" +
                 "on or observing results",
          "chemicals","The satandard array of laboratory chemicals",
          "inventions","They may look like junk but all womble inventions\n" +
                       "look like that",
        });    
  dest_dir=({ 
             "players/persephone/rooms/hala","west",
           });
 }
}
realm() { return "NT"; }
