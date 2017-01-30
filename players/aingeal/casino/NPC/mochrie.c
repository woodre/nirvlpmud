/* Colin Mochrie */

inherit "/obj/monster.c";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold;
  gold = clone_object("obj/money");
  gold->set_money(750);
  move_object(gold,this_object());

     set_name("colin");
     set_alias("mochrie");
     set_alt_name("entertainer");
     set_short("Colin Mochrie");
     set_race("human");
     set_long("Colin Mochrie lopes across the stage, the bright lights\n"+
	      "glinting off his rapidly balding head.  His face twists\n"+
              "into a silly grin as he shoots another one-liner at the\n"+
	      "audience.  He misses no opportunity to fling a barbed,\n"+
	      "well-timed insult at one of the other 'contestants' of\n"+
	      "'Whose Line Is It Anyway'.\n");
     set_level(14);
     set_ac(10 + random(2));
     set_wc(17 + random(2));
     set_hp(200 + random(21));
     set_al(-1);
     set_aggressive(1);
     set_chat_chance(10);
     set_a_chat_chance(25);
   load_chat("Colin says, 'Give me liberty or give me a bran muffin!'\n");
     load_chat("Colin sings in the style of a hoedown, \n"+
	      "People always kid me cause I'm losing all my hair...\n"+
	      "I can't really help it that I'm folicly impaired....\n"+
	     "It really is quite horrible, but my life's not quite through..\n"+
	      "I still get way more sex then either Ryan or Drew!'\n");
     load_chat("Colin quips, 'Here, take this parachute - it opens on impact.\n");
     load_chat("Colin laments, 'It all started with a badly timed bald joke!'\n");
     
     load_a_chat("Colin whines, 'Get away from me, you brute!'\n");
     load_a_chat("Colin screeches as he swings a huge foam wishbone over his head!\n");
     load_a_chat("Colin cries out in pain as he trips over a stool on the stage!\n");
     load_a_chat("Colin hides behind Wayne!\n");
   }
}

