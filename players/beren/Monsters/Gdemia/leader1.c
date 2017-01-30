inherit "/players/beren/Monsters/Gdemia/leader.c";
object ob;
reset (arg) {
:: reset (arg);
if (arg) return;
ob = clone_object ("players/beren/Objects/Weapons/Gdemia/glongs.c");
move_object (ob, this_object ());
command ("wield sword", this_object ());
set_wc (25);
}
