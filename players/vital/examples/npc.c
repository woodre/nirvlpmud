#include "/players/zeus/closed/all.h"
inherit "/obj/monster.c";
int dmg,rounds;
int max;

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_level(20);
   set_name("npc");
   set_short("A dmg npc");
   set_long(0);
   set_hp(1000);
   set_wc(30);
   set_ac(0);
   set_al(0);
   dmg=0;
   rounds=0;
   }
id(str){ return str == "npc"; }
init() {
   ::init();
   add_action("damage","damage");
   add_action("reset_cmd","reset");
   add_action("beat","beat");
   add_action("change_ac","ac");
   add_action("change_wc","wc");
}
change_ac(str) {
    int x;
    if(!str) { notify_fail("The current AC is "+query_ac()+"\n"); return 1;}
    if(sscanf(str,"%d",x) == 1) {
        set_ac(x);
        write("AC has been set to "+str+"\n");
    }
    return 1;
}
change_wc(str) {
    int x;
    if(!str) { notify_fail("The current WC is "+query_wc()+"\n"); return 1;}
    if(sscanf(str,"%d",x) == 1) {
        set_wc(x);
        write("AC has been set to "+str+"\n");
    }
    return 1;
}
heart_beat() {
   if(attacker_ob) {
      dmg += 1000-hit_point;
      rounds++;
say("Damage was "+HIG+(1000-hit_point)+NORM+".  Average is "+
HIG+(dmg/rounds)+"."+((dmg-((dmg/rounds)*rounds))*1000)/rounds+NORM+"\n");
      if((1000-hit_point) > max) max=1000-hit_point;
      heal_self(1000);
   }
  ::heart_beat();
}

damage() {
   if(rounds==0) return 0;
   write("Damage: "+dmg+"\n");
   write("Rounds: "+rounds+"\n");
   write(
"Average: "+(dmg/rounds)+"."+((dmg-((dmg/rounds)*rounds))*1000)/rounds+"\n");
   write("Max: "+max+"\n");
   write("\"reset\" to reset\n");
   return 1;
}
reset_cmd() {
   write("Ok.\n");
   dmg=0;
   rounds=0;
   return 1;
}
beat(str) {
   if(attacker_ob) return 0;
   if(!str) return 0;
   if(present(str) && living(present(str))) {
      attack_object(present(str));
      attack();
   return 1;
   }
}
