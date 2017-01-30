resur(string who,int sub,int frac) {
if(!find_player(who)) {
    write("That person is not online.\n"); return 1; }
  if(find_player(who)->query_invis()) {
    write("That person is not online.\n"); return 1; }
  if(environment(find_player(who)) != etp) {
    write("That person is not present.\n"); return 1; }
  if(find_player(who)->query_level() > 19) {
     write("You cant heal wizes.\n"); return 1; } 
  if(!find_player(who)->query_ghost()) {
    write("That person is not dead.\n"); return 1; }
  if(tsp < sub) {
     write("You dont have enough sp.\n"); return 1; }
  find_player(who)->remove_ghost();
  find_player(who)->add_exp(find_player(who)->query_exp()/frac);
  command("save",find_player(who));
  tp->add_spell_point(-sub);
  write("\n");
  say("\n");
return 1; }