/*********************************
*
*   approved by saber
*
*********************************/
#include "/players/mythos/closed/guild/def.h"
inherit "obj/weapon.c";
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
    set_class(18);
    set_weight(2);
    set_value(5000);
    set_hit_func(this_object());
}

weapon_hit(attacker){
if(call_other(this_player(),"query_attrib","luc") > random(50)) {
  write("Bane carves through its foe!!\n");
  say("Bane carves through its foe!\n");
   if(call_other(attacker,"id","demon")) {
     if(call_other(this_player(),"query_attrib","wil") > random(40) &&
        call_other(this_player(),"query_attrib","pie") > random(40)) {
         write(HIR+"\nBane drinks the blood of its eternal prey!!"+NORM+"\n\n");
         say(HIR+"\nBane drinks the blood of its eternal prey!!"+NORM+"\n\n");
         attacker->heal_self(-15);
     }
  }
  if(call_other(attacker,"id","daemon")) {
    if(call_other(this_player(),"query_attrib","wil") > random(40) &&
       call_other(this_player(),"query_attrib","pie") > random(40)) {
         write(HIR+"\nBane drinks the blood of its eternal prey!!"+NORM+"\n\n");
         say(HIR+"\nBane drinks the blood of its eternal prey!!"+NORM+"\n\n");
         attacker->heal_self(-15);
    }
  }
  if(call_other(attacker,"id","avatar")) {
    if(call_other(this_player(),"query_attrib","wil") > random(40) &&
       call_other(this_player(),"query_attrib","pie") > random(40)) {
         write(HIR+"\nBane drinks the blood of its eternal prey!!"+NORM+"\n\n");
         say(HIR+"\nBane drinks the blood of its eternal prey!!"+NORM+"\n\n");
         attacker->heal_self(-15);
    }
  }
return 5; }
   
    if(pp && random(3) ==0) {
      write("you feel the darkness shade you and strength enters you!\n");
      say("The world seems darker as "+capitalize(tpn)+" swings Bane!\n");
      tp->add_spell_point(1+random(10));
     return 7;}
return;
}

query_save_flag()  { return 0; }

query_gsave() { return 1;}

cleanup() { fix_weapon(); misses = 0; hits = 0; }
