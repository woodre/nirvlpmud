#include <ansi.h>

reset(arg){
  if(arg) return;

  call_out("cost", 35);
  call_out("done", 305);
}

id(str){ return str == "tyborlek enchantment"; }
get(){ return 0; }
drop(){ return 1; }
can_put_and_get(){ return 0; }

reset_timers(){ 
  remove_call_out("cost");
  remove_call_out("done");
  call_out("cost", 35);
  call_out("done", 305);
}

cost(){
  if(!environment()) return;
  if(!environment()->is_player()) return;
  if(environment()->query_sp() > 10)
    environment()->add_spell_point(-5);
  tell_object(environment(), "You feel a warmth flow through your body.\n");
  call_out("cost", 35);
}

done(){
  object t;
  if(!environment()) return;
  if(!environment()->is_player()){
    destruct(this_object()); 
    return;
  }
  tell_object(environment(), 
    MAG+"\nYou feel Tyborlek's enchantment fade to nothing.\n"+NORM);
  if(environment(environment()))
  {
    t = present("tyborlek", environment(environment()));
  tell_room(environment(environment()), 
    MAG+"Tyborlek's enchantment fades from "+
    environment()->query_name() + ".\n" + NORM, ({ environment(), t }));
  destruct(this_object());
  }
}

extra_look(){  
  if(living(environment()) && (this_player() != environment()))
    return MAG+environment()->query_name()+
    " is protected by Tyborlek's enchantment"+NORM;
  else if(living(environment())) 
    return MAG+"You are protected by Tyborlek's enchantment"+NORM; 
}
