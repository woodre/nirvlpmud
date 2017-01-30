#include <ansi.h>

room_inv(str) {
  string blah;
  object room;
  if(!str) room = environment(this_player());
  else {
    if(str[0] != '/') str = this_player()->get_path()+str;
    if(!sscanf(str, "%s.c", blah)) str += ".c";
    if(!(room = find_object(str))) call_other(str, "??");
    if(!(room = find_object(str))) {
      write("Error finding room.\n");
      return 1;
    }
  }
  return display_inventory(room);
}
inv(str) {
  object who;
  if(!str) who = this_player();
  else if(!(who = find_player(str))) {
    write("Player "+capitalize(str)+" not found.\n");
    return 1;
  }
  return display_inventory(who);
}
display_inventory(what) {
  object ob, nob;
  string sh;
  if(!what) return 0; /* just in case */
  ob = first_inventory(what);
  write("Inventory of "+what->short()+":\n");
  if(!ob) {
    write("No items found.\n");
    return 1;
  }
  while(ob) {
    nob = next_inventory(ob);
    write("  ["+file_name(ob)+"]: ");
    sh = ob->short();
    if(sh) write(sh+"\n");
    else write("--INVISIBLE--\n");
    ob = nob;
  }
  write("Done.\n");
  return 1;
}
