inherit "obj/monster";


int one;

reset(arg)
{
   object gold;
   one = 0;
   ::reset(arg);
   if(arg) return;
   set_name("Hydra");
   set_race("elemental");
   set_alias("hydra");
   set_short("Hydra, lord of Water");
   set_long("Hydra is the lord of Water and all its beings.\n"+
     "She looks like a stunningly beautiful female human,\n"+
     "except for here long blue hair. Her lips are bright green.\n");
   set_level(21);
   set_hp(600);
   set_al(0);
   set_wc(30);
   set_ac(35);
   /* converted to add_spell format by illarion
      from the looks of it, dune wanted 2 spells here
   set_chance(65);
   set_spell_dam(50);
   set_spell_mess1("Hydra COMMANDS your lungs to fill with water.");
   set_spell_mess2("Hydra causes the water in your body to FREEZE.");
   */
   add_spell("drown",
       "Hydra COMMANDS your lungs to fill with water!\n"+
       "You cough and splutter!\n",
       "#TN# coughs and splutters in extreme pain!\n",
       20,"30-50","other|water");
   add_spell("freeze",
       "Hydra causes the water in your body to FREEZE!\n",
       0,
       20,"30-50","other|ice");
   set_chat_chance(20);
load_chat("Hydra says: Hello mortals, what is your duty here?\n");
load_chat("Hydra says: You must abide by the laws of my realm.\n");
load_chat("Hydra feeds her sea pets.\n");
   gold=clone_object("obj/money");
   gold->set_money(random(5000)+500);
   move_object(gold,this_object());
   move_object(clone_object("/players/dune/armor/coralplate.c"),
       this_object());
}


heart_beat()
{
  object more;
  string mons;
  int u;

  if (this_object()->query_attack() && random(27) == 5)
  {
    u = random(2);
    if (u == 0)
    {
      more=clone_object("/players/dune/monsters/merman.c");
      move_object(more, environment(this_object()));
      mons = "merman";
    }
    if (u == 1)
    {
      more=clone_object("/players/dune/monsters/shark.c");
      move_object(more, environment(this_object()));
      mons = "shark";
    }
    tell_room(environment(this_object()), 
      "\n%%% Hydra raises her hands and turns her head upward.\n"+
      "%%% She shouts 'HELP ME, DENIZENS OF THE SEA'"+
      "%%% A "+mons+" jumps out of the water to answer her summons!\n\n");
  }

  if (this_object()->query_attack() && 
      this_object()->query_hit_point() <= 0)
  {
    if (one == 0 && this_object()->query_attack())
    {
      log_file("dune.mon",capitalize
        ((this_object()->query_attack())->query_real_name())+
        "("+(this_object()->query_attack())->query_level()+")"+
        " killed hydra.c\n");
      one = 1;
    }
  }
  ::heart_beat();
}
