inherit "obj/weapon";
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("power");
                set_class(15);
                set_value(1);
                set_weight(4);
                set_alias("sword");
      set_short("Power");
set_long("The power Mr Important wields is nothing more but tangible\n"+
"foce created by his mind. You can wield it, but it is not worth anything.\n");
}
}
