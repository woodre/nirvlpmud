/* Guild Level 5 - offensive spell
   Ghastly Stench hits every (non-player) target in the room, 
   causing them all some damage, while making them all attack 
   the necro. Slight additional damage if cast in graveyard.
   TotalCost - 28 + 20 per target
     (20sp per target, 1 eye, 4 blood)    */
ghast_stench() {
int i,dam;
object ob, att;

ob = present("necro_ob",this_player());
dam = 10 + random(20);

if(tp->query_sp() < 20) {
write("You do not have the spell points available for this spell.\n");
return 1; }
if((ob->query_blood() < 4) || (ob->query_eye() < 1)){
write("You do not have the spell components available for the spell.\n");
return 1; }

write("You channel energy fromthe Realm of Death into your spell.\n");
if(present("gsite_ob",environment(tp))){
write("The graveyard increases the power of your spell.\n");
dam = dam + 4; }
write("A sickly green mist rises from the ground.\n");
say(tp->query_name()+" casts a dark spell.\n"+
    "A sickly green mist rises from the ground.\n");

att = all_inventory(environment(tp));
for(i=0;i<sizeof(att);i++) {
  if(living(att[i])) 
    if(att[i]->query_npc() && this_player()->valid_attack(att[i]))
        if(this_player()->query_sp() > 20) {
		  tp->add_spell_point(-20);
          att[i]->hit_player(dam);
    write(att[i]->query_name() +" recoils in pain from the Ghastly Stench.\n");
    say(att[i]->query_name() +" recoils in pain from the mist.\n");
          att[i]->attack_object(tp);
        } else {
          write("You have run out of spell points to continue the stench attack.\n");
          return 1;
		}
}

  ob->add_val(1);
  ob->add_blood(-4);
  ob->add_eye(-1);
  ob->save_me();
return 1; }
