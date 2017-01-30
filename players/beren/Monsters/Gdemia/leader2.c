inherit "/players/beren/Monsters/Gdemia/leader.c";
object ob;
reset (arg) {
:: reset (arg);
if (arg) return;
ob = clone_object ("players/beren/Objects/Armors/Gdemia/gplate.c");
move_object (ob, this_object ());
command ("wear armor", this_object ());
set_ac (15);
}
