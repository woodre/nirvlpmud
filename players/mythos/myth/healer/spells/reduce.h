reduce(string who,string what,int amount,int sub) {
if(!find_player(who)) {
    write("That person is not online.\n"); return 1; }
  if(find_player(who)->query_invis()) {
    write("That person is not online.\n"); return 1; }
  if(environment(find_player(who)) != etp) {
    write("That person is not present.\n"); return 1; }
  if(find_player(who)->query_level() > 19) {
     write("You cant heal wizes.\n"); return 1; } 
  if(find_player(who)->query_ghost()) {
    write("You cant heal a ghost!\n"); return 1; } 
  if(who == tpn) sub = sub*2;
  if(tsp < sub) {
     write("You dont have enough sp.\n"); return 1; }
  if(what == "intox") find_player(who)->add_intoxination(-amount);
  if(what == "stuff") find_player(who)->add_stuffed(-amount);
  if(what == "soak") find_player(who)->add_soaked(-amount);
  tp->add_spell_point(-sub);
  write("\n");
  say("\n");
return 1; }