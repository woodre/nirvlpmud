id(str){ return str == "key" || str == "iron key" || str == "duln_key"; }
short(){ return "An iron key"; }
long(){ write("A rusted iron key.  It doesn't look very special.\n"); }
query_weight(){ return 1; }
query_value(){ return 10; }
get(){ return 1; }
