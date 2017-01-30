int local_weight, max_weight, weight, value, opened, can_open;
int can_get, cant_put;
string name, long_desc, short_desc, alias_name, info;

long() {
  write(long_desc);
  if(can_open) {
    if(opened) {
      write("It is open. ");
      if (first_inventory(this_object()))
	write("There is something in it.\n");
      else
        write("It is empty.\n");
    } else {
      write("It is closed.\n");
    }
  } else {
    if (first_inventory(this_object()))
      write("There is something in it.\n");
    else
      write("It is empty.\n");
  }
}

reset(arg) {
  opened=0;
  if (arg)
    return;
  local_weight = 0;
  opened = 0;
}

init() {
  if(can_open) {
    add_action("open","open");
    add_action("close","close");
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
    return (str == name || str == alias_name);
}

query_value() {
    return value;
}

can_put_and_get(str) {
  if(can_open)
    return opened;
  if(cant_put)
    return str!=0;
  else
    return 1;
}

get() {
    return can_get;
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
set_short(s) {
     short_desc=s;
     if(!long_desc)
          long_desc="You see nothing special.\n";
}
set_alias(a) { alias_name = a; }
set_weight(w) {weight = w;}
set_max_weight(m) {max_weight = m;}
set_info(i) {info = i;}
set_can_get(g) { can_get = g; }
set_can_open(o) {can_open = o;}
set_cant_put(p) { cant_put=p; }

query_alias() { return alias_name; }
query_info() {return info;}
query_local_weight() {return local_weight;}
query_name() {return name;}
query_open() {return opened;}
query_cant_put() { return cant_put; }

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
