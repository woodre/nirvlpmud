inherit "obj/monster";

reset(arg) {
   ::reset(arg);
   if(arg) return;
   switch(random(9)+1) {
      case 1: set_short("A grizzled lego pirate"); break;
      case 2: set_short("A swarthy lego pirate"); break;
      case 3: set_short("A lego pirate with a peg-leg"); break;
      case 4: set_short("An eye-patched lego pirate"); break;
      case 5: set_short("A bald lego pirate"); break;
      case 6: set_short("A menacing lego pirate"); break;
      case 7: set_short("A grinning lego pirate"); break;
      case 8: set_short("A mean looking lego pirate"); break;
      case 9: set_short("A swashbuckling lego pirate"); break;
   }
   set_name("lego pirate");
   set_level(6);
   set_alias("pirate");
   set_race("legoman");
   set_hp(76+random(30));
   set_al(-75);
   set_long("The dangerous, dreaded lego pirates sail their lego ships in search\n"+
            "of plunder and evil doing.  Their scraggly beards hide the vicious\n"+
            "grins and raucous laughter.\n");
   set_wc(8+random(5));
   set_ac(5);
   set_chat_chance(5);
   set_a_chat_chance(10);
   load_chat("Lego pirate says, \"Avast ye matey!\"\n");
   load_chat("Lego pirate says, \"Ahoy, plunder be waitin'.\"\n");
   load_chat("Lego pirate says, \"ARGHH!!!\"\n");
   load_chat("Lego pirate waves his plastic sword.\n");
   load_chat("Lego pirate says, \"Aye Cap'n!\"\n");
   load_chat("Lego pirate sings a dirty sailing tune.\n");
   load_a_chat("Lego pirate screams, \"AAAARRRRGH!!!!\"\n");
   load_a_chat("Lego pirate jabs you with his sword.\n");
   load_a_chat("Lego pirate yells, \"Man the cannons!  They be comin aboard, Cap'n!\"\n");
   load_a_chat("Lego pirate looks mean.\n");
   load_a_chat("Lego pirate says, \"What be yer business aboard, matey?\"\n");
   load_a_chat("Lego pirate grunts in pain.\n");
   load_a_chat("Lego pirate curses!\n");
   set_alt_name("rand_pirate");
   move_object(clone_object("/players/llew/Toys/misc/lego"),this_object());
   move_object(clone_object("/players/llew/Toys/misc/lego"),this_object());
}
