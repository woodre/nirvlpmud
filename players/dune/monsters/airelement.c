inherit "obj/monster";


int once;


reset(arg)
{
  int a;
  once = 0;
  ::reset(arg);
  if (arg) return;
  a = random(3) + 1;
  set_name("air elemental");
  set_race("air elemental");
  set_alias("elemental");
  if (a == 1)
  {
    set_short("A lesser air elemental");
    set_long("The lesser air elemental is a being of pure\n"+
             "air. Let it not mistake you though, for air\n"+
             "can be made to hurt.\n");
    set_level(13);
    set_hp(random(50)+160);
    set_wc(16);
    set_ac(11);
    set_chance(20);
    set_spell_dam(20);
  }
  if (a == 2)
  {
    set_short("An air elemental");
    set_long("The air elemental roams these realms forever,\n"+
             "existing only to thwart other elements.\n"+
             "You are not of the air element, beware.\n");
    set_level(14);
    set_hp(random(50)+190);
    set_wc(17);
    set_ac(12);
    set_chance(20);
    set_spell_dam(25);
  }
  if (a == 3)
  {
    set_short("A greater air elemental");
    set_long("The greater elemental is an awesome sight.\n"+
             "It resembles a tornado of swirling air.\n"+
             "You better not get in its way!\n");
    set_level(16);
    set_hp(random(150)+300);
    set_wc(21);
    set_ac(14);
    set_chance(25);
    set_spell_dam(30);
  }
  set_al(0);
  set_move_at_reset();
  set_aggressive(1);
  set_spell_mess1("The air elemental BLASTS you with raging wind.");
  set_spell_mess2("The air elemental spins a TORNADO at you.");
}


heart_beat()
{
  object more;
  if (this_object()->query_attack()         &&
      this_object()->query_hit_point() < 80 && 
      once == 0)
  {
    more=clone_object("/players/dune/monsters/airservant.c");
    move_object(more, environment(this_object()));
    tell_room(environment(this_object()), 
      "\n~~~ The air elemental sees that the fight is not coming easily.\n"+
      "~~~ It throws a bolt of air into the clouds.\n"+
      "~~~ From out of the clouds comes an aerial servant!\n\n");
    once = 1;
  }
  ::heart_beat();
}
