#include "/players/persephone/rooms.h"
inherit "/players/persephone/closed/thingys.c";
reset (arg){
 if(!present("drake"){
  move_object(clone_object("players/persephone/monster/drake"), TOB);
  move_object(clone_object("players/persephone/obj/chst"), TOB);
 }
 if (!arg) {
  set_light(0);
  short_desc="Galleon's Bridge";
  long_desc="This is what you assume to be the bridge of the Flying\n" +
            "Dutchman. Lying all around the bridge are remnants of\n" +
            "powder kegs and other barrels. As you stand here you\n" +
            "feel ill at ease and you think it is in part to do with\n" +
           "the evil looking pirate eyeing you up and down.\n\n";
  items=({"pirate","By all appearences it looks to be Sir Francis Drake",
          "kegs","They look to be emblazened with the Seal of Queen\n" +
                    "Elizabeth of England",
          "barrels","They seem as if they held rum and ale",
          "bridge","The place the captain gives his orders from",
         });
  dest_dir=({"players/persephone/rooms/galle","north",
  });
 }
}
