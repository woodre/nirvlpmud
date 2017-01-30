inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("shovel");
set_short("A small shovel");
set_long(
	"  This small, metal shovel with the straight wooden handle \n"+
	"is used for digging in the clay found in the area.  The handle\n"+
	"length provides good leverage against the sticky clay.\n");

set_type("club");
set_class(10);
set_weight(1);
set_value(100);
}
