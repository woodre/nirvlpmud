#define LEV "/players/dragnar/Jedi/daemons/JediLevels.c"
#define LOG "/players/dragnar/Jedi/logs/Deaths"

jedi_death(object USER) {
  int i, j, lost, gexp, cexp;
  string type;
  object JEDI;

  if(!USER || USER->query_level() > 19) return;
  JEDI = present("jedi_object",USER);
  if(!JEDI) return;
  gexp = USER->query_guild_exp();
  write_file(LOG, ctime(time())+" "+USER->query_name()+": Jedi Rank: "+USER->query_guild_rank()+", "+gexp+" GEXP, "+gexp/8+" GEXP lost.\n");
  gexp /= 10;
  USER->add_guild_exp(-gexp);
  cexp=call_other("room/adv_guild", "check_level", USER->query_level());
  if(USER->query_exp() < cexp)
    call_other("room/adv_guild", "correct_level", USER);
  if (USER->query_extra_level()) {
    cexp=call_other("room/exlv_guild", "check_level", USER->query_extra_level());
    if(USER->query_exp() < cexp)
      call_other("room/exlv_guild", "correct_extra_level", USER);
  }
  tell_object(USER, "\tJEDI DEATH! LOSING: "+gexp+" guild exps!\n");

  if( USER->query_guild_rank() < 2) return 1;
  while(!LEV->CheckLevel(USER->query_guild_rank(), USER->query_guild_exp())) {
    USER->add_guild_rank(-1);
    tell_object(USER, "You are now Jedi Level: "+USER->query_guild_rank()+".\n");
    lost++;
  }
  if(lost) 
    write_file(LOG, ctime(time())+" "+USER->query_name()+" lost "+lost+" Jedi levels.\n");
  for(i=0; i < lost; i++) {
    type = SelectType();
    while(!JEDI->query_skill(type) && j < 4) {
      type = SelectType(type);
      j++;
    }
    if(j > 3) {
      i = lost;
      if(JEDI->query_skill_points()) {
        JEDI->adj_skill_points(-lost);
        write_file(LOG, ctime(time())+" "+USER->query_name()+" had skill_points reduced.\n");
        if(JEDI->query_skill_points() < 0) 
          JEDI->set_skill_points(0);
      }
    }
    else {
      if(type) {
      JEDI->adj_skill(type, -1);
      tell_object(USER, "Your skill: "+type+" is now "+JEDI->query_skill(type)+".\n");
      write_file(LOG, ctime(time())+" "+USER->query_name()+" had "+type+" reduced.\n");

      }

    }
  j = 0;
  }
  write_file(LOG, "\n");
  JEDI->save_stats();
  USER->save_me();
  return 1;
}

string SelectType(string str) {
  int j;
  string type;

  if(!str) j = random(4);
  if(str == "telekinesis") j = 1;
  if(str == "telepathy") j = 2;
  if(str == "physical") j = 3;
  if(str == "saber") j = 0;
  if(j == 0) type = "telekinesis";
  if(j == 1) type = "telepathy";
  if(j == 2) type = "physical";
  if(j == 3) type = "saber";
  return type;
}
