query_guild_level()     { return guild_level; }
query_guild_exp()       { return guild_exp; }
query_mana()            { return mana; }
query_max_mana()        { return max_mana; }
query_faith()           { return faith; }
query_is_quiet()        { return is_quiet; }
query_donated()         { return donated; }
query_faith_quest()     { return faith_quest; }
query_faith_donate()    { return faith_donate; }
query_heal_count()      { return heal_count; }

query_exp_needed() {
  
       if(Glevel == 14) return 2000000;
  else if(Glevel == 13) return 1500000;
  else if(Glevel == 12) return 800000;
  else if(Glevel == 11) return 400000;
  else if(Glevel == 10) return 200000;
  else if(Glevel == 9 ) return 100000;
  else if(Glevel == 8 ) return 50000;
  else if(Glevel == 7 ) return 30000;
  else if(Glevel == 6 ) return 16000;
  else if(Glevel == 5 ) return 8000;
  else if(Glevel == 4 ) return 4000;
  else if(Glevel == 3 ) return 2000;
  else if(Glevel == 2 ) return 1000;
  else if(Glevel == 1 ) return 500;
  else return 3000000;
}

set_mana(s)             { mana = s; }
set_max_mana(m)         { max_mana = m; }
set_guild_level(gl)     { guild_level = gl; }
set_faith(h)            { faith = h; }
set_faith_quest(h)      { faith_quest = h; }
set_faith_donate(h)     { faith_donate = h; }

add_guild_exp(ep) {
  guild_exp += ep;
}

add_mana(st) {
  mana += st;
  if(mana > max_mana)
     mana = max_mana;
}

add_faith(h) {
  faith += h;
}

