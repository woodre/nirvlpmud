#define LEV "/players/dragnar/Jedi/daemons/JediLevels.c"

main(str) {
  object GUILD,who;
  int level,GE;
  string Name;

  if(!str) { write("Train who?\n"); return 1; }
  if(this_player()->query_guild_rank() < 13 ) {
    write("You are not a Jedi master.\n");
    return 1; }
  Name = capitalize(str);
  who = find_player(str);
  if(!who || !present(who->query_real_name(), environment(this_player()))) {
    write(Name+" is not here.\n");
    return 1; }
  level = who->query_guild_rank();
  GUILD = present("jedi_object",who);
  if(!GUILD) {
    write(Name+" is not a Jedi.\n");
    return 1; }
  GE = who->query_guild_exp();
  if(GUILD->query_my_master() == this_player()->query_real_name()) {
    if(level > 12) {
      write(Name+" has already reached Master Jedi rank.\n");
      return 1;
    }
    if(LEV->QLevel(level, GE)) {
      LEV->Advance(who);
      write("You advance "+Name+"'s Jedi rank.\n");
      tell_object(who, "Your Master has advanced your Jedi rank.\n");
      return 1;
    }
    else {
      write(Name+" is not yet ready to take on the burden of more power.\n");
      return 1;
    }
  }
  write("You are not "+Name+"'s Master.\n");
  return 1;
}
