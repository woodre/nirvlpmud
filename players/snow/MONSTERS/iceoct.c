inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold,ob;
  gold = clone_object("obj/money");
  gold->set_money(random(1000) + 1000);
  move_object(gold,this_object());

  ob = clone_object("players/snow/WEAPONS/ice_star");
  move_object(ob,this_object());
 
     set_name("Ice Octopus");
set_short("A beautiful crystalline structure with waving tentacles");
     set_race( "octopus");
     set_alias("structure");
     set_long(
"This is an incredible creature made entirely from living crystals of ice.\n"+
"Its eight crystal clear arms are tinged with a bluish light and in its eyes\n"+
"you see a piercing gleam of intelligence.\n");
     set_level(19);
     set_ac(10);
     /* 05/17/06 Earwax: snow demons should be weak v fire */
     set_armor_params("other|ice",0,100,0); /* No ice damage */
     set_armor_params("other|fire",0,-100,0);   /* Double fire damage */
     set_wc(30);
     set_hp(400);
/* NEW CODE */
set_wc_bonus(5);
     set_al(1000);
     set_aggressive(0);
set_chance(80);
set_spell_mess1(
"One of the ice octopus' crystal tentacles wraps around its prey. The\n"+
"hapless victim screams in pain!\n");
set_spell_mess2(
"A crystal tentacle wraps tightly around your body. You scream in pain!\n");
set_spell_dam(15);
   }
}

heart_beat() {
  ::heart_beat();
  if(!random(3)) tentacles();
 }

tentacles() {
  object meat;
  if(!environment(this_object())) return 1;
  meat = attacker_ob;
  if(meat)
   if(environment() == environment(meat)) {
    say("The Ice Octopus reaches out with its tentacles!\n"+"\n"+
        capitalize(meat->query_name())+" is wrapped in an icy grip!\n");
    tell_object(meat,"You writh in pain as the tentacles crush you!\n");
   meat->hit_player(random(20)+5); return 1; }
return 1;
}
