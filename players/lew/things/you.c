inherit "obj/monster";

reset(arg) {
  ::reset(arg);
   if(!arg) {
   set_name("you");
  set_short("You the foolish one");
   set_alias("you");
   set_long("It is you");
   set_level(4);
   set_wc(10);
   set_ac(3);
   random_move();
   set_spell_mess1("You puke on your shoes.\n");
   set_spell_mess2("Your cheeks are burning.\n");
   set_spell_dam(15);
   set_chat_chance(50);
   load_chat("You say: Kill me please.\n");
   load_chat("You say: I need to die.\n");
   load_chat("Excuse yourself.\n");
   load_chat("You burst into tears.\n");

   load_chat("B O I N G!\n");
   set_a_chat_chance(5);
   load_a_chat("\n"+
               "\n"+
               "You die.\n"+
               "You have a strange feeling.\n"+
               "You see your body from above.\n"+
               "\n"+
               "Resetting hitpoints to 1/3 max.\n");
}
}
