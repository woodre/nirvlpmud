inherit "/obj/treasure.c";

#include "/players/jareel/ansi.h"

object poisenpain;

reset(arg){
set_id("poison");
set_alias("ooze");
set_long("It is the poison ooze of the Legendary Dragon Necronos.\n");
}

drop(){ return 1; }

init(){
  if(environment(this_object()) == this_player()){
poisenpain = this_player();
call_out("poisonme",40);
}
}

poisonme(){
  tell_object(poisenpain,BOLD+GRN+"Your skin begins to boil and burn as the acid rips through you.\n"+NORM);
poisenpain->add_hit_point(-random(5));
  call_out("poisonme",random(70));
}
