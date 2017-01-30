id(str) { return str == "woo_obj" || str == "woo"; }
get() { return 1; }
drop() { return 1; }
init() { if(this_player()->query_real_name() != "arrina") destruct(this_object());
add_action("woo","woo");
}
woo(str) { return "/players/wizardchild/tool/woo"->woo(str); }
short() { return "Woo woo"; }
