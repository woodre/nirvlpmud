
get(){ return 1; }
string file;
object ob;
id(str){ return str == "logger"; }

short(){ return "Logger"; }

init(){ 
   add_action("log", "log");
}

log(str){
    if(str != "off"){
       file = str;
     ob = clone_object("players/deathmonger/closed/listen");
     move_object(ob, this_player());
     ob->set_logfile(file);
     write("Log on.\n");
     return 1;
    }
   if(str == "off"){
      destruct(ob);
      write("Log off.\n");
      return 1;
    }
}
