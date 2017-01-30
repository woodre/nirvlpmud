#include "/obj/clean.c"
/*
// This is a generic valuable object. Clone a copy, and
// setup local values.
// Modified by Shadowhawk the NUISANCE to use arrays.
// reset() added by Vital - 2005.09.24
*/

string short_desc, long_desc, name, alias, alt_name;
int save_flag, value, local_weight;
string read_msg, info;
string *ids;

int
id(string str) { return (member_array(str, ids) >= 0); }

string
short() { return short_desc; }

void
long() { write(long_desc); }

void
set_name(string str)
{
  name = str;
  alias = str;
  alt_name = str;
  if(!ids) ids = ({ });
  if(member_array(str, ids) == -1)
    ids += ({ str });
}

void
set_alias(string str)
{
  alias = str;
  if(!ids) ids = ({ });
  if(member_array(str, ids) == -1)
    ids += ({ str });
}

void
set_alt_name(string str)
{
  alt_name = str;
  if(!ids) ids = ({ });
  if(member_array(str, ids) == -1)
    ids += ({ str });
}

void
set_id(string *new_ids)
{
  if(!ids) ids = ({ });
  local_weight = 1;
  ids = new_ids;
}

void
add_id(string new_id)
{
  if(!ids) ids = ({ });
  local_weight = 1;
  ids += ({ new_id });
}

void
set_short(string str) {
  short_desc = str;
  long_desc = "You see nothing special.\n";
}

void
set_long(string str) { long_desc = str; }

void
set_value(int v) { value = v; }

void
set_weight(int w) { local_weight = w; }

void
set_read(string str) { read_msg = str; }

void
set_info(string str) { info = str; }

void
set_save_flag() { save_flag = 1; }

string *
query_id()
{
  if(ids) return ids;
  else
    return ({ });
}

int
query_save_flag() { return save_flag; }

string
query_info() { return info; }

int
query_weight() { return local_weight; }

int
query_value() { return value; }

void
init()
{
  if (!read_msg)
    return;
  add_action("read", "read");
}

status
read(string str)
{
  if(!ids) ids = ({ });
  if (member_array(str, ids) == -1)
    return 0;
  write(read_msg);
  return 1;
}

status
save_thing(string str)
{
  save_object(str);
  return 1;
}

status
restore_thing(string str)
{
  restore_object(str);
  return 1;
}

status
get() { return 1; }

status
drop() { return 1; }

void
reset(int arg) { }

