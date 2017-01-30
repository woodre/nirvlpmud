#include "defs.h"
#define CLOTHES "/players/feldegast/std/clothes.c"

inherit ROOM;

string *desc;
string *name;
int *value;
mixed *type;

void add_item(string d, string n, int v, string *t) {
  desc+=({ d });
  name+=({ n });
  value+=({ v });
  type+=({ t });
}

void reset(int arg) {
  if(!present("tailor"))
    move_object(clone_object(MON_PATH+"tailor.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc="Tailor Shop";
  long_desc=
    "  This is a neat little tailor's shop, filled with row upon row of\n"+
    "fashionable and not-so-fashionable clothing.  Near the back of the\n"+
    "shop is a counter where the clerk can tally up purchases.  On the\n"+
    "left wall from the entrance are three mirrors placed at angles to\n"+
    "each other so that shoppers can see themselves from all angles.\n"+
    "Commands: buy, list\n";
  items=({
    "counter","A simple wooden counter",
    "mirrors","You make little googly faces at yourself in the mirrors",
    "clothing","Type 'list' to see a list of all of the clothing",
  });
  dest_dir=({
    PATH+"smerch.c","out",
  });
  desc=({ }); name=({ }); value=({ }); type=({ });
  add_item("a warm coat","coat",250,({ "coat" }));
  add_item("a black leather jacket","jacket",250,({ "coat" }));
  add_item("a pair of blue jeans","jeans",100,({ "pants" }));
  add_item("a pair of blue trousers","trousers",120,({ "pants" }));
  add_item("a pair of brown pants","pants",100,({ "pants" }));
  add_item("a white t-shirt","shirt",50,({ "shirt" }));
  add_item("a green polo shirt","shirt",75,({ "shirt" }));
  add_item("a blue business suit","suit",700,({ "shirt","pants" }));
  add_item("a black tuxedo","tuxedo",800,({ "shirt","pants" }));
  add_item("a red tie","tie",150,({ "tie" }));
  add_item("a bow tie","tie",150,({ "tie" }));
  add_item("a pair of boxers","boxers",50,({ "underwear" }));

  add_item("a white doublet","doublet",80,({ "shirt" }));
  add_item("a pair of leather buckskins","buckskins",120,({ "pants" }));
  add_item("a furry vest","vest",80,({ "vest" }));
  add_item("a red kilt","kilt",100,({ "pants" }));
  add_item("a worn out looking brown robe", "robe", 80, ({ "coat" }));

  add_item("a fuzzy coat","coat",180,({ "coat" }));
  add_item("a white blouse","blouse",60,({ "shirt" }));
  add_item("a black leather skirt","skirt",120,({ "pants" }));
  add_item("a summer dress","dress",200,({ "shirt" }));
  add_item("a black gown","gown",300,({ "shirt", "pants" }));
  add_item("a red gown","gown",300,({ "shirt", "pants" }));
  add_item("a pair of black leather pants","pants",250,({ "pants" }));
  add_item("a pair of cotton panties","panties",50,({ "underwear" }));
  add_item("a lacy white bra","bra",60,({ "bra" }));
  add_item("a lacy black bra","bra",60,({ "bra" }));
  add_item("a pair of lacy lingerie","lingerie",100,({ "underwear" }));
  add_item("a black garter belt","belt",75,({ "garters" }));
  add_item("a white wedding dress","dress",1000,({ "shirt","pants","coat" }));

  add_item("a red scarf","scarf",60,({ "scarf" }));

  /* 03/13/06 Earwax: added, at player request, a belt.  heh. */
  add_item("a black leather belt", "belt", 50, ({ "belt" }));
}

void init() {
  ::init();
  add_action("cmd_list","list");
  add_action("cmd_buy","buy");
}

int cmd_list(string str) {
  int i;
  if(!present("tailor")) return 0;
  for(i=0; i < sizeof(desc); i++) {
    write(pad((i+1)+". ",4));
    write(pad(desc[i],40));
    write(value[i]);
    write("\n");
  }
  return 1;
}

int cmd_buy(string str) {
  object clothes;
  int i;
  if(!present("tailor")) return 0;
  if(!str) {
    notify_fail("Buy what?\n");
    return 0;
  }
  if(sscanf(str,"%d",i)==1) {
    i--;
    if(i < 0 || i > sizeof(desc)) {
      notify_fail("That item is not available.\n");
      return 0;
    }
  }
  else {
    i=member_array(str,name);
    if(i == -1) {
      notify_fail("That item is not available.\n");
      return 0;
    }
  }
  clothes=present("clothing_object",this_player());
  if(!clothes) {
    clothes=clone_object(CLOTHES);
    move_object(clothes,this_player());
  }
  if((int)this_player()->query_money() < value[i]) {
    write("You do not have enough money to buy "+desc[i]+".\n");
    return 1;
  }
  if(clothes->test_type(type[i]))
     return 1;
  clothes->add_item(desc[i],name[i],value[i],type[i]);
  this_player()->add_money(-value[i]);
  write("You wear "+desc[i]+".\n");
  say(TPN+" purchases "+desc[i]+".\n");
  return 1;
}
