inherit "room/room";
 
reset(arg) {
  if(arg) return;
  set_light(1);
  long_desc = 
"  This is Trix Plaza, where TrixTown Main Road crosses TrixTown 2nd Street.\n"+  
"You can go everywhere from here.\n";
  short_desc = "Trix Plaza";
  dest_dir = ({ "/players/trix/castle/town/2str1n.c", "north",
                "/players/trix/castle/town/2str1s.c", "south",
                "/players/trix/castle/town/mainroad3.c", "west",
                "/players/trix/castle/town/mainroad2.c", "east"});
}
