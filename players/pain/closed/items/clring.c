inherit"obj/treasure";
drop() { return 1; }
reset(arg) {
if(arg) return;
set_id("ring");
set_alias("clring");
set_short("Glimmer's Claddaugh Ring from her suitor, Pain");
set_long(
"This is a small silver ring\n"
+ "It is an Irish claddaugh ring\n"
+ "A symbol of love and affection.\n");
set_value(0);
set_weight(0);
}
query_auto_load() { return "/players/pain/closed/items/clring.c:";}
