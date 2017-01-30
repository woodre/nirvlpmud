inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if (!present("heironomous")){
  move_object(clone_object("players/persephone/monster/heiro"), TOB);
 }
 if(!arg) {
  set_light(1);
  short_desc="Heironomous' Study";
  long_desc="Lying all around the study are scraps of paper with all sorts\n" +
            "of scribbling on them.  Against the south wall is a large, well for\n" +
            "Wombles large, oak bookcase with many books in them and\n" +
            "to the north is a passageway leading back out to the hall. Taking\n" +
            "pride of place in the room is a large oak desk. \n\n";
  items=({"desk","It is one of those grand roll top desks you think it must be\n" +
                 "worth a fortune but does not look moveable",
          "paper","Jottings in Womble unfortunately you cannot\n" +
                  "read it",
          "bookcase","A large bookcase with many books all in Womble\n",
        });    
  dest_dir=({ 
             "players/persephone/rooms/hala","north",
  });
 }
}
realm() { return "NT"; }
