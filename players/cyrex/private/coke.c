inherit "obj/soft_drink";
object can;
reset(arg) {
::reset (arg);
set_name("Coke Can");
set_alias("can");
set_alt_name("coke");
set_short("Can of Coke");
set_long("A unresistable can of refreshing icy Coke!\n");
set_value(2);
set_weight(1);
set_strength(10);
set_drinker_mess("You taste the difference from Pepsi!\n");
set_drinking_mess(" takes in the whole can of Coke with one drink!\n");
set_empty_container("can");
}
