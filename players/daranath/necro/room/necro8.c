#include "../defs.h"
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Altar of Bone and Blood";
    long_desc="  "+
"The hallway within the Necromancer Stronghold ends within this\n"+
"small chamber. Bits and pieces of bones adorn a large, dark stone\n"+
"altar, made for those who wish to contact the Realm of Death. The\n"+
"stone floor in front of the altar bears a large sigil, designed\n"+
"in blood, large enough for a Necromancer to drop a corpse\n"+
"within. Arcane writings stand out upon one wall, while the only\n"+
"exit is eastward, back down the hallway.\n";

    items=({
     "room","The room has the same white marble walls as the guild",
     "walls","The white marble is covered with blood stains",
     "wall","The white marble is covered with blood stains",
     "marble","Expensive white marble makes up the guild hall",
    });

    dest_dir=({
      PATH+"/room/necro4.c","east",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("Bits of bone and areas of dried blood are all about the room.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

