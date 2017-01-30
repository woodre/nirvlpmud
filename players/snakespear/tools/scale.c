#define TP this_player()
inherit "obj/treasure";

reset(arg) {
  set_id("scale");
  set_alias("scale");
  set_short("An anything scale");
  set_long("This is a uniquely specialized tool, used for examining stuff.\n"+
           "\t\tUse the command: ck <file>\n");
  set_weight(1);
  set_value(0);
}
init() {
  if(TP->query_level()<21) destruct(this_object());
  add_action("examine_weapon","ck");
}
examine_weapon(str) {
  object ob;
  string file;
  string info;
  ob=present(str,TP);
  if(!ob) {
   write("That's not here.\n");
   return 1;}
  info="";
  info+=pad(object_name(ob),50);
  info+=pad(ob->weapon_class(),4);
  info+=pad(ob->query_weight(),4);
  info+=pad(ob->short(),45);
  info+="\n";
  write(info);
  write_file("/players/snakespear/log/weight.log",info);
  write("Logged.\n");
  return 1;
}
