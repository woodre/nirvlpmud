/* Guild speedster */
#include "../DEFS.h"
#define CAN_DO ({ "n","s","e","w","ne","nw","se","sw","u","d" })


void ncom(string str) {
  if( (member_array(str, CAN_DO) == -1) && 
      !(TRN == OWNER1 || TRN == OWNER2)) {
    write("You cannot ~~SPEED~~ ["+str+"]\n");
    return;
  }
  command(str, TP);
}

status main(string str) {
  string c1, c2, c3, c4, c5;            
  string complete;
  if(!str) { write("Where would you like to go?\n"); return 1; }
  complete = BOLD+"~ ~ ~ SPEED  ENDED ~ ~ ~"+OFF+"\n";
   write(BOLD+"~ ~ ~ NINJA SPEED MODE ~ ~ ~\n\n"+OFF);
  if(sscanf(str,"%s,%s,%s,%s,%s", c1, c2, c3, c4, c5) == 5) {
    ncom(c1); ncom(c2); ncom(c3); ncom(c4); ncom(c5);
  write(complete);
    return 1; }
  if(sscanf(str, "%s,%s,%s,%s", c1, c2, c3, c4) == 4) {
    ncom(c1); ncom(c2); ncom(c3); ncom(c4);              
  write(complete);
    return 1; }
  if(sscanf(str, "%s,%s,%s", c1, c2, c3) == 3) {
    ncom(c1); ncom(c2); ncom(c3); 
  write(complete);
    return 1; }
  if(sscanf(str,"%s,%s", c1, c2) == 2) {
    ncom(c1); ncom(c2);
  write(complete);
    return 1; }
  if(sscanf(str, "%s", c1) == 1) {
    command(c1, TP);
  write(complete);
    return 1; }
  return 1;
}
