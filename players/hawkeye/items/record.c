inherit "obj/treasure";

reset(arg) {
 if(arg) return;
set_short("A Mozart Record");
set_alias("record");
set_long("This is a Record of The Boston Symphony playing Mozart.\n");
   set_weight(1);
    set_value(750);
}
 id(str) { return str == "record" || str == "Doppleganger Badge"; }

