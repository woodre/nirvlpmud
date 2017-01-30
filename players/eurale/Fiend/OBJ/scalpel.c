/*  A Colt 45 Revolver */

inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("scalpel");
set_short("A surgical scalpel");
set_long(
	"  This surgical steel scalpel has the edge of a razor and a\n"+
	"smooth steel handle.  It's curved tip makes it an excellent\n"+
	"instrument for cutting through tissue.\n");

set_type("knife");
set_class(16);
set_weight(1);
set_value(500);
}
