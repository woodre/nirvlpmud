/* *************************************************************************
 * /players/earwax/closed/TRACKER/bin/ttitle.c
 *
 * This will give you the Tracker Pretitle
 *
 * Earwax 7/28/03 - Jareel 9/14/03
 *
 * *************************************************************************
 *
 *   Usage 'ttitle'
 *   
 *  0 PKs, 0 deaths, and a total of 0 Legendary PK Points its Feyth the Saint of Nirvana.
 *      
 *   
*/

#include "../defs.h"

status main(string arg) {
  string original;
  int Deaths, Pks, Points;
  object ob;

  ob = present(TRACKER_ID,this_player());
  Deaths = (int)ob->query_deaths();
  Pks = (int)ob->query_pks();
  Points = (int)ob->query_points();
  if (arg == "keep")
  {
    original = (string)this_player()->query_title();
    ob->set_original_title(original);
  }
  original = (string)ob->query_original_title();
  if (!original) original = "";
  
  this_player()->set_title(original + " ("
    + CYN + Pks + NORM + ":"+HIK+"PKs"+NORM+"/"+ CYN + Deaths + NORM
    + ":"+HIK+"Deaths"+NORM+"/"+ CYN + Points + NORM +":"+HIK+"Points"+NORM+")"+ NORM
    );
  write("You set your PK title.\n");
  return 1;
}
