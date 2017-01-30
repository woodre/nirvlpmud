reset(arg) {
        if(arg) return;
}

 long() {
           write("A sheet of paper on which is written how to reach Trix's area and what's in it,\n"+
                 "type 'read leaflet' to look at it.\n");
           return 1;
        }

 short() {
        return "TRIX REALM NEWS leaflet";
        }

id(str) {
        if( str == "leaflet" ) return 1;
        return 0;
}

init() {
        add_action( "read" , "read");

        return 1;
       }
read(arg)
  {  if (arg=="leaflet") 
        {  write("                         Trix's Realm\n" +
                "To reach it from the church just go north,enter castle,portal.\n" +
                "There are monsters for every level :\n"+
                "The southern part has got low level monsters for newbies and low-medium level\n" +
                "players,while in the northern part there are monsters for medium and high level\n"+
                "players.\n" +
                "IMPORTANT, I OPENED A NEW AREA, FOR MEDIUM-HIGH LEVEL PLAYERS, A REAL KICK*SS\n"+
                "AREA, I THINK , WITH GOOD MONSTERS AND HEALS VENDING MACHINE.\n"+
                "[once entered the castle is south] , GO THERE U WON'T BE DISAPPOINTED.\n"+
      " 400.000 experience points to get !!!! C'mon !!!!\n");
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
