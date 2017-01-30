 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("sword");
set_alias("black");
set_short("A blackened longsword");
set_long("The blade of the longsword has been blackened to prevent it reflecting\n"+
         "light during a robbery or an assassination attempt.\n");
set_class(14);
set_weight(2);
set_value(250);
}
