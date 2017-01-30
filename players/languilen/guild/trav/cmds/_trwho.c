cmd_trwho(){
     int i;
     string state;
     object *list;

     i=0;
     list=filter_array(users(), "filter_list", this_object());
     write(" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\
^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^\n");
     write("   who           state         where\n");
     write(" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\
^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^\n");
     while(i<sizeof(list)){
          state = "";
          write(pad(i+1,3));
          write(pad(list[i]->query_real_name(),14));
          if(list[i]->query_invis()){ state += "I"+list[i]->query_invis(); }
          if(list[i]->in_edit()) state += "E";
          if(!list[i]->query_interactive()) state += "d";
          write(pad(state,8));
          write("\n");
          i++;
     }
     write(" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\
^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^\n");
     return 1;
}
int filter_list(object who){
     if(this_player()->query_level()<who->query_invis()) return 0;
     return 1;
}

