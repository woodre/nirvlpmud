cmd_trav(str){
     int i;
     string msg;
     object *list;

     if(!str){
        write("  ------ Traveler's on channel ------  \n");
     }
     i=0;
     list=filter_array(users(), "filter_list", this_object());
     while(i<sizeof(list)){
          if(str) {
             msg = str;
             if(msg[0] == ':'){
                msg = msg[1..strlen(msg)];
                if(!msg){ return 1; }
                msg = "[Trav] "+this_player()->query_name()+" "+msg+"\n";
                tell_object(list[i],msg);
             } else {
                msg = "[Trav] "+this_player()->query_name()+" sends: "+msg+"\n";
                tell_object(list[i], msg);
             }
          } else tell_object( this_player(), capitalize(list[i]->query_name())+".\n");
          i++;
     }
     return 1;
}
int filter_list(object who){
     if( !present("TRAV_OB", who) ) return 0;
     if( present("TRAV_OB", who)->query_muffle() ) return 0;
     return 1;
}

