inherit "obj/armor";
object boots;
reset(arg) {
::reset(arg);
set_name("boots");
set_alias("boots");
set_short("Mech-Boots");
set_long("A pair of boots made from a very strong material conceived by\n"+
         "the Robotech Masters. It would seem tough to wear, yet it seems\n"+
         "so soft and comfortable. It provides an excellent protection\n"+
         "from the feet up till the knees.\n");
set_ac(2);
/* need some more ac2 boots -Jaraxle [11/10/02] */
set_weight(1);
set_value(1000);
set_type("boots");
}
