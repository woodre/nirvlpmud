#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/monster.c";
int i;
object wep;
id(str) { return str=="skeleton" || str=="spirit" || str=="skel_spirit"; }
reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_name("Skeleton");
 set_short("Skeleton "+HIC+"["+HIW+"spirit"+HIC+"]"+NORM);
 set_long(HIY+
 "  Glowing eyes"+NORM+" are fixed on you, as if to peer into your soul.\n"+
 "The skeleton's bones appear to be still sturdy, with scraps of\n"+
 "purple and gold colored fabrics hanging from them.  The skeleton\n"+
 "stands with purpose, just as the guards of Celestia did during\n"+
 "the prosperous years.\n");
 set_level(20);
 set_hp(650+random(105));
 wep=CO("/players/linus/Plains/obj/r_sword.c");
     MO(wep,TO);
     command("wield sword",TO);
 set_wc(35);
 set_wc_bonus(10+random(10));
 set_ac(19);
 set_heal(5,5);
 set_dead_ob(this_object());
 set_chance(15);
 set_spell_dam(20+random(45));
 set_spell_mess1("The skeleton strikes his attacker with his "+RED+"rusty"+NORM+" sword.");
 set_spell_mess2("The skeleton strikes you with his "+RED+"rusty"+NORM+" sword.");
}
heart_beat(){
 ::heart_beat();
  if(attacker_ob){
  i = random(30);
    switch(i){
    case 0..5: whap_whap();break;
    case 6..29: return 0;break;
  }
 }
}
whap_whap(){
if((attacker_ob) && (attacker_ob->query_ghost())) return;
tell_room(ENV(TO),"\n  The skeleton's eyes "+HIY+"glow brightly."+NORM+"\n\n   The skeleton takes a giant swing with his "+RED+"rusty"+NORM+" sword.\n\n    "+attacker_ob->query_name()+" recoils in pain!\n\n",({ attacker_ob }));
tell_object(attacker_ob,"\n  The skeleton's eyes "+HIY+"glow brightly."+NORM+"\n\n   The skeleton takes a giant swing with his "+RED+"rusty"+NORM+" sword.\n\n    You recoil in pain!\n\n");
if((attacker_ob->query_npc()) && (attacker_ob->query_sp() >=25))
attacker_ob->heal_self(-20-random(20));
else
attacker_ob->add_spell_point(-10-random(20));
}
monster_died() {
 object corpse;
 corpse = present("corpse",environment(TO));
 tell_room(environment(TO),"Something drops to the ground as the skeleton crumbles into a pile of dust.\n\n"+HIY+
 "       * *  F L A S H  * *\n"+NORM+"\n          The glow of the eyes fades away.\n");
 MO(CO("/players/linus/Plains/obj/skull.c"),environment(TO));
 if(corpse) destruct(corpse);
 return 1;
}
init() {
 ::init();
 add_action("no_go","climb");
}
no_go(str) {
 if(!str || str != "out") { return 0; }
 if(str == "out" ) {
 write("The skeleton grabs you, pulling you back into the pit.\n");
tell_room(ENV(),"The skeleton grabs "+TPN+", pulling "+TPO+" back into the pit.\n");
 if(TP->query_ghost()) { return 1; }
 if(TP->query_level() <= 5) { return 0; }
 return 1;
}
}