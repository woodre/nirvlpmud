inherit "/obj/monster.c";
/* Beck's version still has debug msgs. -Feldegast 4-22-01 
inherit "/players/beck/NewStuff/monster.c";
*/
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(3000) + 1000);
  move_object(gold,this_object());
 
move_object(clone_object("players/snow/heals/ice_sphere"),this_object());

     set_name("snow demon");
     set_short("A demon of the icy wastes");
     set_race( "spirit");
     set_alias("demon");
     set_long(
"This demon stands a good 18 feet tall with eight-inch, razor-\n"+ 
"sharp claws protruding from each of its twelve fingers per hand.\n"+ 
"The opaque crystal scales covering this demon reveal what\n"+ 
 "look to be fiery-blue organs inside. The demon moves with the\n"+ "quiet grace of an experienced killer. As it gazes deep into your\n"+ "soul you start to shake with fear you have never known before. \n");
     set_level(22);
     set_ac(14);
     set_wc(random(25)+65);
     set_hp(random(100)+500);
     set_heal(3,2);
     set_al(-1000);
     set_aggressive(1);
     set_chat_chance(7);
     set_a_chat_chance(7);

     /* 05/17/06 Earwax: snow demons should be weak v fire */
     set_armor_params("other|fire",0,-100,0); /* Double damage from fire */
     set_armor_params("other|ice",0,100,0);   /* No damage from cold     */

     load_chat("The demon looks at you with baleful eyes.\n");
     load_chat("A blue fire glows on the demon's claws.\n");
     load_a_chat("The demon rips at your soul.\n");
     load_a_chat("The demon seems to grow stronger.\n");
     set_chance(20);
     set_spell_mess1(
"The demon rips deep into the flesh of its victim and\n" + 
"licks the dripping blood from its claws.\n");
     set_spell_mess2(
"The demon rips deep into your flesh and licks your\n"+
"dripping blood from its claws.\n");
set_spell_dam(30);
   }
}

heart_beat() {
  ::heart_beat();
  if(!this_object()) return;
  if(this_object()->query_wc() < 55) {
    tell_room(environment(this_object()),
      "The Snow Demon cackles with glee!\n");
    this_object()->set_wc(80);
    this_object()->heal_self(300);
 }
  if(attacker_ob && attacker_ob == this_object()) {
    attacker_ob = 0; alt_attacker_ob = 0;
    this_object()->heal_self(300);
  }
  return 1;
}
