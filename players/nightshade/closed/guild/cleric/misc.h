members(str) {
object list, badge;
string P,N,LV,GL;
string GC;
int p,lv,gl,i;
int z, GB;
int gen;
list = users();
i = 0;

  write("                    -=:{ CLERICS OF FAITH }:=- \n");
  write(
"Name           Level          Guild Level     Class\n");
write(
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  while(i < sizeof(list)) {
    badge = present("cleric_guild", list[i]);
    if(badge && list[i]->query_name() != "Someone") {
      lv = list[i]->query_level();
      gl = badge->query_guild_level();
      if(lv < 49) LV = lv;
      else LV = "Wiz";
      N = list[i]->query_name();
      N = capitalize(N);
      N = N+extract("               ",0,15-strlen(N));
      GC = badge->query_guild_class();
      GB = badge->query_is_quiet();
      gen = list[i]->query_gender();
      write(N);
      write(LV + "\t\t");
      if(gl == 15) write("AVATAR\t");
      else
      if(gl == 20) {
        if(gen == 1) write("LORD\t");
        else write("LADY\t");
      }
      else
      write(gl + "\t");
      if(GB) write("B\t");
      else write(" \t");
      if(GC) write(GC + "\n");
      else write("Cleric\n");
    }
    i ++;
  }
  guildsave();
  return 1;
}

donate(str) {
int am;
  if(!str) {
    write("How much do you want to donate?\n");
    return 1;
  }
  sscanf(str, "%d", am);
  if(Me->query_money() < am) {
    write("You do not have that much money!\n");
    return 1;
  }
  if(am < 1) {
    write("You can not cheat Matry!!!\n");
    return 1;
  }
  donated = donated + am;
  Me->add_money(-am);
  write("You donate " +am+ " coins to the guild.\n");
  if(!Badge->query_faith_donate() &&
        Badge->query_donated() > 49999) {
    write("For donating 50k or more, you feel more faithful.\n");
    Badge->add_faith(1);
    faith_donate = 1;
    write_file("/players/nightshade/notes/FAITH",
    ctime(time())+": "+NAME+"("+Faith+") 1 faith for donating 50k\n");
    return 1;
  }
  return 1;
}
help_file(str) {
  if(!str) {
      cat("/players/nightshade/closed/guild/doc/cleric");
    new_shield();
    return 1;
  }
  if(str == "level") {
   cat("/players/nightshade/closed/guild/doc/clevel");
     new_shield();
    return 1;
  }
  if(str == "heal") {
   cat("/players/nightshade/closed/guild/doc/heal");
    new_shield();
    return 1;
  }
  if(str == "magic") {
   cat("/players/nightshade/closed/guild/doc/magic");
    return 1;
  }
  if(str == "attack") {
   cat("/players/nightshade/closed/guild/doc/attack");
    return 1;
  }
  if(str == "summon") {
   cat("/players/nightshade/closed/guild/doc/summon");
    return 1;
  }
  if(str == "general") {
   cat("/players/nightshade/closed/guild/doc/general");
    return 1;
  }
  if(str == "mana") {
   cat("/players/nightshade/closed/guild/doc/mana");
    return 1;
  }
  if(str == "all") {
   cat("/players/nightshade/closed/guild/doc/all");
    return 1;
  }
  if(str == "new") {
   cat("/players/nightshade/closed/guild/doc/cleric_new");
    return 1;
  }
/*
  if(str == "code") {
   cat("/players/nightshade/closed/guild/doc/code");
    return 1;
  }
*/
}


beckon_servant() {
  if(!servant) {
    write("Can't find your servant.\n");
    return 1;
  }
  if(environment(Me)->query_property("NT")) {
    write("The room will not allow you.\n");
    return 1;
  }
  write("You whistle for you servant.\n");
  servant->servant_blah();
  move_object(servant, environment(Me));
  tell_room(environment(Me), "A servant arrives.\n");
  return 1;
}

recycle(str) {
object bot;
  if(str == "bottle") {
    bot = present("bottle", Me);
    if(!bot) {
      write("You do not have a bottle.\n");
      return 1;
    }
    if(bot->query_value() != 10) {
      write("You might not want to recycle that bottle.\n");
      return 1;
    }
    write("You recycle the bottle.\n");
    Gain(Glevel);
    Boost(random(5));
    say(Name+" recycles a bottle.\n");
    destruct(bot);
    return 1;
  }
}
new_members() {
object list, badge;
object loc;
string P,N,LV,GL;
string GC;
int p,lv,gl,i;
int z, GB;
int gen;

  if(Glevel < 5) return;
list = users();
i = 0;

  write("                    -=:{ KNIGHTS OF HONOR }:=- \n");
  write(
" B  Name          Level Glevel  Location\n");
write(
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  while(i < sizeof(list)) {
    badge = present("cleric_guild", list[i]);
    if(badge && list[i]->query_name() != "Someone") {
      lv = list[i]->query_level();
      gl = badge->query_guild_level();
      if(lv < 50) LV = lv;
      else LV = "Wiz";
      N = list[i]->query_name();
      N = capitalize(N);
      N = N+extract("               ",0,15-strlen(N));
      GB = badge->query_is_quiet();
      gen = list[i]->query_gender();
      if(GB) write(" B  ");
      else write("    ");
      write(N);
      write(LV+ "\t");
      if(gl == 16) write("AGM\t");
      else
      if(gl == 17) write("GM\t");
      else
      if(gl == 18) write("KGM\t");
      else
      if(gl == 20) {
        if(gen == 1) write("LORD\t");
        else write("LADY\t");
      }
      else
      write(gl + "\t");
      loc = environment(list[i]);
      if(loc && loc->query_short()) write(loc->query_short());
      else if(loc && !loc->query_short()) write("No short description");
      else write("No environment");
      write(".\n");
    }
    i ++;
  }
  guildsave();
  return 1;
}
guild_mem(str) {
object list, badge;
string N, LV, guild;
int p,lv,gl,i;
int z, GB;
int gen;
  if(!str) {
    write("members <knight> or <cleric> \n");
    return 1;
  }
  if(str != "knight" && str != "cleric") {
    write("members <knight> or <cleric>\n");
    return 1;
  }
  if(str == "knight") guild = "knight";
  if(str == "cleric") guild = "cleric";
list = users();
i = 0;

write("\t\tMembers of the "+
        capitalize(guild)+"'s Guild.\n");
  write(
"Name            Level   Gender          Block\n");
write(
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  while(i < sizeof(list)) {
    badge = present(guild+"_guild", list[i]);
    if(badge && list[i]->query_name() != "Someone") {
      lv = list[i]->query_level();
      if(lv < 50) LV = lv;
      else LV = "Wiz";
      N = list[i]->query_name();
      N = capitalize(N);
      N = N+extract("               ",0,15-strlen(N));
      GB = badge->query_is_quiet();
      gen = list[i]->query_gender();
      write(N);
      write(LV + "\t");
      if(gen == 1) write("Male  \t\t");
      else write("Female\t\t");
      if(GB) write("B\t");
      else write(" \t");
      write("\n");
    }
    i ++;
  }
  guildsave();
  return 1;
}

