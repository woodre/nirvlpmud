/*
 *      File:                   coinbag.c
 *      Function:               treasure item
 *      Author(s):              Hogath@Nirvana
 *      Copyright:              Copyright (c) 2004 Hogath
 *                                      All Rights Reserved.
 *      Source:                 05/24/2004
 *      Notes:                  
 *      Change History:
 */

#include <ansi.h>
#include <security.h>
#include "/players/hogath/tools/def.h"

inherit "obj/treasure";
id(str){return (::id(str) || str == "Cash bag" || str == "cash bag" || str == "Coinbag" || str == "coinbag");} 
reset(arg){
  if(arg) return;
  set_id("purse");
  set_alias("Purse");
  set_short(YEL+"Coin purse"+NORM);
  set_long(YEL+"This is a small magical purse used to carry coins.\n"+
               "It looks like you can 'cash' it to get them out.\n"+NORM);
  set_weight(1);
  set_value(3000+random(1500));
  }


init(){
  ::init();
  add_action("cash_bag","cash");
}

cash_bag(){
      tell_room(environment(tp),
      "The purse disappears as you take "+value+" coins from it.\n");
      tp->add_money(value);
      tp->add_wieght(-1);
      destruct(to);
      return 1;
    }
