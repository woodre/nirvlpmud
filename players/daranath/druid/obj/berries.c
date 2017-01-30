#include <ansi.h>

inherit "obj/treasure";

int a;
string color;

reset(arg) {
  if(arg) return;

a = random(5);
a = random(5);
if(a == 0) {color = HIC; }
if(a == 1) {color = HIR; }
if(a == 2) {color = HIM; }
if(a == 3) {color = HIB; }
if(a == 4) {color = HIG; }

set_id("berries");
set_alias("bunch");
set_short("A bunch of "+color+"berries"+NORM);
set_long("A small bunch of colorful berries, they seem to be in perfect\n"+
         "condition, perhaps to be used somehow.\n");
set_weight(1);
set_value(5+random(10));
}

query_druid_comp() {return 1; }
