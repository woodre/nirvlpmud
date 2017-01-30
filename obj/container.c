inherit "/obj/clean";
inherit "/obj/objtracker.c"; /* 07/04/06 Earwax */

int local_weight, max_weight, weight, value, opened, can_open;
string name, long_desc, short_desc, info;

long() {
  write(long_desc);
  if(can_open) {
    if(opened) {
      write("It is open. ");
      if (first_inventory(this_object()))
	write("There is something in it.\n");
      else
	write("You can put things in it.\n");
    } else {
      write("It is closed.\n");
    }
  } else {
    if (first_inventory(this_object()))
      write("There is something in it.\n");
    else
      write("You can put things in it.\n");
  }
}

reset(arg) {
  if (arg)
    return;
   set_no_clean(1);
  local_weight = 0;
  opened = 0;
}

init() {
  objtracker_init_check(); /* 07/04/06 Earwax */
  if(can_open) {
#if 0 /* Rumplemintz */
    add_action("open"); add_verb("open");
    add_action("close"); add_verb("close");
#else
  add_action("open", "open");
  add_action("close", "close");
#endif
  }
}

query_weight() {
  return weight;
}

add_weight(w) {
  if (local_weight + w > max_weight)
    return 0;
  local_weight += w;
  return 1;
}

short() {
  return short_desc;
}

id(str) {
    return (str == name || str == short_desc);
}

query_value() {
    return value;
}

can_put_and_get() { 
  if(can_open)
    return opened;
  else
    return 1;
}

get() {
    return 1;
}

prevent_insert() {
  if (local_weight > 0) {
    write("You can't when there are things in it.\n");
    return 1;
  }
  return 0;
}

set_value(v) {value = v;}
set_name(n) {name = n;}
set_long(l) {long_desc = l;}
set_short(s) {short_desc = s;}
set_weight(w) {weight = w;}
set_max_weight(m) {max_weight = m;}
set_info(i) {info = i;}
set_can_open(o) {can_open = o;}
is_container() { return 1; }

query_info() {return info;}
query_local_weight() {return local_weight;}
query_name() {return name;}
query_open() {return opened;}

close(str)
{
  if (!id(str))
    return 0;
  opened = 0;
  write("Ok.\n");
  return 1;
}

open(str)
{
  if (!id(str))
    return 0;
  opened = 1;
  write("Ok.\n");
  return 1;
}
