inherit "obj/monster";
object item;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("ant");
set_short("A Fire Ant");
set_long("This is a ferocious fire ant!\n");
set_al(15);
set_level(1);
set_wc(5);
set_hp(20);
set_ac(2);
set_ep(20);
set_aggressive(1);
item = clone_object("/players/grimm/newbie/object/seed");
move_object(item,this_object());
}
