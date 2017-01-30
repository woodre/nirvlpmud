/*  List of Bank Deposits - Dragnar 10/22/99 */

#define PATH "players/dragnar/items/bank/Deposits"
#define LOG "/players/dragnar/logs/BankDeposits"
#define MAX 499 /* Limited Array Size */

string *names;
int *amount;

void reset(int arg) {
  if(arg) return;

  if(!restore_object(PATH)) {
    names = ({ });
    amount = ({ });
    save_object(PATH);
  }
}

Insert(string name, int amt) {
  int index;

  restore_object(PATH);

  name = lower_case(name);
  index = member_array(name, names);
  if(sizeof(names) > MAX) {
    write_file(LOG, ctime(time())+" Deposit Index is Full!.\n");
    return;
  }
  if( index > -1 ) {
    amount[index] += amt;
    SortList();
    return;
  }
  else {
    names += ({ name });
    amount += ({ amt });
    SortList();
  }
}

void SortList() {
  int pass, hold, i;
  string hold2;

  for( pass = 0; pass < sizeof(amount)-1; pass++ ) {
    for( i = 0; i < sizeof(amount)-1; i++ ) {

      if( amount[i] < amount[i+1] ) {
        hold = amount[i];
        hold2 = names[i];
        amount[i] = amount[i+1];
        names[i] = names[i+1];
        amount[i+1] = hold;
        names[i+1] = hold2;
      }
    }
  }
  save_object(PATH);
}

ResetList() {
  names=({});
  amount=({});
  save_object(PATH);
}

string list() {
  string str, tempstr;
  int i;

  str = "";
  for(i=0; i<sizeof(names) && i < 15; i++ ) {
    tempstr = i+1+".";
    str += pad(tempstr,4) + capitalize(pad(names[i],16)) + amount[i] + "\n";
  }
  return str;
}
