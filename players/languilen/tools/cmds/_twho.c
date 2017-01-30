cmd_twho(){
     int i;
     string state;
     object *list;

     i=sizeof(list=users());
     write(" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\
^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^\n");
     write("   who           state         where\n");
     write(" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\
^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^\n");
     while(i--){
          state = "";
          write(pad(i+1,3));
          write(pad(list[i]->query_real_name(),14));
          if(list[i]->query_invis()){ state += "I"+list[i]->query_invis(); }
          if(list[i]->in_edit()) state += "E";
          if(!list[i]->query_interactive()) state += "d";
          write(pad(state,8));
          write("\n");
     }
     write(" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\
^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^\n");
     return 1;
}

