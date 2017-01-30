#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Winespring Inn";
long_desc =
   "A steep flight of sturdy wooden steps lead to the upper level of the\n"+
   "inn where rooms can be had for a modest fee.  Lit, half burned tapers\n"+
   "rest in brass sconces attached to the wall of the stairway. The eighth\n"+
   "step ends in a landing which turns to the right.  An oil lamp burns on\n"+
   "a small upright table in a corner of the landing.\n";

items = ({
 "steps",     "Slightly worn in the center and obviously having seen a lot of use,\n"+
              "they still remain in good condition.  Small dark stains spot several\n"+
              "of the treads and you wonder who may have lost his life here at one\n"+
              "time",
 "rooms",     "From this point you cannot see the rooms",
 "tapers",    "White wax candles twelve snitches in length when new, most are now\n"+
              "burned down to half that.  The flame on each sputters as it burns\n"+
              "due in part to the poor quality of the wax and the cheap flaxen wick",
 "sconces",   "A projecting candlestick holder.  These are made of brass and have a\n"+
              "small mirror on the upright bracket to help reflect the flickering\n"+ 
              "light of the candle",
 "wall",      "The stairwell walls are made of rock up to the landing",
 "stairway",  "Narrow and steep.  The shadows created by the flickering candles\n"+ 
              "chase each other across the walls",
 "step",      "Slightly worn in the center and obviously having seen a lot of use",
 "lamp",      "A simple but efficient glass reservoir of oil having a cotton wick\n"+
              "pushed up through a hollow glass stopper", 
 "table",     "Fully half a span high it fits nicely into the corner",
 "landing",   "A level space half a span by three quarters at the top of the eighth\n"+
              "stair", 
});

dest_dir = ({
   "/players/fakir/inn/room13.c", "west",
   "/players/fakir/inn/room22.c", "climb",
   
   
});

}
