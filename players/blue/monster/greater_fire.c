inherit"obj/monster";

reset(arg) {

   ::reset(arg);

   if(!arg) {

   set_name("lord");
   set_short("A Lord of Flames");
   set_alias("lord");
   set_long(
"This is a huge creature, who seems to be a mixture of fire and flesh.\n"+
"Flames trail his movements and send waves of heat in all directions. He"+
" isn't\nthrilled to see you.\n");
   set_level(11);
   set_hp(165);
   set_ac(9);
   set_chat_chance(40);
   set_a_chat_chance(20);
   load_chat("A Fire Prince turns up his propane torch.\n");
   load_a_chat("A Fire Prince leaps high into the air as flames leap from"+
"his torch!!!\n");
}
   }
