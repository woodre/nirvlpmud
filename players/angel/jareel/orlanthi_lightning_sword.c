#include "/players/jareel/define.h"
inherit "/obj/weapon";

reset(arg){
  if(arg) return;
  ::reset(arg);
  
  set_alt_name("sword");
  
 
  set_short(BOLD+"Ligntning"+NORM+" sword");
  set_long(
    "Raw electrical energy dances over the blade, arching tendrils\n"+
    "of light to and fro.  The weapons hilt seems to be forged from\n"+
    "a runic metal, possibly silver.\n");

  set_class(19);
  set_weight(1);
  set_light(1);
  set_type("sword");
  set_value(5000);
  set_hit_func(this_object());
}
 
weapon_hit(ob){
    int shocker;
    object me;
    me = wielded_by;
    if(!me) me = environment();
    if(!me) return;
    if(!living(me)) return;
    if(!ob) return;
    shocker = random(3);    
    
        if(shocker==0){
           write(BOLD+BLINK+"\n"+
             "Lightning"+NORM+" crackles over "+ob->query_name()+"'s body!!!\n");
             return 5;
             ob->add_spell_point(-random(8));

}
        if(shocker==1){
           write(BOLD+BLINK+"\n"+
             "Lightning"+NORM+" dances down the blade!\n");
             ob->add_spell_point(-random(6));
        
}
        if(shocker==2){
           write(BOLD+BLINK+"\n"+
             "Lightning"+NORM+" dances up "+me->query_name()+"'s arm!\n");
             ob->add_spell_point(-random(3));
}
}
