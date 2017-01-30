#include "/players/dreamspeakr/closed/ansi.h"
inherit "/obj/treasure";

reset(arg) {
   if(arg) return;
   set_id("sign");
   set_long("\n"+
           HIG+"~"+HIY+"*"+HIG+"~-_-~"+HIY+"*"+HIG+"~-_-~"+HIY+"*"+HIG+"~-_-~"+HIY+"*"+HIG+"~-_-~"+HIY+"*"+HIG+"~-_-~"+HIY+"*"+HIG+"~-_-~"+HIY+"*"+HIG+"~-_-~"+HIY+"*"+HIG+"~-_-~"+HIY+"*"+HIG+"~-_-~"+HIY+"*"+HIG+"~-_-~"+HIY+"*"+HIG+"~\n"+
           HIG+"~"+HIY+"*"+HIG+"~                     "+HIY+"W E L C O M E                       "+HIG+"~"+HIY+"*"+HIG+"~\n"+
           HIG+"~"+HIY+"*"+HIG+"~                          "+HIW+"to                             "+HIG+"~"+HIY+"*"+HIG+"~\n"+
           HIG+"~"+HIY+"*"+HIG+"~             "+HIG+"Mark of the Gods Tattoo Studio              "+HIG+"~"+HIY+"*"+HIG+"~\n"+
           HIG+"~"+HIY+"*"+HIG+"~                                                         "+HIG+"~"+HIY+"*"+HIG+"~\n"+
           HIG+"~"+HIY+"*"+HIG+"~  "+HIW+"Where you can buy a tattoo that you will never forget! "+HIG+"~"+HIY+"*"+HIG+"~\n"+
           HIG+"~"+HIY+"*"+HIG+"~     "+HIW+"Impress those around you with your obvious sence    "+HIG+"~"+HIY+"*"+HIG+"~\n"+
           HIG+"~"+HIY+"*"+HIG+"~                       "+HIW+"of style.                         "+HIG+"~"+HIY+"*"+HIG+"~\n"+
           HIG+"~"+HIY+"*"+HIG+"~    "+HIW+"Having a tattoo created by the Gods can give you     "+HIG+"~"+HIY+"*"+HIG+"~\n"+
           HIG+"~"+HIY+"*"+HIG+"~              "+HIW+" the "+HIG+"temporary"+HIW+" vision of                   "+HIG+"~"+HIY+"*"+HIG+"~\n"+ 
           HIG+"~"+HIY+"*"+HIG+"~   "+HIW+"being "+HIG+"stronger, "+HIW+"more "+HIG+"magical"+HIW+", or even more "+HIG+"carasmic   "+HIG+"~"+HIY+"*"+HIG+"~\n"+
           HIG+"~"+HIY+"*"+HIG+"~           "+HIW+"Why not 'order' yourself one now!             "+HIG+"~"+HIY+"*"+HIG+"~\n"+
           HIG+"~"+HIY+"*"+HIG+"~   "+HIW+"Only 10,000 coins to be the talk of the heavens!      "+HIG+"~"+HIY+"*"+HIG+"~\n"+
           HIG+"~"+HIY+"*"+HIG+"~      "+HIW+"To purchase your very own custom tattoo            "+HIG+"~"+HIY+"*"+HIG+"~\n"+
           HIG+"~"+HIY+"*"+HIG+"~               "+HIW+"type:  "+HIG+"'order tattoo'.                    "+HIG+"~"+HIY+"*"+HIG+"~\n"+
           HIG+"~"+HIY+"*"+HIG+"~                                                         "+HIG+"~"+HIY+"*"+HIG+"~\n"+
           HIG+"~"+HIY+"*"+HIG+"~-_-~"+HIY+"*"+HIG+"~-_-~"+HIY+"*"+HIG+"~-_-~"+HIY+"*"+HIG+"~-_-~"+HIY+"*"+HIG+"~-_-~"+HIY+"*"+HIG+"~-_-~"+HIY+"*"+HIG+"~-_-~"+HIY+"*"+HIG+"~-_-~"+HIY+"*"+HIG+"~-_-~"+HIY+"*"+HIG+"~-_-~"+HIY+"*"+HIG+"~"+NORM+"\n"+
           "\n");

   set_value(0);
   set_weight(100);
}


get() { return 0; }

