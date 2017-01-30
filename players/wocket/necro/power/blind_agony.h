/* Guild Level 9 - Attack Spell
   Spell causes massive pain to surge through the target, lowering
   its combat abilities. Hits for small amount of dam as well.
   TotalCost - 96 sp (40sp, 1 heart, 2 skin, 5 blood)   */
blind_agony(str) {
int dam, wepchange, armchange;
object ob, ob2, ob3, att;

ob = present("necro_ob",this_player());
dam = 5 + random(25);
wepchange = 3;
armchange = 2;

if(!str){
  if(tp->query_attack()) {att = tp->query_attack(); }
  else { write("Who do you want to cast the Blinding Agony upon???\n"); return 1; }
}
else{ att = present(str, environment(tp)); }
if(tp->query_sp() < 40) {
write("You do not have the spell points available for this spell.\n");
return 1; }
if((ob->query_blood() < 5) || (ob->query_skin() < 2) || (ob->query_heart() < 1)){
write("You do not have the spell components available for the spell.\n");
return 1; }
if (!att) { write ("There is no "+str+" here to target"); return 1; }
if(att->is_player()) {write("You may not cast this spell at a player.\n");
return 1; }
  if(!att->query_attack()) att->attack_object(tp);
if(!(ob2 = present("ac_check",att))) {
  ob2 = clone_object("/players/daranath/guild/obj/misc/ac_check.c");
  move_object(ob2,att);
}
if(!(ob3 = present("wc_check",att))) {
  ob3 = clone_object("/players/daranath/guild/obj/misc/wc_check.c");
  move_object(ob3,att);
}
if(ob2->query_ac_times() > 1) {
  write("You can only cast Abandon Hope twice at the same target.\n");
  return 1; }
  else ob2->add_ac_times(1);
if(ob3->query_wc_times() > 1) {
  write("You can only cast Blinding Agony twice at the same target.\n");
return 1; }
else ob3->add_wc_times(1);
  
  tp->add_spell_point(-40);
  ob->add_val(2);
  ob->add_blood(-5);
  ob->add_skin(-2);
  ob->add_heart(-1);
  ob->save_me();
write("\nYou reach into the Realm of Death and gather power for the Blinding Agony.\n"+
      "You unleash the power of the spell at "+att->query_name()+".\n");
if((present("gsite_ob",environment(tp))) || (environment(tp)->gravesite())) {
write("<"+HIW+"RoD"+NORM+"> The Graveyard increases the power of the spell.\n");
armchange = armchange + 1;
wepchange = wepchange + 1; }
if(present("badmoon",environment(tp))){
write("<"+HIW+"RoD"+NORM+"> The Badmoon increases the damage of the spell.\n");
dam = dam + 5; }
write(att->query_name() +" howls in pain from the Agony, making it vulnerable.\n");
say(tp->query_name() +" gathers tremendous power from the Realm of Death.\n");
say(tp->query_name() +" targets "+att->query_name()+" with the spell.\n");
say(att->query_name() +" howls in pain and agony, making it vulnerable to attack.\n");
  att->set_ac(att->query_ac() - armchange);
  att->set_wc(att->query_wc() - wepchange);
  att->hit_player(dam);
return 1; }

