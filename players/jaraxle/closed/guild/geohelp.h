/* This takes care of the help listings for the guild. */

geo_help(str){ 
   if(!str){ 
write("Topics available for geo_help are:\n\n");
      list_powers(); return 1; } 

if(str){
   cat("/players/jaraxle/closed/guild/help/"+str+".c");
   return 1; }
}
