/* Guild Level 10 - Attack Spell
   Deathfog hits every target within the room (aka gstench) for
   a considerable amount of damage. 
   TotalCost - 80sp plus 30sp per target
    (1 spine, 2 eye, 5 blood, 30sp per target)   */
deathfog() {
int dam, i;
object ob, att;

ob = present("necro_ob",this_player());
dam = 20 + random(40);

if(tp->query_sp() < 30) {
write("You do not have the spell points available for this spell.\n");
return 1; }
if((ob->query_blood() < 5) || (ob->query_spine() < 1) || (ob->query_eye() < 2)){
write("You do not have the spell components available for the spell.\n");
return 1; }

write("You channel energy form the Realm of Death into your spell.\n");
say(tp->query_name()+" casts a dark spell.\n");
if(present("gsite_ob",environment(tp))){
write("The graveyard lends its strength to the spell.\n");
say(tp->query_name()+" seems to grow in power while in the graveyard.\n");
dam = dam + 5;  }
write("A dark cloud billows forth, engulfing the area.\n");
say("A dark cloud billows forth, engulfing the area.\n");

att = all_inventory(environment(tp));
for(i=0;i<sizeof(att);i++) {
  if(living(att[i])) 
     if(att[i]->query_npc())
        if(this_player()->query_sp() > 30) {
		  tp->add_spell_point(-30);
         att[i]->hit_player(dam);
    write(att[i]->query_name() +" recoils in pain and agony from the DeathFog.\n");
    say(att[i]->query_name() +" recoils in pain and agony from the dark cloud.\n");
          att[i]->attack_object(tp);
        } else {
          write("You have run out of spell points to continue the deathfog attack.\n");
          return 1;
		}
}

  ob->add_val(2);
  ob->add_blood(-5);
  ob->add_spine(-1);
  ob->add_eye(-2);
  ob->save_me();
return 1; }
