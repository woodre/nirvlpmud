/*  the evil queen's crown  */

inherit "obj/armor";
reset(arg) {
  set_name("crown");
set_alias("gold crown");
  set_short("A Gold Crown");
  set_long(
	"A delicate and plain gold crown.\n");
  set_ac(1);
  set_type("helmet");
  set_weight(1);
  set_value(1000);
}

init() {
  ::init();
  move_object(clone_object("players/eurale/Dis/SnWht/OBJ/crown"),
    environment(this_object()));
  destruct(this_object());
}
