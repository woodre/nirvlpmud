inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(int arg){
 if (arg) return;
  set_light(1);
  short_desc="Wet Tunnel";
  long_desc="This is an extremely damp tunnel that runs to the east.\n" +
            "You remember legends that this tunnel was once the hideout\n" +
            "of the infamous Purple People Eater.\n" +
/*  Added next line so people would have a chance. -Snow 1/00 */
      "There is a hole far above you and a ladder leaning against the wall.\n"+
            "\n";
  items=({"tunnel","The tunnel is very damp and you are up to your ankles in water\n" +
                   "with more water falling from the ceiling through a hole",
          "purple","You cannot see him but you hear ominous rumblings coming\n" +
                   "from the east",
          "walls","The walls are slippery and slimy and covered in a blue green algea.\n" +
                  "There is however leaning against the wall a ladder leading\n" +
                  "up to the hole you can barely make out",
          "algea","It does not look like the toxic blue green kind but it does\n" +
                  "give off a soft flourescent aura",
          "light","The light seems to be coming from the algea",
          "hideout","You cannot see a hideout anywhere around here",
          "hole","Perhaps it leads up to the surface",
          "ladder","It is a rickety old wooden ladder with no value all however\n" +
                   "you might be able to climb it",
        });
  dest_dir=({"players/persephone/rooms/pit2","east"
           });
}
init(){
 ::init();
  add_action("climb1","climb");
  add_action("climb1","up");
}
climb1(str){
 if(str=="ladder"){
  write("You carefully climb up the ladder not wishing to break it.\n");
  TPL->move_player("stealthily up the rickety ladder#"+"players/persephone/rooms/junpat3");
  return 1;
 }
 write("What are you trying to climb.\n");
 say(CAPTPLNM + " does a passible imitation of an adventurer climbing up a ladder.\n");
 return 1;
}
         
