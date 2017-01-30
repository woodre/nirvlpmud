 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("warped staff");
set_alias("staff");
set_alt_name("quarterstaff");
set_short("A warped wooden quarterstaff");
set_long("A wooden quarterstaff, it has been neglected for so long that the wood\n"+
         "itself has warped, creating a unique look to the weapon.\n");
set_class(17);
set_weight(1);
set_value(250);
}
