#define MAX_WEIGTH	30
#define ME capitalize(this_player()->query_name())

int local_weight;
int closed;
string owner;

long() {
  if(owner != "noone")
    write(capitalize(owner)+"'s iron chest.\n");

  write(
  "A large chest with iron siding.  This heavy chest is nearly\n"+
  "indestructable!  The chest's unique lock will prevent anyone\n"+
  "but the owner from opening it.\n");

  if(closed) {
    write("The chest is closed.\n");
    return;
  }
  else 
    write("The chest is open.\n");
}

reset(arg) {
  if(arg) return;
  closed = 0;
  owner = "noone";
  local_weight = 0;
}

init() {
  add_action("open","open");
  add_action("close","close");
}

open(str) {
  if(id(str)) {
    if(owner == "nooone" || this_player()->query_real_name() == owner) {
      write("You open the chest.\n");
      say(ME+" opens the iron chest.\n");
      closed = 0;
      return 1;
    }
    else {
      write("The chest is locked!\n");
      say(ME+" tries to open an iron chest.\n");
      return 1;
    }
  }
}

close(str) {
  if(id(str)) {
    write("You close the iron chest.\n");
    write("The strange lock glows under your fingertips.\n");
    say(ME+" closes an iron chest.\n");
    owner = this_player()->query_real_name();
    closed = 1;
    return 1;
  }
}

query_weight() { return 6; }

add_weight(w) {
  if (local_weight + w > MAX_WEIGTH)
    return 0;
  local_weight += w;
  return 1;
}

short() {
  string tmp;
  if(closed) tmp = "closed"; else tmp = "open";
  return "a large iron chest ["+tmp+"]";
}

id(str) { return str == "chest" || str == "iron chest"; }

query_value() { return 100; }

can_put_and_get() {
  if(!closed) return 1;
  else return 0;
}

get() {
  if(!closed) return 1;
  if(owner == "noone") return 1;
  if(this_player()->query_real_name() != owner) {
    write("The chest will not budge!\n");
    say(ME+" tries to take the iron chest but it will not budge.\n");
    return 0;
  }
  return 1;
}

prevent_insert() {
  if (local_weight > 0) {
    write("You can't when there are things in the bag.\n");
    return 1;
  }
  return 0;
}
