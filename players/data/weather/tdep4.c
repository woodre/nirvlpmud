/******************************************************************************
 tdep4.c, written by Carador, Feb-95, rewritten by Chameloid, Nov-97, Tubmud
******************************************************************************/

/*
 * Main intention of this file:
 *
 * - give general information on how timedependent rooms work
 * - show a timedependent room with four time dependencies
 *
 */

#pragma strong_types

// The following header file defines TD_DAY4 and so on.

#include "/players/data/weather/timedep.h"



inherit "/room/room";

// Now configure the room.

void
configure() {
  ROOM::configure();

  
  // Tell the room that there should be four time phases.

  set_timedep4();

  set_short("timedependent room","in");
  
  // The long description. It's just an array of strings, one for every phase.
  
  set_long(({ "The morning is young. There is a brutz here. A ground is here, "
              "too.\n",
              "The brutz brutzes in the heat of the sun. Look at the ground, "
              "too.\n",
              "It's late in the evening and dawning. The brutz looks romantic "
              "now. Don't forget the ground.\n",
              "It's night, the brutz reflects the light of the stars. We also "
              "have a ground.\n",
           }));
  
  // First the items which are independent from the time phases.

  set_items(({
    "ground",
    "Hui! That's a beautiful ground.\n",
  }));
  
  // Now the items which can be seen during all phases but have different
  // descriptions in each phase.
  
  set_items(({
    "brutz", 
   
    // All the descriptions of the first item.  By stating TD_DAY4 as second
    // argument we set a 4-phase day, thus have to supply four descriptions.

    ({ "The brutz yawns. It's morning.\n",
       "The brutz almost melts in the sun.\n",
       "The brutz is shimmering red in the evening light.\n",
       "It reflects the white, sparkling light of the stars.\n" })
  }),TD_DAY4);
  
  // Now some items which can only be seen at certain times.  We use a 4-phase
  // day, so there are four phases denoted "dew", "day", "dawn", and "night".
  // The 4-phase day is set by stating TD_DAY4 as second argument.
  
  set_items(({
    "sun",
    "It's hot.\n"
  }),TD_DAY4,"day");

  // The same for the night.
  
  set_items(({
    "stars",
    "The stars are shining in a bright light.\n"
  }),TD_DAY4,"night");
  
  
  // Okay, we want to have stars and sun be visible in the early evening as
  // well.
  
  set_items(({
    "stars",
    "It's not very dark, so you hardly can see them.\n",
    "sun",
    "The sun almost left the sky.\n"
  }), TD_DAY4,"dawn");
  



}

