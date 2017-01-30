#define LEV "/players/dragnar/Jedi/daemons/JediLevels.c"
main(str) {
  object GUILD,who;
  int GP,level,GE;
  string Name;

  if(!str) return 0;
  if(this_player()->query_guild_rank() < 13 ) return 0;
  who = find_player(str);
  if(!who) {
    write("You concentrate on "+str+", but the Force does not aid you.\n");
    return 1;
  }
  Name = capitalize(str);
  write("You concentrate on "+Name+" and turn to the Force for vision...\n\n");
  level = who->query_guild_rank();
  GUILD = present("jedi_object",who);
  if(!GUILD) {
    environment(who)->long();
    return 1;
  }
  GP = GUILD->query_goodness_pool();
  GE = who->query_guild_exp();
    switch(GP) {
    case -100..0:
      write(Name+" has been turned to the Darkside of the Force.\n");
      break;
    case 1..10:
      write(Name+" is being consumed by anger and is in danger of falling to the Darkside.\n");
      break;
    case 11..40:
      write(Name+" stands at a crossroad, and soon must decide "+who->query_possessive()+" fate.\n");
      break;
    case 41..75:
      write(Name+" is strong with the Lightside of the Force.\n");
      break;
    default:
      write(Name+" has an ERROR.\n");
      break;
    }
  if(GUILD->query_my_master() == this_player()->query_real_name()) {
    if(LEV->QLevel(level, GE)) write("You sense that "+Name+" is ready to advance "+who->query_possessive()+" Jedi rank.\n");
  }
  return 1;
}
