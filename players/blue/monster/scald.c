inherit "/obj/monster.c";

/*
 * Updated 9/1/05 by Feldegast.  Monster had 0 exp value.  Moved wielding of
 * weapon to before setting of wc and that fixed the problem.
 */

reset(arg) {

   object torch;

   ::reset(arg);

   if(!arg) {
     torch=clone_object("players/blue/weapons/torch");
     torch->set_short("Scald's propane torch");
     move_object( torch, this_object());
     command("wield torch",this_object());

     set_name("scald");
     set_short("Scald, the Prince of Fury");
     set_long(
"This is a huge creature, who seems to be a mixture of fire and flesh.\n"+
"Flames trail his movements and send waves of heat in all directions. He"+
" isn't\nthrilled to see you.\n");
     set_level(11);
     set_hp(165);
     set_wc(15);
     set_ac(9);
     set_chat_chance(5);
     load_chat("Scald narrows his eyebrows and examines you.\n");
     load_chat("Scald looks pissed.\n");
     load_a_chat("Scald shoots his torch with deadly aim!!!\n");
     load_a_chat("Scald lets loose a burst of fire!!!\n");
   }
}

