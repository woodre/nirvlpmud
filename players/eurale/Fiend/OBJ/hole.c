inherit "obj/treasure";
reset(arg) {
  if(arg) return;
    set_id("hole");
set_short("A large shallow hole");
set_long(
	"  This large, shallow hole dug in the clay, oddly enough resembles\n"+
	"the shape of a large man.\n");
    set_weight(1000);
    set_value(0);
}
