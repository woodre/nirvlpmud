#include "std_old.h"
#include "/players/dreamspeakr/closed/ansi.h"
#define NUMBER_OF_ITEMS 6
 int inv_no,done,shield, notin;
 string filename,long_dsc,owner_name;

init() {
     if (!done) {
   owner_name="nobody";
     done = 1;
    }
  add_action("on"); add_verb("lock");
  add_action("invite","invite");
  add_action("off"); add_verb("unlock");
  add_action("south"); add_verb("south");
  add_action("look"); add_verb("look");
  add_action("look"); add_verb("l");
  add_action("look"); add_verb("examine");
  add_action("look"); add_verb("exa");
  add_action("read"); add_verb("read");
  add_action("order"); add_verb("purchase");
  if(this_player()->query_real_name() != owner_name && shield == 1) {
    write(capitalize(owner_name) + " has the room locked.\n");
    write("You are transported to the lobby.\n");
  this_player()->move_player("after tring to enter the room#players/dreamspeakr/WEDDING/garden");
 }
 }
static on() {
   shield = 1;
   write("Room locked.\n");
   return 1;
   }
static off() {
   if (call_other(this_player(), "query_real_name", 0) != owner_name) {
  write("You are not allowed to do that!!!!!!!\n");
    return 1;
    }
   shield = 0;
   write("The room is unlocked.\n");
   return 1;
   }

 short() {
   return HIR+capitalize(owner_name) + "'s honeymoon suite"+NORM;
  }
long() {
     write("\n");
     write("     There is a cozy fire blazing in the corner fireplace.  \n");
     write("A beautiful white bear skin rug lays directly in front of the \n");
     write("fireplace.  In the center of the room sits a marble hottub \n");
     write("with ornate pillars surronding it.  Candles flicker casting\n");
     write("shadows across the walls.  On the other side of the room sits \n");
     write("a enormous round bed.  There is a note laying on a endtable \n");
     write("beside the bed.\n");
   if (shield == 1) write ("The door is locked to others.\n");
   if (shield == 0 ) write ("The door is unlocked.\n");
    write("The only exit is south.\n");
}

south() {
  int i,x;
  string *things;

  things = ({ "cat", "vibrator", "oil", "handcuffs" });
  x = 0;

  for( i = 0; i < sizeof(things); i++ ){
       while(present(things[i], this_player())){
            destruct( present(things[i], this_player()) );
            x = 1;
       }
  }
  if( x == 1 ){
     write("\n");
     write(HIR+"All items purchased here have been removed from your inventory.\n"+NORM);
     write(HIR+"                Hope you enjoyed your stay!\n"+NORM);
     write("\n");
  }
  move_object(this_player(), "/players/dreamspeakr/WEDDING/garden.c");
  command("look",this_player());
  return 1;
} 

set_owner(str){
  set_light( 1);
    owner_name = str;
    done = 1;
        return 1;
   }
