cmd_mwho(){
     int i;
     string state;
     object *list;

     i=0;
     list=filter_array(users(), "filter_list", this_object());
     write(" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\
^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^\n");
     write("   who           Inv/PK/NT         where\n");
     write(" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\
^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^\n");
     while(i<sizeof(list)){
          state = "";
          write(pad(i+1,3));
          write(pad(list[i]->query_real_name(),14));
          if(list[i]->query_invis()){
             state += "I/";
          } else { state += " /"; }
          if(list[i]->query_pl_k() || list[i]->query_fight_area()){
             state += "PK/";
          } else { state += "  /"; }
          if(environment(list[i])->query_realm()=="NT") state += "NT";
          write(pad(state,9));
          write(pad(environment(list[i])->query_short(),15));
          write("\n");
          i++;
     }
     write(" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\
^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^\n");
     return 1;
}
int filter_list(object who){
     if(!environment(who)){ return 0; }
     if(this_player()->query_level()<who->query_invis()) return 0;
     return 1;
}


