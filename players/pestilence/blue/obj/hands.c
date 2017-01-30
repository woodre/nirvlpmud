inherit "/obj/treasure.c";

reset(arg){
if(arg) return;
set_id("hands");
set_alias("tickety's hands");
set_short("Tickety's hands");
set_long(
"These are the black hands that used to tell time for Tickety Tock.\n");
set_value(300);
set_weight(1);
}
