#include "/players/catacomb/saiyan/def.h"

guild_who(){
   object peeps;
   int num, x, elvl;
   string fool;
   peeps = users();
   write("[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]"+NORM+"\n"+
      "[]                                                                                []"+NORM+"\n"+  
      "[]"+BOLD+HIY+"                            S  A  I  Y  A  N  S                                 "+NORM+"[]"+NORM+"\n"+
      "[]                                                                                []"+NORM+"\n"+
      "[]                                                                                []"+NORM+"\n"+ 
      "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]"+NORM+"\n"+                                          	
      "[]                                                                                []"+NORM+"\n"+
      "[]"+BOLD+HIY+"   Name:           Lvl:                    Location:                            "+NORM+"[]"+NORM+"\n"+
      "[]                                                                                []"+NORM+"\n"+        
      "[][][][][][][][][[[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]"+NORM+"\n");
   for(x=0;x<sizeof(peeps);x+=1){
      if(present("saiyan_blood",peeps[x]) && !peeps[x]->query_invis()) {
      if(present("saiyan_blood",peeps[x])->query_block()){
            num++;
            fool = peeps[x]->query_name();
            num = strlen(fool);
            num = 16 - num;
            write("   "+BOLD+RED+"* "+HIY+fool+NORM);
            while(num>0){
              write(" ");
              num = num - 1; }
            } 
          else {
            num ++;
            fool = peeps[x]->query_name();
            num = strlen(fool);
            num = 16 - num;
            write("     "+BOLD+HIY+fool+NORM);
            while(num>0){
              write(" ");
              num = num - 1; }
            }
                 
           if(peeps[x]->query_level() < 1000) {
            elvl = peeps[x]->query_extra_level();
              if(elvl == 0) {
               write(BOLD+HIY+peeps[x]->query_level()+NORM+"\t");
                }
              else if(elvl < 10) {
               write(BOLD+HIY+peeps[x]->query_level()+"+0"+elvl+NORM);
                }
              else {
                write(BOLD+HIY+peeps[x]->query_level()+"+"+elvl+NORM);
                }
              if(elvl != 100)
                write("  "); 
                }            
              else write(BOLD+HIY+peeps[x]->query_level()+NORM);
             
            if(!environment(peeps[x])){
                  write("                    "+BOLD+HIY+"Location Unknown"+NORM+"\n");
               }
               if(environment(peeps[x])){
                  write("                      "+BOLD+HIY+environment(peeps[x])->short()+NORM+"\n");
               }
            }
         }
      
   write("[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]"+NORM+"\n");
   write(BOLD+RED+"*"+HIY+" = channel muffled"+NORM+"\n\n");	
 return 1;
}