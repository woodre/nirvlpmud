inherit"obj/treasure";
drop() { return 1; }
reset(arg) {
if(arg) return;
set_id("button");
set_alias("kewlbutton");
set_short("An \"I Am KEWL\" Button");
set_long(
"This is a small happy looking button from Pain\n"
);
set_value(0);
set_weight(0);
}
query_auto_load() { return "/players/pain/closed/items/kewl.c:";}
