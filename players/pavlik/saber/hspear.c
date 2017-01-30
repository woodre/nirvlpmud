/*
 *  Found on Lady Yuki-Onna the Anti Paladin
 *
 */

#define tp this_player()->query_name()
int w;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
     set_name("spear of the Nine Heavens");
     set_alias("spear");
    set_type("spear");         /* set type added by Pavlik */
     set_short("The Spear of the Nine Heavens");
     set_alt_name("demon slayer");
     set_long("A mighty spear carved from the bones of a dead god.\n"+
       "It is covered with golden runes.\n");
     set_read("This spear, Mischylie, was forged to slay Demon kin.\n");
    set_class(16);
    set_weight(2);
    set_value(6001);
    set_save_flag(0);
    set_hit_func(this_object());
}
weapon_hit(attacker){
if(call_other(this_player(), "query_attrib", "pie") > random (50))
 {

tell_room(environment(this_player()),
  "The Spear of the Nine Heavens glows with a holy blue aura.\n"+
  attacker->query_name()+"'s grasp upon the fabric of reality begins to waver.\n");

if(call_other(attacker,"id","demon") || call_other(attacker,"id","devil"))  {
if(call_other(this_player(), "query_attrib", "pie") > random(35)) {
 tell_room(environment(this_player()),
 "The runes on the Spear of the Nine Heavens glow with a pure white light.\n"+
  tp+" impales "+attacker->query_name()+" upon the spear.\n"+
  attacker->query_name()+" howls in pain.\n");
  attacker->heal_self(-20);
    }
     }
  return 13;
  attacker->heal_self(-1);
    }
    return;
}
