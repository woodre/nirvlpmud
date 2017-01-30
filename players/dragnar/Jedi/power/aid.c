#include "defs.h"

inherit CMDBASE;

main(string str){
  object AIDED, ATTACKER, ATTWHO;

  if(USER->query_ghost()) return 0;

  skill_type = "physical";
  if(skill_check(1)) return 1;
  if(cp_check(10)) return 1;
  if(delay_check()) return 1;

  if(!str){
    tell_object(USER,"Aid who?\n");
    return 1;
  }
  AIDED = present(str, environment(USER));
  if(!AIDED){
    tell_object(USER, "That person is not here.\n");
    return 1;
  }

  if(AIDED == this_player()) return 0;
  if(!AIDED->query_attack()){
    tell_object(USER, "That person is not fighting.\n");
    return 1;
  }

  tell_room(environment(USER), USER->query_name()+" rushes forward and meets "
    +capitalize(str)+"'s attacker.\n",({this_player(),AIDED}));

  tell_object(AIDED, USER->query_name()+" rushes forth and meets your attacker!\n");

  write("You rush forth and meet "+capitalize(str)+"'s attacker.\n");
  
  this_player()->hit_player(random(20));
  ATTACKER = AIDED->query_attack();
  AIDED->add_hit_point(SKILL);
  PO->adj_cp(-10);
  USER->attack_object(ATTACKER);
  ATTACKER->attack_object(USER);
  PO->set_force_delay(2);
  USER->add_guild_exp(random(5) + 10);
  return 1;
}
