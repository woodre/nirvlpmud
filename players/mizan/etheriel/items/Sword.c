inherit "obj/weapon";
int die, attacker, pain;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("sword");
    set_long("The hilt and scabbard of this magnificent weapon emit a gleaming\n"+
	"yellow-white light, but the blade of the sword is made of a dark blue\n"+
	"metal, obviously magically enhanced because it almost seems to come alive\n"+
	"alive in your hands...\n");
    set_short("A Sword named Summerhead");
    set_class(20);
    set_value(53000);
    set_alias("sword");
    set_weight(3);
    set_hit_func(this_object());
    }
}
