inherit "obj/treasure";
reset(arg){
if (arg) return;
set_short("Potion of Invulnerability");
set_long("A small flask filled with bubbling pink liquid. Maybe\n"
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
ob = clone_object("/players/nightshade/misc/nohurt");
ob->shadow_target(this_player());
write ("You drink the potion and feel totally invincible!\n");
say(this_player()->query_name()+" drinks a potion of invulnerability.\n");
destruct(this_object());
return 1;
}
