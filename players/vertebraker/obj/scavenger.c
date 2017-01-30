#include <ansi.h>
inherit "/obj/treasure";

string *files;
string *shorts;
int *found;
int loaded;

reset(arg){
  if(arg) return;
  shorts=files=found=allocate(25);
  set_id("scavenger list");
  set_alias("list");
  set_short("A scavenger list");
  set_long("\
Type \"find <item>\" if you find something on your list.\n\n\
You can \"read\" your scavenger list.\n");
}

drop() {
  return 1;
}

init() {
 if(!environment()) return;
 if(!loaded) { loaded = 1;
    restore_me();
  }
  add_action("cmd_find", "find");
  add_action("cmd_read", "read");
}

cmd_find(str){
  int x;
  object ob;
  string sh;
  if(!str) return 0;
  ob = present(str, this_player());
  if(!ob) return 0;
  sh = (string)ob->query_short();
  if(!sh) sh=(string)ob->short();
  if((x=member_array(sh,shorts)) == -1) {
    write("That's not on your list!\n");
    return 1;
  }
  if(files[x] != basename(ob)) {
    string cname;
    write("Sorry, that's not the correct item.\n");
    if(sscanf(files[x],"players/%s/",cname)) {
    write("That item can be found in "+capitalize(cname)+"'s castle.\n");
   }
   else {
    write("That item is in an unknown castle.\n");
   }
   return 1;
  }
  if(found[x]) {
    write("You already found that item.\n");
  return 1;
  }
  write("You found "+sh+"!\n");
  found[x]=1;
  save_me();
  return 1;
}

cmd_read(string str){
  int x, y;
  if(!str) return 0;
  if(!id(str)) return 0;

  y = sizeof(shorts);
  write("\n\t\t\tSCAVENGER LIST\n\n");
  for(x=0;x<y;x++){
    if(found[x]) { write(" "+HIG+"*"+NORM); }
   else write("  ");
    write(shorts[x]+"\n");
  }
  write("\n");
  write(HIG+"*"+NORM+" indicates a found item.\n");
  write("\n");
  return 1;
}

query_auto_load() {
  return "/players/vertebraker/obj/scavenger:0";
}

save_me() {
  save_object("players/vertebraker/obj/scavenger/"+this_player()->query_real_name());
}

restore_me()
{
  restore_object("players/vertebraker/obj/scavenger/"+this_player()->query_real_name());
}

load_data() {
  string *shs; string *fs;
  mixed *sfs;
  sfs=(mixed*)"/players/vertebraker/dev/scav_proc"->get_data();
 shs=sfs[0];
  fs=sfs[1];
  files=fs;
  shorts=shs;
  save_me();
}
