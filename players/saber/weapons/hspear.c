/*
 *  Found on Lady Yuki-Onna the Anti Paladin
 *
 */
/* Updated for dtypes by Illarion Dec 2004 */
#include "/open/ansi.h"
#define tp this_player()->query_name()
int w;
 inherit "obj/weapon.c";
  reset(arg) {
  ::reset(arg);
  if (arg) return;
  set_name("spear of the Nine Heavens");
  set_alias("spear");
  set_type("spear");         /* set type added by Pavlik */
  set_short(YEL+"Spear of the Nine Heavens"+NORM);
  set_alt_name("demon slayer");
  set_long("A mighty spear carved from the bones of a dead god.\n"+
   "It is covered with golden runes.\n");
  set_read("This spear, Mischylie, was forged to slay Demon kin.\n");
  set_class(16);
  set_weight(2);
  set_value(6001);
/*    set_save_flag(0); Make save -Bp 12-02*/
/* weapon's special damage is now magic
  set_hit_func(this_object());
  */
  set_params("magical",0,"magic_hit");
}
magic_hit(attacker){
  if(call_other(this_player(), "query_attrib", "pie") > random (50)){
    
    tell_room(environment(this_player()),
    "The "+YEL+"Spear of the Nine Heavens "+NORM+"glows with a holy "+HIB+"blue aura"+NORM+".\n"+
    attacker->query_name()+"'s grasp upon the fabric of reality begins to waver.\n");
    
    if(call_other(attacker,"id","demon") || call_other(attacker,"id","devil"))  {
      if(call_other(this_player(), "query_attrib", "pie") > random(35)) {
        tell_room(environment(this_player()),
        "The runes on the "+YEL+"Spear of the Nine Heavens"+NORM+" glow with a "+HIW+"pure white light"+NORM+".\n"+
        tp+" impales "+attacker->query_name()+" upon the spear.\n"+
        attacker->query_name()+" howls in pain.\n");
        attacker->heal_self(-20);
      }
    }
    /* changed from 13 to 8 (0-7 magic dam) - Illarion */
    return 8;
  }
  return;
}
