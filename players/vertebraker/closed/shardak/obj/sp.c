#include "/players/balowski/lib.h"
inherit ITEM;

string          *Parts;
int             *Decay;
static string   LongLine;

void create() {
    ::create();
    set_name("stakes");
    set_ids("spears");
    set_property("prevent_get", "You decide not to.\n");
    set_short("Spears and stakes erected from the ground");
    set_long("\
The spears and stakes are firmly secured in the dark soil. There are\n\
slender wooden spears and worm-eaten old stakes rearing their points\n\
in the air. They are smeared in the blood of slain enemies.\n");
    LongLine = "Nothing is mounted.\n";
    Parts = ({ });
    Decay = ({ });
}

void long(string id) {
    ::long(id);
    write(LongLine);
}

void init() {
    add_action("cmd_mount", "mount");
}

string stringify(string *strs) {
    return format(implode(strs, ", "));
}

status cmd_mount(string arg) {
    string it, on;
    object ob;
    int decay, i;

    if (!arg) return (notify_fail("Mount what?\n"), 0);
    if (sscanf(arg, "%s on %s", it, on) != 2) {
        return (notify_fail("Mount " + arg + " on what?\n"), 0);
    }
    if (!id(on)) return 0;
    if (!(ob = present(it, this_player()))) {
        write("You have no " + it + ".\n");
        return 1;
    }
    if (!(decay = (int) ob->query_property("bodypart"))) {
        write("You decide not to.\n");
        return 1;
    }

    it = (string) ob->short();
    i = member_array(it, Parts);
    if (i >= 0) {
        write("You throw away the old body part and mount the new.\n");
        Decay[i] = decay;
    }
    else {
        Parts += ({ it });
       
        Decay += ({ decay });
    }
    destruct(ob);
    return 1;
}
