inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob, ob2;
     ob = clone_object("obj/money.c");
     ob->set_money(random(450));
     move_object(ob,this_object());
     set_name( "v'sha" );
     set_short("A short V'sha (demon)");
     set_race( "demon");
     set_gender("creature");
     set_long("A short V'sha demon with crimson skin and coal black eyes.\n"+
       "It is evil.\n");
     set_level(7);
     set_ac(random(5) + 2);
     set_wc(random(12) + 10);
     set_hp(random(70) + 25);
     set_al(-800);
     set_frog(1);
     set_dead_ob(this_object());
     set_aggressive(1);
     set_chat_chance(5);
     set_a_chat_chance(25);
     load_chat("V'sha howls loudly.\n");
     load_chat("V'sha glares at you.\n");
     load_chat("A burst of flames explodes near you.\n");
     load_a_chat("V'sha hisses at you.\n");
     load_a_chat("V'sha screams at you.\n");
     load_a_chat("V'sha tries to bite you.\n");
     load_a_chat("V'sha glares at you.\n");

     set_spell_mess1("V'sha breaths fire!");
     set_spell_mess2("V'sha breaths fire!");
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
      "The V'sha bursts into flames.\n");
        }
  if(reincar > 1)  {
    tell_room(environment(this_object()),
    "\nThe V'sha gates in another V'sha.\n");
    ob = clone_object("/players/saber/closed/quest/hell/demon.c");
    move_object(ob, environment(this_object()));
        }
  return 0;
        }
