inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(int arg){
 if(!present("billy")) {
  move_object(clone_object("players/persephone/monster/bilt"), TOB);
 }
  if (!arg){
  set_light(1);
  short_desc="Puf's Lair";
  long_desc="This is the famed lair of Puf the Magic Dragon. It is unlike any\n" +
            "other Dragon lair you have seen rather than being messy this lair\n" +
            "is very neat. Against the West wall of this vast cavern you see a \n" +
            "chest and in the middle of the chamber you see Puf's Dragon sized\n" +
            "bed. Also you hear the Music of Peter, Paul and Mary being played\n" +
            "continuously\n";
  items=({"bed","The Bed is simply enormous and has tie died blankets\n" +
                "covering it and Magic Mushrooms all around, in fact\n" +
                "the bed looks like a mushroom",
          "chest","Well a toy box would be more apt and it just below\n" +
                  " a large window looking out to the sea and the magical\n" +
                  "land of Analee\n",
          "music","You cannot see music silly but it sounds like Puff\n" +
                  "the Magic Dragon",
          "Peter","You cannot see Peter here or Paul or Mary but there\n" +
                  "is a large poster of them",
          "toys","A collection of toys from the 1960's including\n" +
                 "yoyo's and a hula hoop",
          "poster","A lovely poster advertising a Peter, Paul and Mary\n" +
                   "concert",
          "window","The window is made of glass",
          "walls","The walls sparkle with an almost mystical sheen\n" +
                  "but with the mushrooms you ate you cannot handle\n" +
                  "the colours",
          "ceiling","The cieling has large Stalagmites hanging down from\n" +
                    "it that sparkle in the light",
          "floor","The floor is perfectly smooth",
  });
  dest_dir=({"players/persephone/rooms/lair_ent2","southeast"
  });
 }
}
realm(){ return "NT"; }
