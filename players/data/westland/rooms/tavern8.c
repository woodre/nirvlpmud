/* ***********************************************
 * tavern1.c
 *
 * Creator - Data
 * 
 * Date of File Completion - 
 * 
 *
 * **********************************************/
#include "ansi.h"
#include "/players/data/defs.h"

inherit "room/room";

reset(arg)
{
  object monster;
  if(arg) 
    return ;    
  set_light(1); 
  short_desc = CYN+"INN"+NORM; 
  long_desc  = CYN+"Oil lamps light the room filled with a fog of pungent pipe smoke. Tables, all arranged in a\n"+
			   "haphazard fashion, were rough, some no more than planks on barrels. There are no chairs, only\n"+
               "benches. To the left a door stands closed, probably leading to the kitchen. To the right, a\n"+
			   "staircase, leading up to the guest rooms. The floor, with a series of paths through the litter\n"+
			   "was mottled with dark stains and spills\n"+NORM;
              
items = ({

 "lamps", "The oil lamp looks to be connected to the wall with a bronze fitting.",
 "fog", "The room is cloaked with a layer of smoke making it a little difficult to see.",
 "tables", "Tables lay scattered about, some look like they need some repair.",
 "planks", "Someone has laid a plank down to use as tables as there arent enough tables. ",
 "barrels", "Some of the barrels look old, but sturdy enough to hold the planks.",
 "benches", "Benches look old, some bent from the weight of too many customers",
 "door", "The door leads to the kitchen, perhaps you should 'knock'",
 "litter", "Various pieces of paper debree litter the ground",
 "stains", "There are stains left by spilled drinks, spit and blood on the floor. ",
 "staircase", "The staircase looks stable enough to hold the weight of a few people.",
 });


 
add_listen("main", "What are you trying to listen to?");
add_listen("sound","You hear a scraping sound");
add_listen("stream", "The stream sounds almost like a clogged nose because of how thick it is");
add_listen("forest", "The forest is silent except for the stream and an odd clicking sound");
add_listen("clicking", "The clicking sound appears to be coming from the rocks");
add_listen("rocks", "You think better than to put your head near the rocks");
add_listen("pond", "You hear the stream feeding into the pond");
add_listen("twigs", "The twigs snap beneath your boots as you step on them");
add_listen("scraping", "A sound as though claws were scraping something");
add_listen("ground", "You hear nothing but your own breathing");

add_taste("main", "What would you like to taste?");
add_taste("stream", "The stream tastes absolutely revolting, making you gag");
add_taste("rocks", "The rocks taste as though something unholy, even in life, died on them");
add_taste("pond", "The pond looks worse than the stream. You refuse to taste it");
add_taste("twigs", "The twigs taste like moldering death. You imediately spit it out");
add_taste("trees", "The trees taste so bad that you puke on yourself");
add_taste("ground", "Why on earth would you want to taste that?");

add_smell("main", "What would you like to smell?");
add_smell("stream", "The stream smells like something died in there, perhaps fish");
add_smell("rocks", "The rocks smell worse than 10 year old gym socks. You back away fast");
add_smell("pond", "The pond smells like rotting fish. Perhaps it once had some in it, but they all died");
add_smell("twigs", "The twigs smell like rotting wood");
add_smell("ground", "The ground smells like death and decay");
  
dest_dir =
  (
  { 
  /* needed to signify an array */
  "players/data/westland/rooms/tavern3.c", "stairs",
  "players/data/westland/rooms/tavern7.c", "west",
  "players/data/westland/rooms/tavern11.c", "north",
  }
 );
 }
 