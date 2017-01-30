short() { return "A reset device"; }
long()  { write("Type 'resetme <stat>' to set a null string in\n");
          return 1; }
id(str) { return str == "reset" || str == "device"; }
get()  { return 1; }
drop() { destruct(this_object()); return 1; }
init() { add_action("resetme", "resetme"); }
resetme(str) {
        if(!str) return 0;
        call_other(this_player(), str, "");
        write("Done.\n");
}
