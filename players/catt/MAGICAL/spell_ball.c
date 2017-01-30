   id(str) { return str == "orb"; }
   get() { return 0; }
   short() { return "Small Floating Orb"; }
   long() {
      write("A small orb floating about 5 feet in the air. It shifts color \n"+
            "constantly and seems to be full of magical energy.\n");
      return 1;
   }
   reset(arg) { if(arg) return; }

   pulse() {
      if(p == 0) {
         
