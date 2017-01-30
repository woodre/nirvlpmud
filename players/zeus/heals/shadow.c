/* 3 shot, 50/50 food && stuff - intox 7 */

inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
int x, type;
reset(arg){

  x = 6;
  type = 1;
  set_id("whisp");
  set_alias("shadow");
  set_weight(1);
}

short(){
  if(type == 1)
    return HIW+"A whispy shadow"+NORM;
  else if(type == 2)
    return BOLD+BLK+"A whispy shadow"+NORM;
}

long(){
  write(
"What you hold in your hand looks like a soft, white shadow.  It is\n"+
"very soft, and slightly bendable.  The strange object seems to have\n"+
"healing properties.  To make use of them, 'embrace shadow'. You\n"+
"sense that you could embrace the shadow "+x+" more times.\n"); 
}

query_value(){  return (x * 1000); }
is_heal(){	if(!random(2)) return "food";  else return "soak";  }
set_type(x){ type = x; }
query_save_flag(){	return 1;  }

void init(){ ::init();	add_action("heal_cmd", "embrace"); }

heal_cmd(str){
  if(str != "shadow") return 0;
  if(!present(this_object(), this_player())) return 0;
  if(!this_player()->eat_food(4) || !this_player()->drink_soft(4)) return 1;
  if(1 == type)
    write(HIW+"You embrace the shadow...   and feel healed.\n"+NORM);
  else if(2 == type)
    write(BOLD+BLK+"You embrace the shadow...   and feel healed.\n"+NORM);
  this_player()->heal_self(50);
  x -= 1;
  if(!x)
  {
    if(1 == type)
      write(HIW+"The whispy shadow fades into nothing...\n"+NORM);
    else if(2 == type)
      write(BOLD+BLK+"The whispy shadow fades into nothing...\n"+NORM);
    local_weight = 0;
  	this_player()->recalc_carry();
	destruct(this_object());
  }
  return 1;
}
