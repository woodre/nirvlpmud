/**********************  5 shot 10/50 portable stuff 10 tox heal
*  10*5=50            *  1200 coins
*  30*5=150           *
*  60/150=.4          *
*  .4 = 8per pt       *
*  8*150 = 1200       *
***********************/
inherit "obj/treasure.c";
#include "/players/zeus/closed/all.h"
int hits;

reset(arg) {   if(arg) return;   hits = 5;  }

id(str){ return str == "meat" || str == "dried meat"; }

short(){ 
  if(environment() == this_player())
    return "Some dried meat ["+hits+"]";
  else 
    return "Some dried meat";
}

long(){  
  write(
"This tasty looking piece of dried meat is ready to 'eat'.  It has a\n"+
"very tangy aroma to it, as though it was marinated in a very tasty\n"+
"sauce.  Looking at it however, you are not sure exactly what kind of\n"+
"meat it is.  There are "+hits+" bites left of the meat.\n"); 
}

is_heal(){			return "stuff";  }
query_save_flag(){	return 1;       }
query_value(){		return (hits * 200); } /* 80% */
get(){				return 1;       }
query_weight(){		return 1;       }

void init(){ ::init(); add_action("eat_cmd", "eat"); }

eat_cmd(str){
  if(str != "meat" && str != "dried meat") return 0;
  if(!this_player()->eat_food(10)) return 1;
  write("You take a bite of the dried meat.\n"+
    "It feels good in your stomach.\n");
  this_player()->add_spell_point(50);
  this_player()->add_hit_point(10);
  hits--;
  if(0 == hits)
  {
    write(BOLD+"You finish off the piece of meat.\n"+NORM);
    destruct(this_object());
    call_other(this_player(),"recalc_carry");
  }
  return 1;
}


