inherit "obj/treasure";

reset(arg) {
 if(arg) return;
set_short("Hiram's key");
set_alias("key");
set_long("This is a brass skelenton key with an inscription on it.\n");
set_read("Hiram's key.\n");
set_weight(1);
set_value(0);
set_save_flag(1);
}
id(str) { return str == "hiram's key" || str == "key"; }
