/*
  backhand_enemy.h
*/

#include "defs.h"

/* -------- Backhand an opponent for damage ---------- */
backhand_enemy(str) {
  int success_chance, random_nbr;
  object target_obj;
  if (MY_PLAYER->query_ghost()) {
    write("How can you attack anything? You are a ghost.\n");
    return 1;
  }
  if (MY_FANGS->query_in_flight()) {
    write("You cannot do that while in flight.\n");
    return 1;
  }
  if (!str)
    if (MY_PLAYER->query_attack() && MY_PLAYER->query_attack()->query_name()) {
      str = MY_PLAYER->query_attack()->query_name();
      if (!present(str, MY_ROOM)) str = 0;
    }
  if (!str) str = MY_FANGS->query_target_name();
  if (!str) {
    write("You must specify who you want to backhand.\n");
    write("Use: backhand [<who>]\n");
    return 1;
  }
  if (MY_LEVEL < 10 || MY_GUILD_EXP < 669) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if (MY_SPELL_POINTS < 20) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  target_obj = present(str, MY_ROOM);
  if (!target_obj) {
    write("'"+str+"' is not here.\n");
    return 1;
  }
  MY_FANGS->set_target_name(str);
  if (MY_LEVEL < 21 && !target_obj->query_npc()) {
    write("You can't use guild spells against players anymore!\n");
    return 1;
  }
  target_obj->attacked_by(MY_PLAYER);
  MY_PLAYER->attacked_by(target_obj);
/* Give em a chance to fail */
  success_chance = ((MY_GUILD_EXP - 666) + 1) * 2 + 85;
  random_nbr = random(100)+1;
  if (success_chance < random_nbr) {
    MY_PLAYER->add_spell_point(- 10);
    write("You missed in your attempt to slap "+capitalize(str)+".\n");
    return 1;
  }
  MY_PLAYER->add_spell_point(- 20);
  target_obj->hit_player(5+random(10));
/* changed from 10+rand(15) to 5+rand(10) sp  from 15 to 20.
   hit_player spells are 1 sp per random 2 sp per set dam. -Bp
*/
/*
  target_obj->hit_player(15+random(30));
*/
  write("You raise your right hand to near your left shoulder and with a\n"+
        "burst of energy, slap "+capitalize(str)+" with the back of your"+
        " hand, making them\n"+
        "stagger back a couple of steps!\n");
  MY_FANGS->tell_my_room(
        MY_NAME_CAP+" raises "+MY_PLAYER->query_possessive()+" right hand "+
        "to near "+MY_PLAYER->query_possessive()+" left shoulder and with\n"+
        "blinding speed, slaps "+capitalize(str)+" with the back of "+
        MY_PLAYER->query_possessive()+" hand, making them\n"+
        "stagger back a couple of steps!");
  return 1;
}
