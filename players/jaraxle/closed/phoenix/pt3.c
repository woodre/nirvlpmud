#include "/players/jaraxle/define.h"
inherit "/obj/treasure.c";

int x=0;
int z=0;

reset(int arg) {
   
   if(arg) return;
   
   set_alias("phoenix idol");
   set_short("Idol of the "+RED+"Phoenix"+NORM+" (base)");
   set_long("This is the base of the Idol of the Phoenix.  The\n"+
      "base is set with two long talons wrapped around the\n"+
      "bottom and golden in tint.\n");
}

id(str){ return str == "phoenix_pt3" || str == "idol of the phoenix" || str == "phoenix" || str == "base"; }

void long(string arg){
   ::long(arg);
   if(this_player()->query_attrib("int") > random(60))
      return (write("You notice something has been written on the bottom.\n"+
         "You may be able to 'read' it.  You also\n"+
         "may be able to 'meld' the idol together.\n"));
}

init() {
   
   ::init();
   
   add_action("wish_it","wish");
   add_action("meld_it","meld");
   add_action("cmd_read","read");
   
}


wish_it(str) {
   object victim, halo;
   int wish_exp;
   halo = clone_object("/players/jaraxle/closed/phoenix/halo.c");
   victim = present("ghost of "+str, environment(TP));
   wish_exp = victim->query_lostexperience();
   
   if (!str) {
      write("Wish who back to life?\n");
      return 1;
   }
   
   if(present("phoenix_pt1",this_player()) ) { x=x+1; }
   if(present("phoenix_pt2",this_player()) ) { x=x+1; }
   
   if(x !=2) { x=0;
      write("You need more pieces of the idol to make this wish.\n");
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
   if(present("phoenix_halo",victim)){ 
      write("This person has been wished back to life recently.\n");
      return 1;
   }
   write("You call upon the power of the "+RED+"PhoeniX"+NORM+"...\n"+
      "You wish for "+capitalize(str)+"'s life to be resurected!\n"+
      "\tA beam of "+HIY+"light"+NORM+" explodes from the Phoenix Idol and covers\n"+
      "\t"+capitalize(str)+" in a "+HIR+"glow of fire"+NORM+".\n");
   write(HIR+"\t\t   _,=~{  _   }~=,_\n"+
      "\t\t _,'    \\_>\\_/    ',_\n"+
      "\t\t .7,     {  }     ,\.\n"+
      "\t\t  '/:,  .m  m.  ,:\\'\n"+
      "\t\t    '}',{/  \\},'{'\n"+
      "\t\t       '{'!!'}'\n"+NORM);
   say(TP->query_name()+" uses the Idol of the Phoenix to wish "+capitalize(str)+" back to life.\n");
   say(HIR+"\t\t   _,=~{  _   }~=,_\n"+
      "\t\t _,'    \\_>\\_/    ',_\n"+
      "\t\t .7,     {  }     ,\.\n"+
      "\t\t  '/:,  .m  m.  ,:\\'\n"+
      "\t\t    '}',{/  \\},'{'\n"+
      "\t\t       '{'!!'}'\n"+NORM);
   say("\tA beam of "+HIY+"light"+NORM+" explodes from "+TP->query_name()+"'s Phoenix Idol and covers\n"+
      "\t"+capitalize(str)+" in a "+HIR+"glow of fire"+NORM+".\nA small "+HIY+"halo"+NORM+" appears over "+capitalize(str)+"'s head.\n");
   call_other(victim, "remove_ghost", 0);
   victim->add_xp(wish_exp/3);
   move_object(halo, victim);
   halo->start();
   
   if(x ==2) {
      
      object blah, blah2;
      
      blah = present("phoenix_pt1",TP);
      blah2 = present("phoenix_pt2",TP);
      destruct(blah);
      destruct(blah2);
      destruct(this_object()); 
      
      return 1; }
}


cmd_read(arg) {
   if(!arg){ notify_fail("Read what?\n"); return 0; }
   if(!id(arg)) return (notify_fail("You may read " + short_desc + ".\n"), 0);
   write("With the Idol of the Phoenix in its complete\n"+
      "form the owner will be able to 'wish' someone\n"+
      "back to life.\n");
   return 1;
}

meld_it(str){
   if(!str){ write("You need to meld idol.\n"); return 1; }
   if(present("phoenix_pt1",this_player()) ) { z=z+1; }
   if(present("phoenix_pt2",this_player()) ) { z=z+1; }
   
   if(z !=2) { z=0;
      write("You need more pieces of the idol to make this meld.\n");
      return 1;
   }
   write("You place the pieced of the idol in order . . .\n"+
      "\tThe pieced meld together, completely solid.\n");
   MOCO("/players/jaraxle/closed/phoenix/idol.c"), TP);
destruct(present("phoenix_pt2",this_player()));
destruct(present("phoenix_pt1",this_player()));
destruct(TO);
return 1; }
