inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

move_object(clone_object("/players/saber/armor/lpants.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/newstuff/junk/black_corset.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/newstuff/junk/collar.c"),this_object());

     set_name("Dominatrix");
     set_short("A leather bound Dominatrix");
     set_alias("dom");
     set_alt_name("dominatrix");
     set_race("human");
     set_gender("female");
     set_long("She stands impossibly tall before you, perched upon her 6 inch\n"+
              "stilleto heels. Black leather pants cling to her body, the laces\n"+
              "running the length of her legs reveal enough to make you blush.\n"+
              "A black corset is drawn tight across her ribcage, lifting and\n"+
              "displaying her full breasts for all to see. Her long, dark hair\n"+
              "has been pulled back into a tight braid.\n"+
              "She glares at you with distain.\n");
     set_level(18);

     init_command("wear corset");
     init_command("wear collar");
     init_command("wear pants");

     set_ac(15);
     set_wc(23 + random(4));
     set_hp(340 + random(20));
     set_al(-969);
     set_aggressive(0);
     set_chat_chance(4);
     set_a_chat_chance(25);
     load_chat("Dominatrix glares at you.\n");
     load_chat("Dominatrix snaps a riding crop across the counter and nods in approval.\n");
     load_chat("Dominatrix leans forward and pulls the laces of her boots tight.\n");
     load_chat("Dominatrix barks at someone in the back, giving them orders.\n");
     load_chat("Dominatrix states: What do you want, worm?\n");
     load_chat("Dominatrix states: What do you want, slave?\n");
     load_chat("Dominatrix mutters something under her breath about would be adventurers\n"+
                "always wasting her time.\n");
     load_a_chat("Dominatrix screams: Bad move Worm!\n");
     load_a_chat("Dominatrix screams: You'll lick the blood from my floor!\n");
     load_a_chat("Dominatrix slugs you with a wicked backhand shot.\n");

   }
}
