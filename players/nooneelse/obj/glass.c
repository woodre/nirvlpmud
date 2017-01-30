/*
 glass.c - filled in kitchen & used to put fire out in study
*/
 
inherit "obj/treasure";

int glass_is_full;
string str;

init() {
  ::init();

  add_action("drink", "drink");
}

drink(str) {
  if (str!="water") return;
  if (glass_is_full) {
    if (!present(this_object(), this_player()))
      move_object(this_object(), this_player());
    write(
      "You raise the glass to drink, but stop when you see how dirty it is.\n");
    say(this_player()->query_name()+
        " raises the glass to drink, but stops upon seeing how dirty it is.\n");
  }
  else
    write("But...the glass is empty!\n");
  return 1;
}
 
reset(arg) {
  set_short("a glass");
  set_long("A dirty drinking glass.\n");
  set_weight(1);
  set_value(1);
  set_glass_full(0);
}

long() {
  if (query_glass())
    write("The glass has water in it.\n");
  else
    write("The glass is empty.\n");
}

set_glass_full(arg) {glass_is_full=arg;}

query_glass() {return glass_is_full;}
id(str) {
  return str=="glass" || str=="drinking glass" || str=="water glass";
}

