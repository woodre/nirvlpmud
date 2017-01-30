backstab(str) {

int MAX, dam;
int MAX_SP, SPCOST;
object ob, att;
MAX = 50;
MAX_SP = 75;

ob = present("necro_ob",tp);


if(!str){
write("What do you want to backstab?\n");
return 1;
} else{ att = present(str, environment(tp)); }
 if(tp->query_attack()) { 
  write("You cannot backstab while in combat already.\n");
  return 1; }
if(tp->query_sp() < 25+10*tp->query_guild_rank()) {
write("You do not have the spell points available for this spell.\n");
return 1; }
if(!att) {write("There is no "+str+" here to backstab.\n"); return 1; }
if(att->is_player()) {write("You may not backstab a player!\n");
return 1; }
if(!present("necro_tool",tp)) { write("You do not have a harvesting tool!\n"); return 1; }
if(!present("necro_tool",tp)->query_wielded()) {
  write("You are not wielding the harvesting tool!\n");
return 1; }

dam = 10 + random(10*tp->query_guild_rank());
if(dam > MAX) dam = MAX;
SPCOST = 25 + 10*tp->query_guild_rank();
if(SPCOST > MAX_SP) SPCOST = MAX_SP;
  att->hit_player(dam);
  tp->add_spell_point(-SPCOST);
  ob->add_val(2);
  ob->save_me();
write("You move around you opponent, hiding in the shadows as you go.\n");
write("You get close and backstab "+att->query_name()+", striking with surprise.\n");
write("The harvesting tool almost seems to make this easy.\n\n");
say(tp->query_name()+" fades into the shadows and sneaks around behind "+att->query_name()+".\n");
say(tp->query_name() +" drives the harvesting tool deep into the back of "+att->query_name()+".\n");
say(att->query_name()+" howls in pain from the backstab!\n");
  att->attack_object(tp);
return 1; }
