#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Muddy Trail.";
long_desc =	
           "   A dark green grass grows everywhere.  A few flowers and  \n"+
           "a couple healthy bushes dot the area.  The road disappears \n"+
           "towards the small stone tower to the north.  There is a lack  \n"+
           "of the ever-present mud.  To the north the trail leads to a \n"+
           "tower and to the east leads back towards town. \n" ;

items = ({
  "road","A muddy road that leads through the town",
  "trail","A trail of packed earth that leads to the north",
  "bushes","Small healthy shrubs",
  "grass","Healthy dark green grass",
  "mud","There seems to be a lack of mud in this area",
  "tower","A solid stone tower that lies to the north",
  "flowers","Blue, red, and yellow flowers dot the landscape",
  "earth","Rich dark soil",
  "town","The main portion of the town lies to the east of here",
});

dest_dir = ({
  "/players/dusan/town/rooms/tower","north",
  "/players/dusan/town/rooms/twn6","east",
});

}
