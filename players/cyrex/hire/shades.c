inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("shades");
set_alias("mirrorshades");
set_short("MirrorShades");
set_long("A nice pair of shades. It reflects all the harmful UV radiation\n"+
         "that can damage your eyes.\n");
set_weight(1);
set_value(250);
set_ac(1);
set_type("misc");
}

