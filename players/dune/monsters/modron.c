inherit "obj/monster";


int one;


reset(arg)
{
   object gold;
   one = 0;
   ::reset(arg);
   if(arg) return;
   set_name("Modron");
   set_race("elemental");
   set_alias("modron");
   set_short("Modron, lord of Air");
   set_long("Modron is the compilation of pure air and electricity.\n"+
"His legs are swirling lightning and his body is of shining metal.\n"+
"Modron's eyes are two larg rubies, a red light glows in the sockets.\n");
   set_level(21);
   set_hp(1000);
   set_al(0);
   set_wc(35);
   set_ac(20);
   set_chance(30);
   set_spell_dam(40);
   set_spell_mess1("Modron throws a LIGHTNING BOLT at you.");
   set_spell_mess2("Modron's eyes shoot a BEAM OF HURT upon you.");
   set_chat_chance(15);
load_chat("Modron says: I shall set you right!\n");
load_chat("Modron floats through the air.\n");
load_chat("Modron says: You are in my realm and are my subject.\n");
   gold=clone_object("obj/money");
   gold->set_money(random(7000)+1000);
   move_object(gold,this_object());
   move_object(clone_object("players/dune/armor/vaporboots.c"),
       this_object());
}


heart_beat()
{
  object more;
  string mons;
  int p;
  if (this_object()->query_attack() && random(30) == 5)
  {
    p = random(2);
    if (p == 0)
    {
      more=clone_object("/players/dune/monsters/airservant.c");
      move_object(more, environment(this_object()));
      mons = "aerial servant";
    }
    if (p == 1)
    {
      more=clone_object("/players/dune/monsters/airelement.c");
      move_object(more, environment(this_object()));
      mons = "air elemental";
    }
    tell_room(environment(this_object()), 
      "\n~~~ The clouds churn in a hurricane!\n"+
      "~~~ A portal opens.\n"+
      "~~~ Modron SUMMONS an "+mons+" to his side!\n\n");
  }

  if (this_object()->query_attack() &&
      this_object()->query_hit_point() <= 0)
  {
    if (one == 0 && this_object()->query_attack())
    {
      log_file("dune.mon",capitalize
        ((this_object()->query_attack())->query_real_name())+
        "("+(this_object()->query_attack())->query_level()+")"+
        " killed modron.c\n");
      one = 1;
    }
  }
  ::heart_beat();
}
