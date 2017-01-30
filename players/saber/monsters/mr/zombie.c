inherit "/obj/monster";


reset(arg) {
   ::reset(arg);
   if (!arg) {
 
     set_name( "zombie" );
     set_short("A freshly animated zombie");
     set_gender("creature");
     set_race("undead");
     set_long("A freshly animated zombie.  It looks somehow familiar.\n");
     set_level(10);
     set_ac(8);
     set_wc(14);
     set_hp(150);
     set_al(-500);
     set_aggressive(1);
     set_dead_ob(this_object());
     set_chat_chance(7);
     set_a_chat_chance(8);
     load_chat("The zombie stumbles.\n");
     load_a_chat("A piece of the zombie falls off.\n");
   }
  }

monster_died()  {
object ob;
  tell_room(environment(this_object()),
     "\nThe zombie falls to pieces.\n\n");
  return 0;
        }
