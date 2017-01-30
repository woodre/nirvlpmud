#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Winespring Inn";
long_desc =
   "Unlike the wooden stairs up and down, the landing is made of a close laid\n"+
   "stone, almost like the pieces of a puzzle.  The workmanship is of a curious\n"+
   "sort...unlike any you have ever seen.  A tall table sits in the corner with\n"+
   "a glass oil lamp resting on top.  The stairway leads up to a long hall with\n"+
   "conjoining rooms or down to the commonroom of the inn.  Half burned tapers\n"+
   "sputter and smoke in brass sconces attached to the walls both up and down.\n";
   

items = ({
 "stairs",    "Slightly worn in the center and obviously having seen a lot of use,\n"+
              "they still remain in good condition.  Dark blood stains spot several\n"+
              "of the treads and you wonder who may have lost his life here at one\n"+
              "time",
 "rooms",     "Closed doors with wooden latches",
 "tapers",    "White wax candles twelve snitches in length when new, most are now\n"+
              "burned down to half that.  The flame on each sputters as it burns\n"+
              "due in part to the poor quality of the wax and the cheap flaxen wick",
 "sconces",   "A projecting candlestick holder.  These are made of brass and have a\n"+
              "small mirror on the upright bracket to help reflect the flickering\n"+ 
              "light of the candle",
 "walls",     "The stairway walls are made of rock up to the hall and down to the\n"+
              "commonroom door",
 "stairway",  "Narrow and steep.  The shadows created by the flickering candles\n"+ 
              "chase each other across the walls",
 "step",      "Slightly worn in the center and obviously having seen a lot of use",
 "lamp",      "A simple but efficient glass reservoir of oil having a cotton wick\n"+
              "pushed up through a hollow glass stopper", 
 "table",     "Fully half a span high it fits nicely into the corner",
 "landing",   "Unlike the wooden stairs up and down, the landing is made of close laid\n"+
              "stone, almost like the pieces of a puzzle.  The workmanship is of a curious\n"+
              "sort...unlike any you have ever seen.  A tall table sits in the corner with\n"+
              "a glass oil lamp resting on top",
 "stone",     "Colored stones with a flat rough surface set almost like the pieces of a\n"+
              "puzzle",
 "commonroom","You cannot see the commonroom from here",

});
dest_dir = ({
   "/players/fakir/inn/room20.c", "descend",
   "/players/fakir/inn/room23.c", "climb",
   
   
});

}
