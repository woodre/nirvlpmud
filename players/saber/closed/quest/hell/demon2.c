inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob, ob2;
     ob = clone_object("obj/money.c");
     ob->set_money(random(650));
     move_object(ob,this_object());
     set_name( "oni Usha" );
     set_short("A bulky Oni Usha (demon)");
     set_alt_name("oni usha");
     set_race( "demon");
     set_gender("creature");
     set_long("A bulky Oni Usha demon with loose flesh hanging in all directions.\n");
     set_level(12);
     set_ac(random(9) + 2);
     set_wc(random(18) + 10);
     set_hp(random(100) + 25);
     set_al(-880);
     set_frog(1);
     set_dead_ob(this_object());
     set_aggressive(1);
     set_chat_chance(5);
     set_a_chat_chance(25);
     load_chat("Oni Usha looks for food.\n");
     load_chat("Oni Usha glares at you.\n");
     load_chat("A burst of flames explodes near you.\n");
     load_a_chat("Oni Usha hisses at you.\n");
     load_a_chat("Oni Usha exhales smoke!\n");
     load_a_chat("Oni Usha tries to bite you.\n");
     load_a_chat("Oni Usha glares at you.\n");

     set_spell_mess1("Oni Usha entangles its foe in loose flabs of skin.");
     set_spell_mess2("Oni Usha entangles you in loose flabs of skin.");
     set_chance(20);
     set_spell_dam(5);
   }
}

monster_died()  {
object ob;
int reincar;
  reincar = random(4);

  if(reincar < 2)  {
    tell_room(environment(this_object()),
      "The Oni Usha bursts into flames.\n");
        }
  if(reincar > 1)  {
    tell_room(environment(this_object()),
    "\nThe Oni Usha gates in another Oni Usha.\n");
    ob = clone_object("/players/saber/closed/quest/hell/demon2.c");
    move_object(ob, environment(this_object()));
        }
  return 0;
        }
