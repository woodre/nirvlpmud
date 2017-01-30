inherit "obj/treasure";
reset(arg){
if (arg) return;
set_short("Potion of Invisibility");
set_long("A small flask filled with bubbling black liquid. Maybe\n"
+ "You should drink it.\n");
   set_weight(1);
   set_value(10000);
   set_alias("potion");
}
init() {
::init();
if (environment() == this_player()) add_action ("drink","drink");
}
drink(str) {
object ob;
if (present(str,this_player()) != this_object()) return 0;
if (this_player()->query_invis()) {
   write ("You are already invisible.\n");
   return 1;
}
ob = clone_object("/players/nightshade/misc/invis_obj");
move_object(ob,this_player());
ob->invis_em();
write ("You drink the potion of invisibility.\n");
say(this_player()->query_name()+" drinks a potion of invisibility.\n");
destruct(this_object());
this_player()->recalc_weight();
return 1;
}
