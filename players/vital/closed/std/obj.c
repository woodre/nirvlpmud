#include "/obj/clean.c"
/*
// This is a generic valuable object. Clone a copy, and
// setup local values.
// Modified by Shadowhawk the NUISANCE to use arrays.
*/

string short_desc, long_desc, info, name, alias, alt_name;
int save_flag, value, local_weight;
string read_msg;
string *ids;

int
id(string str) {
  if(!ids) ids = ({ });
  return (member_array(str, ids) >= 0);
}

string
short() {
  return short_desc;
}

void
set_info(string str) {
  info = str;
}

void
long() {
    write(long_desc);
}

void
set_ids(string *new_ids) {
  local_weight = 1;
  ids = new_ids;
}

void
set_name(string str) {
  name = str;
}

void
set_alt_name(string str) {
  alt_name = str;
}

void
set_alias(string str) {
  alias = str;
}

void
set_short(string str) {
  short_desc = str;
  long_desc = "You see nothing special.\n";
}

void
set_long(string str) {
  long_desc = str;
}

void
set_value(int v) {
  value = v;
}

void
set_weight(int w) {
  local_weight = w;
}

void
set_read(string str) {
  read_msg = str;
}

void
set_save_flag() {
  save_flag = 1;
}

int
query_value() {
  return value;
}

int
get() {
  return 1;
}

int
query_weight() {
  return local_weight;
}

void
init() {
  if (!read_msg)
    return;
  add_action("read","read");
}

int
read(string str) {
  if (member_array(str, ids) == -1)
    return 0;
  write(read_msg);
  return 1;
}

string
query_info() {
  return info;
}


int
save_thing(string str) {
  save_object(str);
  return 1;
}

int
restore_thing(string str){
  restore_object(str);
  return 1;
}

int
query_save_flag() {
  return save_flag;
}
