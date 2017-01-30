lswho() {
   object p;
   int x;
   p = users();
   x = 0;
   write("Lsong listeners:\n");
   for(;x<sizeof(p);x++) {
      if(present("lsong",p[x])) {
         write(p[x]->query_real_name()+", ");
      }
   }
   write("\n\n");
   return 1;
}
