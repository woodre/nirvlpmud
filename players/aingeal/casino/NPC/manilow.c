/* Barry Manilow */


inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold,mic;
  gold = clone_object("obj/money");
  gold->set_money(random(50) + 250);
  move_object(gold,this_object());

  mic = clone_object("/players/aingeal/casino/treasure/barrymic.c");
  move_object(mic,this_object());

   set_name("barry");
   set_alias("Barry");
     set_short("Barry Manilow");
     set_race("human");
     set_long("Barry clutches a wireless microphone with one hand, his other\n"+
              "hand reaching out in supplication as he offers up another\n"+
	      "soulful tune.  His conservative blue suit compliments his  \n"+
	      "petite frame, slightly greying hair and piercing blue eyes. \n");
     set_level(8);
     set_ac(5 + random(2));
     set_wc(9 + random(3));
     set_hp(100 + random(20));
     set_al(100);
     set_aggressive(0);
     set_chat_chance(12);
     set_a_chat_chance(20);
     load_chat("Barry wiggles his hips as he sings,'Her name was Lola....\n"+
              "She was a showgirl.....\n");
     load_chat("Barry closes his eyes as he croons, 'Oh Mandy....\n"+
              "You came and you gave without taking......\n"+
	      "But I sent you away, Oh Mandy.....\n");
     load_chat("Barry sheds a tear as he laments,\n"+
              "Somewhere down the road, our roads are gonna\n"+
	      "cross again....it doesn't really matter when...\n");
     load_chat("Barry stares deeply into your eyes as he sings,\n"+
              "You're my song....music too magic to end.  I'll\n"+
	      "play you over and over again.  Loving so warm,\n"+
	      "moving so right, closing our eyes and feeling alive...\n"+
	      "We'll just go on burning bright...Somewhere in the night.\n");
     load_a_chat("Barry screams, 'Don't interrupt my big finish!'\n");
     load_a_chat("Barry whines, 'You'll ruin my career!'\n");
     load_a_chat("Barry tries to club you with his microphone.\n");
     load_a_chat("Barry flails at you with his fists.\n");
   }
}

