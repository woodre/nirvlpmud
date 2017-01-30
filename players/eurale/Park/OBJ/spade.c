inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("archaeology spade");
set_alias("spade");
set_short("An archaeology spade");
set_long(
	"  This small, metal archaeology spade with the straight wooden \n"+
	"handle is used for digging up artifacts or delicate dinosaur\n"+
	"eggs for preservation.  It can also be used as a weapon in\n"+
	"an emergency.\n");
set_type("knife");
  set_class(8);
  set_weight(1);
  set_value(100);
}
