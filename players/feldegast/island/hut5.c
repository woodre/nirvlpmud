#include "/players/feldegast/defines.h"
inherit ROOM;

reset(arg) {
  object maria;
  if(!present("maria")) {
    maria=clone_object("/players/feldegast/island/npc/maria");
    move_object(maria,this_object());
  }
  if (arg) return;
  set_light(1);
  short_desc="Lady Maria's Hut";
  long_desc=
"     This is the hut of the village tailor, Lady Maria. Various\n"+
"hides and feathers are strewn about the room along with numerous\n"+
"pots of dye.  A workbench is next to the window where Maria can\n"+
"work.\n";
  items=({
    "hides","Tanned hides for making clothes and other stuff\n"+
            "for the villagers",
    "feathers","Mostly peacock and parrot feathers",
    "pots","Big pots of dye in every color of the rainbow",
    "dye","Big pots of dye in every color of the rainbow",
    "workbench","A wooden table with the tools of Maria's trade sitting\n"+
                "on it",
    "window","You see a nice view of the jungle through the window"
  });
  dest_dir=({
    "/players/feldegast/island/village3","south"
  });
}

