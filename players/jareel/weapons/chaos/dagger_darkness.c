#include "/players/jareel/ansi.h"
inherit "/obj/weapon";

reset(arg){
    if(arg) return;
    ::reset(arg);
set_alt_name("dagger");
set_alias("dag");
set_id("dagger");

    set_name(BOLD+BLK+"Dagger"+NORM+" of "+BOLD+BLK+"Darkness"+NORM);

    set_long("This finely crafted razor sharp dagger drains\n"+
                 "all the light from the room.  Its hilt fits perfectly\n"+
                 "in your grasp.\n");
set_class(18);
    set_light(-1);
    set_type("small");
    set_weight(1);
    set_value(3000);
    set_hit_func(this_object());
}
weapon_hit(ob){
              int pain;
              object me;
              me = wielded_by;
              if(!me) me = environment();
              if(!me) return;
              if(!living(me)) return;
              if(!ob) return;
pain = random(3);
              if(pain==2){
write(BOLD+me->query_name()+"'s dagger unleashes..\n"+
         "\n"+
         "                "+BLK+"D  A  R"+NORM+BOLD+"  K  N  E"+BLK+"  S  S  !  !\n"+ 
         "\n"+NORM);
say(BOLD+me->query_name()+"'s dagger..\n"+
         "\n"+
         "                "+BLK+"D  A  R"+NORM+BOLD+"  K  N  E"+BLK+"  S  S  !  !\n"+
         "\n"+NORM);
me->add_spell_point(random(6)+6);
ob->add_spell_point(-random(6)+6);
return 6;
}
}
