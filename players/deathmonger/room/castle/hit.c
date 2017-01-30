

inherit "/players/deathmonger/wanted";
id(str){ return str == "hitter"; }
short(){ return "Hit requestor"; }

init(){
   add_action("add", "add");
   add_action("remove", "delete");
   add_action("display_wanted_list", "display");
}

add(str){
    int ret;
   ret = add_wanted_list(str);
   if(ret == -1) write("No such player exists.\n");
   write(ret+"\n");
   write("You add "+str+" to the hitlist.\n");
   return 1;
}

remove(str){
    int ret;
   ret = remove_wanted_list(str);
   write(ret+"\n");
   write("You delete "+str+" from the hitlist.\n");
   return 1;
}


