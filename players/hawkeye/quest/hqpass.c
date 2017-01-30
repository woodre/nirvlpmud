inherit "obj/treasure";

reset(arg) {
 if(arg) return;
set_short("A Three Day Pass");
set_alias("pass");
set_long("A Three Day Pass.\n");
   set_weight(1);
    set_value(5000);
set_save_flag(1);
}
 id(str) { return str == "pass" || str == "quest"; }

