inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("boots");
set_size(1);
set_short("Lizard Skin Boots");
set_long(
"There boots were made from a giant black lizard.  Commonly found in\n"
+ "Undermouz.  It is very fashionable for the Duergar.\n");
set_weight(1);
set_value(200);
set_ac(1);
set_type("boots");
}
