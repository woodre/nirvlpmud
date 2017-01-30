inherit "/obj/armor.c";
#include "/obj/ansi.h"

reset(arg) 
{

    ::reset(arg);
    if(arg) return;
    set_name("hat");
    set_short("An asshat");

    set_long("This is a hat shaped as an ass. You study it more carefully\n"+
             "and the bet way to describe what it looks like it this:\n"+
             "\n"+
HIR +
"* g o a t s e x * g o a t s e x * g o a t s e x *\n"+
"g                                               g\n"+
"o /     \\             \\            /    \\       o\n"+
"a|       |             \\          |      |      a\n"+
"t|       `.             |         |       :     t\n"+
"s`        |             |        \\|       |     s\n"+
"e \\       | /       /  \\\\\\   --__ \\\\       :    e\n"+
"x  \\      \\/   _--~~          ~--__| \\     |    x\n"+
"*   \\      \\_-~                    ~-_\\    |    *\n"+
"g    \\_     \\        _.--------.______\\|   |    g\n"+
"o      \\     \\______// _ ___ _ (_(__>  \\   |    o\n"+
"a       \\   .  C ___)  ______ (_(____>  |  /    a\n"+
"t       /\\ |   C ____)/      \\ (_____>  |_/     t\n"+
"s      / /\\|   C_____)       |  (___>   /  \\    s\n"+
"e     |   (   _C_____)\\______/  // _/ /     \\   e\n"+
"x     |    \\  |__   \\\\_________// (__/       |  x\n"+
"*    | \\    \\____)   `----   --'             |  *\n"+
"g    |  \\_          ___\\       /_          _/ | g\n"+
"o   |              /    |     |  \\            | o\n"+
"a   |             |    /       \\  \\           | a\n"+
"t   |          / /    |         |  \\           |t\n"+
"s   |         / /      \\__/\\___/    |          |s\n"+
"e  |           /        |    |       |         |e\n"+
"x  |          |         |    |       |         |x\n"+
"* g o a t s e x * g o a t s e x * g o a t s e x *\n"+
NORM +
             "\n");

    set_value(100);
    set_ac(-1);
    set_type("helmet");
    set_alias("asshat");

    set_weight(1);
    set_size(4);
}

