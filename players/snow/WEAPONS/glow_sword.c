/*
This weapon is a combination of glowknife.c and glass_sword.c
It casts light and hurts creatures of the darkness.
*/
 
#include "/players/snow/closed/cyber/color.h"
 
#define TP this_player()
#define TPN TP->query_name()
#define OP TP->query_attack()
#define OPN OP->query_name()
#define PIE call_other(this_player(),"query_attrib","pie")
#define ALN TP->query_alignment()
#define OPALN OP->query_alignment()
#define SWORD YELLOW+"Glowing Sword"+OFF
#define CO call_other
 
inherit "obj/weapon.c";
 
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("glowing sword");
    set_alias("sword");
    set_short(SWORD);
   set_type("sword");
    set_long(
"This sword's brilliant light will burn through any creature\n"+
"of darkness if wielded by one with a pure heart.\n");
    set_class(18);
    set_weight(2);
    set_light(3);
    set_value(500);
    set_hit_func(this_object());
}
 
weapon_hit() {
  if(ALN > 800 && PIE > random(25) && OPALN < 0)  {
    say(TPN+"'s "+SWORD+" burns a glowing trail across "+OPN+"!\n");
    write("Your "+SWORD+" burns a glowing trail across "+OPN+"!\n");
    if(check_race(OP) && PIE > random(30) ) {
      tell_room(environment(TP),
                "\n   "+BOLD+OPN+" burns in BLESSED LIGHT!"+OFF+"\n");
      OP->heal_self(-5-random(PIE/4));
      TP->add_hit_point(random(PIE/5));
    return 5;
   }
  return 2;
  }
       return;
}
 
check_race(object ob) {
  if(
    CO(ob,"id","shadowcreature") ||
    CO(ob,"id","demon") ||
    CO(ob,"id","devil") ||
    CO(ob,"id","daemon") ||
    CO(ob,"id","shadow") ||
    CO(ob,"id","spirit") ||
    CO(ob,"id","undead") ||
    CO(ob,"id","ghost") ) return 1;
  else return 0;
}
