#include "/players/guilds/bards/def.h"

inherit "obj/treasure";
int strength;

extra_look(){
        return environment()->query_name()+"'s body is "+
        HIC+"digesting"+NORM+" rapidly";
}

id(str) { return str=="bardic_digestion_object"; }

query_strength() { return strength; }

add_strength(x) { strength += x; }

start_regen() {
  remove_call_out("regen");
  call_out("regen",2);
}

regen() {
  object ob;
  int is_bard;
  ob=environment();
  if(!ob || !ob->is_player()) {
    destruct(this_object());
    return;
  }
  if(strength<=0) {
    tell_object(ob,HIC+"Your Bardic Digestion has been exhausted.\n"+NORM);
    destruct(this_object());
    return;
  }
  if(present("bard_obj", ob)) is_bard = 1;
  if(ob->query_stuffed()) ob->eat_food(-(is_bard?1+random(2):random(2)));
  if(ob->query_soaked()) ob->drink_soft(-(is_bard?1+random(2):random(2)));
  else
  if(!random(10)) {
    if(strength>50)
      tell_object(ob,HIC+"The power of Bardic Digestion courses through you.\n"+NORM);
    else
      tell_object(ob,HIC+"Your digestion is beginning to fade.\n"+NORM);
  }
  strength-=2;
  call_out("regen",2);
}

drop()
{
        return 1;
}

get()
{
        return 1;
}

can_put_and_get()
{
        return 0;
}
