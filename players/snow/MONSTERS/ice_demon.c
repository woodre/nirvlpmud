/* Average 3* wc, 1/2 ac, 1/2 hps, 7* healing, +spell seems more than fair
 * but,  since in group of agressive 4... extremely dangerous surroundings
 * put in a higher value treasure -- doubt anyone will try to kill these due to
 * very high risk of death
 * Plus, monsters have whimpy set... they run and heal if they get hurt!
 */

inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object tres,ob;
int color;
string shortdesc;

color = random(4);
  if(color == 0) shortdesc = "A grinning Ice Demon";
  if(color == 1) shortdesc = "A cackling Ice Demon";
  if(color == 2) shortdesc = "A furious Ice Demon";
  if(color == 3) shortdesc = "A stunningly beautiful Ice Demon";

  tres = clone_object("/obj/treasure.c");
  tres->set_value(random(400) + 500);
  tres->set_id("blue diamond");
  tres->set_alias("diamond");
  tres->set_long("A jaggedly beautiful diamond of impenetrable blue.\n");
  move_object(tres,this_object());
 
  ob = clone_object("/players/snow/ITEMS/ice_shard.c");
  move_object(ob,this_object());
 
     set_name("ice demon");
     set_short(shortdesc+" of the tundra");
     set_race( "spirit");
     set_alias("demon");
    set_long(
"This demon stands a good 7 feet tall with 6-inch, razor-sharp claws\n"+
"protruding from each of its eight fingers. The translucent crystal scales\n"+
"covering this demon reveal what look to be fiery-blue organs inside. The\n"+
"demon moves with incredible grace and speed. As its piercing azure eyes\n"+
"gaze into yours, you shudder in terror.\n");
     set_level(16);
     set_ac(random(5) + 5);

     /* 05/17/06 Earwax: snow demons should be weak v ice */
     set_armor_params("other|ice",0,100,0); /* No ice damage */
     set_armor_params("other|fire",0,-100,0);   /* Double fire damage */
     set_wc(55 + random(20));
     set_hp(65+random(50));
     set_heal(random(5)+1,random(3)+1);
     set_al(-1000);
     set_aggressive(1);
     set_whimpy();
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat("The demon whirls on the ice.\n");
     load_chat("A blue fire glows in the demon's eyes.\n");
     load_a_chat("The demon screams violently.\n");
     load_a_chat("The demon's claws blur toward you.\n");
set_chance(15);
set_spell_mess1(
"The demon rips its claws deep into the flesh of its victim.\n");
set_spell_mess2(
"The demon's claws rip deep into your flesh. Fiery pain wracks your body.\n");
set_spell_dam(20);
  call_out("demon_life",5);
   }
}

demon_life() {
  call_out("demon_life",10);
  if(this_object()->query_wc() < 55) this_object()->set_wc(80);
  return 1;
}
