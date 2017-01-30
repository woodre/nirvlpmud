inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if(!present("rat")){
  move_object(clone_object("players/persephone/monster/ratty2"),TOB);
 }
 if (!arg) {
  set_light(0);
  short_desc="Town Square";
  long_desc="This square appears extremely strange. As you glance around to the\n" +
            "east you notice that it appears a great deal brighter however to the\n" +
            "south and west the square appears to be equally as gloomy. Indeed\n" +
            "you feel a great sense of forboding in this whole town and you sense\n" +
            "that your every move is being observed perhaps it is caused by the\n" +
            "blackness that surrounds you.\n";
  items=({"sky","The sky is jet black",
          "square","The square is deserted there just are no people around",
          "town","It is a small seaside town what, what more can you say",
          "ground","You can just make out some small furry creatures\n" +
                   "running around",
          "creatures","They are definitely rats not cats",
          "walls","The wall to the west is completely collapsed into rubble",
          "rubble","Just bricks and concrete",
          "blackness","It is totally black",
        });
  dest_dir=({
             "players/persephone/rooms/square1","west",
             "players/persephone/rooms/mid_square","south",
             "players/persephone/rooms/square5","east"
  });
 }
}
realm() { return "NT"; }
