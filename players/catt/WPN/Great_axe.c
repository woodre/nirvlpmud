inherit"obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("broad bladed axe");
set_alias("axe");

set_long("you see a broad bladed axe. It is an awesome weapon\n"+
         "used by only the mightiest of warriors\n");
set_short("Broad Bladed Axe");
set_value(0);
set_weight(1);
set_class(20);
}
