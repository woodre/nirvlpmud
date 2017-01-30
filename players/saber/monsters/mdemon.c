inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob, ob2;
ob = clone_object("obj/money");
ob->set_money(random(400));
move_object(ob,this_object());
     set_name( "minor demon" );
     set_alias("demon");
     set_short("A small demon with crimson skin");
     set_gender("creature");
     set_race( "demon");
     set_long("A minor demon with razor sharp claws and a toothy grin.\n"+
       "It is evil.\n");
     set_level(5);
     set_ac(5);
     set_wc(9);
     set_hp(50);
     set_al(-700);
     set_frog(1);
     set_aggressive(1);
     set_chat_chance(5);
     set_a_chat_chance(5);
     load_chat("The small demon wails like the tormented soul that it is.\n");
     load_chat("The small demon glares at you.\n");
     load_a_chat("The small demon hisses at you.\n");
     load_a_chat("The small demon wails like the tormented soul that it is.\n");
     load_a_chat("The small demon tries to bite you.\n");
     load_a_chat("The small demon glares at you.\n");
     load_a_chat("The small demon says: You will dwell with us within circle forever!\n");

     set_spell_mess1("The small demon rakes its foe with razor sharp claws.");
     set_spell_mess2("The small demon rakes you with razor sharp claws.");
     set_chance(20);
     set_spell_dam(3);
   }
}

init()  {
  ::init();
   add_action("portal","portal");
        }

portal()  {
say(this_player()->query_name()+" tries to step through the portal, but is blocked by a small demon.\n");
  return 1;
        }
