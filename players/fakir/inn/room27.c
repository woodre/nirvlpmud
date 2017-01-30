#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Winespring Inn";
long_desc =
   "The end of a hallway with only six doors, three to a side.  Crude\n"+
   "wooden latches secure each door in place.  There do not seem to\n"+
   "be locks on any of the doors.\n";

items = ({
   "doors",  "Wood plank doors with cross braces top and bottom\n",
   "latches","A sliding wooden handle with a steel shank and pin, used\n"+
             "to keep the door closed securely",
   "door",   "Wood plank door with cross braces top and bottom\n",
  
   
   
});

dest_dir = ({
   "/players/fakir/inn/room29.c", "latch5",
   "/players/fakir/inn/room26.c", "latch6",
   "/players/fakir/inn/room28.c", "south",
   
   
});

}
