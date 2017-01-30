inherit "/obj/monster.c";
short() { return 0; }
long() { return 0; }
id(str) { return this_player()->query_level() > 20 && str == "antifuckup"; }
catch_tell(str) {
  string bleh;
  if(sscanf(str, "%s enters the game.", bleh) == 1) 
    if(find_player(bleh)->query_ip() == "128.248.2.150") 
      destruct(find_player(bleh));
}
