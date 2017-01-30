#include "../../define.h"
#define PATH "/players/vertebraker/castle/new/"
inherit ITEM;

reset(x) {
if(x) return;
set_id("pin");
set_alias("silver pin");
set_short("A silver pin");
set_long(
"A thin silver pin that was beautifully crafted.  A small bit\n"+
"of brown mud has stained the three-inch beauty.  Tiny markings\n"+
"on the head indicate this was the property of one 'T.S.'.\n");
set_weight(0); /* it's a very small pin */
set_value(100+random(30)); }
