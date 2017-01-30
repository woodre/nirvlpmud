inherit "obj/treasure";
object ob;
reset(arg) {
if (arg) return;
set_short("Topaz");
set_long
("A rather large topaz gem Hephastus has plundered.\n");
set_weight(1);
set_alias("gem");
set_value(500);
}
init() 
{
add_action("do_clone", "poo");
}
do_clone() {
   ob=clone_object("players/merlyn/engagement");
move_object(ob, this_object());
}
