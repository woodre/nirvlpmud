inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if(!arg) {
  set_light(1);
  short_desc="Royal Suite";
  long_desc="This is the most beautiful hotel room you have ever seen and you\n" +
            "cannot help but gasp at the sheer splendour. To the west you see the\n" +
            "royal bedroom and to the north is the entry foyer. In this part of\n" +
            "royal suite though are some beautiful antiques and furniture.\n" +
            "\n";
  dest_dir=({"players/persephone/rooms/rsuite","north",
             "players/persephone/rooms/ro_sui2","west",
           });
 }
}
realm() { return "NT"; }
init(){
::init();
add_action ("jiggle","west");
add_action ("jiggle","w");
}
jiggle()
{
  if(!present("womblestart",TPL)){
    write("A strange force seems to be blocking your progress west\n");
  return 1;
  }
}
