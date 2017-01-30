inherit "/obj/objtracker.c"; /* 07/04/06 Earwax */
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
string *multipleIds;
/* added for donated items at green. Fred [7.28.06] */
static int donated_item;

id(str)
{
 if(!multipleIds) multipleIds = ({ });
  return (str == name || 
          str == alias_name || 
          str == "objtreasure" ||
          (member_array(str,multipleIds) > -1));
}

short() {
    return query_short();
}

long() {
    write(query_long());
    if(donated_item) write("This item has been donated.\n");
}

query_value() { return (donated_item ? 0 : value); }

set_id(str) {
    local_weight = 1;
    name = str;
}

set_name(str) { return set_id(str); }
set_alias(str) {
    alias_name = str;
}

set_short(str) {
    short_desc = str;
  if(!long_desc)
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


query_weight() {
    return local_weight;
}

init() {
  objtracker_init_check(); /* 07/04/06 Earwax */
    if (!read_msg)
	return;
#if 0 /* Rumplemintz */
    add_action("read"); add_verb("read");
#else
  add_action("read", "read");
#endif
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

query_save_flag() { return (donated_item ? 1 : save_flag); }
 
/* if shop_dest_flag != 0 then shop dests object, else it saves it. */
query_dest_flag() {return shop_dest_flag;}
/* if you wish the shop to keep the item then set the dest flag to 0
   be sure to do this after set_value */
set_dest_flag(arg) {shop_dest_flag=arg;}


get() { return 1; }

void SetMultipleIds(string *x)
{
 multipleIds = x;
}

string * QueryMultipleIds()
{
 return multipleIds;
}

reset() { }

query_short() { return short_desc; }
query_long() { return long_desc; }

query_light(){
  return set_light(0);
}

query_name() { return name; } /* added by verte boggle */

set_donated_item(int arg){ donated_item = arg; }
query_donated_item(){ return donated_item; }
is_treasure(){ return 1; }

set_my_light(x) { set_light(x); }
