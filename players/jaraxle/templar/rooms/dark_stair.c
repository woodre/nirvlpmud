#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "a dark stair";
long_desc =
"  Here the passage stops and leads down into a long dark\n"+
"stairwell. Torches burn very low providing only minimal\n"+
"light here. A cold draft of wind rises up from the stairs.\n"+
"The dark hallway continues back to the east\n";

items = ({
"torches",
"Small wooden torches trimmed with a dark steel. They burn\n"+
"very low and flicker from the breeze",
"stairs",
"Crude stairs made of stone",
});

dest_dir = ({
  "/players/jaraxle/templar/rooms/dark_hall","east",
  "/players/jaraxle/templar/rooms/mage_room","down"
});

}

init(){
 ::init();
   this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }


