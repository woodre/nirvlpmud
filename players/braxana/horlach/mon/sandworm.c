#include "/players/mythos/dmon/def.h"
inherit "players/mythos/dmon/mon";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("sandworm");
  set_race("worm");
  set_short(YEL+"SandWorm"+NORM);
  set_level(20+random(20));
  set_hp(1000 + random(3000));
  if(random(2) == 0) set_al(0 - random(1500));
  else set_al(0 + random(1500));
  set_wc(30 + random(query_level()));
  set_ac(17 + random(query_level())/5);
  set_long("\n");
  set_heal(2+random(query_level()/3),40 - random(query_level()));
  set_aggressive(1);
  set_wander();
  set_chat_chance();
  set_a_chat_chance();
  load_chat("\n");
  load_chat("\n");
  load_a_chat("\n");   
  load_a_chat("\n");
  load_a_chat("\n");
  set_mass_chance(1 + random(query_level())/2);
  set_mass_dam(query_wc()/2 + random(query_wc()));
  set_mass_spell();
  set_chance(1 + random(query_wc()));
  set_spell_dam(query_wc());
  set_spell_mess1("\n");
  set_spell_mess2("\n"); 
  if(random(3) == 0) {
  set_mult(2 + random(2));}
  set_dead_ob(this_object());
}

query_prevent_shadow() { return 1; }

set_max() { set_level(39); set_hp(3999); set_wc(20 + 38); set_ac(17 + 39/5);
            set_heal(2 + 38/2,2); set_aggressive(1); set_mass_chance(1 + 38/2);
            set_mass_dam(20 + 38 + (20 + 38)/2); set_chance(1 + 20 + 37);
            set_spell_dam(20 + 38); set_mult(3); }

monster_died() {
object leave;
int levcheck;
  switch(random(4)) {
    case 0: leave = clone_object("/obj/money.c"); 
            levcheck = query_level() - 20;
            if(levcheck > 32) leave->set_money(6000);
            if(levcheck > 38) leave->set_money(10000);
            if(levcheck < 33) leave->set_money(5000);
            break;
    case 1: leave = clone_object("/players/mythos/darmor/carapace.c"); break;
    case 2: leave = clone_object("/players/mythos/dmisc/tooth.c"); break;
    case 3: leave = clone_object("/players/mythos/dmisc/meat.c"); break; 
  }
  move_object(leave, environment(this_object()));
}