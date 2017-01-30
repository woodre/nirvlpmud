/* ***********************************************
 * room1.c
 *
 * Creator - Data
 * 
 * Date of File Completion - 7/29/2004
 * 
 *
 * **********************************************/
#include "ansi.h"

inherit "room/room";

reset(arg)
{
  object monster;
  if(arg) 
    return ;    
  set_light(0); 
  short_desc = HIK+"Outer Boundary"+NORM; 
  long_desc  = "Further into this forest there is a murky pond being fed by the\n"+
               "stream. Twigs and rocks litter the ground, making walking difficult.\n"+
			   "A scraping sound can be heard.\n"+NORM;

items=(
 {
 "forest", "Large trees can be seen towards the borders",
 "trees", "The trees are tall and weathered. Some are on the ground, all are dead",
 "ground", "The ground is covered in rocks and twigs",
 "rocks", "The rocks are somewhat large, and the clicker's claws scrape against them",
 "twigs", "Broken pieces from tree branches lay on the ground",
 "pond", "The pond is very filthy, and one would think not to drink it. Dead fish float on the top",
 "stream", "The stream is just as filthy as the pond. Its leads northward",

 }
);
 
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
  "players/data/OUTERB/ROOMS/room6.c", "north",

  }
  );
  monster = clone_object("players/data/OUTERB/MOBS/gripper.c");
  move_object(monster,this_object());
  monster = clone_object("players/data/OUTERB/MOBS/gripper.c");
  move_object(monster,this_object());
} 