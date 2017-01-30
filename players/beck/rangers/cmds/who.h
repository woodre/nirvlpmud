add_active_ranger(str){
if(!member_array(str,active_rangers) !=-1){
active_rangers += ({ str }); }}
remove_active_ranger(str){ active_rangers -= ({ str }); }
ranger_who(){
   object list, ranger, active_ranger;
object active_ranger_com;
   int i,j;
   string where;
   list = users();
   write("\n");
   write("============================ THE POWER RANGERS ==============================\n");
   write("\n");
   write(justify("Lvl",4)+justify("M",2)+justify("Name",15)+justify("Color",9)+justify("Btl?",5)+justify("Place",45));
   write("\n");
   write("\n");
   for( i = 0; i<sizeof(list); i++) {
      where = 0;
      ranger = present("ranger_object", list[i]);
      if(!list[i]->query_invis()){
         if(ranger) {
            string name;
            int lvl;
            name = list[i]->query_name();
            lvl = list[i]->query_level();
            where = environment(list[i])->short();
            write(justify(lvl,4));
            if(ranger->query_muff()){ write(justify("*",2)); }
            if(!ranger->query_muff()){ write(justify(" ",2)); }  
            write(justify(name,15));
            write(justify(ranger->query_ranger_color(),9));
            write(justify(list[i]->query_attack() ? "Yes" : "No",5));
            write(justify(where,45));
            write("\n");
         }
       }
   }
   for( j = 0; j<sizeof(active_rangers); j++) {
      where = 0;
      if(find_living(active_rangers[j])){
         active_ranger = find_living(active_rangers[j]);
         active_ranger_com = present("ranger_object",active_ranger);      
write(justify("??",4));
if(active_ranger_com){
         if(active_ranger_com->query_muff()){ write(justify("*",2)); }
         if(!active_ranger_com->query_muff()){ write(justify(" ",2)); }  
}
else{
write(justify(" ",2));
}
         write(justify(active_ranger->query_name(),15));
if(active_ranger_com){
         write(justify(active_ranger_com->query_ranger_color(),9));
}
else{
write(justify("Enemy",9));
}
         write(justify(active_ranger->query_attack() ? "Yes" : "No",5));
         write(justify(environment(active_ranger)->short(),45));
         write("\n");
      }
   }
   write("\n");
   write("=============================================================================\n");
   return 1;
}
