inherit "obj/monster";

reset(arg)
{
   object gold, weapon;
   ::reset(arg);
   if(arg) return;
   set_name("flytrap");
   set_alias("flytrap");
   set_short("The Invenusable Flytrap");
   set_long("The Invenusable Flytrap is the ruler of Venus Island\n"+
      "It is a tall green monster with an inpeneratrable outer shell\n"+
      "Be careful it doesn't catch you in its trap.\n"+
      "");
   set_level(20);
   set_ac(19);
   set_wc(30);
   set_hp(500);
   set_al(-500);
   set_chance(25);
   set_spell_dam(10);
   set_spell_mess2("The Invenusable Flytrap catches you and starts to digest you, but you\n"+
      "manage to escape this time.\n");
   gold=clone_object("obj/money");
   gold->set_money(5000);
   move_object(gold, this_object());
}
