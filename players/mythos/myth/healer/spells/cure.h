cure(string who,string what,int amount,int chance) {
if(!find_player(who)) {
    write("That person is not online.\n"); return 1; }
  if(find_player(who)->query_invis()) {
    write("That person is not online.\n"); return 1; }
  if(environment(find_player(who)) != etp) {
    write("That person is not present.\n"); return 1; }
  if(find_player(who)->query_level() > 19) {
     write("You cant heal wizes.\n"); return 1; } 
  if(tsp < amount) {
     write("You dont have enough sp.\n"); return 1; }
  if(find_player(who)->query_ghost()) {
    write("You cant heal a ghost!\n"); return 1; } 
  if(who == tpn) amount = amount*2;
  if(!present(what,find_player(who))) {
     write(capitalize(who)+" has no "+what+"\n");
     tp->add_spell_point(-(amount/4));
  return 1; }
  if(chance < random(100)) { tp->add_spell_point(-(amount/2));
     write("You failed to remove the "+what+" from "+who+"\n");
  return 1; }
  tp->add_spell_point(-amount);
  destruct(present(what,find_player(who)));
  write("\n");
  say("\n");
return 1; }