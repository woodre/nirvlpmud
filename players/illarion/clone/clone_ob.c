#include "/players/illarion/dfns.h"
#define CLONE_ID "illarion_clone_cylinders"
#define SAVE "players/illarion/clone/clone_data"

string *customers;
mixed  *customer_data;

reset() {
  if(!customers)
    restore_object(SAVE);
  if(!customers)
    customers=({});
  if(!customer_data)
    customer_data=({});
}

status check_customer(string customer_name) {
  int ind;
  ind=member_array(customer_name,customers);
  if(ind==-1) return 0;
  return customer_data[ind];
}

status add_customer(string customer_name, mixed data) {
  customers+=({customer_name});
  customer_data+=({data});
  save_object(SAVE);
}

status remove_customer(string customer_name) {
  int ind;
  int siz;
  ind=member_array(customer_name,customer_data);
  if(ind==-1) return 0;
  siz=sizeof(customer_data);
  customers=(ind==0?({}):customers[0..ind-1])
    +(ind==siz-1?({}):customers[ind+1..siz]);
  customer_data=(ind==0?({}):customer_data[0..ind-1])
    +(ind==siz-1?({}):customer_data[ind+1..siz]);
  save_object(SAVE);
  return 1;
}
