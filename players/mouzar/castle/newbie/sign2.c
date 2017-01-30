 
 
id(str) {return str == "sign";}
short() { return "A sign";}
long() {write("Nice little sign that you should read.\n"); return 1;}
 
init() {
        add_action("read","read");
        }
  
  read(str) {
          if((!str) || !id(str)) {
               return 0;
                }      
          write("To the west is the small Halfling village of Lindendale.\n"+
                "         Everyone is welcome to the village!!\n");
            return 1;
            }
 
