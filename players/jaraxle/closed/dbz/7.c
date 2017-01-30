#include "/players/jaraxle/define.h"
inherit "/obj/treasure.c";

int x=0;

reset(int arg) {
   
   if(arg) return;
   
   set_alias("ball");
   set_short(YEL+"("+RED+"&"+YEL+")"+NORM+" crystal ball");
   set_long("A small crystal ball that is amber in color.  The ball is\n"+
      "transparent enough to see through.  There are "+RED+"7"+NORM+" small stars\n"+
      "in the middle of the ball.  If you had them all, you could\n"+
      "wish someone back to life.\n");
}

id(str){ return str == "dbz_7" || str == "7" || str == "crystal" || str == "ball"; }

init() {
   
   ::init();
   
   add_action("wish_it","wish");
   
}


wish_it(str) {
   object victim, halo;
   int wish_exp;
   halo = clone_object("/players/jaraxle/closed/dbz/halo.c");
   victim = present("ghost of "+str, environment(TP));
   wish_exp = victim->query_lostexperience();
   if (!str) {
      write("Wish who back to life?\n");
      return 1;
   }
   
   if(present("dbz_1",this_player()) ) { x=x+1; }
   if(present("dbz_2",this_player()) ) { x=x+1; }
   if(present("dbz_3",this_player()) ) { x=x+1; }
   if(present("dbz_4",this_player()) ) { x=x+1; }
   if(present("dbz_5",this_player()) ) { x=x+1; }
   if(present("dbz_6",this_player()) ) { x=x+1; }
   
   if(x !=6) { x=0;
      write("You need more crystal balls to make this wish.\n");
      return 1;
   }
   if (!victim) {
      write("That person is not here to wish for.\n");
      return 1;
   }
   if (!living(victim) || victim->query_npc()) {
      write("You find you cannot wish for that.\n");
      return 1;
   }
   if(victim == this_player()) { 
      write("You cannot wish this upon yourself.\n");
      return 1;
   }
   if(victim->query_dead() > 1) {
      write(str+" is not really dead.\n");
      return 1;
   }
   if (!victim->query_ghost()) {
      write("You cannot wish this upon someone who is alive.\n");
      return 1;
   }
   if(present("dbz_halo",victim)){ 
      write("This person has been wished back to life recently.\n");
      return 1;
   }
   write("You call upon the power of the crystal balls...\n"+
      "You wish for "+capitalize(str)+"'s life to be resurected!\n"+
      "\tA beam of "+HIY+"light"+NORM+" explodes from the crystal balls and covers\n"+
      "\t"+capitalize(str)+" in a "+MAG+"glow of magic"+NORM+".\n");
   say(TP->query_name()+" uses the 7 crystal balls to wish "+capitalize(str)+" back to life.\n"+
      "\tA beam of "+HIY+"light"+NORM+" explodes from "+TP->query_name()+"'s crystal balls and covers\n"+
      "\t"+capitalize(str)+" in a "+MAG+"glow of magic"+NORM+".\nA small "+HIY+"halo"+NORM+" appears over "+capitalize(str)+"'s head.\n");
   call_other(victim, "remove_ghost", 0);
   victim->add_xp(wish_exp/3);
   move_object(halo, victim);
   halo->start();
   
   if(x ==6) {
      
      object blah, blah2, blah3, blah4, blah5, blah6;
      
      blah = present("dbz_1",TP);
      blah2 = present("dbz_2",TP);
      blah3 = present("dbz_3",TP);
      blah4 = present("dbz_4",TP);
      blah5 = present("dbz_5",TP);
      blah6 = present("dbz_6",TP);
      destruct(blah);
      destruct(blah2);
      destruct(blah3);
      destruct(blah4);
      destruct(blah5);
      destruct(blah6);
      destruct(this_object()); 
      
      return 1; }
}

