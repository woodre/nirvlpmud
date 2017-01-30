/*
 *  A Bard Speedster
 *  v3.0 by Saber / Geoffrey Z.
 *
 */
 
static string COMMAND;
static int v;

flight(str)  {
string F1, F2, F3, F4, F5;
int n;


  F1 = F2 = F3 = F4 = F5 = "";
  
  if(!str) {
     write("Syntax: fly < direction > < direction > < etc >\n"); 
     return 1;
       }

  if(!INSTR->query_know_spell("storm_fly"))  {
    write("You have not yet learned the words of flight.\n");
    return 1;
      }

  if(sscanf(str, "%s,%s,%s,%s,%s", F1, F2, F3, F4, F5) == 5) {
    COMMAND = ({F1,F2,F3,F4,F5});
    fly();
    return 1;
       }
    
  if(sscanf(str, "%s,%s,%s,%s", F1, F2, F3, F4) == 4) {
    COMMAND = ({F1,F2,F3,F4});
    fly();
    return 1;
       }
    
  if(sscanf(str, "%s,%s,%s", F1, F2, F3) == 3) {
    COMMAND = ({F1,F2,F3});
    fly();
    return 1;
       }
       
  if(sscanf(str, "%s,%s", F1, F2) == 2) {
    COMMAND = ({F1,F2});
    fly();
    return 1;
       }
       
  if(sscanf(str, "%s", F1) == 1) {
    COMMAND = ({F1});
    fly();
    return 1;
       }

    return 1;
       }


fly() {

  write("\nYou fly up into the air.\n");
  say(tp+" flies up into the air.\n");
  
  for(v=0; v<sizeof(COMMAND); v++) {
    
  if((COMMAND[v]) != "n"  && 
     (COMMAND[v]) != "e"  && 
     (COMMAND[v]) != "s"  && 
     (COMMAND[v]) != "w"  &&
     (COMMAND[v]) != "u"  && 
     (COMMAND[v]) != "d"  && 
     (COMMAND[v]) != "ne" && 
     (COMMAND[v]) != "nw" &&
     (COMMAND[v]) != "se" && 
     (COMMAND[v]) != "sw" && 
     (COMMAND[v]) != "") {

      write("You can not fly "+COMMAND[v]+". Flight ended.\n");
      return 1;
        }
    
    command(COMMAND[v],TP);
        }
    
    write("\nYou land.\n");
    return 1;
        }

