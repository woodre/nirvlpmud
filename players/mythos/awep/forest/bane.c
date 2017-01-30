/*********************************
*
*   approved by saber
*
*********************************/
#include "/players/mythos/closed/guild/def.h"
inherit "obj/weapon";
reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("demonslayer");
    set_alt_name("bane");
    set_alias("blade");
    set_short("Demon's Bane");
    set_long("The blade is of deepest BLUE. It shines with an odd light.\n"+
      "The blade is simple except for some runes written on it in blood red.\n");
    set_read("Demon's Bane   - The HUNTER\n");
    set_type("sword");
    set_class(18);
    set_weight(2);
    set_value(5000);
    set_hit_func(this_object());
}

weapon_hit(attacker){
if(tp->query_attrib("luc") > random(50)) {
  tell_room(environment(tp),"Bane carves through its foe!!\n");
   if(attacker->id("demon") || attacker->id("daemon") || 
       attacker->id("avatar")) {
     if(tp->query_attrib("wil") > random(40) &&
        tp->query_attrib("pie") > random(40)) {
         tell_room(environment(tp),
           HIR+"\nBane drinks the blood of its eternal prey!!"+NORM+"\n\n");
         if(attacker->query_hp() > 15) {
         attacker->heal_self(-15); }
         else { attacker->heal_self(-(attacker->query_hp()) + 1); }
     }
  }
return 3; }
   
    if(pp && random(5) ==0) {
      write("you feel the darkness shade you and strength enters you!\n");
      say("The world seems darker as "+capitalize(tpn)+" swings Bane!\n");
      tp->add_spell_point(1+random(3));
     return 5;}
return;
}

query_save_flag()  { return 0; }

query_gsave() { return 1;}

