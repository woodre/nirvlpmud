#include "/players/wocket/closed/ansi.h"
inherit "/obj/treasure.c";
object sucker;

reset(arg){
set_id("poison");
set_alias("blood");
set_long("It is the venomous blood of the pojoui.\n");
}

drop(){ return 1; }

init(){
  if(environment(this_object()) == this_player()){
sucker = this_player();
call_out("poisonme",40);
}
}

poisonme(){
  tell_object(sucker,RED+"Your skin begins to boil and burn as the venom rips through you.\n"+NORM);
sucker->add_hit_point(-random(50));
  call_out("poisonme",random(70));
}
