inherit "obj/armor";
object cloak;
reset(arg) {
::reset(arg);
set_name("Cloak of Masters");
set_alias("cloak");
set_short("Cloak of Masters");
set_long("A heavy shimmering cloak that once belonged to the Robotech\n"+
          "Masters. It would seem to provide an excellent protection\n"+
          "against heavy attacks.\n");
set_ac(1);
set_weight(3);
set_value(2500);
set_type("misc");
}
