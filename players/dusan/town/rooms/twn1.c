#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Muddy road.";
long_desc =	
           "While walking along the muddy trail this town calls a \n"+
           "main road.  An eerie silence seems to blanket the area. \n"+
           "No children play here and there aren't any villagers in \n"+
           "sight.  The only thing that breaks this silence is the \n"+
           "faint howl of the wind through the shoddy wooden structures\n"+
           "that lie further to the east. \n" ;

items = ({
  "road","A muddy road. It doesn't seem like it has been traveled on recently",
  "structures","Various poorly made wooden buildings",
  "trail","A muddy road. It doesn't seem like it has been traveled on recently",
  "town","A group of shoddy wooden buildings to the east",
  "silence","A uneasy silence hangs in the area",
  "buildings","Wooden buildings to the east",
  "children","You don't see any children playing here",
  "wind","The wind howls through the structures ahead",
});

dest_dir = ({
  "/players/dusan/town/rooms/room1","west",
  "/players/dusan/town/rooms/twn2","east",
});

}
