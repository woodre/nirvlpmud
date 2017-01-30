/* A teller to Jara */
inherit "obj/treasure";
#include "/players/jara/misc/ansi.h"

reset(arg) {
  if(arg) return;

  set_id("amulet");
  set_alias("jtell");
  set_short("An Amulet ("+HIC+"glowing"+NORM+")");
  set_long("The softly glowing amulet is a vibrant blue in color. It seems\n"+
    "to radiate with power. You can use this to communicate with Jara\n"+
    "with the commands: jtell <msg>  or  jtelle <emote>\n");
  set_weight(0);
  set_value(0);
}

drop() {
  write("You may not drop this amulet.\n");
  return 1;
}
init() {
  ::init();
  add_action("cmd_jtell","jtell");
  add_action("cmd_jtell","jtelle");
}
cmd_jtell(string str) {
  string out;
  object ob;
  ob=find_player("jara");
  if(!str || !ob) {
    write("Jara is "+(ob?"here.\n":"not within this realm.\n"));
    return 1;
  }
  else {
    if(query_verb() == "jtell") {
      write(format(HIC+"You tell Jara:"+NORM+" "+str+"\n"));
      out=format("(jtell) "+this_player()->query_name()+": "+str);
      out=HIW+"("+HIC+"jtell"+HIW+")"+NORM+extract(out,7);
      tell_object(ob,out);
      ob->add_tellhistory(out);
    } else {
      write(format(HIW+"("+HIC+"jtell"+HIW+")"+NORM+" "+this_player()->query_name()+" "+str+"\n"));
      out=format("(jtell) "+this_player()->query_name()+" "+str);
      out=HIW+"("+HIC+"jtell"+HIW+")"+NORM+extract(out,7);
      tell_object(ob,out);
      ob->add_tellhistory(out);
    }
  return 1;
  }
}
