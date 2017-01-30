#include <ansi.h>
inherit "obj/treasure.c";
int hits;

reset(arg) {   if(arg) return;   hits = 3;  }

id(str){ return str == "berries" || str == "basket" || 
str == "basket of berries"; }

short(){ return "A basket of "+MAG+"berries"+NORM; }

long(){  
  write(
    "This is an old white wicker basket with berries in it.\n"+
    "Each of the berries looks extremely tasty and delicious.\n"+
    "You may eat the berries in order to feel better.\n");
}

query_save_flag(){   return 1;            }
query_value(){       return (hits * 275); }
get(){               return 1;            }
query_weight(){      return 1;            }

void init(){ ::init(); add_action("eat_cmd", "eat"); }

eat_cmd(str){
  if(str != "berries") return 0;
  if(!present(this_object(), this_player())) return 0;
  if(!this_player()->eat_food(5) || !this_player()->drink_soft(5)) return 1;
  write("You eat some of the berries from the basket.\n"+
    "They taste great and leave you wanting more.\n");
  this_player()->add_spell_point(50);
  hits--;
  if(0 == hits)
  {
    write("You toss away the empty basket.\n");
    local_weight = 0;
    this_player()->recalc_carry();
    destruct(this_object());
  }
  return 1;
}
