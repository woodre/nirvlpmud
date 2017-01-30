settitle() {
   string title;
   if(TP->query_guild_rank() >= 9){
title = RED+"Destroyer of Everything"+WHT+" Good"+NORM;
   }
   else if(TP->query_guild_rank() >= 8){
   title = HIK+"Evil Lord of "+NORM+""+RED+"Destruction "+HIW+"<"+HIK+"DARKNESS"+HIW+">"+NORM;
   }
   else if(TP->query_guild_rank() == 7){
   title = HIK+"Dark lord of "+HIR+"<"+HIK+"DARKNESS"+HIR+">"+NORM;
   } 
   else if(TP->query_guild_rank() == 6){
   title = HIB+"Destroyer of light "+HIR+"<"+HIK+"DARKNESS"+HIR+">"+NORM;	
   }
   else if(TP->query_guild_rank() == 5){
   title = HIG+"Devastator of all that's Decent"+NORM;
   }
   else if(TP->query_guild_rank() == 4){
   title = HIK+"Darkness "+HIR+"<"+HIK+"Incarnate"+HIR+">"+NORM;
   }
   else if(TP->query_guild_rank() == 3){
   title = BOLD+"the wielder of "+HIK+"darkness"+NORM;
   }
   else if(TP->query_guild_rank() == 2){
   title = BLU+"aspiring weaver of the Dark"+NORM;
   }
   else{
   title = HIK+"initiate of Darkness"+NORM;
   }
   TP->set_title(title);
   write("Title set.\n");
   return 1;
}
