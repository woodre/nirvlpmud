inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
int t;
reset (arg){
  if(!present("lad")){
    for(t=0;t<2;t++){
    move_object(clone_object("players/persephone/monster/lad"), TOB);
  }
  }
 if(!arg) {
  set_light(0);
  short_desc="Dark Wharf";
  long_desc="You have arrive at the end of the wharf and it is extremely eerie\n" +
            "and foreboding. Docked along the wharf is a large dark Galleon that\n" +
            "has a large flag flying from its mast. There seems to be a lot of action\n" +
            "on the ship and there are many large boxes here on the wharf. You feel\n" +
            "that the safest way would be back to the Southwest while boarding the\n" +
            "you assume would be extremely perilous.\n";
  items=({"wharf","Come on you know what a wharf is it is where large boats dock\n" +
                  "to take on supplies and unload goods",
          "galleon","This is a large and evil looking ship with three masts and a crows\n" +
                    "nest however you still do not know who owns it",
          "flag","This is the standard pirates flag of a skull and cross bones and\n" +
                 "by the look of things these pirates may mean business",
          "cannons","They look like extremely potent weapons and you do not want to be\n" +
                    "on the recieving end if they are fired",
          "boxes","These are extremely large boxes and look very interesting perhaps\n" +
                  "you should search them",
  });
  dest_dir=({"players/persephone/rooms/pier2a","southwest",
             "players/persephone/rooms/galle","board",
  });
 }
}
realm() { return "NT"; }
