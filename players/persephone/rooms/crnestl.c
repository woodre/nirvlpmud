inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset (arg){
 if (!arg){
  set_light(0);
  short_desc="Galleon Mast";
  long_desc="You are climbing the main mast of the pirate ship below you is the deck\n" +
            "and up above you there is a crows nest however it might be wiser to\n" +
            "go down. Far above the crows nest you can see the beautiful black flag\n" +
            "and down you can see the dark and forboding waters of the cold and\n" +
            "evil sea of Tears\n";
  items=({"flag","It appears to be the Jolly Roger",
          "deck","From what you can make out the deck is definately wooden",
          "nest","You cannot tell anything about it from here other than\n" +
                 "you could stand on it",
          "crows","There are no crows around here a few seagulls but no crows",
          "mast","The Mast is made out of some type of strange wood",
          "sea","You would not want to fall down into it as sharks circle\n" +
                "the Galleon",
        });
  dest_dir=({"players/persephone/rooms/crnestp","up",
             "players/persephone/rooms/galle","down",
  });
 }
}
realm(){ return "NT"; }
init(){
  ::init();
    add_action("south","up");
    add_action("south","u");
}
south(){
  if(!present("womblestart",TPL)){
    write("You cannot seem to climb up the final ladder!!!\n");
  return 1;
  }
}
