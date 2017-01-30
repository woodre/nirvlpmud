id(str) { return str == "overthruster"; }

short() { return "An oscillation overthruster"; }

long()
{
    write(
    "    This is a strange-looking little device which operates as an exchanger providing\n"+
    "  power between two colliding beams of positrons and electrons. It allows for spatial\n"+
    "  inter-dimensional travel within the largely empty space of our existing matter.\n"+
    "  Yeah... that's the 'easy' explanation. Unfortunately, this oscillator appears\n"+
    "  to have burnt out some time ago.\n"); 
}

get() { return 1; }

query_value() { return 120; }

query_weight() { return 1; }

