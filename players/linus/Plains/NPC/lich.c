#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/monster.c";
id(str) { return str=="lich" || str=="guardian" || str=="guard" || str=="guardian lich"; }
reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_name("Lich");
 set_short(BLU+"Guardian Lich"+NORM);
 set_long(
 "  The lich is a sinister being, cloaked in heavy dark blue\n"+
 "robes.  Skeletal hands reach out from beneath the cloak, and\n"+
 "they look to "+HIB+"glow"+NORM+" with magical energies.  Glowing "+HIB+"eyes"+NORM+" peer at\n"+
 "you from beneath a hood.  Icy vapor floats from under the hood\n"+
 "with each breath the creature takes.\n");
 set_level(20);
 set_wc(35);
 set_race("lich");
 set_gender("male");
 set_wc_bonus(random(25));
 set_ac_bonus(random(5));
 set_hp(400+random(250));
 set_heal(5,15);
 set_aggressive(0);
 set_ep(50000000);
 set_dead_ob(TO);
 set_al(random(-1000));
 set_chat_chance(10);
 load_chat("The lich hisses at you in a foreign tongue...\n");
 load_chat(HIB+"Glowing eyes"+NORM+" peer at you from beneath the hood.\n");
 set_a_chat_chance(10);
 load_a_chat("The lich hisses in pain as he is hit.\n");
 set_chance(15);
 set_spell_dam(30);
 set_spell_mess1("The lich grabs his attacker, his nails "+RED+"tearing"+NORM+" into their flesh.\n");
 set_spell_mess2("The lich grabs you, his nails "+RED+"tearing"+NORM+" into your flesh.\n");
}
heart_beat() {
 ::heart_beat();
 if(attacker_ob) {
 switch(random(20)) {
 case 0..5: return 0; break;
 case 6..10: stinky_breath(); break;
 case 11..18: return 0; break;
 case 19: heal_myself(); break; }
 }
}
stinky_breath() {
 if((attacker_ob) && (attacker_ob->query_ghost())) return;
 tell_room(ENV(TO), "The lich takes a deep breath...\n\n"+
                    "   He exhales, his icy breath\n\n"+
                    "                 "+HIC+"~"+HIB+"*"+HIC+"~ F"+HIB+" R "+HIC+"E"+HIB+" E "+HIC+"Z"+HIB+" E "+HIC+"S"+HIC+" ~"+HIB+"*"+HIC+"~"+NORM+"\n\n", ({ attacker_ob }));
 tell_room(ENV(TO), "                                   "+attacker_ob->query_name()+"\n\n", ({ attacker_ob }));
 tell_object(attacker_ob, "The lich takes a deep breath...\n\n"+
                          "   He exhales, his icy breath\n\n"+
                          "                 "+HIC+"~"+HIB+"*"+HIC+"~ F"+HIB+" R "+HIC+"E"+HIB+" E "+HIC+"Z"+HIB+" E "+HIC+"S ~"+HIB+"*"+HIC+"~"+NORM+"\n\n"+
                          "                                   you.\n\n");
 attacker_ob->hit_player(20+random(30), "other|ice");
}
heal_myself() {
 if((attacker_ob) && (attacker_ob->query_ghost())) return;
 tell_room(ENV(TO), "The lich starts chanting...\n\n"+
                    "         An "+HIC+"aura"+NORM+" surrounds him...\n\n"+
                    "                            His wounds start healing.\n");
 heal_self(25+random(25));
}
