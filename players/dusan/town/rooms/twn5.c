#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Muddy Trail.";
long_desc =	
           "   A few small bushes dot the side of the road, and here  \n"+
           "there a some crab grass and weeds stick up from the mud. \n"+
           "A well worn trail leads off to the east towards a small  \n"+
           "stout stone building and the main road continues to the  \n"+
           "north and a foul smell drifts from the northeast. \n" ;

items = ({
  "road","A muddy road that leads through the town",
  "trail","A trail of packed earth that leads to the east",
  "bushes","Small scraggly shrubs",
  "grass","Hearty prickly crab grass",
  "weeds","Withered and brown, these weeds still cling to life",
  "mud","A dark brown mud that makes up most of the road",
  "building","A stout stone building to the east",
  "smell","A strong pungent odor blows in from the northeast",
});

dest_dir = ({
  "/players/dusan/town/rooms/twn6","north",
  "/players/dusan/town/rooms/smithy","east",
  "/players/dusan/town/rooms/twn3","south",
});

}
