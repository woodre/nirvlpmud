/*                                                                              *
 *      File:             /players/angel/area/walmart/room/bakery.c             *
 *      Function:         room                                                  *
 *      Author(s):        Angel@Nirvana                                         *
 *      Copyright:        Copyright (c) 2006 Angel (Josh Hatfield)              *
 *                                All Rights Reserved.                          *
 *      Source:           11/15/06                                              *
 *      Notes:                                                                  *
 *                                                                              *
 *                                                                              *
 *      Change History:                                                         *
 */

#include <ansi.h>

inherit "room/room";

int x;

reset(arg)
{
  ::reset(arg);
  if( !present("doughnut", this_object()) )
  {
    for(x=0; x<2; x++)
    {
    move_object(clone_object("/players/angel/area/walmart/npc/doughnut.c"), this_object());
    }
}
if(arg) return;
  set_light(1);
  short_desc = HIY+"Bakery Isle"+NORM;
  long_desc =
"   "+HIY+"Bakery"+NORM+"\n\
  Visit the Bakery Shoppe at your local Wal-Mart and discover\n\
incredible Everyday Low Prices on fresh, taste tempting bakery\n\
items like beautifully decorated cakes, REAL whipped cream\n\
dessert's,fresh fruit tarts and more. We also offer fresh scratch\n\
made doughnuts daily, fresh bread and rolls, mouth watering muffins\n\
and authentic New York style bagels. Don't forget to look for our\n\
Specialty Dessert's made with REAL Whipped Cream!\n";

  items =
  ({
    "bakery",
    "This is a place where products such as bread, cake, and pastries\n\
are baked or sold",
    "shoppe",
    "This is a small specialty department in a large store",
    "walmart",
    "Wal-Mart is a large retailer bent on overtaking the world!",
    "cakes",
    "We carry a large variety of cakes. They are sweet baked food items,\n\
made of flour, liquid, eggs, and other ingredients, such as raising agents\n\
and flavorings",
    "desserts",
    "We carry a large variety of desserts. They are the sweet course\n\
or dish, as of fruit, ice cream, or pastry, served at the end of a meal",
    "fruit tarts",
    " We carry a large variety of fruit tarts. Fruit Tarts are a\n\
combination of a sweet pastry crust, filled with pastry cream,\n\
and decorated with glazed fruit",
    "whipped cream",
    "We carry a large variety of whipped cream. whipped cream is\n\
a topping for dessert and pies",
    "bread",
    "We carry a large variety of bread. A staple food made from\n\
flour or meal mixed with other dry and liquid ingredients",
    "rolls",
    "We carry a large variety of rolls.A staple food made from\n\
flour or meal mixed with other dry and liquid ingredients ",
    "bagels",
    "We carry a large variety of bagels. A glazed, ring-shaped\n\
roll with a tough, chewy texture, made from plain yeast dough\n\
that is dropped briefly into nearly boiling water and then baked",
    "muffins",
    "We carry a large variety of muffins. They are small, cup-shaped\n\
quick made bread, often sweetened",
    "doughnut",
    "A small ring-shaped cake made of rich, light dough that\n\
is fried in deep fat",

  });
  dest_dir =
  ({
    "/players/angel/area/walmart/room/foods", "foods",	
  });
}
realm(){ return "NT"; }