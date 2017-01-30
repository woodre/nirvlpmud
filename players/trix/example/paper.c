reset(arg) {
        if(arg) return;
}

 long() {
           write("A sheet of paper on which is written some interisting info about Trix-71\n"+
                 "automatic shotgun.\n");
           return 1;
        }

 short() {
        return "Trix-71 shotgun info paper";
        }

id(str) {
        if( str == "paper" ) return 1;
        return 0;
}

init() {
        add_action( "read" , "read");

        return 1;
       }
read(arg)
  {  if (arg=="paper") 
      { write("[Trix]: Here is some information about my shotgun , It can be bought at the\n"+
              "        entrance of my castle (north or the church , enter castle) from a\n"+
              "        weapon vending machine :\n");
        cat("/players/trix/helpdir/guninfo");
        return 1;
      }
     else { return 0; }
  }
get() {
        return 1;
}

drop() {
        return 0;

}
