/* Wayne Brady */

inherit "/obj/monster.c";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(21) + 730);
  move_object(gold,this_object());

     set_name("wayne");
     set_alias("brady");
     set_alt_name("entertainer");
     set_short("Wayne Brady");
     set_race("human");
     set_long("Wayne Brady bursts with energy as he dances across the stage,\n"+
	      "his boyish good looks capturing everyone's attention.\n"+
              "His broad smile shines against ebony skin as he launches into\n"+
	      "another impossible impromptu song that leaves the audience\n"+
	      "in stitches.  He is the clear musical talent of the \n"+
	      "'contestants' of 'Whose Line Is It Anyway'.\n");
     set_level(14);
     set_ac(10 + random(2));
     set_wc(17 + random(2));
     set_hp(200 + random(21));
     set_al(-1);
     set_aggressive(1);
     set_chat_chance(10);
     set_a_chat_chance(25);
   load_chat("Wayne quips, 'Yes, hey girl, I work for Drew Carey.'\n");
     load_chat("Wayne sings in the style of a gospel singer, 'Toast....!\n"+
	      "Toast...is so crunchy and hot....Toast!'\n");
     load_chat("Wayne croons in the style of a country-western singer,\n"+
          "He's Leonard...the lawyer, and he'll lock you up faster than...'\n");
     load_chat("Wayne rocks, 'Come along Pizza Hut and deliver me....'\n"+
         "And the cola, oh deliver me.....OOh, deliveriveriveriveriver me!'\n");
     load_chat("Wayne raps, 'Uh, uh, what, what....\n"+
	"Nownownow shuttles have blown off, I think you've gott solve 'em...\n"+
	"Because you realize, 'Houston I've got a problem....''\n");
     
     load_a_chat("Wayne runs across the stage, his face contorted in anger!\n");
     load_a_chat("Wayne screams a parody of a battle cry as he brandishes\n"+
		     "a huge foam carrot at his attacker!\n");
     load_a_chat("Wayne launches a stool from the stage directly at your head!\n");
     load_a_chat("Wayne hides behind Ryan!\n");
   }
}

