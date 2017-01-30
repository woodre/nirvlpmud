inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("hat");
set_alias("cone hat");
set_short("A cone hat");
set_long(
"This is a cone hat made of cardboard, it's painted with vivid and happy\n"
+ "colours, a huge ball of string is on the top of it, making ppl who wear\n"
+ "it look like clowns.\n");
set_weight(0);
set_value(0);
set_ac(1);
set_type("helmet");
}
