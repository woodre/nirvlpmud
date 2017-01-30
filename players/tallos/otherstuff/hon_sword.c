/*
A weapon that uses player level to determine how well it works.
Found on /pl/s/MONSTERS/icingdeath3.c and approved :)
*/
 
/*
Updated by Illarion to account for the now extra stats and 
extra levels that players can now gain.  Approved by Fred.
*/

#define MEAT this_player()->query_attack()
#define MEATN capitalize(MEAT->query_name())
#define TPN capitalize(this_player()->query_name())
#define TPL this_player()->query_level()
#define TPXL this_player()->query_extra_level()
#define GEN this_player()->query_possessive()
#define TP this_player()
#define TPS call_other(TP,"query_attrib","str")
#define TPI call_other(TP,"query_attrib","int")
#define TPW call_other(TP,"query_attrib","wil")
#define TPST call_other(TP,"query_attrib","ste")
#define TPSTA call_other(TP,"query_attrib","sta")
 
#include "/players/snow/closed/cyber/color.h"
inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("honed longsword");
    set_alias("longsword");
    set_short("A finely honed longsword");
   set_type("sword");
    set_long(
"A titanium-alloy longsword, this is very light and strong.\n"+
"It would be a deadly weapon if wielded by one with skill.\n");
    set_class(20);
    set_weight(2);
    set_value(2000);
    set_hit_func(this_object());
}
weapon_hit() {
  if(!MEAT) return 0; /* - ill */
  skill_hit();
  /* change: 65% at xlvl 20 (same as previous odds) 83% at xlvl 40, 
    91% at lxl 75,  93% at xlvl 100 */
  if(random(TPXL) > random(13))  {
  say(TPN+
" skillfully hacks into "+MEATN+" with "+GEN+" honed longsword!\n");
  write(
"You skillfully hack into "+MEATN+" with your honed longsword!\n");
  return 4;
   }
  return 1;
}
 
skill_hit() {
  object meat;
  meat = this_player()->query_attack();
  if(!meat) return 1;
  /* Change: 65% at str 20, 75% at str 30, 80% at str 35 */
  if(random(TPS) > random(13)) strength_hit(meat);
  /* Change: 10% at wis 20, 16% at wis 30, 19% at wis 35 */
  if(random(TPW) > random(90)) wil_hit(meat);
return 1;
}

strength_hit(object ob) {
  int lev; string name;
  lev = TPL + (TPXL/2);
  name = ob->query_name();
  write("You "+RED+"IMPALE"+OFF+" "+name+" with a savage thrust!\n");
  say(TPN+" "+RED+"IMPALES"+OFF+" "+name+" with a savage thrust!\n");
  ob->heal_self(-(lev/5));
  return 1; }

mapping ac_effects;
    
wil_hit(object ob) {
  int oac; string name;
  name = ob->query_name();
  oac = ob->query_ac();
  if(!oac) return 1;
  if(oac < 10) return 1;
  write("You "+GREEN+"overcome"+OFF+" "+name+"'s desire to defend itself!\n");
  say(TPN+" "+GREEN+"overcomes"+OFF+" "+name+"'s desire to defend itself!\n");
  if(ob->query_interactive()) { ob->heal_self(-5); return 1; }
  /* is not working properly - illarion 5 dec 2004 
  ob->set_ac(oac - 1);
  instead we'll register the sword as a piece of armor on the target */
  if(!ac_effects) ac_effects=([]);
  if(ac_effects[ob]) {
    ac_effects[ob]--;
  } else {
    ac_effects[ob]=-1;
  }
  ob->RegisterArmor(this_object(),({"physical",ac_effects[ob],0,0}));
  return 1; }

/* keep the sword from lowering the exp value */
no_exp_effect() { return 1; }
