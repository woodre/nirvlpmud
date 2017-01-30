#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);
add_property("no_fight");
add_property("no_magic");
short_desc = "Food Hut";
long_desc =
        "  A small, rounded straw hut which smells of sweet fruits.  The\n"+
        "walls are lined with shelves full of oddly shaped foods and tools\n"+
        "for farming.  At the end of the hut there is a small counter with\n"+
        "a decorative vase.\n";

items = ({
  "hut","A small hut made of straw",
  "foods","Random shaped foods of unknown origin",
  "tools","These look like variations of farming tools",
  "shelves","Long wooden shelves held against the wall with vines",
  "vines","Thin grey vines hold up the shelves",
  "counter","A short counter made of knotty pine",
  "vase","The vase has a small sign on it you might want to look at",
"sign","\t\t"+HIC+"("+HIW+"For Sale"+HIC+")\n\n"+
HIW+"\t."+HIB+"["+NORM+" CaoCao Fruit : 400  coins"+HIB+"]"+HIW+".\n"+
HIW+"\t."+HIB+"["+NORM+" Teenom Fruit : 400  coins"+HIB+"]"+HIW+".\n"+
HIW+"\t."+HIB+"["+NORM+" Roht Fruit   : 1200 coins"+HIB+"]"+HIW+".\n"+
HIW+"\t."+HIB+"["+NORM+" Kool Fruit   : 1800 coins"+HIB+"]"+HIW+".\n"+
HIW+"\t."+HIB+"["+NORM+" Lychee Fruit : 1800 coins"+HIB+"]"+HIW+".\n"+
HIW+"\t."+HIB+"["+NORM+" Ahqwa Fruit  : 1800 coins"+HIB+"]"+HIW+".\n"+
HIW+"\t."+HIB+"["+NORM+" Junju Fruit  : 1800 coins"+HIB+"]"+HIW+".\n"+
HIW+"\t."+HIB+"["+NORM+" Amplee Fruit : 2700 coins"+HIB+"]"+NORM+"",
});
MOCO("/players/jaraxle/3rd/warrior/mon/carin.c"),TO);
dest_dir = ({
  "/players/jaraxle/3rd/warrior/rooms/treee.c","out",
});

}

query_no_fight() {return 1;}

/* added read and list to help players out -Vital 04/10/2005 */
init()
{
  ::init();
  add_action("read_me","read");
  add_action("list_me","list");
}

list_me()
{
  write("\
\t\t"+HIC+"("+HIW+"For Sale"+HIC+")\n\n"+
HIW+"\t."+HIB+"["+NORM+" CaoCao Fruit : 400  coins"+HIB+"]"+HIW+".\n"+
HIW+"\t."+HIB+"["+NORM+" Teenom Fruit : 400  coins"+HIB+"]"+HIW+".\n"+
HIW+"\t."+HIB+"["+NORM+" Roht Fruit   : 1200 coins"+HIB+"]"+HIW+".\n"+
HIW+"\t."+HIB+"["+NORM+" Kool Fruit   : 1800 coins"+HIB+"]"+HIW+".\n"+
HIW+"\t."+HIB+"["+NORM+" Lychee Fruit : 1800 coins"+HIB+"]"+HIW+".\n"+
HIW+"\t."+HIB+"["+NORM+" Ahqwa Fruit  : 1800 coins"+HIB+"]"+HIW+".\n"+
HIW+"\t."+HIB+"["+NORM+" Junju Fruit  : 1800 coins"+HIB+"]"+HIW+".\n"+
HIW+"\t."+HIB+"["+NORM+" Amplee Fruit : 2700 coins"+HIB+"]"+NORM+".\n");
  return 1;
}

read_me(str)
{
  if (!str || str != "sign")
  {
    notify_fail("What are you trying to read?\n");
    return 0;
  }
  write(
"\t\t"+HIC+"("+HIW+"For Sale"+HIC+")\n\n"+
HIW+"\t."+HIB+"["+NORM+" CaoCao Fruit : 400  coins"+HIB+"]"+HIW+".\n"+
HIW+"\t."+HIB+"["+NORM+" Teenom Fruit : 400  coins"+HIB+"]"+HIW+".\n"+
HIW+"\t."+HIB+"["+NORM+" Roht Fruit   : 1200 coins"+HIB+"]"+HIW+".\n"+
HIW+"\t."+HIB+"["+NORM+" Kool Fruit   : 1800 coins"+HIB+"]"+HIW+".\n"+
HIW+"\t."+HIB+"["+NORM+" Lychee Fruit : 1800 coins"+HIB+"]"+HIW+".\n"+
HIW+"\t."+HIB+"["+NORM+" Ahqwa Fruit  : 1800 coins"+HIB+"]"+HIW+".\n"+
HIW+"\t."+HIB+"["+NORM+" Junju Fruit  : 1800 coins"+HIB+"]"+HIW+".\n"+
HIW+"\t."+HIB+"["+NORM+" Amplee Fruit : 2700 coins"+HIB+"]"+NORM+".\n");
  return 1;
}