add_to_long(str){
  if (call_other(this_player(), "query_real_name", 0) != owner_name) {
     return 0;
     }
}
invite(str) {
object guest;
    guest=find_player(str);
  if(!guest)
   {
   write(capitalize(str)+" is not currently logged in.\n");
   return 1;
   }
  if(file_name(environment(guest)) != "players/dreamspeakr/WEDDING/garden")
    {
   write(capitalize(str)+" is not in the lobby.\n");
   return 1;
   }
  if (shield == 1)
   {
    write("You must unlock the door first.\n");
    return 1;
   }
  move_object(guest,this_object());
   write(capitalize(str)+" has been allowed to enter.\n");
   tell_object(guest, "You are pushed into the portal by some unseen force.\n");
   write(capitalize(str) + " arrives.\n");
   return 1;
}
look(str) {
   if (!str) {
   return 0;
  }
  if (str == "at note" ){
    write("Maybe you should read it!\n");
   return 1;
  }
   if(str == "at fire" ){
    write("Popping and sizzling inside the fireplace the flames dance as their \n");
    write("colors fascinate you.\n");
   return 1;
  }
   if(str == "at fireplace"){
     write("Made from the finest black marble in the lands.\n");
   return 1;
  }
   if(str == "at rug"){
     write("From the hide of a pure white polar bear.  It is so soft to the touch.\n");
   return 1;
  }
   if(str == "at hottub"){
     write("Filled to the rim with hot water and bubbles, it appears to be made just \n");
     write("for two! \n");
   return 1;
  }
   if(str == "at pillars"){
     write("Large black marble pillars encircle the hottub with elegance.\n");
   return 1;
  }
   if(str == "at candles"){
     write("White candles in candelobras decorate the room.  Small dripplets of wax \n");
     write("run down the sides of them as they burn.\n");
   return 1;
  }
   if(str == "at walls"){
     write("Reflections of light flicker across the marble walls.\n");
   return 1;
  }
   if(str == "at bed"){
     write("A velvety soft blanket covers this enormous round bed.  Covered in an \n");
     write("abundance of large pillows you feel as though you might never get up!\n");
   return 1;
  }
   if(str == "at endtable"){
     write("A golden table beside the bed, there appears to be a note on it!\n");
   return 1;
  }
return 0;
}
read(str){
    if (!str) {
       write("What would you like to read?\n");
       return 1;
    }
    if (str == "note") {
       write("\n");
       write(HIR+"  .:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:.\n"+NORM);
       write(WHT+"\n");
       write("\tCongratulations on your marriage!  During your stay \n");
       write("\there you may purchase any of the following items: \n");
       write("\t("+HIR+"purchase "+NORM+WHT+"by "+HIR+"numbers"+NORM+")\n");
       write(WHT+"\n");
       write("\t   1.  Cat-of-nine-tails          500 coins\n");
       write("\t   2.  Fuzzy Handcuffs            250 coins\n");
       write("\t   3.  A realistic vibrator       250 coins\n");
       write("\t   4.  Massaging oil              500 coins\n");
       write("\n");
       write("\tAll items are NON storable and cannot leave the room! \n");
       write("\n");
       write(HIR+"  .:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:.\n"+NORM);
       write("\n");
       return 1;
    }
}
order(str) {

    if (!str) {
       write("What would you like to purchase?\n");
       return 1;
    }
    if (str == "1") {
       if (call_other(this_player(), "query_money", 0) < 500) {
         write("That costs 500 gold coins, which you don't have.\n");
       return 1;
       }
       call_other(this_player(), "add_money", - 500);
       move_object(clone_object("/players/dreamspeakr/WEDDING/OBJ/catonine.c"), this_player());
       write("You pay 500 gold for a Cat-of-nine-tails.\n");
       return 1;
    }
    if (str == "2") {
       if (call_other(this_player(), "query_money", 0) < 250) {
         write("That costs 250 gold coins, which you don't have.\n");
       return 1;
       }
       call_other(this_player(), "add_money", - 250);
       move_object(clone_object("/players/dreamspeakr/WEDDING/OBJ/cuffs.c"), this_player());
       write("You pay 250 gold for a pair of fuzzy handcuffs.\n");
       return 1;
    }
    if (str == "3") {
       if (call_other(this_player(), "query_money", 0) < 250) {
         write("That costs 250 gold coins, which you don't have.\n");
       return 1;
       }
       call_other(this_player(), "add_money", - 250);
      move_object(clone_object("/players/dreamspeakr/WEDDING/OBJ/vibrator.c"), this_player()); 
      write("You pay 500 gold for a realistic vibrator.\n");
       return 1;
    }
    if (str == "4") {
       if (call_other(this_player(), "query_money", 0) < 500) {
         write("That costs 500 gold coins, which you don't have.\n");
       return 1;
       }
       call_other(this_player(), "add_money", - 500);
       move_object(clone_object("/players/dreamspeakr/WEDDING/OBJ/oil.c"), this_player());
       write("You pay 500 gold for a vial of massaging oil.\n");
       return 1;
    }
}

realm() { return "NT"; }
