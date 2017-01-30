shield(string who,int amount,int sub,string what) {
object shield;
if(!find_player(who)) {
    write("That person is not online.\n"); return 1; }
  if(find_player(who)->query_invis()) {
    write("That person is not online.\n"); return 1; }
  if(environment(find_player(who)) != etp) {
    write("That person is not present.\n"); return 1; }
  if(find_player(who)->query_level() > 19) {
     write("You cant shield wizes.\n"); return 1; } 
  if(find_player(who)->query_ghost()) {
    write("You cant shield a ghost!\n"); return 1; } 
  if(who == tpn) sub = sub*2;
  if(tsp < sub) {
     write("You dont have enough sp.\n"); return 1; }
  if(shield = present("shielding",find_player(who))) {}
  else shield = clone_object("/players/mythos/myth/healer/spells/shield.c");
  shield->set_time(amount);
  shield->set_percent(amount);
  if(what) shield->set_type(what);
  move_object(shield,find_player(who));
  tp->add_spell_point(-sub);
  write("\n");
  say("\n");
return 1; }