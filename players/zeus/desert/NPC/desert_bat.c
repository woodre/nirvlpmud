inherit "/obj/monster";
int a;

reset(arg){
  ::reset(arg);
  if (!arg){

  a = 14+random(12);
  set_name("desert bat");
  set_alias("bat");
  set_short("A desert bat");
  set_race("bat");
  set_long(
"This is a bat of the desert.  It has a fairly small body, with two\n"+
"long wings, each a thin membrane stretching over its long, sharp\n"+
"fingers.  It has two large, pointy ears.  The thumbs of its forefeet\n"+
"are small, equipped with sharp claws.\n");
  set_level(13+random(2));
  set_ac(8+random(2));    /* mguide 10   for level 13*/
  set_wc(18);             /* mguide 17  */
  set_hp(190);            /* mguide 195 */
  set_chat_chance(3);
  set_a_chat_chance(3);
  load_chat("A desert bat flies overhead.\n");
  load_chat("A desert bat circles overhead.\n");
  load_chat("A desert bat glides through the darkness.\n");
  load_chat("A desert bat emits a stream of high-pitch sounds.\n");
  load_chat("A desert bat flies through the sandy skies.\n");
  load_a_chat("A desert bat evades your attack.\n");
  set_chance(4);
  set_spell_dam(20);      /* mguide ? */
  set_spell_mess1("A desert bat circles overhead.\n");
  set_spell_mess2("A desert bat flies down and claws your neck!\n");
  set_dead_ob(this_object());
  }  
}

id(str){ return str == "zeus_inculta_npc"
             || str == name || str == alt_name || str == alias; }

monster_died(){
  object x,y;
  x = present("corpse", environment());
  x -> set_short("The dead body of a desert bat");
  x -> set_long(
    "This is the dead body of a desert bat.  One of its wings\n"+
    "has broken and some bloodly gashes are seeping onto the\n"+
    "ground beneath it.");
  y = clone_object("/obj/treasure.c");
  y -> set_name("bat wing");
  y -> set_alias("wing");
  y -> set_short("A bat wing");
  y -> set_weight(1);
  y -> set_value(670+random(61));  /* mguide 700 */
  y -> set_long(
    "This is the wing of a desert bat.  It is black and somewhat hairy.\n"+
    "It is a leathery membrane stretched between the extremely elongated\n"+
    "four \"fingers\" of the desert bat.  There is a little blood on it.\n");
  move_object(y, environment(x));
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
  if(!random(3))
    a -= 2;
  if(a)
    a--;
  else
  {
    "/players/zeus/desert/OBJ/bat_daemon.c"->make_bat(attacker_ob);
    if(present("desert bat", environment()))
      present("desert bat", environment())->attack_object(attacker_ob);
    a = 1000;
  }
}
