/*
 *  Mwho.h
 *  Mob Misc Ability
 */

mwho_cmd(string str){         /*  also used in mob and fam  */
     int i;
     string state, room, area, owner, junk;
     object *list;

     i=0;
     list=filter_array(users(), "filter_invis", this_object());
     if(!str) str == "";

     switch(str){
           case "fam":{ list=filter_array(list, "filter_mob", this_object());
                        list=filter_array(list, "filter_fam", this_object());
                        break;}
           case "mob":{ list=filter_array(list, "filter_mob", this_object());
                        break;}
           default: break;
     }
     write(" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\
^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^\n");
     write("   who           Inv/PK/NT         where\n");
     write(" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\
^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^\n");
     while(i<sizeof(list)){
          state = "";
          write(pad(i+1,3));
          write(pad(capitalize(list[i]->query_real_name()),14));
          if(list[i]->query_invis()){
             state += "I/";
          } else { state += " /"; }
          if(list[i]->query_pl_k() || list[i]->query_fight_area()){
             state += "PK/";
          } else { state += "  /"; }
          if(environment(list[i])->query_realm()=="NT") state += "NT";
          write(pad(state,9));
          if(environment(list[i])) {
             if(list[i]->query_level() > 19) room = "A Higher Plane";
             else {
                room = object_name(environment(list[i]));
                sscanf(room,"%s/%s/%s",area,owner,junk);
                if (area=="room")  room = "Downtown Nirvana";
                else  room = capitalize(owner)+"'s Realm";
             }
          }
          else room = "Lost in Space";
          write(room);
          write("\n");
          i++;
     }
     write(" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\
^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^\n");
     return 1;
}
