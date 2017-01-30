#include <ansi.h>

inherit "room/room";

int x;

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = HIC+"Front Aisle"+NORM;
  long_desc =
"  Welcome to your local "+HIB+"Wal-Mart Supercenter."+NORM+" Over the past four\n\
decades, we have grown from a small chain to a global enterprise\n\
with 5,000 stores in 15 countries. Voted 'most admired retailer'\n\
by Fortune magazine, our company is rooted in ethical values:\n\
We work hard, embrace change, and always try to do better. Enjoy\n\
shopping at your local Nirvana Wal-Mart Supercenter!\n";

  items =
  ({
    "walmart",
    "Wal-Mart is a large retailer bent on overtaking the world!",
    "decade",
    "A period of ten years",
    "chain",
    "A number of establishments, such as stores, theaters, or\n\
hotels, under common ownership or management",
    "enterprise",
    "An industrious business organization with systematic activity,\n\
especially when directed toward profit",
    "stores",
    "A place where merchandise is offered for sale",
    "countries",
    "The territory of a nation or state, land",
    "retailer",
    "A retailer sales goods or commodities in small quantities\n\
directly to consumers",
    "magazine",
    "A periodical containing a collection of articles, stories,\n\
pictures, or other features",
    "values",
    "Wal-mart has three basic beliefs. They are Respect the Individual,\n\
Service to the Customer, and Strive for Excellence",

  });
  dest_dir =
  ({
    "/players/angel/area/walmart/room/foods",             "foods",
    "/players/angel/area/walmart/room/hardlines",         "hardlines",
    "/players/angel/area/walmart/room/softlines",         "softlines",
    "/players/angel/area/walmart/room/walmart_checkout",  "checkout",
  });
}