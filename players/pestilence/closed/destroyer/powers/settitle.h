settitle() {
   string title;
   string rank;
   if(TP->query_guild_rank() >= 11){
   title = HIR+">"+HIK+"General"+HIR+"< "+HIK+"of the "+HIW+">"+HIR+"A"+HIW+"."+HIR+"o"+HIW+"."+HIR+"P"+HIW+"<"+NORM;
   rank = "General";
   }
   if(TP->query_guild_rank() == 10){
   title = HIR+">"+HIK+"Colonel"+HIR+"< "+HIK+" of the "+HIW+">"+HIR+"A"+HIW+"."+HIR+"o"+HIW+"."+HIR+"P"+HIW+"<"+NORM;
   rank = "Colonel";
   }
   else if(TP->query_guild_rank() == 9){
   title = HIW+">"+HIR+"Major"+HIW+"< "+HIK+" of the "+HIW+">"+HIR+"A"+HIW+"."+HIR+"o"+HIW+"."+HIR+"P"+HIW+"<"+NORM;
   rank = "Major";
   }
   else if(TP->query_guild_rank() == 8){
   title = HIR+">"+HIK+"Captain"+HIR+"<"+HIK+" of the "+HIW+">"+HIR+"A"+HIW+"."+HIR+"o"+HIW+"."+HIR+"P"+HIW+"<"+NORM;
   rank = "Captain";
   }
   else if(TP->query_guild_rank() == 7){
   title = HIK+">"+HIR+"1st Lieutenant"+HIK+"<"+HIG+" of the "+HIW+">"+HIR+"A"+HIW+"."+HIR+"o"+HIW+"."+HIR+"P"+HIW+"<"+NORM;
   rank = "1st lieutenant";
   } 
   else if(TP->query_guild_rank() == 6){
   title = HIB+"2nd Lieutenant "+HIK+"of the "+HIW+">"+HIR+"A"+HIW+"."+HIR+"o"+HIW+"."+HIR+"P"+HIW+"<"+NORM;       
   rank = "2nd lieutenant";
   }
   else if(TP->query_guild_rank() == 5){
   title = GRN+"Ser"+YEL+"gea"+GRN+"nt M"+YEL+"ajo"+GRN+"r of"+YEL+" the "+HIW+">"+HIR+"A"+HIW+"."+HIR+"o"+HIW+"."+HIR+"P"+HIW+"<"+NORM;
   rank = "sgt major";
   }
   else if(TP->query_guild_rank() == 4){
   title = GRN+"Mas"+YEL+"ter"+GRN+" Ser"+YEL+"gea"+GRN+"nt o"+YEL+"f the "+HIW+">"+HIR+"A"+HIW+"."+HIR+"o"+HIW+"."+HIR+"P"+HIW+"<"+NORM;
   rank = "master sgt";
   }
   else if(TP->query_guild_rank() == 3){
   title = GRN+"Ser"+YEL+"gea"+GRN+"nt"+YEL+" of "+GRN+"the "+HIW+">"+HIR+"A"+HIW+"."+HIR+"o"+HIW+"."+HIR+"P"+HIW+"<"+NORM;
   rank = "sergeant";
   }
   else if(TP->query_guild_rank() == 2){
   title = GRN+"Cor"+YEL+"por"+GRN+"al"+YEL+" of"+GRN+" the "+HIW+">"+HIR+"A"+HIW+"."+HIR+"o"+HIW+"."+HIR+"P"+HIW+"<"+NORM;
   rank = "corporal";
   }
   else{ 
   title = GRN+"low"+YEL+"ly P"+GRN+"riv"+YEL+"ate "+GRN+"of the "+HIW+">"+HIR+"A"+HIW+"."+HIR+"o"+HIW+"."+HIR+"P"+HIW+"<"+NORM;
   rank = "private";
   }
   TP->set_title(title);
   present("destroyer_ob", TP)->set_grank(rank);
   write("Title set.\n");
   return 1;
}
