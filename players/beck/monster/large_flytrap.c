inherit "/players/beck/closed/FuzzyBeast.c";

reset(arg)
{
   object gold, fly;
   if(arg) return;
   set_name("flytrap");
   set_alias("flytrap");
   short_desc=({
         "A large venus flytrap",
         "A good sized venus flytrap",
         "A medium sized venus flytrap with huge traps",
});
   long_desc=({
         "This looks like a common venus flytrap except its leaves are\n"+
         "one foot in diameter.\n",
         "All you see is green as this uncommonly large trap\n"+
         "prepares to devour you.\n",
         "This flytrap is large enough to make you want to run away.\n",
});
   ::reset(arg);
   set_level(10);
   set_hp(150);
   set_wc(14);
   set_ac(8);
   set_aggressive(random(1));
   set_al(-200);
   set_chat_chance(1);
   load_chat("The Large Flytrap catches a large fly and burps.\n");
   gold=clone_object("obj/money");
   gold->set_money(350);
   move_object(gold, this_object());
   if(!present("fly", this_object())){
      fly = clone_object("/players/beck/object/fly.c");
      move_object(fly, this_object());
   }
}
