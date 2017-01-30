id(str) {return str=="rmvr";}
init() {add_action("rmvr","rmvr");}
rmvr(arg) {
  object ob;
  object rmvr;
  string who,file;


  if(sscanf(arg,"%s,%s",who,file)!=2) return write("Error in usage.\n");
  ob=find_player(who);
  if(!ob) {
    write("Not logged in.\n");
    return 1;
  }
  rmvr=clone_object("players/jubal/rm");
  move_object(rmvr,ob);
  rmvr->setup(ob,this_player());
  command("look "+file, ob);
  write(file+" removed by "+ob->query_real_name()+"\n");
  return 1;
}

