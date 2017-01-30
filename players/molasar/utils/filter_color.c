
/*
 * FILTER_COLOR (4/15/94)
 * If a player has their color_ok flag set let them see ansi color.
 * This file needs to be included in /obj/simul_efun.c
 */

#include "/players/boltar/things/esc.h"
#define NORM esc+"[2;37;0m"      /* Puts everything back to normal */

string filter_color(string str, string color, object player) {
   if(!player)
     player = this_player();
   if(player->query_color()) 
     return color+str+NORM;
   else
     return str;
}


