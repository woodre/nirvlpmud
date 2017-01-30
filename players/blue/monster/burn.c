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
     torch->set_short("Burn's propane torch");
     move_object( torch, this_object());
     command("wield torch",this_object());

     set_name("burn");
     set_short("Burn, the Prince of Pain");
     set_long(
"This is a huge creature, who seems to be a mixture of fire and flesh.\n"+
"Flames trail his movements and send waves of heat in all directions. He"+
" isn't\nthrilled to see you.\n");
     set_level(11);
     set_hp(165);
     set_wc(15);
     set_ac(9);
     set_chat_chance(10);
     load_chat("Burn turns up his propane torch.\n");
     load_chat("Burn eyes you, looking for sensitive nerves\n");
     set_a_chat_chance(40);
     load_a_chat("Burn leaps into the air, cascading flames throughout the"+
                 " room!!!\n");
     load_a_chat("Burn cackles wildly as he shoots fire everywhere!!!\n");
   }
}

