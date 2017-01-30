#include "/players/mythos/closed/ansi.h"

id(str) { return str == "vending machine" || str == "vending" || 
          str == "machine"; }

short() { return HIB+"A vending machine"+NORM; }

long() { write("A snazzy vending machine.  To look at a list\n"+
               "of items type <list>.  To buy anything type\n"+
               "buy <item name>.  To check what each product\n"+
               "does type check <item name>\n"); 
        }
        
get() { return 0; }  /* This makes it so that people can not pick it up*/

reset(arg) {
if (arg) return;
  move_object(this_object(),"/room/vill_green.c");
}

init() {
   add_action("llist","list");   /*list action , reason why the function 
                                   is llist is because other things might 
                                   list */
   add_action("bbuy","buy");    
   add_action("ocheck","check");
}

llist() {
  write("Things you may buy.\n"+
        "          wooden_boy  10 coins\n"+
        "          monitor     500 coins\n"+
        "          speedster   1000 coins\n"+
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
  if(str == "wooden_boy") {
    item = clone_object("/players/mythos/prac/boy.c");
    value = 10;
    m = 1;      /* here m has now been set to 1 this means that the player can
                   now purchase the item..  i.e. if you set it up so 
                   that for each item m = 1 then the code will allow the 
                   purchase */
  }
  if(str == "monitor") {
    item = clone_object("/players/mythos/mmisc/mon.c");
    value = 500;
    m = 1;
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
  if(m) {
  if(this_player()->query_money() < value) {
    write("You do not have enough to pay for that item!\n");
  return 1;}
  heavey = item->query_weight();
  this_player()->add_weight(heavey);
  this_player()->add_money(-value);    /*take the money from player*/
  move_object(item,this_player());
  this_player()->save_me();
  write("You have bought a "+str+"\n");
  say(capitalize(this_player()->query_real_name())+" buys a "+str+
  " from the machine\n"); }
  else { write("That can not be bought here.\n"); }
return 1; }

ocheck(str) {
  if(!str) { write("What do you wish to check?\n"); return 1;}
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
   if(str == "monitor") {
     write("You do not want to be in a guild or unable to do so?\n"+
           "Well, don't worry you are not missing out on anything\n"+
           "once you purchace this important hit-point/spell-point \n"+
           "monitor!  True it isn't fancy but it has what is needed!\n"+
           "And should you ever get a fancier monitor, a few keystrokes\n"+
           "gets rid of this object!  <autoloads>\n"); }
   if(str == "wooden_boy") {
   write("Here's the ultimate in crime fighting!  The wooden boy!\n"+
         "Lots of fun when you wish to spook someone with the watch \n"+
         "watch command- lets you see the room descript. And is great\n"+
         "fun to throw at people!\n"); }
return 1;}
