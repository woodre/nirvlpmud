id(str) { return str == "object"; }
init() {

   add_action("random_number","number");

}

random_number() {
   int n, i;
   i=0;
   while( i < 20 ) {
      write(i +" " + random(3)+ "\n");
      i+=1;
   }
   return 1;
}
