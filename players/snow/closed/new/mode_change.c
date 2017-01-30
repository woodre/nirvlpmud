#include "../DEFS.h"

status main(string str) {
  object boo;
  if(!str) {
    write("Usage: mode <none/attack/defense>\n");
    write("Current mode: "+BOLD);
    if((int)IPTP->query_attack_mode() == 0) write("NONE");
    if((int)IPTP->query_attack_mode() == 1) write("ATTACK");
    if((int)IPTP->query_attack_mode() == 2) write("DEFENSE");
    write(OFF+"\n");
    return 1; 
  }
  if(str == "none") {
    IPTP->set_attack_mode(0);
    write(BOLD+"Attack mode set to: NONE"+OFF+"\n");
    return 1;
  }
  if(str == "attack") {
    IPTP->set_attack_mode(1);
    write(BOLD+"You set your attack mode to: ATTACK"+OFF+"\n");
    return 1;
  }
  if(str == "defense") {
    IPTP->set_attack_mode(2);
    write(BOLD+"Attack mode set to: DEFENSE"+OFF+"\n");
    return 1;
  }
  write("You have chosen an invalid attack mode.\n");
  return 1;
}
