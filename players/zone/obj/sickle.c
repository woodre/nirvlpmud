inherit"obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("Golden Sickle");
set_alias("sickle");
set_short("sickle");
set_long(
"A golden sickle used to harvest herbs.  A branch is cut and caught in a\n";
"basket before it hits the ground.\n");
set_value(3000);
set_weight(2);
set_class(10);
}
