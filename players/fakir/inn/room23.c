#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Winespring Inn";
long_desc =
   "A simple hallway with only six doors, three to a side.  Crude wooden\n"+
   "latches secure each door in place.  There do not seem to be locks on\n"+
   "any of the doors.\n";

items = ({
   "doors",  "Wood plank doors with cross braces top and bottom",
   "latches","A sliding wooden handle with a steel shank and pin, used\n"+
             "to keep the door closed securely",
   "door",   "Wood plank door with cross braces top and bottom",
  
   
   
});

dest_dir = ({
   "/players/fakir/inn/room31.c", "latch1",
   "/players/fakir/inn/room24.c", "latch2",
   "/players/fakir/inn/room28.c", "north",
   "/players/fakir/inn/room22.c", "descend",
   
   
});

}
