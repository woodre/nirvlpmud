heal(string who,string what,int sub,int amount) {
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
  if(tp->query_exp() < ) {
     write("You cant do that.\n"); return 1; }
  find_player(who)->set_attrib(what,(find_player(str)->query_attrib(what))+1);
  tp->add_spell_point(-sub);
  tp->add_exp(-amount);
  write("\n");
  command("save",tp);
  say("\n");
return 1; }