inherit "obj/treasure";

reset(arg) {
 if(arg) return;
set_short("a small key");
set_alias("key");
set_long("a small Army issue locker key.\n");
   set_weight(1);
    set_value(50);
set_save_flag(1);
}
id(str) { return str == "mash key" || str == "key"; }
