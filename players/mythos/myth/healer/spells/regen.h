#define MAXREG 3

regen(string who,int percent,int sub,string what) {
object regen;
string type;
int ok;
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
  if(who == tpn) sub = sub*2; ok = 0;
  if(tsp < sub) {
     write("You dont have enough sp.\n"); return 1; }
  if(!what) type = "both"; else type = what;
  if(regen = present("reg_"+type,find_player(who))) {
    if(regen->query_amount() > MAXREG) ok = 1;}
  else regen = clone_object("/players/mythos/myth/healer/spells/regen.c");
  regen->set_percent(percent);
  regen->set_type(type);
  if(!ok) regen->set_amount(regen->query_amount() + 1);
  move_object(regen,find_player(who));
  tp->add_spell_point(-sub);
  write("\n");
  say("\n");
return 1; }