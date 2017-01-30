inherit "room/room";
#include "/players/persephone/rooms.h"
reset(int arg){
 if(!present("statue")){
  move_object(clone_object("players/persephone/closed/stat2"), TOB);
 }
 if (!arg) {
  set_light(0);
  short_desc="Center of Square";
  long_desc="You are in the center of the square of Stormhold. Perhaps the most\n" +
            "startling thing you notice about the center of the square is that\n" +
            "everything appears to be completely black. From the statue in the\n" +
            "exact center of the square to the benches scattered around. Perhaps\n" +
            "the eeriest thing about this area is that there seems to be a constant\n" + 
            "moaning that appears to be coming from the direction of the statue.\n" +
            "\n";
  items=({ "tree","A large and wizened old black oak tree that appears to be mourning\n" +
                 "the darkness and evil times that have hit Stormhold",
          "fountain","This once glorious fountain is now in a state of complete\n" +
                     "disrepair where once water flowed a now much darker\n" +
                     "takes its place",
          "liquid","The liquid is a reddy brown. Now what could that be?",
          "blood","It is blood",
          "benches","They are made of some strange type of wood that almost looks\n" +
                    "metallic",
          "ground","The ground is so black you cannot see anything other than\n" +
                   "some bigfeet just below you",
          "feet","They are your feet what do you think the look like",
          "wood","This must be ironbark",
          "sky","You must be joking it is to dark to see the sky",
          "lamp","The street light is working but it seems to be unable\n" +
                 "to penetrate the darkness that surrounds you",
        });

  dest_dir=({"players/persephone/rooms/square3","north",
             "players/persephone/rooms/square1","northwest",
             "players/persephone/rooms/square2","west",
             "players/persephone/rooms/square4","southwest",
             "players/persephone/rooms/square6","south",
              "","\n                                ",
              "players/persephone/rooms/square8","southeast",
             "players/persephone/rooms/square7","east",
             "players/persephone/rooms/square5","northeast"
  });
 }
}
