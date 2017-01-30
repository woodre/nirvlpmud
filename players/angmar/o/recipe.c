inherit "obj/treasure";

void
reset(status arg) {
  if(arg)
    return;
  set_name("recipe");
  set_alias("angmars recipe");
  set_short("A recipe");
  set_long("A recipe, maybe you can read it.\n");
  set_weight(1);
  set_value(10);
}

status
get() {
  return 1;
}

void
init() {
  treasure::init();
  add_action("read_recipe", "read");
}

status
read_recipe(string str) {
  if (!id(str))
    return 0;
  write("Ingredients:\n\n");
  write("The fresh corpse of a monster\n");
  write("A dead fish\n");
  write("A slimy mushroom\n");
  write("A corncob\n");
  write("The skeleton of a rat\n\n");
  write("Mix all ingredients in a magically prepared container.\n");
  write("Add this recipe to the mixture and speak the magic words\n");
  write("kashmirak gorondolum\n");
  return 1;
}
    
status
query_destruct_when_sold() {
  return 1;
}
