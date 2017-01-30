/*                                                                            *
 *      File:             /players/angel/rewards/seller.c                     *
 *      Function:         seller                                              *
 *      Author(s):        Angel@Nirvana                                       *
 *      Copyright:        Copyright (c) 2007 Angel                            *
 *                                All Rights Reserved.                        *
 *      Source:           07/20/07                                            *
 *      Notes:                                                                *
 *                                                                            *
 *                                                                            *
 *      Change History:                                                       *
 */

#include "/sys/lib.h"

inherit "obj/treasure";
 
id(str) {
  return str == "portable merchant" || str == "merchant";
}
 
reset(arg)
{
   set_value(0);
   set_weight(0);
   set_short("Portable Merchant");
   set_long("The Portable Merchant.\nYou can sell your items to the store with the 'sell' command.\n");
   return 1;
}
 
init()
{
   ::init();
   if(environment(this_object())!=this_player()) return 1;
   if((this_player()->query_name()=="Angel")
      || (this_player()->query_name()=="Angel")) {
     add_action("sell","sell");
   }
   else write("This tool is for Angel's use only.\n");
   return 1;
}

sell(item) {
    object ob;

    if (!item)
        return 0;
    if (item == "all") {
        object next;
        ob = first_inventory(this_player());
        while(ob) {
            next = next_inventory(ob);
            if (!ob->drop() && ob->query_value()) {
                write(ob->short() + ":\t");
                do_sell(ob);
            }
            ob = next;
        }
        write("Ok.\n");
        return 1;
    }
    ob = present(item, this_player());
    if (!ob)
        ob = present(item, this_object());
    if (!ob) {
        write("No such item ("); write(item); write(") here.\n");
        return 1;
    }
    do_sell(ob);
    return 1;
}

do_sell(ob) {
    int value, do_destroy;
    object stre;

    value = ob->query_value();
    if (!value) {
        write(ob->short() + " has no value.\n");
        return 1;
    }
    if (environment(ob) == this_player()) {
        int weight;
        if (call_other(ob, "drop", 0)) {
            write("I can't take it from you!\n");
            return 1;
        }
        weight = call_other(ob, "query_weight", 0);
        call_other(this_player(), "add_weight", - weight);
    }
    if ( value > 2000 || ob->query_sell_destruct())
        do_destroy = 1;
    write("You get "); write(value); write(" gold coins.\n");
    this_player()->add_money(value);
/*    add_worth(value, ob); */
write("The");
    if (do_destroy) {
        write(" valuable item is hidden away.\n");
        destruct(ob);
        return 1;
    }
write("c");
    stre=find_object("room/store");
    if(!stre) {
      write("ERROR!  Store is missing from game!\n");
      destruct(ob);
      return 1;
    }
    stre->store(ob);
    return 1;
}
 
drop() { return 1; }
 
query_auto_load() { return "/players/angel/rewards/seller.c:"; }
