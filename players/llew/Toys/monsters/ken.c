inherit "obj/monster";

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("Ken");
   set_level(7);
   set_alias("ken");
   set_race("doll");
   set_hp(105);
   set_al(35);
   set_short("Ken");
   set_long("Ken is gorgeous in his masculinity.  His plastered smile\n"+
      "increases his sense of vanity.  Isn't he perfect?\n");
   set_wc(11);
   set_ac(6);
   set_alt_name("ken_doll");
   set_chat_chance(8);
   set_a_chat_chance(14);
   load_chat("Ken looks at himself in a mirror.\n");
   load_chat("Ken says, \"Aren't I beautiful?\"\n");
   load_chat("Ken smiles at himself.\n");
   load_chat("Ken buys Barbie a new car.\n");
   load_a_chat("Ken shouts, \"Don't mess up my hair.\"\n");
   load_a_chat("Ken hits you like a girl.\n");
   load_a_chat("Ken looks around for Barbie to protect him.\n");
   load_a_chat("Ken looks mighty uncomfortable.\n");
   move_object(clone_object("/players/saber/stuff/mirror"),this_object());
}
