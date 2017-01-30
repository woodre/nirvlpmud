static string short_desc, long_desc;
static int value, local_weight;
static string name, alias_name;
static string alt_name;
 
id(str) {
    return str == name || str == alias_name || str == alt_name;
}
 
short() {
    return short_desc;
}
 
long() {
    write(long_desc);
}
 
set_name(str) {
    name = str;
}
set_short(str) {
    short_desc = str;
    long_desc = "You see nothing special.\n";
}
set_alias(str) { alias_name = str; }
set_alt_name(str) { alt_name = str; }
set_long(str) { long_desc = str; }
set_value(v) { value = v; }
set_weight(w) { local_weight = w; }
get() { return 1; }
 
 
int query_value() { return value; }
int query_weight() { return local_weight; }
set_arm_light(l) { set_light(l); }

