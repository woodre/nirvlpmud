#include "defs.h"

inherit MONSTER;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object(ARM_PATH+"bplate2.c"),this_object());
  init_command("wear plate"); /* 1500 */
  move_object(clone_object(WEP_PATH+"blackaxe.c"),this_object());
  init_command("wield axe"); /* 2000 */
  if(!random(3)) {
    move_object(clone_object(ARM_PATH+"buckler.c"),this_object());
    init_command("wear shield"); /* 50/3 = 16 */
  }
  if(!random(3)) {
    move_object(clone_object(ARM_PATH+"blcloak.c"),this_object());
    init_command("wear cloak"); /* 500/3 = 166 */
  }
  if(!random(3)) {
    move_object(clone_object(ARM_PATH+"gauntlet.c"),this_object());
    init_command("wear gauntlet"); /* 75/3 = 25 */
  }
  add_money(1000+random(600)); /* 1300 */
  set_name("dreadknight");
  set_alt_name("knight");
  set_short(BOLD+BLK+"Dreadknight"+NORM);
  set_long(
"This warrior has gained great power and endurance through demonic\n"+
"pacts.  His skin, beneath his plate armor has become the color of\n"+
"charcoal, and his face has been twisted into a rictus of pain.  His\n"+
"eyes have become twin pools of blood, mirroring his blood soaked\n"+
"soul.\n" /* Lame */
  );
  set_gender("male");
  set_race("human");
  set_level(20);
  set_wc(30+random(4));
  set_ac(14+random(3));
  set_hp(600+random(50));
  set_heal(3,1);
  set_al(-1000+random(100));
  set_chat_chance(4);
  load_chat("Dreadknight hisses softly.\n");
  load_chat("Dreadknight paces the room.\n");
  set_a_chat_chance();
  load_a_chat("The dreadknight's wounds begin to close.\n");
  load_a_chat("Dreadknight hisses at you!\n");
  load_spell(40,20,1,
    BLK+BOLD+"\nThe dreadknight touches you with its death cold hands.\n\n"+NORM,
    BLK+BOLD+"\nThe dreadknight touches #ATT# with its death cold hands.\n\n"+NORM);
  wc_bonus+=3; /* Hb aggro bonus */
  set_dead_ob(this_object());
}

void heart_beat() {
  object ob;
  ::heart_beat();
  if(!attacker_ob) {
    ob=first_inventory(environment());
    while(ob) {
      if(ob->is_player() && !random(10)) {
        this_object()->attack_object(ob);
        tell_room(environment(), BOLD+"Dreadknight says: I HUnGEr fOR yOUr SOuL.\n"+NORM);
      }
      ob=next_inventory(ob);
    }
  }
}

monster_died(me) {
  if(!random(3)) {
    tell_room(environment(), "With a loud CRACK, the Dreadknight's Black Axe shatters!\n");
    destruct(present("axe",present("corpse",environment())));
  }
  if(!random(3)) {
    tell_room(environment(), "With a loud CRACK, the Dreadknight's breastplate shatters!\n");
    destruct(present("plate",present("corpse",environment())));
  }
}
  
