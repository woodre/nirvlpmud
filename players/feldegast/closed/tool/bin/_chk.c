string password;
string name;
int no_give;

int do_cmd(string str) {
  name=0;
  if(!str) { write("Usage: fin <name>\n"); return 1;}
  if(!restore_object("pfiles/"+extract(str,0,0)+"/"+lower_case(str))) {  
     if(restore_object("players/inactive_saved/"+lower_case(str))) {
       write("------------INACTIVE------------INACTIVE------------\n");
      write("-----Reactivation possible after:"+
            ctime(no_give+1296000)+"\n");
       write("----------------------------------------------------\n");
    }
    if(restore_object("banish/"+lower_case(str)))
      write("------------BANISHED------------BANISHED------------\n");
  }
  if(!name) {
    write("No such player exists.\n");
    return 1;
  }
   write(name+"\t");
  write(password+"\n");
  return 1;
}
