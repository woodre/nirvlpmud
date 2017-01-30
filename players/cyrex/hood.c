inherit "obj/armor";
object hood;
reset(arg) {
::reset(arg);
set_name("Hood of masters");
set_alias("hood");
set_short("Hood of Masters");
set_long("A strange hood that once belonged to the Robotech Masters.\n"+
         "It would serve the wearer great protection for the head for it\n"+
         "is made of an unknown material that only the Masters would know of.\n");
set_ac(2);
set_weight(2);
set_value(2500);
set_type("helmet");
}
