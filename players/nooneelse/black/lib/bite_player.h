/*
  bite_player.h
*/

#include "defs.h"

/* -------- Bite a player (recuitment) ---------- */
bite_player(str) {
  object obj, target_obj;
  int is_a_traitor;
  string msg;

  if (!str) {
    write("You must specify who you want to bite.\n");
    write("Use: bite <who>\n");
    return 1;
  }

/*
if(this_player()->query_real_name() == "kazer") {
  write("You try to bite but are unsuccessful...\n");
  return 1; }
*/

target_obj=present(str, MY_ROOM);
if(!target_obj) {
  write(capitalize(str)+" is not here!\n");
  return 1; }

/* >>><<<< */
  if (MY_LEVEL < 17 || MY_GUILD_EXP < 671) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if (MY_FANGS->check_guild(str)!="{     ~:~    }") {
    if (MY_FANGS->check_guild(str)!=" ") {
      write(capitalize(str)+" is already in the "+
            MY_FANGS->check_guild(str)+" guild!\n");
      return 1;
    }
  }
  obj=present("vampirebite", target_obj);
  if (present("nooneelse@vampire@fangs", target_obj)) {
    write("That player is already a vampire!\n");
    return 1;
  }
  if (target_obj->query_guild_exp()==1) target_obj->add_guild_exp(-1);
  if (target_obj->query_guild_exp()) {
    write("You can't recruit a member of another guild.\n"+
          "Have them leave their old guild first.\n");
    return 1;
  }
  if (target_obj->query_guild_exp()==1234) {
    write(target_obj->query_name()+" has been banned from all the guilds!\n"+
          "You cannot bite "+target_obj->query_objective()+".\n");
    return 1;
  }
  if (target_obj->query_npc()) {
    write("You can only bite players!\n");
    return 1;
  }
  call_other(GUILD_PROHIBIT, "???");
  is_a_traitor = GUILD_PROHIBIT->query_traitor(target_obj->query_real_name());
  if (is_a_traitor) {
    write(capitalize(target_obj->query_real_name())+
          " is a traitor to the guild!  You cannot bite traitors!\n");
    return 1;
  }
  if(target_obj->query_level() < 3) {
     write("A player must be level 3 to join a guild.\n");
     return 1;
  }
  /* no biting in wizards unless its by a guild master or assistant */
  if(target_obj->query_level() > 20 &&
     (GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_MASTER &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_ASSISTANT)) {
     write("Only the Guild Master or a Guild Assistant can bite wizards.\n");
     return 1;
  }
  /* wizards don't get to bite unless its by a guild master, assistant, or lieutenant */
  if(MY_LEVEL > 20 &&
     (GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_MASTER &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_ASSISTANT &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_LIEUTENANT)) {
     write("Wizards cannot bite players. That's getting involved in player affairs.\n");
     return 1;
  }
  MY_FANGS->tell_my_room(
          MY_NAME_CAP+
          " pierces "+capitalize(target_obj->query_name())+"'s neck with "+
          MY_PLAYER->query_possessive()+" fangs and drinks deeply.");
  write("As you open your jaws wide to be able to clamp down on "+
        capitalize(str)+"'s\n"+
        "neck, your lips slide back to expose your sharp fangs.\n"+
        "You feel an almost electric shock as the first drop of "+
        target_obj->query_possessive()+"\n"+
        "blood touches your tongue.\n");

  /* added track who is biting who */
  msg = MY_NAME_CAP + "\t\tbit\t" + capitalize(str) +
        "\t\ton\t" + ctime(time()) + "\n";
  write_file("/players/nooneelse/black/VAMPIRE_BITE.log", msg);
  if (obj) {
    obj->add_a_bite(MY_NAME);
    return 1;
  }
  obj=clone_object(VAMPIRE_BITE);
  move_object(obj, target_obj);
  obj->add_a_bite(MY_NAME);
  return 1;
}
