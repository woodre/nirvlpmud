inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("deadring");
set_short("ring");
set_long("A metallic ring which has an ornate minotour carved into its\n"+
"mantle.  The bloodstone eyes glint unnaturally and cast shadow over its\n"+
"surface under all lighting conditions.\n");
set_weight(1);
set_value(2500);
set_ac(1);
set_type("ring");
}
