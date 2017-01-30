 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("sword");
set_alias("black");
set_short("A blackened shortsword");
set_long("The blade of the shortsword has been blackened to prevent it reflecting\n"+
         "light during a robbery or an assassination attempt.\n");
set_class(13);
set_weight(1);
set_value(100);
}
