/* This takes care of the help listings for the guild. */

geo_help(str){ 
   if(!str){ 
      cat("/players/jaraxle/closed/guild/help/Geo_Help.h");
      return 1; }
   
   if(str){
      if(file_size("/players/jaraxle/closed/guild/help/"+str+".c") < 1){
         write("There is no help on that topic.\n");
         return 1; }
      
      cat("/players/jaraxle/closed/guild/help/"+str+".c");
      return 1; }
}
