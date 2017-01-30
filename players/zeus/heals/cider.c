/********************** 6 shot 25/25 portable intox 10 tox heal
*  10*6=60               * 1200 coins
*  25*6=150             *
*  60/150=.4            *
*  .4 = 8per pt          *
*  8*150 = 1200       *
***********************/
inherit "obj/treasure.c";
#include "/players/zeus/closed/all.h"
int hits;

reset(arg) {   if(arg) return;   hits = 6;  }

id(str){ return str == "bottle" || str == "bottle of cider" ||
str == "cider" || str == "hard cider"; }

short(){ return "A bottle of hard cider ["+hits+"]"; }

long(){  write(
"This is a clear bottle filled with dark yellow hard cider.  There is\n"+
"no label on the bottle, making you wonder just who made it.  There\n"+
"are "+hits+" 'drink's of cider left in the bottle.\n"); }

is_heal(){			return "alcohol";  }
query_save_flag(){	return 1;       }
query_value(){		return (hits * 100); }
get(){				return 1;       }
query_weight(){		return 1;       }

void init(){ ::init(); add_action("drink_cmd", "drink"); }

drink_cmd(str){
 if(str != "cider" && str != "hard cider") return 0;
 if(!"/players/zeus/newbie/check.c"->check()) return 1;
 if(!call_other(this_player(),"drink_alcohol", 10)) return 1;
 write("You take a drink of the hard cider, the wonderful beverage\n"+
	 "filling your senses with the faint taste of apples.\n");
 hits--;
 if(0 == hits){
   write(BOLD+
	   "You empty the bottle of cider, disgarding the bottle.\n"+NORM);
   destruct(this_object());
   call_other(this_player(),"recalc_carry");
 }
 return 1;
}

