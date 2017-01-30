#include "/players/guilds/bards/def.h"

inherit "obj/treasure";
int strength;

extra_look(){
        return environment()->query_name()+"'s body is "+
        HIY+"regenerating"+NORM+" rapidly";
}

id(str) { return str=="bardic_regeneration_object"; }

query_strength() { return strength; }

add_strength(x) { strength += x; }

start_regen() {
  remove_call_out("regen");
  call_out("regen",2);
}

regen() {
  object ob;
  ob=environment();
  if(!ob || !ob->is_player()) {
    destruct(this_object());
    return;
  }
  if(strength<=0) {
    tell_object(ob,HIM+"Your Bardic Regeneration has been exausted.\n"+NORM);
    destruct(this_object());
    return;
  }
  if(present("bard_obj"),ob)
    ob->add_hit_point(2);
  else
    ob->add_hit_point(1+random(2));
  if(!random(10)) {
    if(strength>50)
      tell_object(ob,HIM+"The power of Bardic Regeneration courses through you.\n"+NORM);
    else
      tell_object(ob,HIM+"Your regeneration is beginning to fade.\n"+NORM);
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
