#include "/players/dreamspeakr/closed/ansi.h"
#define PATH "/players/dreamspeakr/WEDDING/"

inherit "room/room";

reset(arg) {
  if(arg) return;
     move_object(clone_object("/players/dreamspeakr/WEDDING/motel.c"), this_object());
set_light(1);

short_desc = HIR+"Garden of Love"+NORM;
long_desc =
    "\n"+
    "     Lush green plants blanket the ground all around twin\n"+
    "fountains in the center of this open air garden.  A golden \n"+
    "pathway lined by large marble pillars leads around the garden\n"+
    "to the chapel entrance.  There are two dressing rooms next to \n"+
    "the entrance to the chapel.  There is a sign hanging on the\n"+
    "chapel door.\n"+
    "\n"
;

items = ({
    "sign","Maybe you should read it\n",
    "plants","Healthy green plants blanket the ground all around this \n"+
             "peaceful garden\n",
    "ground","The ground below your feet is paved in gold",
    "pathway","A golden pathway appears to have been made of pure gold",
    "garden","Lush plants sprout out from all around this well kept gargen",
    "pillars","Ornate pillars line the pathway made from beautiful marble",
    "counter","A long counter where you can register for a room in the lodge",
    "wall","The wall to the chapel",
    "cubicals","Small boxes to hold the keys to the honeymoon suites",
    "keys","Golden keys lay just inside the cubicals",
    "fountains","In the center of the garden sits a pair of fountains, each \n"+
                "with golden cherubs shooting water from their mouths\n",
    
});
dest_dir = ({
    PATH+"chapel.c","chapel",
    PATH+"garden.c","dressing_room",
    "/players/dreamspeakr/CASTLE/entrance.c","south",
    
});
}

init(){
    ::init();
    add_action("order");
    add_verb("purchase");
    add_action("read","read");
    add_action("invite","invite");
    add_action("chapel","chapel");
    add_action("dressing","dressing_room");
    add_action("leave_room","south");
}
order(str){
    if (!str) {
       write("What would you like to purchase?\n");
       return 1;
    }
    if (str == "1") {
       if (call_other(this_player(), "query_money", 0) < 100) {
       write("That costs 100 gold coins, which you don't have.\n");
       return 1;
       }
       call_other(this_player(), "add_money", - 100);
       move_object(clone_object("/players/dreamspeakr/WEDDING/OBJ/cake.c"), this_player());
       write("You pay 100 gold for a piece of wedding cake.\n");
       return 1;
    }
    if (str == "2") {
       if (call_other(this_player(), "query_money", 0) < 100) {
       write("That costs 100 gold coins, which you don't have.\n");
       return 1;
       }
       call_other(this_player(), "add_money", - 100);
       move_object(clone_object("/players/dreamspeakr/WEDDING/OBJ/champagne.c"), this_player());
       write("You pay 100 gold for a chilled glass of champagne.\n");
       return 1;
    }
    if (str == "3") {
       if (call_other(this_player(), "query_money", 0) < 500) {
       write("That costs 500 gold coins, which you don't have.\n");
       return 1;
       }
       call_other(this_player(), "add_money", - 500);
       move_object(clone_object("/players/dreamspeakr/WEDDING/OBJ/rice.c"), this_player());
       write("You pay 500 gold for some birdseed.\n");
       return 1;
    }
    if (str == "4") {
       if (call_other(this_player(), "query_money", 0) < 500) {
       write("That costs 500 gold coins, which you don't have.\n");
       return 1;
       }
       call_other(this_player(), "add_money", - 500);
       move_object(clone_object("/players/dreamspeakr/WEDDING/OBJ/confetti.c"), this_player()); 
       write("You pay 500 gold for some "+HIB+"C"+HIR+"o"+HIG+"l"+HIY+"o"+HIW+"r"+HIB+"f"+HIR+"u"+HIG+"l"+HIY+" C"+HIW+"o"+HIB+"n"+HIR+"f"+HIG+"e"+HIY+"t"+HIW+"t"+HIB+"i"+NORM+".\n");
       return 1;
    }
}

