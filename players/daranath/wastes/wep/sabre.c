 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("sword");
set_alias("sabre");
set_short("A wicked curved sabre");
set_long("The steel of the blade gleams along the curve of the Sabre. Its handle\n"+
         "is wrapped in dark leather cord, protecting your hand as you wield it.\n");
set_class(17);
set_weight(1);
set_value(450);
}
