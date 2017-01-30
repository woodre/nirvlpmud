#include "/players/fred/ansi.h"
inherit "/obj/monster.c";
int i, randomnum;
object attacked, weapon;
#define attacked (this_object()->query_attack())

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("overlord");
  set_alias("ferret");
  set_race("creature");
  set_short(BOLD+GRN+"Fe"+NORM+HIC+"rr"+NORM+HIR+"et"+NORM+BOLD+MAG+" Overlord"+NORM);
  set_long(
    "  It is hard to make out the Overlord in the shadows\n"+
    "All you can see is a large looming figure glaring\n"+
    "back at you with large green eyes. It is probably\n"+
    "best to just leave it alone.\n");
  
  set_level(21);
  set_hp(1200);
  set_al(-1000);
  set_ac(20);
  set_wc(55);
  set_wc_bonus(36);
  set_aggressive(1);
  set_dead_ob(this_object());
  set_chance(20);
  set_spell_dam(75);
  set_spell_mess1(
    "The ferret "+CYN+"CHARGES "+NORM+"its foe!\n");
  set_spell_mess2(
    "\nYou are "+GRN+"L A U N C H E D"+NORM+" into a nearby tree.\n");
}

heart_beat(){
  ::heart_beat();
  if(random(100) < 60){
  if(attacker_ob && !attacker_ob->query_ghost()){
  already_fight=0;
  attack();
  }
 }
}

monster_died(){
  object corpse;
  write_file("/players/fred/log/monster", attacker_ob->query_name() + " killed Ferret Overlord " + ctime()[4..15] + "\n");
  corpse = present("corpse", environment());
  tell_object(attacked,
    "You watch as the ferret disappears leaving only its remains\n");
  move_object(clone_object("/players/fred/forest/Obj/cwep.c"),
    environment(this_object()));
  if(corpse)
   destruct(corpse);
  return 1;
  }
