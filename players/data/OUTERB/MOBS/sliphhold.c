/* ***********************************************
 * room20.c
 *
 * Creator - Data
 * 
 * Date of File Completion - 11/20/05
 * 
 *
 * **********************************************/

#include "/players/data/defs.h"
#define OWN capitalize(owner)
inherit "room/room";

string own;

reset(arg){
  if(arg) return;
  own = "noone";

short_desc = "Inside the Sliph (traveling)"+own;


long_desc =
        "The inside of the Silver Sliph \n";
	
}

get(){ return 0; }
drop(){ return 1; }
set_own(str) { own = str; }
query_dont_clean_obs_here() { return 1; }