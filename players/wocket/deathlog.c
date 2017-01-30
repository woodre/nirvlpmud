
if(!is_npc){
   if(environment(this_object())->query_spar_area())
      log_file("DEATHS","Spar->");
   if(attacker_ob){
      if(attacker_ob->is_player() && query_ip_number(attacker_ob) && attacker_ob != this_object()){
         if(environment(this_object())->query_spar_area())
            log_file("PK","Spar->");
         log_file("PK", ctime(time())+" "+name+" "+experience+" exp "+money+" gold : killed by "+
            attacker_ob->query_real_name()+" | "+alt_attacker_ob->query_real_name()+".\n");
      }
      log_file("DEATHS",ctime(time())+" "+name+" "+experience+" exp "+money+" gold killed by "+
         attacker_ob->query_real_name()+".\n");
   }
   log_file("DEATHS", ctime(time()) + "  " + name + " " + experience + " exp "+money + " gold - killer unknown.\n");
   if(this_player()){ 
      log_file("DEATHS","this_player is "+this_player()->query_real_name()+"   "+this_player()->query_name()+"\n");
   }
}
