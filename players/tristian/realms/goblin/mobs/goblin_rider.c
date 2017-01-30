inherit "/players/vertebraker/closed/std/monster.c";
#include "/players/tristian/lib/goblin_define.h"
object gold;

reset(arg){

 ::reset(arg);
  if (arg) return;

  set_name("Goblin Rider");
  set_alt_name("rider");
  set_race("goblin");
  set_alias("goblin");
  set_short("An Elite Goblin Rider");
  set_long("The elite of the goblin army, the dreaded\n"+
           "goblin rider, is a slightly oversized goblin\n"+
           "astride a fearsome wolf.  Together, these\n"+
           "two make a deadly team.\n");
  set_level(9);
  set_ac(7);
  set_wc(13);
  set_hp(140);
  set_al(-300);
  set_aggressive(0);
  set_chat_chance(4);
      load_chat("The goblin picks his nose.\n");
      load_chat("The goblin eats what he picks out of his nose.\n");
  set_dead_ob(this_object());

}

  monster_died(){
      tell_room(environment(),
          "You discover a pile of coins among the remains of the goblin.\n");
  gold = clone_object("/obj/money.c");
  gold->set_money(400+random(50));
  move_object(gold, environment());

      tell_room(environment(),
          HIY+"The rider slumps off the back of the wolf leaving just a snarling wolf to deal with.\n"+NORM);
      move_object(
            clone_object("/players/tristian/realms/goblin/mobs/wolf.c"),
        this_object());
}
