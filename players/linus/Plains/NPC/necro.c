#include "/players/linus/def.h"
#define ATT attacker_ob
#define ATTN ATT->query_name()
inherit "/players/vertebraker/closed/std/monster.c";
int i;
object wep;
id(str) { return (::id(str)) || str=="necro" || str=="lord" || str=="necromancer"; }
reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_name("Zargan");
 set_alias("zargan");
 set_gender("male");
 set_short("Zargan - "+HIK+"Necromantic Lord"+NORM);
 set_long(
 "  Zargan was once a loyal servant of King Reuben.  A thin and frail\n"+
 "man, he was always powerful in the magical arts.  He served in King\n"+
 "Reuben's court as a cleric, healing and protecting the knights and\n"+
 "the family of the king.  Zargan was always in search of more power,\n"+
 "and unfortunately his search led him down a dark and twisted path.\n"+
 "He became intrigued by death and the powers of the afterlife.  He\n"+
 "started to study dark magics such as raising the dead, disease and\n"+
 "mind control.  He eventually began practicing on recently deceased\n"+
 "citizens, and some that weren't.  His work was eventually discovered\n"+
 "and he was banished from the kingdom.  He went into hiding, and still\n"+
 "practiced his dark magic, robbing graves to get corpses to work with.\n"+
 "He continued to gain in power, developing a cult-like following in the\n"+
 "process.  He is cloaked in black robes, his silver hair falling from\n"+
 "beneath his hood.  A small leather pouch is tied around his waist, and\n"+
 "in his right hand is a serrated sword, its hilt adorned with a skull.\n");
 set_level(23);
 set_hp(1100+random(205));
 set_wc_bonus(25+random(35));
 set_ac(24);
 set_heal(10,15);
 wep=CO("/players/linus/Plains/obj/ensword.c");
     MO(wep,TO);
 command("wield sword",TO);
 set_wc(40);
 set_dead_ob(this_object());
 set_chance(15);
 set_spell_dam(50+random(55));
 set_spell_mess1("Zargan touches his attacker with a finger and whispers 'burn'...\n"+
                 "       the smell of burning flesh fills the air and his attacker\n"+
                 "           recoils in pain!\n");
 set_spell_mess2("Zargan touches you with a finger and whispers 'burn'...\n"+
                 "       the smell of burning flesh fills the air and you\n"+
                 "           recoil in pain!\n");
}
monster_died() {
 object corpse;
 corpse = present("corpse",environment(TO));
 tell_room(environment(TO),"Zardon drops his sword and vanishes...\n\n"+HIK+
 "       Demonic laughter echoes throughout the cave...\n\n\n"+NORM+
 "          Zargon's robe and pouch are all that remain.\n");
 MO(CO("/players/linus/Plains/obj/skull.c"),environment(TO));
 if(corpse) destruct(corpse);
 return 1;
}
whap_whap(){
if((attacker_ob) && (attacker_ob->query_ghost())) return;
tell_room(ENV(TO),"\n  Zargon strikes "+ATTN+" with his serrated blade\n\n"+RED+
                  "        blood"+NORM+" pours from the open wound...\n", ({ ATT }));
tell_object(ATT,"\n  Zargon strikes you with his serrated blade\n\n"+RED+
                "        blood"+NORM+" pours from the open wound...\n");  
ATT->hit_player(20+random(50));
}
mega_ouch() {
if((ATT) && (ATT->query_ghost())) return;
tell_room(ENV(TO),"\n Zargon pulls some items from his pouch...\n\n"+
                  "   He mumbles some words in a foreign tongue, and the items burst into "+HIR+"flames"+NORM+"\n"+
                  "\n   He then tosses the "+BRED+HIY+"FIREBALL"+NORM+" at "+ATTN+"...\n\n",({ ATT }));
tell_room(ENV(TO),"        "+ATTN+" bursts into "+HIR+"FLAMES"+NORM+"!\n", ({ ATT }));
tell_object(ATT,"\n Zargon pulls some items from his pouch...\n\n"+
                "   He mumbles some words in a foreign tongue, and the items burst into "+HIR+"flames"+NORM+"\n"+
                "     He then tosses the "+BRED+HIY+"FIREBALL"+NORM+" at you...\n\n"+
                "        you burst into "+HIR+"FLAMES"+NORM+"!\n");
 ATT->heal_self(-100-random(101));
}
help_me() {
  object skel;
  skel=CO("/players/linus/Plains/NPC/assist_skeleton.c");
  MO(skel,ENV(TO));
  tell_object(ATT,"\nZargon pulls some dust from his pouch...\n\n"+
                  "  He mumbles some words in a foreign tongue and tosses the dust to the ground.\n\n"+
                  "    A "+HIB+"skeleton"+NORM+" rises from the ground and attacks you!\n");
  tell_room(ENV(TO),"\nZargon pulls some dust from his pouch...\n\n"+
                    "  He mumbles some words in a foreign tongue and tosses the dust to the ground.\n\n"+
                    "    A "+HIB+"skeleton"+NORM+" rises from the ground and attacks "+ATTN+"!\n", ({ ATT }));
  skel->attacked_by(ATT);
  skel->set_master(TO);
}
heart_beat(){
 ::heart_beat();
  if(ATT){
  i = random(50);
    switch(i){
    case 0..5: whap_whap();break;
    case 6..25: return 0;break;
    case 26..29: mega_ouch();break;
    case 30..40: return 0;break;
    case 41..50: help_me();break;
  }
 }
}
