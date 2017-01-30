object ME;
shadow_me(ob) {
  ME = ob;
  shadow(ob,1);
}
add_intoxication(str) {
  if(ME->query_level() > 28) return 1;
  if(ME->query_guild_name() != "Riskadh") {
    shadow(ME,0);
  }
  tell_object(ME,"You feel a the alcohol burning as it goes down.\n");
  ME->add_hit_point(-10);
  tell_object(ME,"Grand Master Riskadh tells you:  You have broken a sacred rule..\n"+
              "Cause you have used and intoxicating object the Ancients do not\n"+
              "find you worthy enough to use meditate.  You must contact Mouzar\n"+
              "to put you back in favor of the Ancients.\n");
  write_file("/players/mouzar/closed/guild/log/drink",ME->query_real_name()+" was caught drinking "+ctime(time())+".\n");
  ME->set_guild_flag("putz");
  return 1;
}
drink_alcohol(str) {
  if(ME->query_level() > 29) return 1;
  if(ME->query_guild_name() != "Riskadh") {
    shadow(ME,0);
  }
  tell_object(ME,"You feel a the alcohol burning as it goes down.\n");
  ME->add_hit_point(-10);
  tell_object(ME,"Grand Master Riskadh tells you:  You have broken a sacred rule..\n"+
              "Cause you have used and intoxicating object the Ancients do not\n"+
              "find you worthy enough to use meditate.  You must contact Mouzar\n"+
              "to put you back in favor of the Ancients.\n");
  write_file("/players/mouzar/closed/guild/log/drink",ME->query_real_name()+" was caught drinking "+ctime(time())+".\n");
  ME->set_guild_flag("putz");
  return 1;
}
 
