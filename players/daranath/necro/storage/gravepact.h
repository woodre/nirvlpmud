/* Gravepact version 1.0 for the Necromancers...
   See gravepact_list in /guild/doc for specs on the gravepact */

gravepact(str) {

int a, b, c;
int gpact;
object ob, att;

ob = present("necro_ob",this_player());
if(!str){
  if(tp->query_attack()) {att = tp->query_attack(); }
else { write("Who do you want to establish the gravepact with?\n"); return 1; }
}
else{ att = present(str, environment(tp)); }

if(tp->query_sp() < 25) {
write("You do not have the spell points available for the gravepact.\n");
return 1; }
if((ob->query_blood()) < 3) {
write("You do not have the blood available for the gravepact.\n");
return 1; }
if(!att) {
write("Who the fuck do you want to gravepact?\n");
return 1; }
if(att->is_player()) {
write("You may not establish a gravepact with a player.\n");
return 1; }
  if(!att->query_attack()) att->attacked_by(tp);
  tp->add_spell_point(-25);
  ob->add_val(3);
  ob->add_blood(-3);
  ob->save_me();

/* start of random gravepact functions */
a = tp->query_guild_rank();
b = random(10);
gpact = (random(a) + b);
write("CHECK - GRAVEPACT NUMBER "+gpact+" ENDCHECK\n");

switch(gpact) {
  case 0: c = tp->query_sp(); tp->add_spell_point(-c); break;
  case 1: break;
  case 2: break;
  case 3: break;
  case 4: break;
  case 5: break;
  case 6: break;
  case 7: break;
  case 8: break;
  case 9: break;
  case 10: break;
  case 11: break;
  case 12: break;
  case 13: break;
  case 14: break;
  case 15: break;
  case 16: break;
  case 17: break;
  case 18: break;
  case 19: break;
  case 20: break;
}
write("END GRAVEPACT \n");
return 1; 
}
