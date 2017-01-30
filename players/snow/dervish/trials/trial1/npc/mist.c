/* 
 * Forbin
 * Created:   2003.09.12
 * Last edit: 2003.09.12 -forbin
 * =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
 * This mob guards the entrance to the Dervish quest area.
 * I has a high ac, low wc (it's mist after all), and the lower its
 * hps, the higher its ac.  It heals 800 hps 5 times during the 
 * fight, and also heals 7 hp per hb.
 * Since it has such low wc, most of the damage comes from a 
 * relatively small spell attack and a multihit attack (can have up
 * to eleven hits in a round).
 * =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
 * Change log:
 */

#include "/players/forbin/define.h"
inherit "/players/vertebraker/closed/std/monster.c";
#define ROOT "/players/snow/dervish/trials/trial1/"

int regen;

id(str) { return (::id(str) || str == "mist"
                            || str == "mist creature" 
                            || str == "dervish mist creature"); }

reset(arg) {
  object gold;
  ::reset(arg);
  if(arg) return;

message_hit = ({ HIM+"S T R A N G L E S"+NORM, " with a choking fog",
                 HIM+"C H O K E S"+NORM, " violently",
                 HIW+"CHOKES"+NORM, " draining the life from them",
                 HIW+"DRIVES"+NORM, " into the ground with a painful THUD",
                 "swrils around", "",
                 "floats about", "",
                 "misses", " barely harming", });

  set_name("Mist");
  set_gender("creature");
  set_long("  A swirling purple mists pours forth from the gaping hole in the\n"+
           "ground.  It swirls about with a live of its own.\n");
  set_level(22);
  set_hp(1200);
  set_wc(25);
  set_ac(30);
  set_al(0);
  set_wc_bonus(0);
  set_ac_bonus(0);
  set_hp_bonus(2000); /* This should be 4000, making it 200 cause of low wc */
  set_dead_ob(this_object());
  set_chat_chance(1+random(2));
    load_chat(HIM+"A purple mist floats about the area.\n"+NORM);
    load_chat(HIM+"Mist oozes out of the hole.\n"+NORM);
    load_chat(HIM+"A purple mist swirls about you.\n"+NORM);
  set_chance(30);
  set_spell_dam(25+random(76));
    set_spell_mess1(HIM+"The purple mist twists about its attack.\n"+NORM);
    set_spell_mess2(HIM+"The purple mist twists about you.\n"+NORM);
  regen = 5;
}                                    

heart_beat() {
  ::heart_beat();
  if(!environment()) return;
  if(!attacker_ob) return;
  if(hit_point < 100) hit_point += 7;
  ac_check();
  if(regen && hit_point <= 150) regen_check();
  multihit();
}

ac_check() {
  if(!present(attacker_ob, environment())) return;
  if(hit_point <= 950) armor_class = 33;
  if(hit_point <= 900) armor_class = 36;
  if(hit_point <= 850) armor_class = 39;
  if(hit_point <= 800) armor_class = 42;
  if(hit_point <= 750) armor_class = 45;
  if(hit_point <= 700) armor_class = 48;
  if(hit_point <= 650) armor_class = 51;
  if(hit_point <= 600) armor_class = 54;
  if(hit_point <= 500) armor_class = 57;
  if(hit_point <= 400) armor_class = 60;
  if(hit_point <= 300) armor_class = 63;
  if(hit_point <= 200) armor_class = 66;
  if(hit_point <= 100) armor_class = 69;
  else armor_class = 30;
}

regen_check() {
  if(!present(attacker_ob, environment())) return;
  tell_room(environment(), HIM+"\t\nMist swirls out from a gaping hole in the gound!\n\n"+NORM);
  hit_point += 800;
  regen--;
}

multihit(){
  if(!random(2)) extrahit();
  if(!random(4)) extrahit();
  if(!random(4)) extrahit();
  if(!random(6)) extrahit();
  if(!random(6)) extrahit();
  if(!random(8)) extrahit();
  if(!random(10)) extrahit();
  if(!random(13)) extrahit();
  if(!random(16)) extrahit();
  if(!random(20)) extrahit();
}

extrahit() {
  if(!attacker_ob) return;
  if(!attacker_ob->query_ghost()) { 
    already_fight = 0; 
    ::attack();
  }
}

monster_died() {
  object corpse;
  corpse = present("corpse", environment(this_object())); 
  environment(this_object())->mist_died();
  if(corpse) destruct(corpse);
    return 1;
}