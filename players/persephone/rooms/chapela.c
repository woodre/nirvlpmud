inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg) {
if(!present("priest")){
    move_object(clone_object("players/persephone/monster/prie"),TOB);
  }
 if(!arg) {
  set_light(1);
  short_desc="Seamans Chapel";
  long_desc="It is quite amazing to find a Seaman's Chapel in a town taken over by\n" +
            "Pirates but something seems to be protecting it and that is why the\n" +
            "the interior of this chapel looks so calm and peaceful. Ther is a shiny\n" +
            "alter in the middle of the chapel and there appear to be many people\n" +
            "sitting in the pews in praying. Standing behind the alter is the minister.\n" +
            "To the west you can see the square while on the wall to the East you\n" +
             "see a large window.\n";
  items=({"window","This is a beautiful stained glass window of the like you have\n" +
                   "never seen before. Perhaps it is Michealangelo",
          "alter","This alter is extremely elegant and looks to be made of Platinum\n" +
                  "which could explain why it shines so brightly",
           "pews","They are the type of wooden benches you sit on in church and they\n" +
                  "look extremely uncomfortable",
           "square","You have to outside to get an idea of the square",
           "floor","The floor appears to be made of Polished wood and is so shiny you\n" +
                   "can see your reflection in it",
           "reflection","You see an image of your travel weary face, ugh you think you\n" +
                        "need a bath",
           "walls","The walls appear to be plaster and are covered in religious decorations",
           "decorations","You know pictures from biblical scenes. You even think you can\n" +
                         "see Isaac and Jacob in one of them. There is another with\n" +
                         "a sailor depicted in it",
           "sailor","You are not sure but it could be Jesus or some high powered prophet",
  });
  dest_dir=({"players/persephone/rooms/square5","west",
             "players/persephone/rooms/life_r","east",
           });
 }
}
realm(){ return "NT";}
