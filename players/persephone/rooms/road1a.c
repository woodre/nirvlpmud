inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if(!present("auctioneer")){
  move_object(clone_object("players/persephone/monster/auct"),TOB);
 }
 if(!present("bob")){
  move_object(clone_object("players/persephone/monster/bob"),TOB);
 }
 if(!present("executive")){
  move_object(clone_object("players/persephone/monster/bman"),TOB);
 }
 if (!arg) {
  set_light(1);
  short_desc="Town Border";
  long_desc="You have arrived at the outskirts of the Town of Stormhold which once\n" +
            "had an extremely peaceful reputation but is now apparently full of\n" +
            "dark and sinister places. You even hear that pirates now run the town\n" +
            "If you look East and West you see that another road intersects with\n" +
            "the main North South road. To the south you see the center of the town\n" +
            "while to the North you see the Harbour Center. There appear to be\n" +
            "many dark and sinister shapes in all directions except north\n";
  items=({"shapes","They are shadows of the past",
          "shadows","Dim dark memories of Stormhold before the evil came",
          "harbour","You cannot quite make out the harbour perhaps\n" +
                    "you should get closer and check it out",
          "road","The road is in good condition",
          "stormhold","Stormhold appears to be the cultural centre of the\n" +
                      "world",
          "intersection","The intersection between main street and the Boardwalk.\n" +
                         "On each corner of the intersection is a sign",
          "signs","These are just street signs and all look the same\n" +
                  "perhaps you should read one",
          "towncenter","It is to far away to get a good impression other\n" +
                       "than the black clouds that seem to lie over it",
          "pirates","You cannot see any pirates here but maybe you better be more\n" +
                    "careful",
          "places","What places you cannot see any places from here",
        });
  dest_dir=({"players/persephone/rooms/harbb","north",
             "players/persephone/rooms/road2a","west",
             "players/persephone/rooms/road1b","south",
             "players/persephone/rooms/road2b","east"
  });
 }
}
realm() { return "NT"; }
