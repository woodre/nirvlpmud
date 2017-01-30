inherit "obj/monster";

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("Mrs. Potato Head");
   set_level(6);
   set_alias("potato head");
   set_race("potato");
   set_hp(90);
   set_al(50);
   set_short("Mrs. Potato Head");
   set_long("Mrs. Potato Head looks lovely in her feminine potato attire.\n"+
      "She has red lips and a smile, though she looks a bit worried\n"+
      "for Mr. Potato Head.\n");
   set_wc(10);
   set_ac(5);
   set_alt_name("mrs potato head");
   set_chat_chance(8);
   set_a_chat_chance(14);
   load_chat("Mrs. Potato Head comforts Mr. Potato Head.\n");
   load_chat("Mrs. Potato Head smiles pleasantly.\n");
   load_chat("Mrs. Potato Head fixes her parts.\n");
   load_a_chat("Mrs. Potato Head says, \"Oh no!\"\n");
   load_a_chat("Mrs. Potato Head frets.\n");
   load_a_chat("Mrs. Potato Head mashes.\n");
   move_object(clone_object("/players/llew/Toys/misc/rand_potato_part"),this_object());
   move_object(clone_object("/players/llew/Toys/misc/rand_potato_part"),this_object());
}
