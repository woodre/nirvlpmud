#include "/players/feldegast/defines.h"
inherit "obj/treasure";

reset(arg) {
  set_id("wand");
  set_alias("tool");
  set_short("Armor tool");
  set_long("This is a uniquely specialized tool, used for examining armor\n"+
           "objects in bulk.  Use the command: tf <file>\n");
  set_weight(1);
  set_value(0);
}
init() {
  if(TP->query_level()<21) destruct(this_object());
  add_action("examine_armor","tf");
}
examine_armor(str) {
  object ob;
  string file;
  string info;
  if(str[0]!='/') file=TP->get_path()+str;
  else file=str;
  write("File: "+file+"\n");
  ob=clone_object(file);
  if(!ob->query_type()) {
    write("That is not a piece of armor!\n");
    destruct(ob);
    return 1;
  }
  info="";
  info+=pad(file_name(ob),45);
  info+=pad(ob->armor_class(),5);
  info+=pad(ob->query_type(),8);
  info+=pad(ob->query_weight(),5);
  info+=pad(ob->query_value(),7);  
  info+="\n";
  write(info);
  write_file("/players/feldegast/log/armor.log",info);

  write("You jot this information down.\n");
  destruct(ob);
  return 1;
}


