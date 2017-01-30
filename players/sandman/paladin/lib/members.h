

#define PATH "/players/sandman/paladin/members/"

members() {
   int i, tmp;
   status trunc_flag;
   string *dir, *paladins;
    
   trunc_flag = 0;
   dir = get_dir(PATH);
   if(sizeof(dir) > 100)  {
     dir = dir[0..100];
     trunc_flag = 1;
   }
   paladins = ({ });
write("Players which have Paladin guild files:\n");
write("[================================================================]\n");
   for(i=0; i < sizeof(dir); i++) {
      string name;
      name = dir[i];
      sscanf(name, "%s.o", name);
      name = capitalize(name);
      paladins += ({ name });
   }
   tmp = 0;
   for(i=0; i < sizeof(paladins); i++) {
      write(justify(paladins[i],15));
      tmp++;
      if(tmp == 4) {
        write("\n");
        tmp = 0;
      } else
        write(justify("",3));
   }
   if(tmp)
     write("\n");
   if(trunc_flag) 
     write("***TRUNCATED***\n");      
write("[================================================================]\n");   
   return 1;
}
