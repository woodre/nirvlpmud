add_action("Who","gwho");
Who(){
   object list;
   int kill,i,level,invis;
   string name,killer,tab,ed,guild,loc;
   list = users();
   write("Name"+"\t\t"+"Level"+"\t"+"Edit"+"\t"+"Killer"+"\t"+"Guild\t"+"Location\n");
   write("<<------------------------------------------------------------------------>>\n");
   for(i = 0; i<sizeof(list); i++){
      name = capitalize(list[i]->query_real_name());
      if(environment(list[i])){
         if(environment(list[i])->short()){
            loc = environment(list[i])->short();
         }
       }
      else{
         loc = "Unknown";
       }
      level = list[i]->query_level();
      invis = list[i]->query_invis();
      kill = list[i]->query_pl_k();
      ed = "  ";
      guild = "None ";

      if(in_editor(list[i])){ed = "ed";}
      if(present("thief guild",list[i])){guild = "Thief";}
      if(present("fangs",list[i])){guild = "Vamps";}
      if(present("robes",list[i])){guild = "Cler.";}
      if(present("books",list[i])){guild = "Necro";}
      if(present("license",list[i])){guild = "Ass. ";}
      if(present("seal",list[i])){guild = "Mason";}
      if(present("penta",list[i])){guild = "Alche";}
      if(present("badge",list[i])){guild = "Doppl";}
      if(present("mages_guild_object",list[i])){guild = "Mages";}
      if(kill == 0){killer = "-";}
      if(kill == 1){killer = "k";}
      if(invis == 18){
         if(this_player()->query_level() > level -1){
            tab = "\t\t";
            if(strlen(name) > 7){tab = "\t";}
            write(name+tab+level+"\t"+ed+"\t"+killer+"\t"+guild+"\t"+loc+"\n");
         }
       }
      if(invis == 0){
         tab = "\t\t";
         if(strlen(name) > 7){tab = "\t";}
         write(name+tab+level+"\t"+ed+"\t"+killer+"\t"+guild+"\t"+loc+"\n");
       }
   }
   return 1;
}


