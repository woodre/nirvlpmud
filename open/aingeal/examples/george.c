/* George, Liberace's brother */


inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold,violin;
  gold = clone_object("obj/money");
  gold->set_money(random(500) + 500);
  move_object(gold,this_object());

  violin = clone_object("/players/aingeal/casino/weapons/violin.c");
move_object(violin,this_object());
  
     set_name("george");
     set_alias("George");
     set_short("Liberace's brother, George");
     set_race("human");
     set_long("George Liberace is a dapper, round-faced little man with\n"+
              "black, pomade-slicked hair, a Chaplin-style mustache,\n"+
              "and flashing eyes. He appears to be less than pleased.\n");
     set_level(16);
     set_ac(10 + random(3));
     set_wc(18 + random(4));
     set_hp(250 + random(50));
     set_al(-1000);
     set_aggressive(1);
     set_chat_chance(10);
     set_a_chat_chance(10);
     /* Regular chats */
     load_chat("George calls out, 'Dora?  Where are you, Dora?'\n");
     load_chat("George chants, 'A one and-a two and-a....'\n");
     load_chat("George shoulders his violin, pausing before drawing the\n"+
              "bow across the strings.\n");

     /* Combat chats */
     load_a_chat("George flings his violin violently at your torso!\n");
     load_a_chat("George swings his violin directly at your head!\n");
     load_a_chat("George cries, 'I will avenge my brother!\n");
     load_a_chat("George impales you with his violin bow!\n");

     }
}

