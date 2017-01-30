inherit "obj/monster";
object gold,ob;
reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("monster");
   set_alias("monster");
set_short("Nameless Monster");
set_long(
"This is a monster that has no name. Kill it anyway. HeHe.\n");
   set_level(10);
   set_hp(150);
   set_al(100);
   set_wc(14);
   set_ac(8);
   gold=clone_object("obj/money");
   gold->set_money(200);
   move_object(gold,this_object());
ob=clone_object("players/nightshade/armor/typeless");
move_object(ob, this_object());
}
