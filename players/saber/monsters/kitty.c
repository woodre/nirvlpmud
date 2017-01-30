inherit "/obj/monster";
object ob,gold;

reset(arg) {
   ::reset(arg);
  ob = clone_object("/players/saber/armor/kittycloak.c");
move_object(ob,this_object());
   if (!arg){
     set_name( "smilodon" );
   set_short("A Smilodon");
     set_race( "feline");
     set_alt_name("fang");
     set_long("A huge feline with six inch long fangs.\n"+
       "It looks like an extremely large tiger.\n");
     set_level(16);
     set_ac(13);
     set_wc(22);
     set_hp(400);
     set_al(-300);
     set_chat_chance(15);
     set_a_chat_chance(15);
     load_chat("The crowd cheers.\n");
     load_chat("The smilodon roars loudly.\n");
     load_a_chat("The crowd cheers.\n");
     load_a_chat("Smilodon bites you.\n");
     load_a_chat("Smilodon roars loudly.\n");
     set_spell_mess2("Smilodon sinks it's large fangs into you.");
     set_spell_mess1("Smilodon sinks its fangs into its foe.");
     set_chance(15);
     set_spell_dam(10);
   }
}
