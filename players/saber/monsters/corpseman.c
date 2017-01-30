inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

  object ob, ob2, gold;

gold = clone_object("obj/money");
gold->set_money(13);
move_object(gold,this_object());

     set_name( "man" );
     set_short("A small, dirty man");
     set_race( "possessed man");
     set_gender("male");
     set_long("A small, dirty man with dull eyes.\n"+
     "You get a strange feeling about him...\n");
     set_level(3);
     set_ac(5);
     set_wc(10);
     set_hp(70);
     set_al(-666);
     set_aggressive(0);
     set_dead_ob(this_object());
     set_chat_chance(15);
     set_a_chat_chance(10);
     load_chat("The man wipes off his knife.\n");
     load_chat("The man cuts deeply into a corpse.\n");
     load_a_chat("The man's eyes suddenly glow a faint red...\n");
     load_chat("The man cuts something out of the corpse.\n");
     load_chat("The man say 'Where is that body card?'\n");
     load_a_chat("The man slices you with his knife.\n");
     load_a_chat("The man says 'Well, at least I don't have to pay for your corpse.\n");
     load_a_chat("The man suddenly shimmers with an aura of power.\n");

   }
  }

monster_died()  {
object ob;
 ob = clone_object("/players/saber/closed/quest/items/demon.c");
  move_object(ob,this_object());
tell_room(environment(this_object()),
  "\nA large demon materializes from within the corpse of the man.\n\n"+
     "The demon laughs and screams 'I AM FINIALLY FREE!'\n");
  return 0;
        }
