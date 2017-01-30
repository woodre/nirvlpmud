inherit "obj/monster";
object who;
reset(arg){
   object gold,sblade;
   ::reset(arg);
   if(arg) return;
   set_name("waiter");
   set_race("human");
   set_alias("waiter");
   set_short("The chief waiter");
   set_long("This is the chief waiter of the restaurant, wearing a white suit and a black bow\n" +
      "tie, you can ask him for the 'list' of the dishes.\n");
   set_level(1);
   set_hp(400);
   set_al(-200);
   set_wc(0);
   set_ac(2012);
   set_aggressive(0);
   set_chat_chance (5);
   load_chat("The waiter says: Can I help you, sir?\n");
   load_chat("The waiter looks through the menu.\n");
   gold=clone_object("obj/money");
   gold->set_money(600+random(50));
   move_object(gold,this_object());
}
catch_tell(arg)
{ string name,first,before;
    if(arg)
  if(sscanf(arg,"%s says: %s list%s",name,first,before))
   { name=lower_case(name);
     who=find_living(name);
     call_out("dice",0);
     return 1;
   }
}    
dice()
  {  if(who) tell_object(who, "\n            .----------------------.______.----------------------.\n"+
                        "            |----------------------|dishes|----------------------|\n"+
                        "            |----------------------`------'----------------------|\n"+
                        "            | # |      dish           | pts healed |    cost     |\n"+
                        "            |----------------------------------------------------|\n"+
                        "            | 1 | red lobster         | (50hp+50sp)| 500   coins |\n"+
                        "            | 2 | spaghetti           | (40hp+40sp)| 400   coins |\n"+
                        "            | 3 | t-bone steak        | (30hp+30sp)| 300   coins |\n"+
                        "            | 4 | vegetal soup        | (20hp+20sp)| 200   coins |\n"+
"            | 5 | Panna Elena         | (15hp+15sp)| 150   coins |\n"+

                        "            | 6 | salad               | (10hp+10sp)| 140   coins |\n"+
                        "            `----------------------------------------------------'\n");
     return 1;
}
