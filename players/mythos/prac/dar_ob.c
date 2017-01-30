#include "/obj/clean.c"
string short_desc, long_desc;
string name, alias_name;
string read_msg;
string alt1,alt2,alt3;

id(str)
{
    return str == name || str == alias_name || str == alt1 || str == alt2 ||
           str == alt3;
}

short() {
    return short_desc;
}

long() {
    write(long_desc);
}

query_value() { return 0; }

set_id(str) {
    name = str;
}

set_alias(str) {
    alias_name = str;
}

set_short(str) {
    short_desc = str;
    long_desc = "You see nothing special.\n";
}

set_alt1(str) { alt1 = str; }

set_alt2(str) { alt2 = str; }

set_alt3(str) { alt3 = str; }

set_long(str) {
    long_desc = str;
}

set_read(str) {
    read_msg = str;
}

get() {
    return 1;
}

query_weight() {
    return 0;
}

init() {
    if (!read_msg)
	return;
    add_action("read", "read");
}

read(str) {
    if (str != name &&  str != alias_name)
	return 0;
    write(read_msg);
    return 1;
}

query_save_flag() { return 1;}
