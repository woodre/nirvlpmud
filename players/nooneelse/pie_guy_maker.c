/*
 pie_guy_maker.c
*/
inherit "obj/treasure";
object obj;
string msg, str;
init() {
  add_action("make_pie_guy", "mpg");
}

make_pie_guy(msg){
  if (!msg) {
    write("You must supply target name.\n");
    return 1;
  }
  obj=clone_object("players/nooneelse/pie_guy");
  obj->set_target_name(msg);
  call_other("/players/nooneelse/pie_shop", "???", 0);
  move_object(obj, "/players/nooneelse/pie_shop");
  return 1;
}

reset(arg) {
  if (arg) return;
  set_short("a pie guy maker. (type mpg <target>)");
  set_long("A pie guy maker. (type mpg <target>).\n");
  set_value(0);
  set_weight(1);
}

id(str) { return str=="pie guy maker"; }
