inherit "obj/monster";

reset(arg) {
  ::reset(arg);
   if(arg) return;
   set_name("teddy bear");
   set_level(5);
   set_alias("bear");
   set_race("stuffed animal");
   set_hp(70);
   set_al(75);
   set_wc(8);
   set_ac(7);
   switch(random(4)+1) {
      case 1:
        set_short("A brown teddy bear");
         break;
      case 2:
         set_short("A black teddy bear");
         break;
      case 3:
         set_short("A white teddy bear");
         break;
      case 4:
         set_short("A gray teddy bear");
         break;
   }
   set_long("A soft teddy bear that looks like it wants to be loved.\n");
   set_chat_chance(8);
   set_a_chat_chance(15);
   set_alt_name("rand_teddy");
   load_chat("A teddy bear hugs you.\n");
   load_chat("A teddy bear looks at you lovingly.\n");
   load_chat("A teddy bear nuzzles you warmly.\n");
   load_a_chat("The teddy bear looks sad.\n");
   load_a_chat("The teddy bear beats you with it's paw.\n");
}
