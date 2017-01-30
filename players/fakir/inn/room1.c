#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Winespring Inn";
long_desc =
   "The porch of the Winespring Inn.  A wicker swing is attached to\n"+
   "the rafters by a braided rope on both ends, and sways gently in \n"+
   "the breeze.  A welcome mat lies before the door, and bids you\n"+
   "welcome to 'enter'.\n";

items = ({
   "porch",  "Wooden planks have been laid in a random pattern over the dirt\n"+
             "to make a dry sort of entry area for the inn.  Some call it a\n"+
             "porch, but it is really just a place to kick the mud off a pair\n"+
             "of boots before entering the inn.  A makeshift roof was added \n"+
             "a few years back by a passing carpenter to pay for a weeks room\n"+
             "and board.  The roof is well built and shingled with cedar",
   "inn",    "The first floor of the inn is built of river rock, though some\n"+
             "say the foundation was built of rock brought from the mountains\n"+
             "of mist.  The whitewashed second story juts out over the lower\n"+
             "floor all the way around.  Red roof tile, the only such roof in\n"+
             "the village, glitters in the weak sunlight, and smoke drifts\n"+
             "from the fireplace chimney",
   "swing",  "A three seat swing made from steamed willow branches woven together\n"+ 
             "in such a way that they hold their shape and add support to each\n"+
             "other", 
   "rafters","Unfinished raw wood square cut and about two spans in length. They\n"+
             "are attached to the front wall of the inn at a 4/10 pitch to easily\n"+
             "shed any heavy winter snow",
   "rope",   "A heavy, thick braided rope made from the stripped rushes found near\n"+
             "Watch Hill, a town located near the Waterwood",
   "mat",    "A grass mat purchased from a peddler",
   "door",   "Laminated wood planks painted a bright red and reinforced with thick\n"+
             "cast iron straps bolted top and bottom from the inside.  This door\n"+
             "could withstand an army of darkfriends",
});
   
             

dest_dir = ({
   "/players/fakir/inn/room4.c", "enter",
   "/room/eastroad5.c",          "wheel", 
});

}
