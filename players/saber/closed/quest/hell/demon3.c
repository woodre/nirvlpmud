inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob, ob2;
     ob = clone_object("obj/money.c");
     ob->set_money(random(350));
     move_object(ob,this_object());
     set_name( "manes" );
     set_short("A small Manes (demon)");
     set_race( "demon");
     set_gender("creature");
     set_long("A small demon with sharp claws and a hideous grin.\n"+
       "It is evil.\n");
     set_level(6);
     set_ac(random(3) + 2);
     set_wc(random(10) + 10);
     set_hp(random(50) + 25);
     set_al(-700);
     set_frog(1);
     set_dead_ob(this_object());
     set_aggressive(1);
     set_chat_chance(5);
     set_a_chat_chance(25);
     load_chat("Manes wails like the tormented soul that it is.\n");
     load_chat("Manes glares at you.\n");
     load_chat("A burst of flames explodes near you.\n");
     load_a_chat("Manes hisses at you.\n");
     load_a_chat("Manes wails like the tormented soul that it is.\n");
     load_a_chat("Manes tries to bite you.\n");
     load_a_chat("Manes glares at you.\n");

     set_spell_mess1("Manes rakes its foe with razor sharp claws.");
     set_spell_mess2("Manes rakes you with razor sharp claws.");
     set_chance(20);
     set_spell_dam(5);
   }
}

monster_died()  {
object ob;
    tell_room(environment(this_object()),
    "\n\nThere is a huge burst of flames!\n\n");
    tell_room(environment(this_object()),
    "47th Servant of Chaos Shizkra jumps from the flames.\n"+
    "Demon Enforcer of Chaos Balzron jumps from the flames.\n\n");
    tell_room(environment(this_object()),
    "Balzron hisses \"\What are you doing here Mortal?  You dare enter the Dark Circle?\"\n"+
    "Balzron hisses \"\In the name of the bound one, we shall now slay you!\"\n");
    ob = clone_object("/players/saber/closed/quest/hell/balzron.c");
    move_object(ob, environment(this_object()));
    ob = clone_object("/players/saber/closed/quest/hell/shizkra.c");
    move_object(ob, environment(this_object()));
  return 0;
        }
