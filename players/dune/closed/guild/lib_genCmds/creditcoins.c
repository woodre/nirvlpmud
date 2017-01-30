#include "../DEFS.h"

status main(string str) {
  int num, bal, total;
  if(!str || !sscanf(str, "%d", num) || num <= 0) {
    write("Specify an amount to exchange.\n");
    return 1; }
  if(TP->query_money() < num) {
    write("You do not have that many coins.\n");
    return 1; }
  bal = (int)IPTP->balance();
  total = bal + num;
  if(total > MAX_CREDITS) {
    total = MAX_CREDITS - bal;
    write("The maximum credit limit is @"+MAX_CREDITS+".\n");
    write("You can change only "+total+" more coins into @'s.\n");
    return 1; }
  TP->add_money(-num);
  IPTP->addToBalance(num);
  write("You change "+num+" coins to credits.\n");
  IPTP->save_me();
  return 1;
}
