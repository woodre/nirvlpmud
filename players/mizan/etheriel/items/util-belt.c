#define MAX_WEIGTH      6
inherit "obj/armor";

int local_weight;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  local_weight = 0;
  set_name("Batman's Utility Belt");
  set_value(2000);
  set_ac(1);
  set_weight(1);
  set_type("belt");
  set_alias("belt");
}

clean_up() {
  if(local_weight) {
    write("The items in the belt clunk and clatter against one another.\n");
  }
  return 1;
}

long() {
    write("This is a bright yellow belt with a variety of locked compartments\n"+
	"and canisters on it. However, one of them appears to be usable.\n");
    if (first_inventory(this_object()))
        write("There are things in the belt.\n");
    else
        write("Maybe you can put things into the belt.\n");
}

add_weight(w) {
  if (local_weight + w > MAX_WEIGTH) return 0;
  local_weight += w;
  return 1;
}

short() {
  if(worn) {
    return "Batman's Utility Belt (worn)";
  }
  return "Batman's Utility Belt";
}

can_put_and_get() { return 1; }

get() {
    return 1;
}

prevent_insert() {
  if (local_weight > 0) {
    write("You can't when there are things in the belt.\n");
    return 1;
  }
  return 0;
}

