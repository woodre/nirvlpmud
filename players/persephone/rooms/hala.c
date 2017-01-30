inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if (!present("victoria")){
  move_object(clone_object("players/persephone/monster/vict"), TOB);
 }
 if(!arg) {
  set_light(1);
  short_desc="A Pretty Hall";
  long_desc="This is an extremely pretty hall by the size of it you think\n" +
            "that some very small creatures live here perhaps even the famed\n" +
            "Wombles.  It looks quite inviting with a pretty rug running down\n" +
            "the middle of this short and small hallway which is littered with\n" +
            "womble treasures such as string and a large tree growing in the\n" +
  "middle\n\n";
  dest_dir=({"players/persephone/rooms/gnolla","up",
             "players/persephone/rooms/brom","north",
             "players/persephone/rooms/livr","west",
             "players/persephone/rooms/study","south",
             "players/persephone/rooms/lab","east",
  });
 }
}
realm(){ return "NT"; }
