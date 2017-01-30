/*
 * This is a generic valuable object. Clone a copy, and
 * setup local values.
 */

string short_desc, long_desc, info;
int save_flag, value, local_weight;
string name, alias_name;
string read_msg;

id(str)
{
    return str == "rose" || str == "a rose";
}

short() {
    return "A rose";
}

long() {
    write("A long stemmed rose\n");
}

query_value() { return 100; }

set_id(str) {
    local_weight = 1;
    name = "rose";
}

set_alias(str) {
    alias_name = "a rose";
}

set_short(str) {
    short_desc = "A rose";
    long_desc = "You see nothing special.\n";
}

set_long(str) {
    long_desc = "a long stemmed red rose\n";

}

set_value(v) {
    value = 100;
}

set_weight(w) {
    local_weight = 1;
}

set_read(str) {
    read_msg = "Une fleur pour vous ma cherie\n";
}

get() {
    return 1;
}

query_weight() {
    return local_weight;
}

init() {
    if (!read_msg)
	return;
    add_action("read","read");
}

read(str) {
    if (str != name &&  str != alias_name)
	return 0;
    write(read_msg);
    return 1;
}

set_info(str) { info = str; }
query_info() { return info; }
save_thing(str){
     save_object(str);
     return 1;
  }
restore_thing(str){
      restore_object(str);
      return 1;
   }
set_save_flag() {
save_flag = 1;
 }
query_save_flag() {
return save_flag;
 }
