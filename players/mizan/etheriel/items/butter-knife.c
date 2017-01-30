inherit "obj/weapon";
int die, attacker, pain;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("butter knife");
    set_long("Not just any knife, but a firm yet flexible butter knife from\n"+
	"Strindler the Tool Maker's forge...\n");
    set_short("The butter knife of the Sandwich Maker");
    set_class(8);
    set_value(120);
    set_alias("knife");
    set_weight(1);
    set_hit_func(this_object());
    }
}
