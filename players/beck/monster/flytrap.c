inherit "obj/monster";

reset(arg)
{
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name("flytrap");
   set_alias("flytrap");
   set_short("A venus flytrap");
   set_long("This is a venus flytrap, a carniverous plant.\n");
   set_level(5);
   set_hp(75);
   set_ac(5);
   set_wc(9);
   set_aggressive(0);
   set_al(-100);
   set_chat_chance(1);
   load_chat("SNAP\n"+
      "The flytrap catches a fly, and starts to digest it.\n");
   gold=clone_object("obj/money");
   gold->set_money(200);
   move_object(gold, this_object());
}
