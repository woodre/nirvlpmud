#include <ansi.h>

inherit "obj/armor";
#define EN environment(this_object())
#define ME capitalize(environment(this_object())->query_name())
#define IT capitalize(environment(this_object())->query_attack()->query_name())

reset(arg) {
  if(arg || root()) return;
  ::reset(arg);
  set_short("Storm Cloak");
  set_long(
  "A huge flowing garment of fine dark material.  Blue energy of the storms\n"+
  "crackles across its surface.  You wonder if it is safe to touch.\n");
  set_ac(1);
  set_weight(2);
  set_value(15000);
  set_alias("cloak");
  set_name("the Storm Cloak");
  set_type("misc");
  set_save_flag(1);
  call_out("funks", 10);
  set_params("other|electric", 2, 5, "do_special");
}

funks(){
  int ranx;

  if(!EN || !environment(EN) | !worn) {
    call_out("funks", 50);
    return 1;
  }

  ranx = random(7);

  if(ranx == 0) {
    tell_object(EN, "Your storm cloak crackles with energy.\n");
    tell_room(environment(EN), ME+"'s cloak crackles with mysterious energy.\n");
  }
  else if(ranx == 2) {
    if(EN->query_attack()){
      if(EN->query_sp() > 4) {
      tell_room(environment(EN),
      "Tiny sparks of electricity surge from "+ME+"'s cloak and "+
  HIY+"ZAP"+NORM+" "+IT+"!\n", ({EN,EN->query_attack()}));
      tell_object(EN, "\
Tiny sparks of electricity surge from your cloak and "+HIY+"ZAP"+NORM
+" "+IT+"!\n");
       tell_object(EN->query_attack(), "\
Tiny sparks of electricity surge from "+ME+"'s cloak and "+
HIY+"ZAP"+NORM+" you!\n");
      EN->query_attack()->hit_player(random(5), "other|electric");
      EN->add_spell_point(-random(5));
    }
    }
    else {
      tell_object(EN, "Tiny sparks of electricity crackle across your cloak.\n");
      tell_room(environment(EN), "Tiny sparks of electricty crackle across "+ME+"'s cloak.\n");
    }
  }
  else if(ranx == 3) {
    tell_room(environment(EN),
    ME+"'s storm cloak ripples in the wind and thunder rolls across the sky.\n");
    if(EN->query_attack()) tell_room(environment(EN),
    IT+" glances up at the sky nervously ...\n");
  }
  else if(ranx == 5){
    tell_object(EN, "Your cloak vibrates softly with powerful magic.\n");
  }

  call_out("funks", 60+random(90));
  return 1;
}
