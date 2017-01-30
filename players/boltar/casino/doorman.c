inherit "obj/living.c";

#include "security.h"
#include "/obj/lib/living/settings.h"

short() { return "A Doorman"; }

long(str) {
       write("The doorman is wearing a brightly colored uniform, \n"+
             "typical of the trade. It is blue with gold trim.\n" +
             "He appears happy and greets you with a smile.\n");
       return 1;
}
id(str) {
    return str == "doorman" || str == "man";
}

reset(arg) {
    if (arg)
	return;
    name = "doorman";
    level = 15;
    experience = 50000;
    max_hp = 200;
    hit_point = 200;
    weapon_class = 12;
    is_npc = 1;
    cap_name = "Doorman";
    alignment = 200;
    enable_commands();
}

query_name() { return "doorman"; }

