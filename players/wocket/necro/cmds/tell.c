#include "../defs.h"

cmd(str){
   string *word_a,msg;
   object ob;
   if(str){
      word_a = explode(str," ");
      if(word_a[0] == "-old"){
         word_a -= word_a[0];
         msg = implode(word_a," ");
         if(tp->tell(msg)){
            return 1;
         }
         return 0;
      }
   }
   if(CONVERTMSG_D->convert_tell(str,BOLD+BLK))
      return 1;
}
