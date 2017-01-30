#include "/players/pain/color.h"
pt(str){
   int x;
   object patch;
   object ob;
   string who;
   if(!str) {
      write("You must specify a message\n");
      return 1;
   }
   sscanf(str,"%s %s",who,str);
   ob = users();
   for(x=0; x<sizeof(ob);x+=1){
      if(present("star_tattoo", ob[x])){
         patch = present( "star_tattoo", ob[x]);
         if(patch->query_muff() == 0 && patch->query_color() == 0){
            tell_object(ob[x],YELLOW+"~*~"+END+BOLD+who+
               END+YELLOW+"~*~:"+END+" "+str+"\n");
         }
         if(patch->query_muff() == 0 && patch->query_color() == 1){
            tell_object(ob[x], "~*~"+who+"~*~: "+str+"\n");
         }
       }
   }
   return 1;
}
