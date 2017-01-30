inherit "obj/monster";

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("woozle");
   set_level(7);
   set_race("stuffed animal");
   set_hp(105);
   set_al(-125);
   set_short("A scarry-looking woozle");
   set_long("The woozle is long and slender, scurrying about the room.\n"+
       "He looks very upsetting.  Don't look at it too long.\n");
   set_wc(11);
   set_ac(6);
   set_chat_chance(8);
   set_a_chat_chance(15);
   load_chat("The woozle scurries this way and that.\n");
   load_chat("The woozle makes an undescribable noise.\n");
   load_chat("The woozle honks at you.\n");
   load_chat("The woozle wiggles.\n");
   load_a_chat("The woozle screeches.\n");
   load_a_chat("The woozle claws at you.\n");
   load_a_chat("The woozle tries to bite you.\n");
}
