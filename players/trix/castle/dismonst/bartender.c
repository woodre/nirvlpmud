inherit "obj/monster";
object who;
reset(arg){
   object gold,sblade;
   ::reset(arg);
   if(arg) return;
   set_name("tom");
   set_race("human");
   set_alias("bartender");
   set_short("Tom, the bartender");
   set_long("This is Tom, a friendly and good looking bartender able to mix the strongest and\n" +
      "most flavoured cocktails of the whole mud. Ask him for the 'list' of the drinks.\n");
   set_level(1);
   set_hp(400);
   set_al(-200);
   set_wc(0);
   set_ac(1000);
   set_aggressive(0);
   set_chat_chance (5);
   load_chat("Tom says: Good evening sir, what should I serve you?\n");
   load_chat("Tom mixes a cocktail with an incredible ability!\n");
   gold=clone_object("obj/money");
   gold->set_money(600+random(50));
   move_object(gold,this_object());
}
catch_tell(arg)
{ string name,first,before;
  if(sscanf(arg,"%s says: %s list%s",name,first,before))
   { name=lower_case(name);
     who=find_living(name);
     call_out("dice",0);
     return 1;
   }
}    
dice()
  {  tell_object(who, "\n            .----------------------._____.-----------------------.\n"+
                        "            |----------------------|wines|-----------------------|\n"+
                        "            |----------------------`-----'-----------------------|\n"+
                        "            | # |   item      |level|intox|heal pts|    cost     |\n"+
                        "            |----------------------------------------------------|\n"+
                        "            | 1 | coffee      | any | -10 |   --   | 180   coins |\n"+
                        "            | 2 | chianti     | any |   7 |   15   | 300   coins |\n"+
                        "            | 3 | baileys     | >=5 |   8 |   20   | 320   coins |\n"+
                        "            | 4 | vodka       | >=10|  12 |   30   | 360   coins |\n"+
                        "            | 5 | whiskey     | >=10|  13 |   40   | 440   coins |\n"+
                        "            | 6 | pure alcohol| >=10|  14 |   50   | 500   coins |\n"+
                        "            `----------------------------------------------------'\n"+
                        "                   ( 'buy #' to purchase the stuff u need )\n");
     return 1;
}
