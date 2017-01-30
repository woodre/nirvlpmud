/*
  repair_exp.h
*/

/* ---- Allow upper level members to fix players who lose guild exp ---- */
repair_exp(str) {
  int i, n;
  object obj, target_obj;
  string target_name;
  if (!str) {
    write("Use: repair fangs <who> <task #>\n"+
          "                   0=no tasks done yet\n"+
          "                   1=demon priest\n"+
          "                   2=sturdy short guy (dwarf in mines)\n"+
          "                   3=Baphomet (minotaur)\n"+
          "                   4=Ironwood coffin near Sebastian the Druid\n"+
          "                   5=giants\n"+
          "                   6=gloves\n");
    return 1;
  }
  if (GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_MASTER &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_ASSISTANT &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_LEUTENANT) {
    write("You can't use that abilitiy.\n");
    return 1;
  }
  sscanf(str, "fangs %s %d", target_name, n);
  target_obj=find_player(target_name);
  if (!target_obj) {
    write("Can't find '"+target_name+"'\n");
    return 1;
  }
  if (n < 0 || n > 6) {
    write("'"+n+"' is an incorrect task #.  It must be between 0 & 6.\n");
    return 1;
  }
  obj=present("nooneelse@vampire@fangs", target_obj);
  if (!obj) {
    write(capitalize(target_name)+" doesn't have member's fangs.\n");
    return 1;
  }
  i = target_obj->query_guild_exp();
  target_obj->add_guild_exp(-i);
  i=666+n;
  target_obj->add_guild_exp(i);
  write(capitalize(target_name)+"'s task level is now '"+n+"'.\n");
  return 1;
}
