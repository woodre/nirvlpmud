inherit "obj/monster";

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("Barbie");
   set_level(7);
   set_alias("barbie");
   set_race("doll");
   set_hp(105);
   set_al(40);
   set_short("Barbie");
   set_long("It's the famous Barbie in all her perfection.  Her slender\n"+
      "figure and blonde hair catch every eye.  Don't you want to be\n"+
      "just like her when you grow up?\n");
   set_wc(11);
   set_ac(6);
   set_chat_chance(8);
   set_a_chat_chance(14);
   load_chat("Barbie brushes her pretty hair.\n");
   load_chat("Barbie says, \"I love to drive my new car.\"\n");
   load_chat("Barbie smiles beautifully.\n");
   load_chat("Barbie struts her stuff!\n");
   load_a_chat("Barbie screams!\n");
   load_a_chat("Barbie says, \"You are NOT nice!\"\n");
   load_a_chat("Barbie whacks you with her purse.\n");
   load_a_chat("Barbie gives you a dirty look, but she looks pretty doing it.\n");
   move_object(clone_object("/players/llew/Toys/misc/brush"),this_object());
   move_object(clone_object("/players/llew/Toys/misc/purse"),this_object());
}
