inherit "obj/monster";


int v, one;


reset(arg)
{
   object gold;
   one = 0;
   ::reset(arg);
   if(arg) return;
   set_name("Urdlen");
   set_race("elemental");
   set_alias("urdlen");
   set_short("Urdlen, lord of Earth");
   set_long("Urdlen resembles a gargantuan half-man half-mole.\n"+
     "He has long sharp claws and two thin fangs.\n"+
     "Urdlen's eyes glow blue, and his claws glow white.\n");
   set_level(19);
   set_hp(550);
   set_al(0);
   set_wc(29);
   set_ac(20);
   set_chance(40);
   set_spell_dam(45);
   set_spell_mess1("Urdlen throws a stalagtite at you!");
   set_spell_mess2("Urdlen DIGS into your flesh!");
   set_chat_chance(8);
load_chat("Urdlen says: You leave my diggers alone!\n");
load_chat("Urdlen ignores you.\n");
load_chat("Urdlen digs at some rock.\n");
   gold=clone_object("obj/money");
   gold->set_money(random(3000)+500);
   move_object(gold,this_object());
   for(v = 1; v <=3; v++) {
   move_object(clone_object("/players/dune/objects/gem.c"),
       this_object());}
}


heart_beat()
{
  object more;

  if (this_object()->query_attack() && random(27) == 5)
  {
    more=clone_object("/players/dune/monsters/digger.c");
    move_object(more, environment(this_object()));
    tell_room(environment(this_object()), 
      "\n### Urdlen gets mad!\n"+
      "### The ground thrusts upward.\n"+
      "### A digger pops out of the earth.\n\n");
  }

  if (this_object()->query_attack() && random(40) == 6)
  {
    if (present(environment("digger")))
    {
      tell_room(environment(this_object()), 
        "\n### Urdlen loses his temper and picks up one of his diggers.\n"+
        "### He cusses 'Damn digger can't do a thing, can you!'\n"+
        "### Urdlen breaks the digger's neck and continues attacking.\n\n");
      destruct(present(environment("digger")));
    }
  }

  if (this_object()->query_attack() && 
      this_object()->query_hit_point() <= 0)
  {
    if (one == 0 && this_object()->query_attack())
    {
      log_file("dune.mon",capitalize
        ((this_object()->query_attack())->query_real_name())+
        "("+(this_object()->query_attack())->query_level()+")"+
        " killed urdlen.c\n");
      one = 1;
    }
  }
  ::heart_beat();
}
