#include "/players/guilds/bards/def.h"

status main(string str) {
  object ob,mod,mark;
   int i, numero; 
  int aaa, bbb, damage;

  if(TP->query_spell_dam())
    FAIL("You've already cast a spell.\n");

  if (!str) {
    if(!(ob = (object)TP->query_attack()))
    {
    write("To use type: true_name <monster> >\n");
    return 1;
    }
  }
  else ob=present(str,environment(TP));
  if (attack_spell(-189, 9, 100, ob) == -1)
    return 0;

  if (present("true_name_mark", ob)) {
    write("You may only speak the True Name of a creature once.\n");
    return 1;
  }

  tell_room(environment(TP), "\n\n");
  write("You speak the "+BOLD+"TRUE NAME"+NORM+" of the creature called "+
      ob->query_name() + ".\n");
  say(tp + " speaks the "+BOLD+"TRUE NAME"+NORM+" of the creature called "+
    ob->query_name() + ".\n");
  tell_room(environment(TP),
        "You watch as " + ob->query_name() + " writhes in\n\n");
        tell_room(environment(TP),HIR+
      "                  *                                   \n"+ 
      "                *  *                                  \n"+
      "              *    *                                  \n");
        tell_room(environment(TP),
      "             * ** *   ****  *****  ****   *   *       \n"+
      "            *    *   *  *   *   *   *  *   *   *      \n"+
      "           *    *   *  *    *   *    *  *   *   *     \n");
        tell_room(environment(TP),
      "          *    *   * **     *****     *  *   *****    \n"+
      "                     *                            *   \n"+
      "                    *                       *      *  \n");
        tell_room(environment(TP),
      "               *****                       ********** \n\n"+NORM+
      "                                at the sound of its "+BOLD+
            "TRUE NAME"+NORM+".\n\n");
/* this is handled another way now so it doesn't affect exp
  call_other(ob, "set_heal", 0, 100);
*/
  damage=20+random(30);
  if (damage > ob->query_hp())
    damage = (int)ob->query_hp() - 1;
  ob->hit_player(damage,"magical");
  if (living(ob))
    ob->attack_object(TP);
  TP->attack_object(ob);
 /* 
  * The code of mob_mob.c prevents ac and wc from going too low.
  * After a certain point casting true_name or agony increases 
  * the duration without lowering ac/wc further.
  *
  * Also, true_name is limited to one cast per creature.
  */
  mod=present("bard_acwc_modifier", ob);
  if(!mod) {
    mod = clone_object(OBJ+"mob_mod.c");
    move_object(mod, ob);
    mod->originals();
  }
  numero = random((BLVL)/2) + 3;
  while(numero){
     mod->wc_mod();
     mod->ac_mod();
     numero -= 1;
  }
  mark=clone_object("/players/guilds/bards/obj/true_name_mark.c");
  mark->set_victim(ob);
  move_object(mark,ob);
  TP->spell_object(ob, "true_name", 1, 1, "", "", "");
  TP->set_spell_dtype("magical");
  call_other(TP, "add_spell_point", -100);
  return 1;
}
