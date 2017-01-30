#include <ansi.h>
inherit "/obj/monster";
  int count;
reset(arg) {
 ::reset(arg);
 if(arg||root()) return;
 set_name("Skeleton");
 set_alias("pile of bones");
 set_alt_name("bones");
 set_short("A Pile of Bones *animated*");
 set_long("An old pile of bones that has been brough back to 'life'.\n");
 set_ep(0);
 set_alias("skeleton");
 set_can_kill(1);
 set_ac(0);
 set_wc(22);
 set_hp(180);
 count = 0;
 enable_commands();
 set_dead_ob(this_object());
 set_message_hit(({
    HIK+"ANNIHILATED"+NORM, " with powers of "+HIK+"UnDeath"+NORM,
    HIK+"destroyed"+NORM, " relentlessly",
    HIK+"savagely tortured"+NORM, " with a quick flurry of blows",
    HIK+"grasped"+NORM, ", draining "+HIM+"life-force"+NORM,
    HIK+"beat"+NORM, " hard",
    "knocked", " off-balance",
    "tapped", " lightly",
  }));
  set_weapon_params(({"other|evil",22,0}));
 call_out("stuff", 1);
}

int id(string str)
{
  return (::id(str)||str=="pile");
}

stuff(){
  if(!this_object()->query_attack()){
    tell_gone();
    destruct(this_object());
    return 1;
  }
  if(count >= 7){
    tell_gone();
    destruct(this_object());
    return 1;
  }
  count++;
  call_out("stuff", 3);
  return 1;
}

tell_gone(){
  tell_room(environment(this_object()),
  this_object()->short()+" suddenly stops moving.\n"+
  "The skeleton falls to the ground and shatters into tiny pieces.\n");
  return 1;
}

monster_died(){
 tell_room(environment(this_object()),
 this_object()->short()+" shatters into tiny pieces.\n");
 destruct(present("corpse", environment(this_object())));
 return 0;
}
