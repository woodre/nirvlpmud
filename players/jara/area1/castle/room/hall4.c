/* Hall 4 (outside portal), Created <6/19/01> by Jara */

#include "/players/jara/misc/ansi.h"
#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Zercher Castle- Hallway";
  long_desc=
    "  The westernmost end of the hallway seems brighter here, a strange light\n"+
    "coming from the room to the north. The candlelight seems to dance over the\n"+
    "walls and there is a portrait of a beautiful young woman hanging on the\n"+
    "wall. There is an archway, carved from stone in the northern wall, and the\n"+
    "hallway leads to the east.\n";
  items=({
    "light",
    "The dim light seems to seep from the archway through the northern wall",
    "candlelight",
    "A soft glowing light",
    "stone",
    "The stone is dark in color and cold to the touch",
    "portrait",
    "The painting of a beautiful young woman hangs on the southern wall of the\n"+
    "hallway",
    "woman",
    "The woman in the portrait has black hair falling in loose curls just past\n"+
    "her shoulders. Her skin is milky white in color and her eyes are a deep\n"+
    "blue",
    "candelabras",
    "The six foot tall candelabras are made of pure silver and hold six white\n"+
    "candles",
    "candles",
    "The candles are flickering softly against the darkness and appear to have\n"+
    "been burning for some time",
    "wax", 
    "The hot wax has been dripping from the candle tip and slowly cooling\n"+
    "as it dripped to the base of the candle",
    "base",
    "The rounded base of the candle holders are filled with the cool wax",
    "holders",
    "The silver basin of the candle holders are rounded in shape and\n"+
    "collect the wax",
    "shadows",
    "The dark shadows seem to dance with the flickering light",    
    "walls",
    "The dark stone walls are cold to the touch and are well worn",
    "corners",
    "The darkness is just beyond the flickering candlelight",
    "archway",
    "The archway is carved with arcane writings",
    "writings",
    "Carved from the stone, the writing seems unreadable" });
  dest_dir=({
    PATH+"tower1","north",
    PATH+"hall3","east" });
}
