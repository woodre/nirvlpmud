#include <ansi.h>
inherit "/obj/treasure.c";
int duration;
reset(arg){

  duration = 4;
  set_id("apple");
  set_short(GRN+"An apple of purity"+NORM);
  set_long(
"  This dark green apple is flawless.  Its skin is perfectly smooth,\n"+
"reflecting the light that it catches.  The small stem protrudes out\n"+
"from the top of the apple about an inch, curving to the side.  He\n"+
"who eats of the apple of purity will be reinvigorated and filled\n"+
"with renewed hunger and vigor.\n");
  set_weight(1);
  set_value(1430);
}

void init(){
  ::init();
  add_action("eat_cmd", "eat");
}

eat_cmd(str){
  if(str != "apple") return 0;
  if(!present(this_object(), this_player())) return 0;
  write(GRN+"You take a bite of the apple of purity...\n"+NORM);
  say(this_player()->query_name()+" takes a bite of an apple.\n");
  this_player()->heal_self(50);
  local_weight = 0;
  short_desc = 0;
  long_desc = 0;
  name = "invis_apple";
  this_player()->recalc_carry();
  call_out("effect", 4);
  return 1;
}

effect(){
  environment()->drink_alcohol(-1);
  environment()->drink_soft(-4);
  environment()->eat_food(-4);
  duration--;
  if(duration)
    call_out("effect", 4);
  else
    destruct(this_object());
}

drop(){ if(!local_weight) return 1; return 0; }
