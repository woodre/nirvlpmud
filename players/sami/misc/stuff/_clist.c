#include "/players/mokri/define.h"

main() {
   
   string *files;
   int x;
   
   files = get_dir("/players/sami/misc/stuff/");
   
   write("Commands\n========\n");
   
   for(x = 0; x < sizeof(files); x++) {
      
      if(extract(files[x],0,0) == "_") {
         write(extract(files[x],1,strlen(files[x])-3)+"\n");
       }
      
   }
   
}
