
#define MAX_LIST 30
#define SPEAK(x) write("The armorer says:  "+x);

int cost, weight;
string me, long_str, short_str;
object itemob;

reset(arg) {
   if(!arg)
     set_light(1);
   extra_reset();
}

object torch, bag, rope, sword, mace, twosword, axe, shield;
int i;

extra_reset() {
   if(!present("sword")) {
     i = 0;
     while(i < 2) {
       sword = clone_object("players/sandman/paladin/obj/weapon");
       sword->set_name("broadsword");
       sword->set_weapon_type("sword");
       sword->set_short("A broadsword");
       sword->set_long("A finely crafted steel broadsword.\n"+
                       "A small triangle is etched in the blade "+
                       "near the hilt.\n");
       sword->set_class(12+random(3));
       sword->set_value(600);
       move_object(sword, this_object());
       i += 1;
     }
     twosword = clone_object("players/sandman/paladin/obj/2weapon");
     twosword->set_weapon_type("sword");
     twosword->set_name("sword");
     twosword->set_short("A two-handed sword");
     twosword->set_long("A finely crafted two-handed sword.\n"+
                      "A small triangle is etched in the blade "+
                      "near the hilt.\n");
     twosword->set_class(13+random(3));
     twosword->set_extra_damage(3);
     twosword->set_value(700);
     move_object(twosword, this_object());
   }
   if(!present("mace")) {
     mace = clone_object("players/sandman/paladin/obj/weapon");
     mace->set_name("mace");
     mace->set_weapon_type("mace");
     mace->set_short("A medium sized mace");
     mace->set_long("A wooden mace, with steel riveted to the head\n"+
                    "of the mace.  A small triangle is etched in the "+
                    "handle.\n");
     mace->set_class(12+random(3));
     mace->set_value(450);
     move_object(mace, this_object());
   }
   if(!present("shield")) {
     i = 0;
     while(i < 10) {
       shield = clone_object("players/sandman/paladin/obj/palshield");
       shield->set_id("shield");
       shield->set_short("A paladins fighting shield");
       shield->set_long("A sturdy shield designed for parrying blows.\n"+
                        "A small triangle is etched on the face of the "+
                        "shield.\n");
       shield->set_value(125);
       move_object(shield, this_object());
       i += 1;
     }
   }
   if(!present("torch")) {
     torch = clone_object("obj/torch");
     torch->set_name("torch");
     torch->set_short("A torch");
     torch->set_long("A small torch coated with pitch.\n");
     torch->set_weight(1);
     torch->set_fuel(2000);
     move_object(torch, this_object());
   }
   if(!present("bag")) {
     bag = clone_object("obj/bag");
     move_object(bag, this_object());
   }
   if(!present("rope")) {
     rope = clone_object("obj/rope");
     move_object(rope, this_object());
   }
}

short() { return "Storage room for the Paladin Armory"; }

long() {
   write("The storage room for the Paladin Armory.\n"+
         "A curtained doorway lies to the south.\n");
}

init() {
   add_action("west","west");
}

west() {
   this_player()->move_player("west#players/sandman/paladin/armory");
   return 1;
}

inspect(item) {
   object dest;
   itemob = present(item, this_object());
   if(!itemob) {
     SPEAK("I do not have a "+item+" to inspect.\n");
     return 1;
   }
   move_object(itemob, this_player());
   command("look at "+item, this_player());
   move_object(itemob, this_object());
   return 1;
}

buy(item) {
   int number;

   if(sscanf(item, "%d", number) == 1) {
     if(number <= 0) {
       write("You must specify a positive number.\n");
       return 1;
     }
     buy_numbered_item(number);
     return 1;
   }
   itemob = present(item, this_object());
   if(!itemob) {
     SPEAK("That is not here.\n");
     return 1;
   }
   buy_item(itemob);
   return 1;
}

buy_numbered_item(number) {
   object ob, itemob;
   int max, counter;
   
   max = MAX_LIST;
   ob = first_inventory(this_object());
   if(!ob) {
     SPEAK("The shop has nothing to sell at this time.\n");
     return 1;
   }
   counter = 1;
   while(ob && max > 0) {
     if(counter == number) 
       itemob = ob;
     ob = next_inventory(ob);
     counter += 1;
     max -= 1;
   }
   if(!itemob) {
     write("There are only "+(counter-1)+" items available.\n");
     return 1;
   }
   buy_item(itemob);
   return 1;
}

buy_item(itemob) {
   cost = 2 * itemob->query_value();
   weight = itemob->query_weight();
   short_str = itemob->short();
   if(cost > this_player()->query_money()) {
     SPEAK("You do not have enough money.\n");
     return 1;
   }
   if(!this_player()->add_weight(weight)) {
     SPEAK("You cannot carry that much!\n");
     return 1;
   }
   this_player()->add_money(-cost);
   this_player()->add_weight(weight);
   me = this_player()->query_name();
   say(capitalize(me)+" buys "+short_str+".\n");
   write("You buy "+short_str+" for "+cost+" gold pieces.\n");
   SPEAK("Thank you!\n");
   move_object(itemob, this_player());
   return 1;
}

inventory(str) {
   object ob;
   int max, counter;
   string tmp_cnt;

   max = MAX_LIST;
   ob = first_inventory(this_object());
   if(!ob) {
     SPEAK("The shop has nothing to sell at this time.\n");
     return 1;
   }
   counter = 1;
   while(ob && max > 0) {
     if(counter < 10)
       tmp_cnt = " "+counter;
     else tmp_cnt = counter;
     if(str == "all") {
       write("["+tmp_cnt+"]   "); list(ob);
       max -= 1;
     }
     if(str == "weapons" && ob->weapon_class()) {
       write("["+tmp_cnt+"]   "); list(ob);
       max -= 1;
     }
     if(str == "armors" && ob->armor_class()) {
       write("["+tmp_cnt+"]   "); list(ob);
       max -= 1;
     }
     ob = next_inventory(ob);
     counter += 1;
   }
}

list(ob) {
   string tmp_cost;
   
   cost = 2 * ob->query_value();
   if(cost < 10)
     tmp_cost = "    "+cost;
   else if(cost < 100)
          tmp_cost = "   "+cost;
   else if(cost < 1000)
          tmp_cost = "  "+cost;
   else if(cost < 10000)
          tmp_cost = " "+cost;
   else tmp_cost = cost;
   if(cost) {
     write(tmp_cost+":\t"+ob->short()+".\n");
   }
}


