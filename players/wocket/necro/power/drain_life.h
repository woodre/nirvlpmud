/* Guild Level 3 - Neg heal attack spell plus slight healing.
   healing effect symulates necro taking lifeforce as thier own.
   TotalCost - 32 sp (20 sp, 1 Skin and 2 Blood)   */
drain_life(str) {
int dam, heal;
object ob, att;

dam = 5 + random(15);
heal = random(8);
ob = present("necro_ob",this_player());

if(!str) {
  if(tp->query_attack()) {att = tp->query_attack(); }
  else { write("Lifedrain who???\n"); return 1; }
} else { att = present(str, environment(this_player())); }

if(tp->query_sp() < 20) {
write("You do not have the spell points available for this spell.\n");
return 1; }
if((ob->query_blood() < 2) || (ob->query_skin() < 1)) {
write("You do not have the spell components available for the spell.\n");
return 1; }
if (!att) { write ("There is no "+str+" here to touch"); return 1; }
if(att->is_player()) {write("You may not drain a player!\n");
return 1; }
  if(!att->query_attack()) att->attacked_by(tp);
  tp->add_spell_point(-20);
  ob->add_val(1);
  ob->add_blood(-2);
  ob->add_skin(-1);
  ob->save_me();
write("You open a channel between the Realm of Death and Nirvana.\n"+
      "You use the negative energy to drain the life from your foe.\n");
if(present("badmoon",environment(tp))){
dam = dam + 3;
heal = heal + 2;
write("<"+HIW+"RoD"+NORM+"> Your spell grows stronger by the presence of the BadMoon\n"); }
write("You seem stronger from the lifedrain.\n");
say(tp->query_name() +" releases a dark spell at "+att->query_name()+".\n");
say(tp->query_name() +" grows stronger as "+att->query_name()+" howls in pain.\n");
  tp->add_hit_point(heal);
  att->heal_self(-dam);
return 1; }
