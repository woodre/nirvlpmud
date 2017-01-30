int w;
 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("steel longsword");
set_alias("longsword");
set_type("sword");
set_short("A steel longsword");
set_long("A good sturdy steel longsword, the newly formed Qual'tor Town Guard\n"+
         "uses these almost exclusivly.\n");
set_class(14);
set_weight(1);
set_value(150);
}
