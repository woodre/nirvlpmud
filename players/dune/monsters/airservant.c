inherit "obj/monster";


reset(arg)
{
  int a;
  ::reset(arg);
  if(arg) return;
  a = random(3) + 1;
  set_name("aerial servant");
  set_race("air elemental");
  set_alias("servant");
  if (a == 1)
  {
    set_short("A vaporous aerial servant");
    set_long("The vapor servant is hard to see, but its movements\n"+
             "give it away. It has the body of a humanoid.\n");
    set_level(10);
    set_hp(random(20)+140);
    set_wc(14);
    set_ac(8);
    set_chance(15);
    set_spell_dam(10);
  }
  if (a == 2)
  {
    set_short("A solid aerial servant");
    set_long("The solid servant is large and its body is of solid cloud.\n"+
             "Two black holes mark where its eyes should be.\n");
    set_level(11);
    set_hp(random(25)+150);
    set_wc(15);
    set_ac(9);
    set_chance(15);
    set_spell_dam(15);
  }
  if (a == 3)
  {
    set_short("A greater aerial servant");
    set_long("The greater servant is massive. It is 12-feet high.\n"+
         "It moans in eternal servitude. But who is its master?\n");
    set_level(12);
    set_hp(random(30)+160);
    set_wc(16);
    set_ac(9);
    set_chance(20);
    set_spell_dam(20);
  }
  set_al(0);
  set_move_at_reset();
  set_spell_mess1("The aerial servant blasts you with a magic wind.");
  set_spell_mess2("The aerial servant sucks the air from your body.");
}


heart_beat()
{
  object more;
  if ((this_object()->query_attack()) && (random(35) == 5))
  {
    more=clone_object("/players/dune/monsters/airservant.c");
    move_object(more, environment(this_object()));
    tell_room(environment(this_object()), 
      "\n~~~ The aerial servant summons another of its kind.\n\n");
  }
  ::heart_beat();
}
