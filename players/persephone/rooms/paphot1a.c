inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if(!present("pirate")){
  move_object(clone_object("/players/persephone/monster/pirac") ,TOB);
 }
 if (!arg) {
  set_light(0);
  short_desc="Hostel Room";
  long_desc="You are in a large, foul smelling, room with many mattresses around\n" +
            "you other than these mattresses there appears to be no furniture in\n" +
            "the room at all. You cannot be sure, however, as there are many bodies \n" +
            "piled up in the room. To the west you see a corridor which looks to be\n" +
            "the safest direction to go and a little alcove to the south.\n" +
            "\n";
  items=({"mattresses","To call these things mattresses would be very generous indeed they\n" +
                      "look more like sacks of straw however one mattresses looks extremely\n" +
                      "maybe you should search it",
          "floor","You cannot really make out the floor as there are to many mattresses \n" +
                  "and bodies on it",
          "bodies","They are definately human and by the looks of it they all seem to \n" +
                    "have been mudered",
          "walls","The walls look as if they have been painted with blood",
          "ceiling","The ceiling is covered in a green mould that looks extremely unhealthy",
          "mould","The mould is green however since you did not pay attention to your \n" +
                  "biology lessons you do not know what type of mould",
               });
  dest_dir=({"players/persephone/rooms/paphot1b","west",
             "players/persephone/rooms/alcovea","south",
                  });
 }
}
init(){
  ::init();
    add_action("south","south");
    add_action("south","s");
}
south(){
  if(!present("womblestart",TPL)){
    write("You feel to much fear to proceed West!!!\n");
  return 1;
  }
}
