/*
 * Updated 9/1/05 by Feldegast.  Monster had 0 exp value.  Moved wielding of
 * weapon to before setting of wc and that fixed the problem.  Also reduced
 * chat chance (spammy!)
 */

inherit "/obj/monster";

reset(arg) {

   object torch;

   ::reset(arg);

   if(!arg) {
     torch=clone_object("players/blue/weapons/torch");
     torch->set_short("Scorch's propane torch");
     move_object( torch, this_object());
     command("wield torch",this_object());

     set_name("scorch");
     set_short("Scorch, the Prince of Destruction");
     set_long(
"This is a huge creature, who seems to be a mixture of fire and flesh.\n"+
"Flames trail his movements and send waves of heat in all directions. He"+
" isn't\nthrilled to see you.\n");
     set_level(11);
     set_hp(165);
     set_wc(15);
     set_ac(9);
     set_chat_chance(5);
     load_chat("Scorch's veins begin to appear on his forehead.\n");
     load_chat("Scorch picks up a rock and eats it.\n");
     load_a_chat("Scorch roars with power!!!\n");
     load_a_chat("You feel the temperature rise as Scorch blasts his torch\n");
   }
}

