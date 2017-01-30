inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob, ob2;
     ob = clone_object("obj/money.c");
     ob->set_money(random(550));
     move_object(ob,this_object());
     set_name( "tra Nunok" );
     set_short("An ugly Tra NuNok (demon)");
     set_alt_name("tra nunok");
     set_race( "demon");
     set_gender("creature");
     set_long("An ugly Tra NuNok demon with pale green skin.\n"+
       "It is evil.\n");
     set_level(10);
     set_ac(random(7) + 2);
     set_wc(random(15) + 10);
     set_hp(random(120) + 25);
     set_al(-900);
     set_frog(1);
     set_dead_ob(this_object());
     set_aggressive(1);
     set_chat_chance(5);
     set_a_chat_chance(25);
     load_chat("Tra NuNok rubs its wart covered tummy.\n");
     load_chat("Tra NuNok glares at you.\n");
     load_chat("A burst of flames explodes near you.\n");
     load_a_chat("Tra NuNok hisses at you.\n");
     load_a_chat("Tra NuNok farts.\n");
     load_a_chat("Tra NuNok tries to bite you.\n");
     load_a_chat("Tra NuNok glares at you.\n");

     set_spell_mess1("Tra NuNok spits acid on its foe");
     set_spell_mess2("Tra NuNok spits acid on you");
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
      "The Tra NuNok bursts into flames.\n");
        }
  if(reincar > 1)  {
    tell_room(environment(this_object()),
    "\nThe Tra NuNok gates in another Tra NuNok.\n");
    ob = clone_object("/players/saber/closed/quest/hell/demon1.c");
    move_object(ob, environment(this_object()));
        }
  return 0;
        }
