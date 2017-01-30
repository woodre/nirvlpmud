inherit "/obj/monster";

reset(arg){
  ::reset(arg);
  if (!arg){

  set_name("scorpion");
  set_short("A scorpion");
  set_race("scorpion");
  set_long(
"This is a small, dark shaded scorpion.  It is about 8 inches long, with\n"+
"four pairs of legs, two pincerlike claws, and one venomous tail.\n"+
"It looks like if you leave it alone, it will leave you alone.\n");
  set_level(13);
  set_ac(7);              /* mguide 10   for level 13*/
  set_wc(15);             /* mguide 17  */
  set_hp(180);            /* mguide 195 */
  set_chat_chance(3);
  set_a_chat_chance(3);
  load_chat("A scorpion moves slowly across the ground.\n");
  load_chat("A scorpion sits quietly in the sand.\n");
  load_chat("A scorpion runs into a rock.\n");
  load_chat("A scorpion seems to look around.\n");
  load_chat("A scorpion twitches its tail.\n");
  load_a_chat("A scorpion claws at you.\n");
  set_dead_ob(this_object());
  }  
}

id(str){ return str == "zeus_inculta_npc"
             || str == name || str == alt_name || str == alias; }

monster_died(){
  object x,y;
  x = present("corpse", environment());
  if(x)
  {
    x -> set_short("The dead body of a scorpion");
    x -> set_long(
      "This is the dead body of a scorpion.  Its body is in bad\n"+
      "shape, having suffered fatal wounds during combat.  The\n"+
      "tail of the scorpion has been broken off.");
  }
  y = clone_object("/obj/treasure.c");
  y -> set_name("scorpion tail");
  y -> set_alias("tail");
  y -> set_short("A scorpion tail");
  y -> set_weight(1);
  y -> set_value(670+random(61));  /* mguide 700 */
  y -> set_long(
    "This is the broken tail of a scorpion.  It appears to still have\n"+
    "some poison in the venom glands.\n");
  move_object(y, environment());
  if(!(random(12)))
    move_object(clone_object("/players/fred/closed/bloodfist/obj/gem.c"), environment());
  return 1; 
}

heart_beat(){
  ::heart_beat();
  if(!environment())
    return;
  if(!attacker_ob)
    return;
  if(!random(7))
  {
    tell_object(attacker_ob,
      "The scorpion sticks you with its tail...\n"+
      "\tVenom begins to course through your body...\n");
    if(present("scorpion_z_p", attacker_ob))
      present("scorpion_z_p", attacker_ob)->add_level(level / 2);
    else
    {
      object a;
      a = clone_object("/players/zeus/desert/OBJ/scorpion_poison.c");
      move_object(a, attacker_ob);
      a -> set_level(level);
    }
  }
}
