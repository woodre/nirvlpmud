#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/monster.c";
id(str) { return str=="ghoul" || str=="undead";  }
int x, ouch;
object corpse, wep, arm;
reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_name("Ghoul");
 set_short("A ghoul");
 set_long(
 "  The ghoul is an undead creature, created from a fresh corpse.  Dark\n"+
 "necromantic power is used to give these hideous creatures life, and\n"+
 "feeding on the living sustains them.  Rotting flesh hangs from the\n"+
 "ghoul, giving off a stench of death and decay.  Used primarily as\n"+
 "soldiers, ghouls are ferocious fighters, skilled in many forms of\n"+
 "combat\n");
 set_level(18);
 wep = CO("/players/linus/Plains/obj/sword.c");
 MO(wep,TO);
 init_command("wield sword");
 arm = CO("/players/linus/Plains/obj/shield.c");
 MO(arm,TO);
 init_command("wear shield");
 set_ac(14);
 set_wc(30);
 set_ac_bonus(4);
 set_wc_bonus(2);
 set_hp(400+random(150));
 set_al(random(-1000));
 set_aggressive(0);
 set_chat_chance(5);
 load_chat("The ghoul moans, sending chills up your spine...\n");
 load_chat("A piece of rotten flesh falls from the ghoul...\n");
 set_a_chat_chance(5);
 load_a_chat("The ghoul lashes out with his maggot infested hand.\n");
 load_a_chat("The ghoul swings hard with his sword.\n");
 load_a_chat("The ghoul raises his shield in defense.\n");
 set_chance(10);
 set_spell_dam(15+random(30));
 set_spell_mess1("The ghoul claws his attacker, leaving an "+GRN+"infected"+NORM+" wound.");
 set_spell_mess2("The ghoul claws you, leaving an "+GRN+"infected"+NORM+" wound.");
}
heart_beat() {
 ::heart_beat();
 if(attacker_ob){
  x = random(30);
    switch(x){
    case 0..2: bite_me();break;
    case 3..30: return 0;break;
  }
 }
 corpse = present("corpse",ENV(TO));
 if(corpse) { 
 say("The ghoul picks up the corpse and hungrily devours it.\n"); 
 move_object(corpse, TO);
 heal_self(10+random(50));
   destruct(corpse);
   return 1;
 }
}
bite_me() {
ouch = 5+random(20);
if((attacker_ob) && (attacker_ob->query_ghost())) return;
tell_room(ENV(TO), "The ghoul bites a piece of flesh from "+attacker_ob->query_name()+" and swallows it.\n"+
                                        RED+"      Blood"+NORM+" drips from its mouth.\n", ({ attacker_ob }));
tell_object(attacker_ob, "The ghoul bites a piece of flesh from you and swallows it.\n"+
                                               RED+"      Blood"+NORM+" drips from its mouth.\n");
heal_self(ouch);
attacker_ob->hit_player(ouch);
return 1;
}
 

