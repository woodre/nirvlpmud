inherit "obj/monster";

reset(arg) {
   ::reset(arg);
   if(arg) return;
   move_object(clone_object("/players/llew/Toys/armor/beret"),this_object());
   init_command("wear beret");
   set_name("Play-doh Man");
   set_level(6);
   set_alias("man");
   set_race("play-doh");
   set_hp(90);
   set_al(10);
   set_short("Play-doh Man");
   set_long("The man is made from many colors of squishy playdoh.\n"+
      "He has a smile formed on his face, but basically he just\n"+
      "sits there staring at nothing in particular.\n");
   set_wc(10);
   set_ac(5);
   set_alt_name("play-doh man");
   set_chat_chance(8);
   set_a_chat_chance(15);
   load_chat("Play-doh Man sits there.\n");
   load_chat("Play-doh Man doesn't do anything special.\n");
   load_chat("Play-doh Man looks squishy.\n");
   load_a_chat("Play-doh Man squished noisily.\n");
   load_a_chat("Play-doh Man gets hit.\n");
   load_a_chat("A chunk of doh falls off Play-doh Man.\n");
}
