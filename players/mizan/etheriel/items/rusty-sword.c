inherit "obj/weapon";
int die, attacker, pain;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("rusty sword");
    set_long("This is a beat-up and rusty sword.\n"+
	"It is about as sharp as a bowling ball.\n");
    set_short("A rusty sword");
    set_class(8);
    set_value(200);
    set_alias("sword");
    set_weight(3);
    set_hit_func(this_object());
    }
}
