inherit "obj/armor";

reset (arg) {
::reset (arg);
if (arg) return;

set_name("shield");
set_alias("shield");
set_short("Sonic Shield");
set_long("This shield is made from an unknown metal. It hums with tremendous\n"+
         "sounds that will block any incoming attacks. This shield is large\n"+
         "enough to cover your whole body and offers great protection.\n");
set_ac(2);
set_value(1000);
set_weight(1);
set_type("shield");

return;
}
