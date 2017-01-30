inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob, ob2;
     ob = clone_object("obj/money.c");
     ob->set_money(random(1000));
     move_object(ob,this_object());
     ob2 = clone_object("/players/saber/closed/quest/items/cloak.c");
     move_object(ob2, this_object());
     init_command("wear cloak");
     set_name( "shizkra" );
     set_short("47th Servant of Choas Shizkra");
     set_race( "demon");
     set_alias("servant");
     set_gender("creature");
     set_long("You catch a brief image of a large doglike creature.\n"+
       "Best not stare too long, for choas was not ment to be viewed...\n");
     set_level(16);
     set_ac(6);
     set_wc(30);
     set_hp(350);
     set_al(-1000);
     set_frog(1);
     set_dead_ob(this_object());
     set_aggressive(1);
     set_chat_chance(5);
     set_a_chat_chance(5);
     load_chat("Shizkra barks at you with a low pitched whine.\n");
     load_chat("Shizkra howls at you.\n");
     load_chat("A burst of flame explodes near you.\n");
     load_a_chat("A burst of flame explodes near you.\n");
     load_a_chat("Shizkra bites you with its spiked fangs.\n");

     set_spell_mess1("Shizkra bites its foe and rips off a huge chunk fo flesh.");
     set_spell_mess2("Shizkra bites you and rips off a huge chunk of flesh.");
     set_chance(15);
     set_spell_dam(40);
   }
}

monster_died()  {
tell_room(environment(this_object()),
 "\n\nShizkra howls in pain as its body turns to flames.\n"+
 "Shizkra slumps to the ground.\n");
  return 0;
        }
