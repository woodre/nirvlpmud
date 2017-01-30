#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Muddy Trail.";
long_desc =	
           "   Brown whilted grass sprouts up from the dark earth, and   \n"+
           "the road seems a lot less traveled.  A few strangeled bushes\n"+
           "sprout here and there along the road, and a foul smell waifts  \n"+
           "in from the wooden building to the east.  To the west the road\n"+
           "curves toward the north. \n" ;

items = ({
  "road","A muddy road that leads through the town",
  "trail","A trail of packed earth that leads to the east",
  "bushes","Small scraggly shrubs",
  "grass","Hearty prickly crab grass",
  "weeds","Withered and brown, these weeds still cling to life",
  "mud","A dark brown mud that makes up most of the road",
  "building","A shabby wooden building to the east there seems to be somethings hanging in front of it",
  "smell","A strong pungent odor blows in from the east",
  "earth","Rich dark soil",
});

dest_dir = ({
  "/players/dusan/town/rooms/twn7","west",
  "/players/dusan/town/rooms/tannery","east",
  "/players/dusan/town/rooms/twn5","south",
});

}
