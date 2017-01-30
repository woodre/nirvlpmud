#include "/players/feldegast/defines.h"
inherit ROOM;
reset(arg) {
  object doctor;
  if(!present("doctor")) {
    doctor=clone_object("/players/feldegast/island/npc/doctor");
    move_object(doctor,this_object());
  }
  if (arg) return;
  set_light(1);
  short_desc="A messy hut";
  long_desc=
"     This hut is littered with old banana peels and dirty clothes.\n"+
"A rumpled old bed lies in the corner.  Exotic designs are scrawled\n"+
"in bright paint on every available surface.  You suspect this isn't\n"+
"the residence of a sane individual.\n";
  items=({
    "bed","Tic-tac-toe games are scrawled all over the bed's frame.\n"+
          "You notice that X seems to win more often than O.\n",
    "peels","You watch the banana peels carefully to make sure they aren't\n"+
            "moving.  The doctor needs to clean his room more often",
    "clothes","Most of it seems to be underwear.  The doctor likes his\n"+
              "underwear fresh",
    "designs","One large design is a large heart with the letters N+M in it",
    "paint","Bright, nearly fluorescent pinks, blues, purples, and greens"
  });
  dest_dir=({
    "/players/feldegast/island/village2","north"
  });
}

