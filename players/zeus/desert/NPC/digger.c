inherit "/obj/monster";
int *shell, c;

reset(arg){
  ::reset(arg);
  if (!arg){

  c = -1;
  shell =({ 10,9,9,9,10,14,18,20,20,20,20,18,14 });  /* 13 */
  set_name("digger");
  set_short("A hard-shelled digger");
  set_race("creature");
  set_gender("creature");
  set_long(
"This is a fairly small creature that lives inside its shell.  The shell\n"+
"itself is faded and old, but still looks very beautiful.  The creature\n"+
"has four short legs, and on the front two it has small claws ideal for\n"+
"digging into the hard ground.  It has a fairly long neck, with a small,\n"+
"round head and a very hard beak.\n");
  set_level(15);
  set_ac(12);             /* mguide 12   for level 15*/
  set_wc(16);             /* mguide 20  */
  set_hp(280);            /* mguide 225 */
  set_heal(1,5);
  set_chat_chance(3);
  set_a_chat_chance(3);
  load_chat("A digger moves about slowly.\n");
  load_chat("A digger pokes its head out to look around.\n");
  load_chat("A digger stops for a moment to dig at the ground.\n");
  load_chat("A digger seems to look at you.\n");
  load_a_chat("A digger hits you with a crushing blow.\n");
  set_dead_ob(this_object());
  }  
}

id(str){ return str == "zeus_inculta_npc"
             || str == name || str == alt_name || str == alias; }

monster_died(){
  object x,y;
  x = present("corpse", environment());
  x -> set_short("The small corpse of a digger");
  x -> set_long(
    "This is the little body of a dead digger.  Outside of its\n"+
    "shell it looks very helpless.  You almost feel bad that you\n"+
    "decided to take its life in the first place.");
  y = clone_object("/obj/treasure.c");
  y -> set_name("digger shell");
  y -> set_alias("shell");
  y -> set_short("The shell of a digger");
  y -> set_weight(1);
  y -> set_value(800+random(110));  /* mguide 875 */
  y -> set_long(
    "This shell used to provide protection for a digger, until you decided\n"+
    "to mercilessly kill it.  The shell has seen much wear and tear from\n"+
    "the sands of the desert, but you can still make out a faint pattern\n"+
    "of colors.  It is actually a quite beautiful piece of treasure.\n");
  move_object(y, environment(x));
  if(!(random(12)))
    move_object(clone_object("/players/fred/closed/bloodfist/obj/gem.c"), environment());
  return 1; 
}

void heart_beat(){
  ::heart_beat();
  if(!environment())
    return;
  if(!attacker_ob)
    return;
  c++;
  if(c > 12)
    c = 0;
  armor_class = shell[c];
  if(c == 0)
  {
    tell_room(environment(),
      "The digger pokes its head out to look around.\n");
    weapon_class += 4;
  }
  if(c == 1 || c == 2 && !random(2))
  {
    tell_object(attacker_ob,
      "The digger bites you with its hard beak!\n");
    attacker_ob->hit_player(14);
  }
  else if(c == 4)
  {
    tell_room(environment(),
      "The digger hides its head in its shell.\n");
    weapon_class -= 4;
  }
}

