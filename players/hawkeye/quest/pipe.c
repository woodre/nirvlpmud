inherit "obj/treasure";

reset(arg) {
 if(arg) return;
set_short("A Pipe");
set_alias("pipe");
set_long("A Pipe.\n");
   set_weight(1);
    set_value(5000);
set_save_flag(1);
}
 id(str) { return str == "pipe" || str == "quest"; }

