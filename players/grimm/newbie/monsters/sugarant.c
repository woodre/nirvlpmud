inherit "obj/monster";
object item;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("ant");
set_short("A Sugar Ant");
set_long("This is a ferocious sugar ant!\n");
set_al(15);
set_level(1);
set_wc(3);
set_hp(17);
set_ac(2);
set_ep(13);
set_aggressive(1);
item = clone_object("/players/grimm/newbie/object/sugar");
move_object(item,this_object());
}
