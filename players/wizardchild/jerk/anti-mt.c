short() { return 0; }
long() { return 0; }
id(str) { return str == "blh"; }
drop() { return 1; }
init() { add_action("mt", "mt"); add_action("mt", "me"); 
         add_action("mt", "ct"); add_action("mt", "ce"); }
mt(str) {
        write("Fuck off you pansie bastard, you are not wanted on the guild channel.\n");
        return 1;
}
