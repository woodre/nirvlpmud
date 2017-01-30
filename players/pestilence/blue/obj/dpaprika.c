inherit "/obj/treasure.c";

reset(arg){
if(arg) return;
set_id("paprika");
set_alias("dash");
set_short("A dash of Paprika");
set_long(
"A dash of paprika from baby Paprika.\n");
set_value(100);
set_weight(1);
}
