#include "../def.h"

inherit G_ROOM;

void reset(status x)
{
 ::reset(x);
 if(x) return;
 set_light(1);
 open = 1;
 if(!restore_object(SAVE_ROOM+"shop"))
 {
  set_short("Shop of the "+GUILDNAME);
  set_long("\
 Plush red carpeting rolls gently across the soft cedar\n\
floor and leads up to a short wooden counter.  Behind\n\
the counter are short glass display cases.  In the store-\n\
room, you can see both unopened and opened wooden crates\n\
of various sizes and shapes.\n");
 set_items(({
  "carpeting", "Plush red carpeting that feels so soft",
  "floor", "A lightly tinged cedar wood was chosen \
to complete the floor",
  "cases", "Various items can be seen.\nTo see a \
complete list, type 'list'",
  "storeroom", "Crates are stacked up in the corner",
  "crates", "Dozens of crates of varying heights and widths",
 }));
 }
 if(!present("shop sign"))
  MO(CO(DIR_OBJ+"shop_sign"), TO);
}

void init()
{
 ::init();
 add_action("cmd_list", "list");
 add_action("cmd_buy",  "buy");
 add_action("cmd_sell", "sell");
}

status cmd_list(string str)
{
 string *items;
 int    *qty;
 int    *prices;
 int    i, s;
 string x;

 items=(string*)SHOPDAEM->query_items();
 qty=(int*)SHOPDAEM->query_quantities();
 prices=(int*)SHOPDAEM->query_prices();

 s = sizeof(items);

 write("\n\tItems for Sale:\n\n");

 for(i=0;i<s;i++)
 {
  x = pad(""+(i+1), 2);
  write(" ["+x+"]: "+pad(items[i],20,46)+" "+pad(""+qty[i],20,46)+
   " "+prices[i]+"\n");
 }

 return 1;
}
