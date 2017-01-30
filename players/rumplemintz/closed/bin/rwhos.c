string sort_list(string *who){
   int j, i, sorted;
   object tmp;
   sorted = 0;
   while(!sorted){
      sorted = 1;
      j--;
      for(i=0; i<j; i++)
      if(who[i]->query_level() < who[i+1]->query_level()){
         tmp = who[i];
         who[i] = who[i+1];
         who[i+1] = tmp;
         sorted = 0;
         }
   }
   return who;
}

int rwhos(){

