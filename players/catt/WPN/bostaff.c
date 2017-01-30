inherit"obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("bo staff");
set_alias("staff");
set_short("bo staff");
set_long(
"a small bo staff of the shintae monks... it seems to have special\n"
+ "runes carved into it.\n");
set_value(200);
set_weight(2);
set_class(7);
}
