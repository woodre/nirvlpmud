/* Set ac to 12 and wc to 14 - they were not set before  -Snow */


inherit "obj/monster";

reset(x) { if(x) return;
   set_hp(180);
  set_wc(12);
  set_ac(14);
   set_name("flagg");
   set_alias("advisor");
   set_short("Flagg, the King's advisor");
   set_al(142);
   set_long("This is Flagg, the advisor to the King.\n");
   set_level(12);
   set_chat_chance(40);
   load_chat("Flagg says:  Now where is that fool of a wizard Galileo?\n");
   load_chat("Flagg looks around briefly.\n");
   load_chat("Flagg says:  Galileo must be on top of the tower doing "+
             "experiments again.\n");
   load_chat("Flagg says:  That wizard is never around when you need him!\n");
   load_chat("Flagg sighs.\n");
   ::reset(0);
}

