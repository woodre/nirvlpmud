#include "../DEFS.h"

status main(string str) {
  int amount;
  if(!IPTP) {
    tell_object(TP, "You are not a "+FUNKYNAME+".\n");
    return 1; 
  }
  if(!str || !sscanf(str, "%d", amount)) {
    tell_object(TP, "Usage: exchange <amount>.\n");
    return 1; 
  }
  call_other(GLEVELD, "exchange_exp", TP, amount);
  return 1;
}