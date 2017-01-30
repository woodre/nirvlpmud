#include "/obj/clean.c"
/*
 * This is a generic valuable object. Clone a copy, and
 * setup local values.
 */

string short_desc, long_desc, info;
int save_flag, value, local_weight;
string name, alias_name;
string read_msg;
int shop_dest_flag;

id(str)
{
    return str == name || str == alias_name;
}

short() {
    return short_desc;
}

long() {
    write(long_desc);
}

query_value() { return value; }

set_id(str) {
    local_weight = 1;
    name = str;
}

set_alias(str) {
    alias_name = str;
}

set_short(str) {
    short_desc = str;
    long_desc = "You see nothing special.\n";
}

set_long(str) {
    long_desc = str;
}

set_value(v) {
   shop_dest_flag = 1;
    value = v;
}

set_weight(w) {
    local_weight = w;
}

set_read(str) {
    read_msg = str;
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
  add_action("read", "read");
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
set_save_flag(arg) {
save_flag = 1;
if(arg > 0) save_flag = arg;
 }
query_save_flag() {
return save_flag;
 }
/* if shop_dest_flag != 0 then shop dests object, else it saves it. */
query_dest_flag() {return shop_dest_flag;}
/* if you wish the shop to keep the item then set the dest flag to 0
   be sure to do this after set_value */
set_dest_flag(arg) {shop_dest_flag=arg;}
