inherit "/obj/monster";
object gold;

reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("desert brute" );
  set_alias("brute");
  set_short("A towering brute of the desert");
  set_long(
"The massive creature before you is a desert brute.  Its skin is as\n"+
"tough as the rock and virtually the same color.  It seems to barely\n"+
"even notice the sands whipping against it.  It's muscular arms rest\n"+
"against the ground, keeping it upright.  It appears to be a rather\n"+
"placid beast, but if angered it could probably tear you apart.  Do\n"+
"not attack it if you are not prepared.\n");
  set_level(23);
  set_ac(24);
  set_wc(34);
  set_wc_bonus(14);
  set_hp(1000);
  set_al(-100);
  set_aggressive(0);
  set_chat_chance(1);
  load_chat("The brute breaths slowly.\n");
  load_chat("The brute seems oblivious to the blowing winds.\n");
  load_chat("The brute grunts softly.\n");
  set_dead_ob(this_object());
}

monster_died(){
  tell_room(environment(),
    "You discover a pile of coins among the remains of the brute.\n");
  gold = clone_object("/obj/money.c");
  gold->set_money(6000 + random(4000));
  move_object(gold, environment());
  if(!(random(5)))
    move_object(clone_object("/players/fred/closed/bloodfist/obj/gem.c"), environment());
}

id(str){ return str == "zeus_inculta_npc"
             || str == name || str == alt_name || str == alias; }

heart_beat(){
  ::heart_beat();
  if(!environment()) return;
  if(!attacker_ob) return;
  if(present(attacker_ob, environment()) && !random(10))
  {
    tell_room(environment(), 
      "The brute roars up on its hind legs!\n\n\n"+
      "\t\tThe brute comes crushing down on\n\t\t"+attacker_ob->query_name()+
      " with its mighty fists!\n\n",
      ({ attacker_ob }));
    tell_object(attacker_ob,
      "The brute roars up on its hind legs!\n\n\n"+
      "\t\tThe brute comes crushing down on\n"+
      "\t\tyou with its mighty fists!\n\n");
    attacker_ob->hit_player(100+random(70));
  }
}

