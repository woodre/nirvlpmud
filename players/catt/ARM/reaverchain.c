inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("chainmail");
set_alias("chain");
set_short("Black mercenary chainmail");
set_long(
"This is the black chainmail worn by reavers mercenary company...\n"
+ "it is not really black but a black tinted silver. You also \n" +
"notice that this chainmail is very light, whatever the reason you feel\n" +
 "this is very good armor.\n", 1);
set_weight(2);
/* Value changed from 5000 to 500  -Snow */
set_value(500);
set_ac(4);
set_type("armor");
}
