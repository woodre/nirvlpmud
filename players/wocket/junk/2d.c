mixed *sorted;


id(string str) {

   return str == "test" || str == "2d";
}


init() {
   add_action("data","data");
      
}
reset(arg){
  int i;
    if(arg) return;
   sorted = allocate(2);
  for(i=0; i<sizeof(sorted); i++) {
      sorted[i] = ({ i,"test" });
  }
}


data() {
   int i;
   int j;

   for( i = 0; i < sizeof(sorted); i++ ) {
     for(j=0; j<sizeof(sorted[i]); j++) {
       write("i: "+i+" j: "+j+" data: "+sorted[i][j]+".\n");
     }
   }
   write("\n");
   return 1;
}

get() { return 1; }
drop() { return 1; }
query_weight() { return 0; }
query_value() { return 0; }

