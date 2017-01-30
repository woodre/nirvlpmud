inherit"obj/monster";

   reset(arg) {
   ::reset(arg);
   
   if(!arg) {

   set_name("monster");
   set_short("A Generic Impossible Monster");
   set_level(1);
   set_hp(10000000);
   set_ac(100000);
   set_wc(3);
   set_a_chat_chance(75);
   load_a_chat("You cannot kill me MORON.\n");
   load_a_chat(capitalize(this_object()->query_name()) + " giggles.\n");
   }
}
