inherit "/obj/monster";
object ob,gold;

reset(arg) {
   ::reset(arg);
gold = clone_object("obj/money");
gold->set_money(900);
move_object(gold,this_object());
   if (!arg){
     set_name( "owlbear" );
     set_short("A hulking Owlbear");
     set_race( "orc");
     set_long("A large creature resembling a cross between a giant owl and a bear.  It is\n"+
 "covered with a thick coat of dark brown fur and feathers.  The Owlbear\n"+
 "stands eight feet tall, and has a beak of ivory white.  Its eyes glow a\n"+
 "maddening shade of red.\n");
     set_level(15);
     set_ac(11);
     set_wc(20);
     set_hp(250);
     set_al(-650);
     set_aggressive(1);
     set_chat_chance(15);
     set_a_chat_chance(15);
     load_chat("The crowd cheers.\n");
     load_chat("The owlbear roars loudly.\n");
     load_a_chat("The crowd cheers.\n");
     load_a_chat("Owlbear bites you.\n");
     load_a_chat("Owlbear roars loudly.\n");
     set_spell_mess1("Owlbear hugs its opponent.\n"+
          "You think you hear bones crack.");
     set_spell_mess2("Owlbear hugs you VERY hard.");
     set_chance(10);
     set_spell_dam(11);
   }
}
