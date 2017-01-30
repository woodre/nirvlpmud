short() { return "A MUD scanner"; }
long()  { write("A scanner that can detect certain aspects common among all players.\n");
          write("Use 'scan query_<command>'\n");
          return 1;
}
id(str) { return str == "scanner" || str == "mud scanner"; }
get()   { return 1; }
drop()  { destruct(this_object()); return 0; }
init()  { add_action("uscan", "uscan");      }
uscan(str) {
        int i;
        object usr;
        usr = users();
        write("Asked: "+str+"\n");
        for(i = 0; i < sizeof(usr); i++) {
                write(usr[i]->query_name()+"\t\t: "+call_other(usr[i], str)+"\n");                
        }
        write("Done.\n");
        return 1;
}
