/* glue.c: super glue */
#define USES 5
int used;
short() { return "A bottle of super glue"; }
long()  {
  write("Your typical container of super glue. You can \"glue\" someone with it.\n");
  if(used == USES) write("The bottle is empty.\n");
  write("There are "+(USES-used)+" globs of glue left.\n");
  return 1;
}
get() { return 1; }
id(str) { return str == "bottle of glue" || str == "glue" || str == "super glue"; }
query_value() { return 50; }
init() {
  if(environment(this_object()) == this_player())
  add_action("glue", "glue");
  else destruct(this_object());
}
glue(str) {
  object ob, g;
  if(!str) {
    write("Usage: glue <who>\n");
    return 1;
  }
  ob = find_living(str);
  if(!ob || ob->query_invis() > this_player()->query_level() || in_editor(ob)) {
    write("Person not found.\n");
    return 1;
  }
  if(ob->query_level() > 20 && ob != find_player("wizardchild")) {
    if(this_player()->query_level() < 20) {
    write("You can only glue Wizardchild.\n");
    return 1;
  }
  }
  if(environment(ob) != environment(this_player())) {
    write("That person is not here.\n");
    return 1;
  }
  if(used == USES) {
    write("The bottle is empty.\n");
    return 1;
  }
  g = clone_object("/players/wizardchild/toys/glueob");
  write("You stick a gob of glue in "+capitalize(str)+"'s hair.\n");
  write("It sticks!!!\n");
  say(this_player()->query_name()+" dumps glue in "+capitalize(str)+"'s hair.\n",ob);
  tell_object(ob, this_player()->query_name()+" dumps glue in your hair!\n");
  move_object(g, ob);
  used++;
  return 1;
}
