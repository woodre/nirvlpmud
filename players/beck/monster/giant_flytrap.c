inherit "obj/monster";

reset(arg)
{
   object gold, bird;
   ::reset(arg);
   if(arg) return;
   set_name("flytrap");
   set_alias("flytrap");
   set_short("A giant venus flytrap");
   set_long("This is the largest venus flytrap you have ever seen.\n"+
      "The traps are over 3 feet in diameter.  They look ready to eat you up.\n");
   set_level(15);
   set_hp(225);
   set_wc(20);
   set_ac(12);
   set_aggressive(0);
   set_al(-500);
   set_chat_chance(5);
   set_chance(20);
   set_spell_dam(8);
   set_spell_mess2("The Giand Flytrap catches you and starts to digest\n"+
      "your outer layer of skin.  You barely escape from certain death.\n");
   load_chat("The Giant Flytrap catches a small bird and burps.\n");
   gold=clone_object("obj/money");
   gold->set_money(750);
   move_object(gold, this_object());
   if(!present("bird", this_object())){
      bird = clone_object("/players/beck/object/small_bird.c");
      move_object(bird, this_object());
   }
}
