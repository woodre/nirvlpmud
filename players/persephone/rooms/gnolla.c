inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
int i;
int t;
reset (arg){
 if(!present("puppy")){
  for(i=0;i<3;i++){
   move_object(clone_object("players/persephone/pup"), TOB);
  }
 }
 if (!present("punk")){
  move_object(clone_object("players/persephone/monster/punk"), TOB);
 }
 if (!present("ant")){
  for(t=0;t<2;t++){
   move_object(clone_object("players/persephone/monster/ant"), TOB);
  }
 }
 if(!arg) {
  set_light(1);
  short_desc="Grassy Dell";
  long_desc="You are in a grassy depression or dell on Blueberry Hill. All around\n" +
            "you are lovely willow trees and you feel a soft breeze blowing through\n" +
            "the dell. At the edge of the dell you think you can make out something\n" +
            "strange while the top of the hill is to the East and a small hole\n" +
            "leads down.\n" +
  "\n";
  dest_dir=({"players/persephone/rooms/bhillt","east",
             "players/persephone/rooms/hala","down",
});
 }
}
realm(){ return "NT"; }
