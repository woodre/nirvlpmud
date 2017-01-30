inherit "obj/monster";

reset(arg) {
   ::reset();
   if(arg) return;
   set_name("Hephalump");
   set_level(8);
   set_alias("hephalump");
   set_race("stuffed animal");
   set_hp(120);
   set_al(-150);
   set_short("An ugly hephalump");
   set_long("This thing is the scariest beast you've ever set your poor\n"+
            "defenseless eyes upon.  It has stripes and polka dots, it's big,\n"+
            "and mean and angry.\n");
   set_wc(12);
   set_ac(7);
   set_chat_chance(7);
   set_a_chat_chance(14);
      load_chat("The hephalump roars.\n");
   load_chat("The hephalump roams around.\n");
   load_chat("The hephalump looks at you menacingly.\n");
   load_chat("The hephalump changes color before your very eyes.\n");
   load_a_chat("The hephalump ROARS!\n");
   load_a_chat("The hephalump whacks you with its trunk.\n");
   load_a_chat("The hephalump looks real mad.\n");
   load_a_chat("The hephalump charges about.\n");
   move_object(clone_object("/players/llew/Toys/heals/honey.c"),this_object());
}
