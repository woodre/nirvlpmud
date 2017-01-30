inherit "obj/treasure";

int current_page;
status recipeflag;

void
reset(status arg) {
  if(arg)
    return;
  set_name("notebook");
  set_alias("book");  
  set_short("A notebook");
  set_long("It is a small notebook with various formulas scribbled in it.\n");
  set_weight(1);
  set_value(10);
  current_page = 0;
  recipeflag=0;
}

status
get() {
  return 1;
}

void
init() {
  treasure::init();
  add_action("open", "open");
  add_action("close", "close");
  add_action("read_book", "read");
}

status
open(string str) {
  if (!id(str))
    return 0;
  if (current_page > 0) {
    write("The notebook is already open.\n");
    return 1;
  }
  current_page = 1;
  write("Ok.\n");
  if (!recipeflag) {
    recipeflag = 1;
    move_object(clone_object("players/angmar/o/recipe"),
      environment(this_player()));
    write("Something fell out of the notebook.\n");
    say("Something falls out of the notebook as "+
        this_player()->query_name()+" opens it.\n");
    }
  return 1;
}

status
close(string str) {
  if (!id(str))
    return 0;
  if (current_page == 0) {
    write("It is already closed.\n");
    return 1;
  }
  current_page = 0;
  write("Ok.\n");
  return 1;
}

status
read_book(string str) {
  if (!id(str))
    return 0;
  if (current_page == 0) {
    write("It is closed.\n");
    return 1;
  }
  if (current_page == 1)
    write("You can't understand the language.\n");
  return 1;
}
