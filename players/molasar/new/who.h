
/*
 * filter_short() - Makes short desc look nicer
 */

#define SHORT_LEN 65

who() {
   object list;
   int i, lvl;
   string sh;

   list = users();
   write("[===========================================================]\n");
   for(i=0; i < sizeof(list); i++) {
     sh = list[i]->short();
     if(strlen(sh) > SHORT_LEN + 10)
       filter_short(sh);
     else
       write(sh+"\n");
   }
   write("[===========================================================]\n"); 
   return 1;
}

filter_short(str) {
   string tmp_str, tmp_str2;
   int total_len, i;

   total_len = strlen(str);
   for(i=0; i < (total_len - SHORT_LEN); i++) {
      if(str[SHORT_LEN+i] == ' ')
        break;
      if(i > 9)
        break;
   }
   tmp_str = str[0..(SHORT_LEN+i)];   
   tmp_str2 = str[(SHORT_LEN+i+1)..total_len];
   if(strlen(tmp_str2) > SHORT_LEN + 10)
     tmp_str2 = tmp_str2[0..(SHORT_LEN+10)];
   write(tmp_str+"\n");
   write("  ");
   write(tmp_str2+"\n");
}
