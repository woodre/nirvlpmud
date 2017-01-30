weaken(str) {
int dam, armorchange, wepchange;
object ob, ob2, att;

ob = present("destroyer_ob",this_player());
dam = random(20);
armorchange = 4;
wepchange = 2;
/*
if(this_player()->query_guild_rank() < 7){ write("You can't use ability yet.\n"); return 1; }
*/
if(this_player()->query_guild_rank() < 8){ write("You can't use this spell yet.\n"); return 1; }
    if (!USER->query_attack()){
        write("You must be fighting to use weaken.\n");
        return 1;
    }
if(!str){
  if(tp->query_attack()) {att = tp->query_attack(); }
  else { write("Weaken who???\n"); return 1; }
}
else{ att = present(str, environment(tp)); }
if(tp->query_sp() < 50) {
write("You do not have the spell points available for this spell.\n");


return 1; }
if (!att) { write ("There is no "+str+" here to target.\n"); return 1; }
if(att->is_player()) {write("You may not cast this skill on a player.\n");
return 1; }
  if(!att->query_attack()) att->attack_object(tp);
if(!(ob2 = present("armyac_check",att))) {
  ob2 = clone_object("/players/pestilence/closed/destroyer/obj/ac_check.c");
  move_object(ob2,att);
}
  if(ob2->query_ac_times() == 1) {
  write("You can only weaken a mob once.\n");
  return 1; }
  else ob2->add_ac_times(1);
  tp->add_spell_point(-50);

write("\nYou bellow loudly!.\n"+
      "You the ram your shoulder into "+att->query_name()+"'s midsection leaving them slightly more vulnerable.\n");
write(att->query_name() +" hunches over in pain.\n");
say(tp->query_name() +" bellows loudly!\n");
say(tp->query_name() +" rams their shoulder into "+att->query_name()+"'s midsection leaving them slightly more vulnerable.\n");
say(att->query_name() +" hunches over in pain.\n");
  att->set_ac(att->query_ac() - armorchange);
  att->set_wc(att->query_wc() + wepchange);
return 1; }
