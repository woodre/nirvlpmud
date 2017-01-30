inherit "obj/monster";
object item;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("ant");
set_short("A Red Ant");
set_long("This is a ferocious red ant!\n");
set_al(15);
set_level(1);
set_wc(4);
set_hp(15);
set_ac(2);
set_ep(10);
set_aggressive(1);
item = clone_object("/players/grimm/newbie/object/cracker");
move_object(item,this_object());
}
