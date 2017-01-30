inherit "/obj/monster";
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object ob;
  ob = clone_object("/players/snow/WEAPONS/tsunami.c");
move_object(ob,this_object());
 
     set_name("giant crab");
     set_short("A giant crab");
     set_race("crab");
     set_alias("giant crab");
     set_long("This is quite probably the largest crab you have ever seen.\n" +
                    "Each of its claws are big enough to rip you in half and the \n" +
                    "body of the crab itself is twice your height. It seems to be very \n" +
                    "posessive about the trident that lies just underneath it.");
     set_level(20);
     set_ac(60);
     set_wc(40);
     set_hp(1000);
     set_heal(3,1);
     set_al(0);
     set_aggressive(1);
     set_chat_chance(7);
     set_a_chat_chance(7);
 
     load_chat("The crab scuttles toward you.\n");
     load_chat("The crab brushes lovingly against its trident.\n");
     load_a_chat("The crab's shell resists your blows.\n");
set_chance(40);
set_spell_mess1("One of the crab's great claws grabs onto an unlucky victim.\n");
set_spell_mess2("One of the great crab's claws crushes the crap out of you.\n");
set_spell_dam(50);
   }
}
