inherit "obj/monster";

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("Pirate Captain");
   set_level(9);
   set_alias("pirate");
   set_race("legoman");
   set_hp(111+random(50));
   set_al(-150);
   set_short("The Dreaded Lego Pirate Captain");
   set_long("The dangerous, dreaded lego pirates sail their lego ships in search\n"+
            "of plunder and evil doing.  Their scraggly beards hide the vicious\n"+
            "grins and raucous laughter.\n");
   set_wc(11+random(5));
   set_ac(7);
   set_chat_chance(5);
   set_a_chat_chance(10);
   set_alt_name("captain");
   load_chat("Pirate Captain says, \"Haha, that King didn't stand a chance against me!\"\n");
   load_chat("Pirate Captain says, \"Yo ho ho, scurvy dogs, put yer backs to it!\"\n");
   load_chat("Pirate Captain says, \"ARRGH!!!\"\n");
   load_chat("Pirate Captain laughs mockingly.\n");
   load_chat("Pirate Captain says, \"That King was no match fer us.  We scattered his wretched\n"+
             "                      bones to the four corners of the world!  Harrgh!!\"\n");
   load_chat("Pirate Captain grins.\n");
   load_a_chat("Pirate Captain screams, \"AARRRRGH!!!\"\n");
   load_a_chat("Pirate Captain yells, \"After this wharf rat, ye useless dogs!\"\n");
   load_a_chat("Pirate Captain says, \"You'll never get the crown.  I plundered it fer meself.\"\n");
   load_a_chat("Pirate Captain says, \"We'll take you down with the ship!\"\n");
   load_a_chat("Pirate Captain slashes you with his plastic sword.\n");
   load_a_chat("Pirate Captain sneers.\n");
   move_object(clone_object("/players/llew/Toys/quest/crown"),this_object());
   move_object(clone_object("/players/llew/Toys/misc/lego"),this_object());
   move_object(clone_object("/players/llew/Toys/armor/pirate_hat"),this_object());
   move_object(clone_object("/players/llew/Toys/misc/parrot"),this_object());
}
