inherit "obj/monster";

reset(arg){
   object gold,weap,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("vendor");
   set_alias("vendor");
   set_short("Town Vendor");
set_long("An ordianry vendor selling meat pies.\n");
   set_level(16);
set_aggressive(0);
   set_hp(400);
   set_al(0);
   set_wc(22);
   set_ac(13);
   set_chance(30);
   set_spell_dam(15);
set_spell_mess1("The vendor whips out a meat pie!\n");
set_spell_mess2("You are hit in the face by a meat pie!\n");
   gold=clone_object("obj/money");
   gold->set_money(890);
   move_object(gold,this_object());
weap=clone_object("players/nightshade/misc/pie");
move_object(weap, this_object());
}
