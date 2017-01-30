#include "/players/fakir/color.h"
inherit "/obj/monster";
int ack,qq,q,kkk;
object envir;
reset(arg)  {
  object armor;
  ::reset(arg);
  if(arg) return;
  set_name("myrddraal");
  set_alias("demon");
  set_race("demon");
  set_short(BOLD+RED+"Myrddraal"+OFF);
  set_long(
  "Commander of Trollocs, its twisted evil inspires fear.  Created from\n"+
  "human parts, it resembles a man in size and shape.  Its skin is sickly\n"+
  "and pale, with no hair of any kind visible.  Leather wings, the color\n"+
  "of burned flesh fold across the hunched back and drag the ground. \n");
  set_level(20);
  set_hp(500 +random(100));
  set_al(-1000);
  set_wc(30);
  set_ac(17);
  set_dead_ob(this_object());
  set_a_chat_chance(15);
  load_a_chat(BOLD+RED+"The Myrddraal blocks your attack with its wing."+OFF+"\n");
  load_a_chat("The Myrddraal scratches your thigh drawing blood...\n");
  load_a_chat("Sharp claws slash across your chest and poison races toward your heart.\n");
  load_a_chat("The Myrddraal steps back, spins once, and gestures with a magic symbol of evil.\n");
  load_a_chat("A poison "+RED+"R E D  M I S T "+OFF+"surrounds the Myrddraal.\n");
  set_chance(10);
  set_spell_dam(25);
  set_spell_mess1(BOLD+RED+"The Myrddraal reaches out with poison claws."+OFF+"\n");
  set_spell_mess2(BOLD+RED+"The Myrddraal reaches out and rakes your eyes with poison claws."+OFF+" \n");
  add_money(3000+random(1500));
}

heart_beat() {
  ::heart_beat();
  if(!environment()) return;
  if(!query_attack()) {
    if(!random(10)) {
      envir = 0;
      ack = allocate(10);
      qq = 0;
      kkk = 0;
      envir = all_inventory(environment(this_object()));
      for(q=0;q<sizeof(envir);q++) { 
      if(envir[q]->is_player()) {
      ack[qq] = envir[q];
      qq++; }
      }
      q = 0;
      while(q<sizeof(ack) && !kkk) {
      if(ack[q] && !random(5)) {
      attack_object(ack[q]);
      kkk = 1;
      }
      q++; } 
      }
    } 
  else if(query_attack() && query_attack() == this_object()) { heal_self(100000); }
  }

monster_died() {
  move_object(clone_object("/players/fakir/ways/ARM/wings.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
  "The "+BOLD+RED+"Myrddraal's"+OFF+" leather wings drop to the floor.\n");
  return 0; }
