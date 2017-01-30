string name,guild_name;
int level,guild_exp,ex_lv,experience,guild_rank;

id( str ) {
        if(str=="qgm") return 1;
        return 0;
}

set_search(str) {
  if(!str) return;
  if(!restore_object("players/"+str)) {
    name="<noone>";
    return 1;
  }
  return 1;
}

query_guild_name(){ return guild_name; }

query_guild_rank() { return guild_rank; }

query_name() {
  return capitalize(name);
}

query_real_name() {
  return name;
}

query_guild_exp() { return guild_exp; }

query_level() {
  return level;
}

query_extra_level(){return ex_lv;}

query_exp() {
  return experience;
}
