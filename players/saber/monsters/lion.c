inherit "/obj/monster";
object ob,gold;

reset(arg) {
   ::reset(arg);
  ob = clone_object("/players/saber/stuff/lionskin.c");
move_object(ob,this_object());
   if (!arg){
     set_name( "lion" );
     set_short("A large lion");
     set_race( "feline");
     set_long("A large and powerful feline covered with golden brown fur.\n"+
       "It has a dark golden mane and wicked looking teeth and claws.\n"+
       "Lion looks hungry.\n");
     set_level(14);
     set_ac(11);
     set_wc(18);
     set_hp(215);
     set_al(-500);
     set_aggressive(1);
     set_chat_chance(15);
     set_a_chat_chance(15);
     load_chat("The crowd cheers.\n");
     load_chat("The lion roars loudly.\n");
     load_a_chat("The crowd cheers.\n");
     load_a_chat("Lion bites you.\n");
     load_a_chat("Lion roars loudly.\n");
     set_spell_mess1("Lion rakes its opponent with huge claws.");
     set_spell_mess2("Lions rakes you with its claws.");
     set_chance(15);
     set_spell_dam(8);
   }
}
