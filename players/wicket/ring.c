inherit "/obj/treasure.c";
#include <ansi.h>

id(str) {
return str == "ring" || str == "wicket_ring";
}

short() { return HIG+"--`--}"+HIR+"@ "+NORM+"Rob's own"+HIY+" golden "+NORM+"wedding ring (Kerrii)"; }
long() {
write("You see a wide band of pure gold, simple and elegant.\n"+
"This shows your undying love for your one, and true\n"+
"love for Kerrii Lidke.\n");
}

drop() { return 0; }
get() { return 1; }
query_weight() { return 2; }
query_value() { return 0; }
