inherit "/players/vertebraker/closed/std/monster.c";
#include "/players/tristian/lib/goblin_define.h"
object gold;

reset(arg){

 ::reset(arg);
  if (arg) return;

  set_name("Goblin Sentry");
  set_alt_name("sentry");
  set_race("goblin");
  set_alias("goblin_sentry");
  set_short("A goblin sentry in dirty armor");
  set_long("A short dirty looking humanoid that you would guess\n"+
           "to be a goblin. This goblin is wearing dirty\n"+
           "mismatched armor.\n");
  set_level(5);
  set_ac(5);
  set_wc(9);
  set_hp(75);
  set_al(-100);
  set_aggressive(0);
  set_chat_chance(4);
      load_chat("The goblin picks a bug off his armor, and EATS it.\n");
      load_chat("The goblin yawns and says, 'Me no want guard anymore.'\n");
  set_dead_ob(this_object());

  move_object(clone_object("/players/tristian/realms/goblin/obj/goblin_armor1.c"),
      (this_object()));
  init_command("wear armor");

}

  monster_died(){
      tell_room(environment(),
          "You discover a pile of coins among the remains of the goblin.\n");
  gold = clone_object("/obj/money.c");
  gold->set_money(90);
  move_object(gold, environment());
}