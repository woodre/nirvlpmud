/* Gladys Knight */

inherit "/obj/monster.c";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold,rock_jacket;
  gold = clone_object("obj/money");
  gold->set_money(random(50) + 200);
  move_object(gold,this_object());

  rock_jacket = clone_object("/players/aingeal/casino/armor/rock_jacket.c");
  move_object(rock_jacket,this_object());

     set_name("knight");
     set_alias("gladys");
     set_alt_name("entertainer");
     set_short("Gladys Knight");
     set_race("human");
     set_long("Gladys Knight flashes her dazzling smile at the audience,\n"+
              "her petite figure, smooth mahogany skin, and wide, sparkling\n"+
	      "brown eyes still captivating after all these years.  The \n"+
	      "stage lights reflect dully against the black leather of her\n"+
	      "'Rock and Roll Hall of Fame' jacket, receieved after her \n"+
	      "induction into that august institution a few years back.\n"+
	      "She closes her eyes as she belts forth the opening lines\n"+
	      "of another soulful tune.\n");
     set_level(15);
     set_ac(11 + random(2));
     set_wc(19 + random(2));
     set_hp(220 + random(31));
     set_al(500);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(25);
   load_chat("Gladys croons, 'You'd be there, between each line of pain and glory...\n"+
   "Cause you're the best thing that ever happened to me...'\n");
     load_chat("Gladys dances across the stage as she sings out,\n"+
              "'Got a license to kill....\n"+
	      "and you know I'm goin straight for your heart!'\n");
     load_chat("Gladys gets teary eyed as she sings, \n"+
              "Better luck next time, baby....for all eternity,\n"+
             "Even if it's not with me, I wish you all that love could be.'\n");
     load_chat("Gladys gazes soulfully into the audience as she sings,\n"+
              "'Because neither one of us...wants to be the first to say...\n"+
	      "Farewell my love.....goodbye.'\n");
     load_a_chat("Gladys squares off against you, her eyes flashing with anger!\n");
     load_a_chat("Gladys cries, 'You'll pay for this!'\n");
     load_a_chat("Gladys rolls up the sleeves of her jacket and punches you\n"+
		     "squarely in the jaw!\n");
     load_a_chat("Gladys sneers at you as she rakes her fingernails down your face!\n");
   }
}

