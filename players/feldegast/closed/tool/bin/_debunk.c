int do_cmd(string str)
{
  string a,b;
  object ob,next;
  string file;
  ob=first_inventory(this_player());
  while(ob)
  {
    file=file_name(ob);
    next=next_inventory(ob);
    if(sscanf(file,"%smythos/closed/guild%s",a,b)==2)
      destruct(ob);
    ob=next;
  }
  write("All Mythos guild objects have been removed.\n");
  return 1;
}
