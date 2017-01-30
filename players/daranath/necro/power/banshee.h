/* Guild Level 11 (avatar) - Attack Spell
   Banshee has the possibility of causing the most damage in
   the necros arsenal. massive cost leads to monster damage,
   plus the 50% possibility of loosing a point of sta.
   TotalCost - 174sp (60sp, 1 soul, 3 eye, 7 blood)   */
banshee(str) {
int dam;
object ob, att;

dam = 50 + random(100);
ob = present("necro_ob",this_player());

if(!str){
  if(tp->query_attack()) {att = tp->query_attack(); }
  else { write("Banshee who???\n"); return 1; }
}
else{ att = present(str, environment(tp)); }
if(tp->query_sp() < 60) {
write("You do not have the spell points available for this spell.\n");
return 1; }
if((ob->query_soul() < 1) || (ob->query_eye() < 3) || (ob->query_blood() < 7)) {
write("You do not have the spell components available for the spell.\n");
return 1; }

if(!att) {write("There is no "+str+" here to banshee!\n"); return 1; }
if(att->is_player()) {write("You may not banshee a player!\n");
return 1; }
  if(!att->query_attack()) att->attack_object(tp);
  att->heal_self(-dam);
  tp->add_spell_point(-60);
  ob->add_val(3);
  ob->add_soul(-1);
  ob->add_eye(-3);
  ob->add_blood(-7);
  ob->save_me();

write("Banshee emote here.\n");
if(random(2) == 0) {
write("The Realm of Death takes part of your soul as the cost of the spell.\n");
tp->raise_stamina(-1);
dam = dam + 20;  }
if((present("gsite_ob",environment(tp))) || (environment(tp)->graveyard())) {
write("<"+HIW+"RoD"+NORM+"> The spell seems perfect for the confines of the Graveyard.\n");
dam = dam + 15;  }
say(tp->query_name()+"'s eyes flash with a burst of power.\n");
say(att->query_name()+" howls in pain and agnony.\n");
return 1; }
