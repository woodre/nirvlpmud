id(str) { return str == "mortis"; }

file(str) { if(!str) return;
            if(rm(str)) return 1;
              else return -1; } 
            

