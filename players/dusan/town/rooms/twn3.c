#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Muddy road.";
long_desc =	
           "   The main road curves to the north.  There seem to be   \n"+
           "more fresh tracks on the road than closer to the entrance. \n"+
           "A few shrubs grow on the roadside and, up ahead the road \n"+
           "splits off to the east and, you can see some smoke rising  \n"+
           "in the northeast. To the west leads to the entrance of the  \n"+
           "town.\n" ;

items = ({
  "road","A muddy road. It doesn't seem like it has been traveled on recently",
  "shrubs","Stunted little bushes growing along the roadside",
  "trail","A muddy road. It doesn't seem like it has been traveled on recently",
  "town","A group of shoddy wooden buildings",
  "traffic","The town road doesn't seem to have had much traffic",
  "tracks","There are a few fresh tracks in the mud but they are few and far between",
  "smoke", "A thin stream of smoke rises from the northeast",
  "town","This muddy little village can barely be called a town",
  "mud","A dark brown mud that makes up most of the road",
  "entrance","The entrance is back to the west"
});

dest_dir = ({
  "/players/dusan/town/rooms/twn5","north",
  "/players/dusan/town/rooms/twn2","west",
});

}
