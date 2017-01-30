#include "../def.h"

#define SAVEFILE (SAVE_DAEM+"shop")

int    *quantities;
int    *prices;
string *items;

void reset(status x)
{
 if(x) return;
 quantities = prices = items = ({ });
 restore_object(SAVEFILE);
}

status list_item(string item, int price, int qty)
{
 int x;
 if((x = member(items, item)) > -1)
 {
  prices[x]      = price;
  quantities[x] += qty;
  save_object(SAVEFILE);
  return 1;
 }
 else
 {
  items      += ({item});
  prices     += ({price});
  quantities += ({qty});
  save_object(SAVEFILE);
  return 0;
 }
}
