#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
int spent;
 id(str) { return str == "wishing well" || str == "well" ||
          str == "well"; }
short() { return HIY+ "A Wishing Well" +NORM;}
 long() { write("A Wishing Well.  To see what you might wish\n"+
               "for and cost, type <list>.  To wish for an item type\n"+
               "buy <item name>\n");
        }
  get() { return 0; }  /* This makes it so that people can not pick it up*/
 init() {
   add_action("llist","list");   /*list action , reason why the function
                                   is llist is because other things might
                                   list */
   add_action("bbuy","buy");
    add_action("check_spent","checkspent");
}

check_spent() {
  if(this_player()->query_level() < 40) return 0;
  write("Spent: "+spent+"\n");
  return 1; }

 llist() {
  write("Things you may wish for and how much the wish costs.\n\n"+
       "To make your wish, type 'buy' <item name>\n\n"+
        "         pretty paddle      100 coins\n"+
        "         ugly stick         100 coins\n"+
        "         lemonade          1800 coins\n"+
        "         honeycomb         1800 coins\n"+
        "         ale               1800 coins\n");
  return 1;}
  bbuy(str) {
object item;
int value, m, heavey;
m = 0;     /* here m is 0..  notice at end of file there is a if(m) {}
              this means if m = 1 then do whatever...  in this case if
              m is still 0 then the write("That can not be bought here.\n")
              line will be activated */
  if(!str) return 0;
  if(str == "pretty paddle") {
    item = clone_object("/players/arrina/treas/paddle.c");
    value = 100;
    m = 1;      /* here m has now been set to 1 this means that the player can
                   now purchase the item..  i.e. if you set it up so
                   that for each item m = 1 then the code will allow the
                   purchase */
  }
  if(str == "ugly stick") {
    item = clone_object("/players/arrina/treas/stick.c");
    value = 100;
    m = 1;
  }
  if(str == "ale") {
    item = clone_object("/players/arrina/heals/ale.c");
    value = 1800;
    m = 1;
  }
  if(str == "lemonade") {
    item = clone_object("/players/arrina/heals/ade.c");
    value = 1800;
    m = 1;
  }
  if(str == "honeycomb") {
    item = clone_object("/players/arrina/heals/honeyc.c");
    value = 1800;
    m = 1;
  }
  if(m) {
  if(this_player()->query_money() < value) {
    write("You do not have enough to pay for that item!\n");
  return 1;}
  heavey = item->query_weight();
   if(!this_player()->add_weight(heavey)) {
    write("You can not carry anymore items.\n");
    return 1; }
   this_player()->add_money(-value);    /*take the money from player*/
  spent += value;
  move_object(item,this_player());
  write("You wished for the "+str+".\n");
  say(capitalize(this_player()->query_real_name())+" buys the "+str+
  " from the well.\n"); }
  else { write("That is a futile wish.... the well doesn't have that.\n"); }
return 1; }

query_spent() { return spent; }
