query_auto_load() { return "/players/wizardchild/closed/no_channels:"; }
id(str) { return str == "still"; }
get() { return 1; }
drop() { return 1; }
init() { add_action("nope","risque");
add_action("nope","gossip");
add_action("nope","shout");
add_action("nope","junk");
add_action("nope","babble");
add_action("nope","equip");
add_action("nope","announce");
add_action("nope","wiz");
add_action("nope","msg");
}
nope(str) { write("You cannot do that.\n"); return 1; }
