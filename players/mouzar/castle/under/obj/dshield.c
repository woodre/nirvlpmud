inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("shield");
set_short("Drow Shield");
set_long(
"A nicely crafted shield with a picture of a spider on the front of it\n");
set_weight(1);
set_value(500);
set_ac(1);
set_type("shield");
}
