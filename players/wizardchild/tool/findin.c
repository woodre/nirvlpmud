/* finds a function in someone's inventory */
/* using function_exists(str, ob)          */
findin(str) {
  string wh,fn;
  object who, ob;
  if(sscanf(str, "%s %s", wh, fn) < 2) {
    write("Usage: findin <who> <function>\n");
    return 1;
  }
  if(!(who = find_player(wh))) {
    write("No such player.\n");
    return 1;
  }
  ob = first_inventory(who);
  while(ob) {
    if(function_exists(fn, ob)) 
      write(" ["+file_name(ob)+"] "+ob->short()+"\n");
    ob = next_inventory(ob);
  }
  return 1;
}
