#include "/players/feldegast/defines.h"
inherit ROOM;
reset(arg) {
  object storyteller;
  if(!present("storyteller")) {
    storyteller=clone_object("/players/feldegast/island/npc/storyteller");
    move_object(storyteller,this_object());
  }
  if (arg) return;
  set_light(1);
  short_desc="A dusty hut";
  long_desc=
"     This is a dusty old hut filled with old scrolls and desks.\n"+
"Several benches are also here where listeners can gather to\n"+
"listen to the storyteller.\n";
  items=({
    "scrolls","They're in some language you don't recognize",
    "desks","Bamboo desks with graffiti carved on them",
    "graffiti","'N+M Forever','C.S. loves D.B.','K.S. is a slut'",
    "benches","These are made of a strong yet flexible wood that\n"+
              "you don't recognize"
  });
  dest_dir=({
    "/players/feldegast/island/village1","north"
  });
}

