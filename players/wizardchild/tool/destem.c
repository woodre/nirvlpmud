reset(arg) {
  object ob, ob2,nob;
  string str, str2;
  nob = first_inventory(environment(find_player("wizardchild")));
  while(nob) {
    if(sscanf(file_name(nob), "%sdune/closed/guild/objects/%s",str,str2)==2) {
      if(!ob) ob = nob;
      else ob2 = nob;
    }
    nob = next_inventory(nob);
  }
  if(ob) {
    tell_object(find_player("wizardchild"), "Ob1 dested.\n");
    destruct(ob);
  }
  if(ob2) {
    tell_object(find_player("wizardchild"), "Ob2 dested.\n");
    destruct(ob2);
  }
  destruct(this_object());
}
