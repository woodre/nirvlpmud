#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;


set_light(1);

short_desc = "Outside of the University" ;
long_desc =
     "    You stand in front of a big building and in the middle of\n"+
     "the road.  You are surrounded by a lot of traffic but you seem\n"+
     "oblivious of it.  Your mind is all intent upon considering what\n"+
     "might be going on inside of the building:  you bet it must be\n"+
     "very interesting and stimulating.\n",

items = ({
   "building","An imponent building with a large inscription in its top part\n", 
   "inscription","         S C H O O L   O F   E N G I N E E R I N G \n",
   "road","A recently paved road, one way only",
});

dest_dir = ({
  "/players/francesco/univ/rooms/scala","enter",
  "/room/forest11.c","resign",
});

}
