make_monster() {
  object monster;
  monster = clone_object("/obj/monster");
  /* name and alias are what the monster is identifyable by */
  monster->set_name("chipmunk");
  monster->set_alias("tiny");
  monster->set_race("critter");
  monster->set_short("Tiny chipmunk");
  monster->set_long(
  "A tiny little chipmunk.  Cute isn't it?\n");
  monster->set_level(7);
    if(random(100)>80) { monster->set_aggressive(1); }
    if(random(100)>20) { monster->set_whimpy(1); }
/* I want to think about this some.
    if(random(100)>90) { monster->set_can_kill(1); }
*/
  monster->set_hp(105);
  monster->set_wc(11);
  monster->set_ac(6);
  monster->set_ep(25000);   
  monster->set_al(-100);
  /* set up a message seen when the monster is around */
  monster->load_chat("The chipmunk chips at a nut.\n");
  monster->set_chat_chance(5); /* 5% chance of seeing it */
  /* set up a message seen when the monster is fighting */
  monster->load_a_chat("The tiny chipmunk SCREECHES at you!\n");
  monster->set_a_chat_chance(20);
  /* Set up monster spell */
  monster->set_chance(22);
  monster->set_spell_dam(random(7));
  monster->set_spell_mess1("Chipmunk bites it's victim!\n");
  monster->set_spell_mess2("Chipmunk bites you!\n");
  return monster; /* return our created monster to the room */
}
