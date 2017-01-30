inherit "obj/armor";

reset(arg){
   ::reset(arg);
   set_short("A small magic cube");
   set_long("In olden days this cube could cast forth a strong light to help\n"+
            "to guide the user.  Now only a faint glimmer is there.\n");
   set_ac(1);
   set_weight(2);
   set_value(100);
   set_alias("cube");
   set_name("Cube of Pentegarn");
   set_type("misc");
}
