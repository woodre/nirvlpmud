/**********************
*   8*5=40            *  5 shot 10/50 portable intox 8 tox heal
*   5*30=150          *  1950 coins
*   40/150=,266       *
*   .266=13pp         *
*   13*150=1950       *
***********************/
inherit "obj/treasure.c";
#include "/players/zeus/closed/all.h"
int hits;

reset(arg) {   if(arg) return;   hits = 5;  }

id(str){ return str == "bottle" || str == "bottle of brandy" ||
str == "brandy"; }

short(){ 
  if(environment() == this_player() && hits)
    return "A bottle of brandy ["+hits+"]";
  else if(hits)
    return "A bottle of brandy";
  else
    return "An empty bottle";
}

long(){  
  if(!hits)
  {
    write(
      "This is a dark green bottle.  There is no label on the outside.\n"+
      "The strong smell of brandy lingers around it, however there is\n"+
      "none left in the bottle.\n");
  }
  else
  {
    write(
"This is a dark green bottle filled with brandy.  There is no label\n"+
"on the bottle, making you curious of its origins.  It is very strong\n"+
"stuff, to be sure.  There are "+hits+" 'drinks left.\n"); 
  }
}

is_heal(){			return "alcohol";  }
query_save_flag(){	return 1;       }
get(){				return 1;       }
query_weight(){		return 1;       }
query_value(){
  if(hits)
    return (hits * 200);
  else 
    return 5;
}

void init(){ ::init(); add_action("drink_cmd", "drink"); }

drink_cmd(str){
  if(!hits) return 0;
  if(str != "brandy" && str != "bottle of brandy") return 0;
  if(!this_player()->drink_alcohol(8)) return 1;
  write("You take a drink of the brandy.  The strong\n"+
    "liquid fills your body with warmth.\n");
  hits--;
  this_player()->add_spell_point(50);
  this_player()->add_hit_point(10);
  if(0 == hits)
    write(BOLD+"You finish the brandy in the bottle.\n"+NORM);
  return 1;
}
