inherit "obj/monster";


int one;


reset(arg)
{
   object gold;
   one = 0;
   ::reset(arg);
   if(arg) return;
   set_name("Saal");
   set_race("elemental");
   set_alias("saal");
   set_short("Saal, lord of Fire");
   set_long("Saal is the compilation of pure destructive fire.\n"+
     "Spikes of white flame flash from his burning body.\n"+
     "You feel the intense heat he radiates... it bursts from\n"+
     "him in transparent waves.\n");
   set_level(21);
   set_hp(850);
   set_al(0);
   set_wc(20);
   set_ac(35);
   set_chance(35);
   set_spell_dam(60);
   set_spell_mess1("Saal BLASTS you with white hot fire.");
   set_spell_mess2("Saal FRIES your buns.");
   set_chat_chance(10);
load_chat("Saal says: I shall destroy you!\n");
load_chat("Saal causes elemental chaos.\n");
load_chat("Saal expands his realm of fire to consume Nirvana.\n");
   gold=clone_object("obj/money");
   gold->set_money(random(7000)+1500);
   move_object(gold,this_object());
   move_object(clone_object("players/dune/armor/firehelm.c"),
       this_object());
move_object(clone_object("/players/dune/objects/eyeobj.c"),
       this_object());
}


heart_beat()
{
  object more;
  string mons;
  int u;

  if (this_object()->query_attack() && random(38) == 5)
  {
    u = random(3);
    if (u == 0)
    {
      more=clone_object("/players/dune/monsters/firewyrm.c");
      move_object(more, environment(this_object()));
      mons = "fire wyrm";
    }
    if (u == 1)
    {
      more=clone_object("/players/dune/monsters/firedrake.c");
      move_object(more, environment(this_object()));
      mons = "fire drake";
    }
    if (u == 2)
    {
      more=clone_object("/players/dune/monsters/firedragon.c");
      move_object(more, environment(this_object()));
      mons = "fire dragon";
    }
    tell_room(environment(this_object()), 
      "\n^^^ A blast of fire explodes from the center of the room!\n"+
      "^^^ A gate forms in middle-air.\n"+
      "^^^ Saal BECKONS a "+mons+" from the magic gate!\n\n");
  }

  if (this_object()->query_attack() &&
      this_object()->query_hit_point() <= 0)
  {
    if (one == 0 && this_object()->query_attack())
    {
      log_file("dune.mon",capitalize
        ((this_object()->query_attack())->query_real_name())+
        "("+(this_object()->query_attack())->query_level()+")"+
        " killed saal.c\n");
      one = 1;
    }
  }
  ::heart_beat();
}
