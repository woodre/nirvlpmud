#include "/players/fred/mages/defs.h"

inherit "room/room";

reset(arg){ 
  if(arg) return;
 if(!present("dummy")) {
   MO(CO("players/fred/mages/obj/dummy"), TO); }
  set_light(1);
  short_desc = "The Guild Haven";
  long_desc = "A small practice arena where Black Circle Mages can test their\n"+
              "fighting skills on the Power Gauge provided here. There is\n"+
              "a sign nailed to the wall next to the guage.\n";
  
  items=({
  "sign",
  "           Power Guage\n"+
  "*************************************\n\n"+
  "Weak attack - - - - - - - - -  Yellow\n"+
  "Average attack - - - - - - - -  Green\n"+
  "Good attack - - - - - - - - - -  Blue\n"+
  "Strong attack - - - - - - - - Magenta\n"+
  "Powerful attack - - - - - - - -   Red\n\n"+
  "*************************************\n",});

  dest_dir = ({"/players/fred/mages/rooms/teleport", "up",
              "/players/fred/mages/rooms/advance", "down"});}