read(str){
    if (!str) {
       write("What would you like to read?\n");
       return 1;
    }
    if (str == "sign") {
       write("\n");
       write(HIR+"  .:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:.\n"+NORM);
       write(HIR+"\n");
       write("                    CHAPEL OF LOVE"+NORM+"\n");
       write(HIW+"\n");
       write("\tWedding guests should proceed to the chapel.  \n");
       write("\tThe bride and groom should go to their dressing \n");
       write("\trooms to prepare before entering the chapel.\n");
       write("\n");
       write("\tYou may also buy some goodies here to help you \n");
       write("\tcelebrate after the ceremony! ("+HIR+"purchase"+HIW+" by "+HIR+"numbers"+HIW+")\n");
       write("\n");
       write("\t  1.  A piece of wedding cake           100 coins\n");
       write("\t  2.  A tall glass of champagne         100 coins\n");
       write("\t  3.  Birdseed to throw at the couple   500 coins\n");
       write("\t  4.  "+HIB+"C"+HIR+"o"+HIG+"l"+HIY+"o"+HIW+"r"+HIB+"f"+HIR+"u"+HIG+"l"+HIY+" C"+HIW+"o"+HIB+"n"+HIR+"f"+HIG+"e"+HIY+"t"+HIW+"t"+HIB+"i"+HIW+"                 500 coins\n"+NORM);
       write(HIW+"\n");
       write("\tYou can also send an invitation to the ceremony\n");
       write("\tceremony to a friend for the sum of 50 coins.\n");
       write("\n");
       write("\tTo do so type:  "+HIR+"invite <playername>"+HIW+"\n");
       write("\n");
       write(HIR+"  .:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:.\n"+NORM);
      return 1;
      }
}

invite(str){
   object new;

   if (call_other(this_player(), "query_money", 0) < 50) {
      write("That costs 50 gold coins, which you don't have.\n");
      return 1;
   }
   if(!str) { 
      write("You must invite someone.\n"); 
      return 1; 
   }
   if(!find_living(str)) {
      write("You can't do that!\n");
      return 1;
   }
   if ( !find_player(str) ) {
      write(capitalize(str) + " is not logged on.\n");
      return 1;
   }
   if(find_player(str)->query_invis() > 18){
      write(capitalize(str) + " is not logged on.\n");
      return 1;
   }
   if(present("invitation", find_player(str))){
    write("That player already has an invitation.\n");
    return 1;
   }
   call_other(this_player(), "add_money", - 50);
   new=clone_object("/players/dreamspeakr/WEDDING/OBJ/invite.c");
   move_object(new, find_player(str));
   tell_object(find_player(str), HIW+"A White dove flys in and drops something into your inventory!"+NORM+"\n");
   write(capitalize(str) + " has been sent an invitation!\n");
   return 1;
}

chapel() {
   if((int)this_player()->query_invis() > 18){
      move_object(this_player(), "/players/dreamspeakr/WEDDING/chapel.c"); 
      command("look",this_player());
      return 1;
   } else {
      say("An usher greets "+this_player()->query_name()+" at the door and escorts "+this_player()->query_name()+" into the chapel.\n");
      write("An usher greets you at the door and escorts you into the chapel.\n");
      move_object(this_player(), "/players/dreamspeakr/WEDDING/chapel.c");
      say("An usher enters escorting " +this_player()->query_name()+ ".\n");
      command("look",this_player());
      return 1;
   }
}

leave_room() {
  int i,x;
  string *things;

  x = 0;
  things = ({ "bouquet", "cane", "cumberbun", "black_shoes", "tie", "tophat", "tuxedo", "garter", "cameo", "wedding_dress", "attitude", "penny", "lace_veil", "satin_shoes" });
  for ( i = 0; i < sizeof(things) ; i++ ){
       while( present(things[i], this_player()) ){
             destruct( present(things[i], this_player()) );
             x = 1;
       }
  }
  if( x == 1 ){
  write("\n");
  write(HIW+"The Usher says:  "+HIR+"All rented items have been safely returned! \n"+NORM);
  write(HIR+"                 Hope to see you again!\n"+NORM);
  write("\n");
  }
  if((int)this_player()->query_invis() > 18){
      move_object(this_player(), "/room/yard.c"); 
      command("look",this_player());
      return 1;
   } else {
      say(this_player()->query_name()+" exits south.\n");
      move_object(this_player(), "/room/yard.c");
      say(this_player()->query_name()+" arrives.\n");
      command("look",this_player());
      return 1;
   }
}
dressing() {
   if( (string)this_player()->query_gender() == "female" ) {
      if((int)this_player()->query_invis() > 18){
        move_object(this_player(), "/players/dreamspeakr/WEDDING/bride.c"); 
        command("look",this_player());
        return 1;
       } else {
         say(this_player()->query_name()+" exits dressing_room.\n");
         move_object(this_player(), "/players/dreamspeakr/WEDDING/bride.c");
         say(this_player()->query_name()+" arrives.\n");
         command("look",this_player());
         return 1;
       }
   }
   if( (string)this_player()->query_gender() == "male") {
      if((int)this_player()->query_invis() > 18){
        move_object(this_player(), "/players/dreamspeakr/WEDDING/groom.c"); 
        command("look",this_player());
        return 1;
       } else {
         say(this_player()->query_name()+" exits dressing_room.\n");
         move_object(this_player(), "/players/dreamspeakr/WEDDING/groom.c");
         say(this_player()->query_name()+" arrives.\n");
         command("look",this_player());
         return 1;
      }
   }
}

query_no_fight() { return 1; }

realm() { return "NT"; }
