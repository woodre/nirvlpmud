inherit"obj/monster";

reset(arg) {
   ::reset(arg);

   if(!arg) {

   set_name("demon");
   set_short("A little fire demon");
   set_long(
"Fire drips out of his  pores as he snorts fire at you.  Good thing he's not"+
"\nstanding on a shag rug.\n");
   set_level(9);
   set_hp(150);
   set_ac(7);
   set_wc(14);
   set_a_chat_chance(10);
   set_race("demon");
   load_a_chat("The fire demon flics his bic menacingly!!!\n");
   }
}
