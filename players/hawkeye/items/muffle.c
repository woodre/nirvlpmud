inherit "obj/treasure";
int i;
init() {
  add_action("gag","gag");
  ::init();
 }
reset(arg) {
   if (arg) return;
   i = 5;
  set_short("A Gag");
   set_alias("gag");
   set_weight(1);
   set_value(200);
  set_long("A Gag");
}
gag(str) {
 object ob, stick;
  if(!str) {
    write("gag what?\n");
    return 1;
  }
  if(str=="hawkeye") {
    write("I THINK NOT!\n");
    return 1;
  }
  if (i>0) {
  if (!present(str,environment(this_player()))) {
    write("gag whom?\n");
  } else {
  ob = find_living(str);
    if(ob->query_level()>19 && !this_player()->query_real_name()=="hawkeye") {
  write("Cant tape them\n");
     move_object(stick, this_player());
     i--;
   write("You tapped um.\n");
   i--;
    stick = clone_object("players/hawkeye/items/muffler.c");
     move_object(stick,ob);
  }
  }
 } else {
  write("The gag disappears.\n");
  destruct(this_object());
  return 1;
  }
return 1;
}
