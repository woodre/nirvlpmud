inherit "obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("Katana of Lions");
set_alias("katana");
set_short("Katana of Lions");
set_long("Katana of the the Lion Men... a traditional weapon used by the\n" +
         "Lion Men in the Imperial Palace.\n");
set_value(1000);
set_weight(2);
set_class(15);
}
