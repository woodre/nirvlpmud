#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = BLU+"A bug house"+NORM;
   long_desc =
    "     The door swings and closes behind you.  Suddenly some chittering\n"+
    "sound becomes loud.  Something rustles over your feet.  When your eyes\n"+
    "finally adjust to the gloom, you notice the dead insects all over the\n"+
    "floor.  You have entered a bug-house, in the corner there is a strange\n"+
    "looking bed.\n";
   
   items = ({
         "door","The door to the house swings closed as you enter",
         "bugs","Dead bugs are smashed on the floor",
         "house","The house is filled with dead bugs all over the place",
         "floor","The floor is covered with dead bugs",
         "wall","The wall is covered with gourd",
          });

   dest_dir = ({
         "/players/brittany/xanth/garden.c","out",
              });
}
