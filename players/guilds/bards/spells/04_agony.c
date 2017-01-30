#include "/players/guilds/bards/def.h"

status main(string str) {
  object ob;
  object mod;
  int numero;

  if(TP->query_spell_dam())
    FAIL("You've already cast a spell.\n");
  if (!str) {
    ob=(object)TP->query_attack();
  } else {
    ob = present(str, environment(TP));
  }
  if ( !ob  || !present(ob,environment(TP)) ) 
    FAIL("You must have a target for this spell.\n");

  if (attack_spell(-100, 4, 30, ob) == -1) return 0;

  say(tp + " plays a dissonant chord upon " + POSS(TP) + " " + INST + ".\n" +
    "A black aura settles over " + NAME(ob) + ".\n");
  write("You play a dissonant chord upon your " + INST + ".\n" + 
    "A black aura settles over " + NAME(ob) + ".\n");
  mod=present("bard_acwc_modifier", ob);
  if(!mod) {
    mod = clone_object(OBJ+"mob_mod.c");
    move_object(mod, ob);
    mod->originals();
  }
  numero = random(BLVL/2) + 1; /* min 2 max 5 */
  while(numero){
    mod->wc_mod();
    mod->ac_mod();
    numero -= 1;
  }
  mod->check_max();
  TP->spell_object(ob, "agony", 1, 30, "", "", "");
  return 1;
}
