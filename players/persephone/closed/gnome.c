
id(str){ return str == "gnome"; }
get(){ return 1; }
drop() { return 1; }

query_auto_load() { 
          return ("players/bastion/closed/gnome:"); 
}

init(){
     add_action("hey","hey");
}


hey(){
     object ob;
      int i;
     ob = users();
     for(i=0;i<sizeof(ob);i++){
     if(ob[i]->query_level() >= 40){
       if(ob[i]->query_invis()){
      write(ob[i]->query_real_name()+" (invis)    "+file_name(environment(ob[i]))+
      "\n");
       }
      else
       write(ob[i]->query_real_name()+"   "+file_name(environment(ob[i]))+"\n");
     }
}
return 1;
}
