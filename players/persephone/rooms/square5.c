inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if (!arg) {
  set_light(1);
  short_desc="Town Square";
  long_desc="You feel a great deal more at ease here than you think you would either\n" +
            "to west or southwest. As your eyes adjust to the light here you notice\n" +
            "that Stormhold would have once been a quite idyllic town, now however\n" +
            "all you sence is a feeling of forboding. On the building to the northwest\n" +
            " you see a large sign while to the east you see a sea-man's chapel. The\n" +
            "square continues on to the south, west and southwest and a road leads\n" +
            "north\n" +
            "\n";
  items=({"chapel","The chapel is rather unasuming and shows none of the granduer\n" +
                   "of other buildings you have seen in stormhold. It also seems\n" +
                   "that church emits an aura of good will",
          "sign","Just a sign on top of the building to the northwest",
          "building","It looks to be the police station of Stormhold",
          "town","You cannot see the whole town from here",
          "light","The sun is just dipping behind some large black clouds and\n" +
                  "while the sky is getting darker it is quite nice here",
          "streetlight","The streetlights are not working and many of the lamposts\n" +
                        "around here look to be damaged",
          "lamposts","They are bent or broken",
          "ground","The ground is covered with cobblestones",
          "cobblestones","Well they are cobblestones and they look well worn",
          "road","The road runs is in a good state of repair and heads north there\n" +
                 "is a roadsign at the roads beginning",
          "roadsign","It looks just like a normal roadsign perhaps you should read it",
        });
  dest_dir=({"players/persephone/rooms/road3c","north",
             "players/persephone/rooms/square3","west",
             "players/persephone/rooms/square7","south",
             "players/persephone/rooms/chapela","east",
             "players/persephone/rooms/mid_square","southwest"
  });
 }
}
realm() { return "NT"; }
