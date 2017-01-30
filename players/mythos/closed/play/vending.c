#include "/players/mythos/closed/ansi.h"
object buyer;

id(str) { return str == "vending machine" || str == "vending" || 
          str == "machine"; }

short() { return HIB+"A vending machine"+NORM; }

long() { write("A snazzy vending machine.  To look at a list\n"+
               "of items type <list>.  To buy anything type\n"+
               "buy <item name>.  To check what each product\n"+
               "does type check <item name>\n"); 
        }
        
get() { return 0; }  /* This makes it so that people can not pick it up*/

init() {
   add_action("llist","list");   /*list action , reason why the function 
                                   is llist is because other things might 
                                   list */
   add_action("bbuy","buy");    
   add_action("ocheck","check");
}

llist() {
  write("Things you may buy.\n"+
        "          quicktyper  FREE     \n"+
        "          pet         min 500 coins\n"+
        "          wooden_boy  10 coins\n"+
        "          speedster   1000 coins\n"+
        "          biometer    200 coins\n"+
        "          watch       100 coins\n"); 
  return 1;}
  
bbuy(str) {
object item;
int value, m, heavey;
m = 0;     /* here m is 0..  notice at end of file there is a if(m) {}
              this means if m = 1 then do whatever...  in this case if
              m is still 0 then the write("That can not be bought here.\n")
              line will be activated */
  if(!str) return 0;   
  if(str == "quicktyper") {
    item = clone_object("/players/mythos/prac/qt.c");
    value = 0;
    m = 1;  }
  if(str == "pet") {
    buyer = this_player();
    write("How much do you wish to pay [500 - 80000]: ");
    input_to("pets");
  return 1; }
  if(str == "wooden_boy") {
    item = clone_object("/players/mythos/prac/boy.c");
    value = 10;
    m = 1;      /* here m has now been set to 1 this means that the player can
                   now purchase the item..  i.e. if you set it up so 
                   that for each item m = 1 then the code will allow the 
                   purchase */
}
  if(str == "speedster") {
    item = clone_object("/players/mythos/mmisc/speed.c");
    value = 1000;
    m = 1;
  }
  if(str == "watch") {
    item = clone_object("/players/mythos/mmisc/watch.c");
    value = 100;
    m = 1;
  }
  if(str == "biometer") {
    item = clone_object("/players/mythos/mmisc/biometer.c");
    value = 200;
    m = 1;
  }
  if(m) {
  if(this_player()->query_money() < value) {
    write("You do not have enough to pay for that item!\n");
  return 1;}
  heavey = item->query_weight();
  this_player()->add_weight(heavey);
  this_player()->add_money(-value);    /*take the money from player*/
  move_object(item,this_player());
  write("You have bought a "+str+"\n");
  say(capitalize(this_player()->query_real_name())+" buys a "+str+
  " from the machine\n"); }
  else { write("That can not be bought here.\n"); }
return 1; }

ocheck(str) {
  if(!str) { write("What do you wish to check?\n"); return 1;}
  if(str == "quicktyper") {
    write("A new and improved quicktyper.\n"+
          "Allows one to not only alias commands but nickname secondary\n"+
          "commands or names.  And if you dont like it you can always\n"+
          "get rid of it and get an old one!  <autoloads>\n");
  }
  if(str == "pet") {
     write("Adapted from Sandman's Generic Pets this pet\n"+
           "will help you in your combat and will listen to\n"+
           "a limited set of commands.  A useful little thing.\n");
  }
  if(str == "watch" || str == "sci-watch") {
    write("An <autoloading> watch, that allows one to tell the time-\n"+
          "both in CST and time left of reboot- and has a handy register\n"+
          "command for those unlucky times that you are having player glitches!\n"+
          "<autoloads>\n"); }
  if(str == "speedster") {
    write("Tired of that lag but you aren't in a guild that supplies a way\n"+
          "to beat that lag?  Purchase this 5 command speedster! At a touch\n"+
          "of a button you can beat that lag and get to where you wish in a\n"+
          "heartbeat!  And should you ever wish to get rid of this, just \n"+
          "a quick set of keyboard keys and it is gone!  <autoloads>\n"); }
   if(str == "wooden_boy") {
   write("Here's the ultimate in crime fighting!  The wooden boy!\n"+
         "Lots of fun when you wish to spook someone with the watch \n"+
         "watch command- lets you see the room descript. And is great\n"+
         "fun to throw at people!\n"); }
   if(str == "biometer") {
   write("Ever wanted to know the health of everyone in a single room?\n"+
         "Here's the anser to that problem.  No more single target \n"+
         "scanners.  Here is a biometer that shows the health of everyone.\n"+
         "At a touch of the keyboard and you have instant information!\n");
   }
return 1;}

pets(str) {
int value,coins,stats;
object pet;
  if(!str) return 0;
  sscanf(str,"%d",value);
  if(value < 500) { tell_object(buyer,"Minimum 500 coins.\n"); return 1; }
  if(buyer->query_money() < value) { 
     tell_object(buyer,"You dont have that much.\n");
  return 1; }
      coins = value;
      if(value > 10000) coins = 10000;
      stats = coins / 500;
      pet = clone_object("/players/mythos/prac/pet.c");
      pet->set_oowner(buyer);
      pet->set_level(stats);
      pet->set_ac(stats/4);
      pet->set_wc(stats);
      pet->set_hp(stats * 10);
      if(value > 15000) pet->special_on(1);
      if(value > 30000) pet->special_on(2); 
      if(value > 60000) pet->multiple_on();
      pet->set_exx(0);
      move_object(pet,environment(buyer));
      tell_object(buyer,"You buy a pet.\n");
     buyer->add_money(-value);
     return 1; 
}