#include "/players/jareel/ansi.h"
inherit "/obj/weapon";

reset(arg){
    if(arg) return;
    ::reset(arg);
    set_alt_name("drakesword");
    set_alias("bastard sword");
  set_id("bastard sword");
    set_name("The "+BOLD+BLU+"Drakesword"+NORM+"");
    set_long("This finely crafted bastard sword is razor sharp.\n"+
  "The hilt is rather plain in desigh but reflects\n"+
  "an eerie blue glow\n");
set_class(19000);
    set_weight(2);
    set_type("sword");
    set_weight(2);
    set_value(3000);
    set_hit_func(this_object());
}


query_save_flag(){ return 1; }

weapon_hit(ob){
              int pain;
              object me;
              me = wielded_by;
              if(!me) me = environment();
              if(!me) return;
              if(!living(me)) return;
              if(!ob) return;
pain = random(3);
        if(pain==0){
write("The"+BOLD+BLU+" Drakesword"+NORM+" drians you as it makes you stronger.\n");
me->add_hit_point(-4);
me->add_spell_point(3);
return 50000;
}
       if(pain==1){
write("The"+BOLD+BLU+" Drakesword"+NORM+" drians you as it makes you stronger.\n");
me->add_hit_point(-5);
me->add_spell_point(4);
return 50000;
}
       if(pain==2){
write("The"+BOLD+BLU+" Drakesword"+NORM+" drians you as it makes you stronger.\n"+
"Your "+BOLD+BLU+"Drakesword"+NORM+" plunges deep into "+ob->query_name()+"!\n");
  say(me->query_name()+"'s "+BOLD+BLU+"Drakesword"+NORM+" plunges deep into "+ob->query_name()+"!\n");
me->add_hit_point(-3);
me->add_spell_point(random(8));
ob->add_spell_point(-random(8));
return 50000;
}
}
