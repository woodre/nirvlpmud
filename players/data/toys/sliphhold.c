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

string owner;

reset(arg){
  if(arg) return;
  owner = "noone";
}

set_short()
{ 
"Inside the Silver Sliph (traveling)"; 
}

set_long(
        "A stick that is used to bonk people on the head. It is once said that \n"+
        "you get bonked on the head with this, your soul is forever gone, and \n"+
        "you will do whatever this pimp says for you to do. If you want freedom \n"+
        "then you better get to work. \n");
	}	

id(str){ return str == "mage room" || str == owner+"'s mage_room"; }
get(){ return 0; }
drop(){ return 1; }
set_owner(str){ owner = str; }


query_dont_clean_obs_here() { return 1; }