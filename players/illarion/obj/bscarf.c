/* send a wiz a tell object */
inherit "obj/treasure";
#include "/players/illarion/dfns.h"

string *scarf_hist;
int hist_index;

object owner;

reset(arg) {
  if(arg) return;

  scarf_hist=allocate(10);
  
  set_id("scarf");
  set_alias("itell");
  set_short("A dark black scarf");
  set_long("A black, but fuzzy scarf.  It can be used to speak with\n"+
           "Illarion even if he is invisible or busy, or simply\n"+
           "to check if he is on, with the command: "+BLD("itell(e)")+".\n");
  set_value(0);
  set_weight(0);
}
drop() {
  if(query_verb()=="drop")
    write("You can't drop the scarf.\n");
  else if(query_verb()=="quit") {
    write("Your scarf dissolves into smoke and blows away.\n");
    destruct(this_object());
    return 0;
  }
  return 1;
}
id(str) { return ::id(str) || str == "illarion_scarf_object"; }
set_owner(ob) { if(!TP || TPRN!="illarion") return; owner=ob; }
init() {
  if(environment() && (!owner || owner !=environment())) return destruct(this_object());
  ::init();
  add_action("cmd_itell","itell");
  add_action("cmd_itell","itelle");
  add_action("cmd_show_hist","ihist");
}
cmd_itell(string str) {
  string out;
  object ob;
  object ring;
  ob=find_player("illarion");
  if(!str || !ob) {
    write("Illarion is "+(ob?"here.\n":"not here.....\n"));
    return 1;
  }
  else {
    if(query_verb() == "itell") {
      write(format("You itell Illarion: "+str+"\n"));
      out=format("(itell) "+TPN+": "+str);
      out=HIY+"(itell)"+NORM+extract(out,7);
    } else {
      write(format("(itell) "+TPN+" "+str+"\n"));
      out=format("(itell) "+TPN+" "+str);
      out=HIY+"(itell)"+NORM+extract(out,7);
    }
    ring = present("illarion_dring",ob);
    tell_object(ob,out);
    if(ring) ring->add_ring_hist(out);
    else ob->add_tellhistory(out);
    add_scarf_hist(out);
    ob->Replyer(TPRN);
  return 1;
  }
}

add_scarf_hist(str) {
  scarf_hist[hist_index++] = "["+ctime()[11..15]+"]"+str;
  if(hist_index >9) hist_index=0;
}

cmd_show_hist() {
  int x;
  if(!this_player()) return 0;
  if(this_player()->query_real_name() != "illarion" && this_player() != owner) {
    if(environment())
      tell_object(environment(),this_player()->query_real_name()+" tried to read the scarf's history.\n");
    write("I don't think so.\n");
  }
  for(x=hist_index; x<10; x++)
    if(scarf_hist[x]) write(scarf_hist[x]);
  for(x=0; x< hist_index; x++)
    if(scarf_hist[x]) write(scarf_hist[x]);
  return 1;
}

query_auto_load() {
  return "/players/illarion/obj/bscarf:";
}
