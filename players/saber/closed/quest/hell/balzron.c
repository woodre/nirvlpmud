inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob, ob2;
     ob = clone_object("obj/money.c");
     ob->set_money(random(6000));
     move_object(ob,this_object());
     ob2 = clone_object("/players/saber/closed/quest/hell/demonfire.c");
     move_object(ob2, this_object());
     init_command("wield sword");
     set_name( "balzron" );
     set_short("Demon Enforcer of Choas Balzron");
     set_race( "demon");
     set_alias("enforcer");
     set_gender("creature");
     set_long("Your catch a brief image of dark claws and crimson skin.\n"+
       "Best not stare too long, for choas was not ment to be viewed...\n");
     set_level(21);
     set_ac(18);
     set_wc(30);
     set_hp(500);
     set_al(-1000);
     set_frog(1);
     set_dead_ob(this_object());
     set_aggressive(1);
     set_chat_chance(5);
     set_a_chat_chance(25);
     load_chat("Balzron glares at you with eyes of choas.\n");
     load_chat("Balzron calls upon the power of choas for healing.\n");
     load_chat("A burst of flame explodes near you.\n");
     load_a_chat("A burst of flame explodes near you.\n");
     load_a_chat("Balzron rakes you with its spiked talons.\n");
     load_a_chat("@# 135!#%K )GSI !#%\n");
     load_a_chat("!#% KS 305 1!#% KG)S i#% k       )gi 1\n");
     load_a_chat("#!%  TG_ ! %K-S 3 klwrk12^ SR g1\n");
     load_a_chat("KGS) 1#%_+ k1l3 5 Sokj1 3%13 5k)S GSk!\n");
     load_a_chat("!# S KGL )T k135 15 LKG)WS T1#% K% IGw015\n");

     set_spell_mess1("Balzron smites its foe with a chaos vortex.");
     set_spell_mess2("Balzron smites you with a choas vortex.");
     set_chance(15);
     set_spell_dam(40);
   }
}

monster_died()  {
tell_room(environment(this_object()),
 "\n\nBalzron screams in rage as his body turns to flames.\n\n"+
 "Balzron screams \"\You may have defeated me, but you shall not live.\"\n"+
 "Balzron screams \"\One waits for you now, and he shall feast upon your bones.\"\n");
tell_room(environment(this_object()),
 "\n\nBalzron slumps to the ground, its body a mass of fire.\n");
  return 0;
        }
