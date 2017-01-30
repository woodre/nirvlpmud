settitle2() {
   string title;
   string rank;
   if(TP->query_guild_rank() >= 11){
   title = HIK+"of the "+HIW+">"+HIR+"A"+HIW+"."+HIR+"o"+HIW+"."+HIR+"P"+HIW+"<"+NORM;
   rank = present("destroyer_ob", TP)->query_grank();
   }
   else if(TP->query_guild_rank() == 10){
   title = HIK+"of the "+HIW+">"+HIR+"A"+HIW+"."+HIR+"o"+HIW+"."+HIR+"P"+HIW+"<"+NORM;
   rank = "Colonel";
   }
   else if(TP->query_guild_rank() == 9){
   title = HIK+"of the "+HIW+">"+HIR+"A"+HIW+"."+HIR+"o"+HIW+"."+HIR+"P"+HIW+"<"+NORM;
   rank = "Major";
   }
   else if(TP->query_guild_rank() == 8){
   title = HIK+"of the "+HIW+">"+HIR+"A"+HIW+"."+HIR+"o"+HIW+"."+HIR+"P"+HIW+"<"+NORM;
   rank = "Captain";
   }
   else if(TP->query_guild_rank() == 7){
   title = HIK+"of the "+HIW+">"+HIR+"A"+HIW+"."+HIR+"o"+HIW+"."+HIR+"P"+HIW+"<"+NORM;
   rank = "1st Lieutenant";
   } 
   else if(TP->query_guild_rank() == 6){
   title = GRN+"of the "+HIW+">"+HIR+"A"+HIW+"."+HIR+"o"+HIW+"."+HIR+"P"+HIW+"<"+NORM;       
   rank = "2nd Lieutenant";
   }
   else if(TP->query_guild_rank() == 5){
   title = GRN+"of the "+HIW+">"+HIR+"A"+HIW+"."+HIR+"o"+HIW+"."+HIR+"P"+HIW+"<"+NORM;
   rank = "Sgt Major";
   }
   else if(TP->query_guild_rank() == 4){
   title = GRN+"of the "+HIW+">"+HIR+"A"+HIW+"."+HIR+"o"+HIW+"."+HIR+"P"+HIW+"<"+NORM;
   rank = "Master Sgt";
   }
   else if(TP->query_guild_rank() == 3){
   title = GRN+"of the "+HIW+">"+HIR+"A"+HIW+"."+HIR+"o"+HIW+"."+HIR+"P"+HIW+"<"+NORM;
   rank = "Sergeant";
   }
   else if(TP->query_guild_rank() == 2){
   title = GRN+"of the "+HIW+">"+HIR+"A"+HIW+"."+HIR+"o"+HIW+"."+HIR+"P"+HIW+"<"+NORM;
   rank = "Corporal";
   }
   else{ 
   title = GRN+"of the "+HIW+">"+HIR+"A"+HIW+"."+HIR+"o"+HIW+"."+HIR+"P"+HIW+"<"+NORM;
   rank = "Private";
   }
   TP->set_title(title);
   TP->set_pretitle(rank);
   present("destroyer_ob", TP)->set_grank(rank);
   write("Title set.\n");
   return 1;
}
