/*   This monster sells heals in my Caer Dyvi.  At
     ~/rooms/dyvi2.c                             */

inherit "obj/monster";

reset(arg) {
   if(arg || root()) return;
   set_name("woman");
   set_level(20);
   set_alias("vendor");
   set_race("human");
   set_hp(100);
   set_ac(6);
   set_wc(12);
   set_ac(6);
   set_short("A woman food vendor");
   set_long("A woman sells food and drink to warriors on the go.\n"+
      "You may want to \"ask woman\" what she has for sale.\n");
}

init() {
   ::init();
   add_action("ask","ask");
   add_action("buy","buy");
}
ask(str) {
   if(!str || str != "woman") {
      notify_fail("Ask who?\n");
   }
   write("You ask the womand what she has for sale.\n");
   say(this_player()->query_name()+" asks the woman what she has for sale.\n");
   write("The woman smiles at you graciously.\n");
   say("The woman smiles at "+this_player()->query_name()+" graciously.\n");
   tell_room(environment(),"The Woman says, \"I've got the best traveling food available:\n"+
      "\ta full skin of Ipocras to parch your thirst,\n"+
      "\ta tall bottle of Mead to warm you,\n"+
      "\tor a bowl of Meat Pie to sustain you.\n"+
      "\tAll for only 1600 gold coins each.\n");
   tell_room(environment(),"\tWhat would you like to buy, "+query_respective(this_player())+"?\"\n");
   return 1;
}

query_respective(obj) {
   if(obj->query_gender() == "male") return "Sir";
   return "Ma'am";
}
buy(str) {
   object bought;
   string path;
   if (!str){
      write("Buy what?\n");
      return 1;
   }
   switch(str) {
      case "ipocras": 
      case "skin":
         path="/players/llew/Celts/heals/ipocras.c";
         break;
      case "mead":
      case "bottle":
         path="/players/llew/Celts/heals/mead.c";
         break;
      case "pie":
      case "bowl":
      case "meat pie":
         path="/players/llew/Celts/heals/meatpie";
         break;
   }
   if(path==0) {
      say("The woman looks at "+this_player()->query_name()+" in confusion.\n");
      write("The woman looks at you in confusion.\n");
      tell_room(environment(),"The woman says, \"You wanted a "+str+", "+query_respective(this_player())+"?\n"+
         "                 I'm sorry, I don't have that to sell.\"\n");
      return 1;
   }
   if(this_player()->query_money() < 1600) {
      say("The woman scoffs at "+this_player()->query_name()+".\n");
      write("The woman scoffs.\n");
      tell_room(environment(),"The woman says, \"I don't takes rocks for payment, "+query_respective(this_player())+".\n"+
         "                 I'll need some coins for my wares.\"\n"); 
      return 1;
   }
   bought=clone_object(path);
   this_player()->recalc_carry();
   if(transfer(bought,this_player()) == 1) {
      write("The woman peers at you closely.\n");
      say("The woman peers at "+this_player()->query_name()+" closely.\n");
      tell_room(environment(),"The woman says, \"I could sell you "+bought->short()+",\n"+
         "                 but how would you be able to carry it?\"\n");
      destruct(bought);
      return 1;
   }
   this_player()->add_money(-1600);
   say(this_player()->query_name()+" asks the woman for "+bought->short()+".\n"+
      "The woman takes "+this_player()->query_possessive()+" coins and hands "+this_player()->query_objective()+" "+bought->short()+".\n");
   write("The woman takes your money, and hands you "+bought->short()+".\n");
   tell_room(environment(),"The woman says, \"Thank you, "+query_respective(this_player())+"!  I hope you enjoy it.\"\n");
   return 1;
}
