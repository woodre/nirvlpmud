/* *************************************************************************
 * /players/earwax/closed/TRACKER/bin/tpretitle.c
 *
 * This will give you the Tracker Pretitle
 *
 * Earwax 7/28/03 - Jareel 9/14/03
 *
 * *************************************************************************
 *
 *   Usage 'tpretitle'
 *   
 *  0 PKs, 0 deaths, and a total of 0 Legendary PK Points its Feyth the Saint of Nirvana.
 *      
 *   
*/

#include "../defs.h"

status main(string arg) {
  int Deaths, Pks, Points;
  object ob;

  ob = present(TRACKER_ID,this_player());
  Deaths = (int)ob->query_deaths();
  Pks = (int)ob->query_pks();
  Points = (int)ob->query_points();
  
  /* because of how set_pretitle() works, can't absorb ansi well enough */
  this_player()->set_pretitle("RECORD: "
    + Pks + " PKs/"+Deaths+" deaths/"+Points
    + " points:"+NORM+NORM);
  write("You set your PK pretitle.\n");
  return 1;
}
