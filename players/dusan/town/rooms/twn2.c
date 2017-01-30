#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Muddy road.";
long_desc =	
           "   The main road of this town doesn't seem to have had  \n"+
           "much traffic as of late.  The tracks and ruts in the mud \n"+
           "are mostly old,  if not for the few fresh tracks here and\n"+
           "there it would be easy to believe this town was completely \n"+
           "abandoned.  A side street branches off to the south and, a \n"+
           "shoddy wooden house is to the north.  To the east and west \n"+
           "the main road continues. \n" ;

items = ({
  "road","A muddy road. It doesn't seem like it has been traveled on recently",
  "house","A wooden house to the north that looks like a large shack",
  "trail","A muddy road. It doesn't seem like it has been traveled on recently",
  "town","A group of shoddy wooden buildings",
  "traffic","The town road doesn't seem to have had much traffic",
  "tracks","There are a few fresh tracks in the mud but they are few and far between",
  "ruts", "Groves in the road made by wagon wheels all of them are old",
  "town","This muddy little village can barely be called a town",
  "street","A small street branches off to the south",
  "wheels","The ruts in the road seem to have been made by wagon wheels",
  "mud","A dark brown mud that makes up most of the road",
  "groves","Ruts in the road made by wagon wheels"
});

dest_dir = ({
  "/players/dusan/town/rooms/house","north",
  "/players/dusan/town/rooms/twn1","west",
  "/players/dusan/town/rooms/twn3","east",
  "/players/dusan/town/rooms/twn4","south",
});

}
