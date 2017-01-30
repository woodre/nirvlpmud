#include "/players/dreamspeakr/closed/ansi.h"

inherit "obj/treasure";

reset(arg){
   if(arg) return;
   
   set_id("rose");
   set_weight(1);
   
   set_short(HIR+"The Rose"+NORM);
   set_long(HIR+"                                      The Rose "+NORM+"\n"+      
      "                            Written by Amanda McBroom\n"+
      HIR+"     .     ."+NORM+"\n"+
      HIR+"   ...  :``..':             "+NORM+"\n"+
      HIR+"   : ````.'   :''::'        "+NORM+"Some say love, it is a river...\n"+ 
      HIR+"  ..:..  :     .'' :        "+NORM+"           ...that drowns the tender reed.\n"+
      HIR+"``.    `:    .'     :       "+NORM+"Some say love, it is a razor...\n"+
      HIR+"   :    :   :        :      "+NORM+"           ...that leaves the soul to bleed.\n"+
      HIR+"    :   :   :         :     "+NORM+"Some say love, it is a hunger...\n"+
      HIR+"    :    :   :        :     "+NORM+"           ...an endless aching need.\n"+
      HIR+"     :    :   :"+NORM+GRN+"__|"+HIR+"``"+NORM+GRN+"_|_"+NORM+"     But I say love, it is a flower...\n"+
      HIR+"      : "+NORM+GRN+"___"+HIR+":"+NORM+GRN+"__|     _"+HIR+"''"+NORM+"                ...and you its only seed.\n"+
      GRN+"      _|   _"+HIR+"'"+NORM+GRN+"  _|||||"+HIR+"'"+NORM+"\n"+      
      GRN+"     |__'''``|||||||        "+NORM+"It's the heart afraid of breaking...\n"+
      HIG+"     '         `||||        "+NORM+"           ...that never learns to dance.\n"+
      HIG+"                 `||_       "+NORM+"It's the dream afraid of waking...\n"+
      HIG+"                  `||       "+NORM+"           ...that never takes the chance.\n"+
      GRN+"           ___ "+HIG+"    |||_ "+NORM+"    It's the one that won't be taken...\n"+
      GRN+"        __|   _| `. "+HIG+"||"+HIR+"'`"+NORM+"              ...that cannot seem to give.\n"+
      GRN+"      __|  _   `|_| "+HIG+"||   "+NORM+"   And the soul afraid of dying...\n"+
      GRN+"      | __|     _|``"+HIG+"|||  "+NORM+"              ...that never learns to live.\n"+
      GRN+"      |    __''     "+HIG+"|||  "+NORM+"\n"+
      GRN+"      | _''          "+HIG+"||  "+NORM+"   When the night has been to lonely...\n"+
      GRN+"       |             "+HIG+"|| "+NORM+"               ...and the road has been to long.\n"+
      HIG+"                     ||     "+NORM+"And you think that love is only... \n"+
      HIG+"                     ||     "+NORM+"           ...for the lucky and the strong.\n"+
      HIG+"                     |||    "+NORM+"Just remember in the winter...\n"+
      HIG+"                     |||    "+NORM+"           ...far beneath the bitter snow.\n"+
      HIG+"                      ||    "+NORM+"Lies a seed that with the sun's love...\n"+
      HIG+"                      ||    "+NORM+"           ...in the spring becomes the rose...\n"+
      HIG+"                      ||    "+NORM+"\n"+
      "\n"+
      "You can "+HIR+"'sniff'"+NORM+" your lovely rose.\n"+
      "You can "+HIR+"'brush'"+NORM+" the rose upon a loved ones cheek.\n"+
      
      MAG+"                    Another creation from Dreamspeakr\n"+NORM);
}
init(){
   int i;
   
   add_action("sniff_rose","sniff");
   add_action("brush", "brush");
}

int sniff_rose(string str){
   if (!str || str != "rose"){
      notify_fail("What would you like to sniff?\n");
      return 0;
   }
   write("You slowly bring the "+HIR+"rose "+NORM+"to your nose, closing your eyes as you take \n"+
      "in its heavenly scent.\n");
   say(this_player()->query_name()+" brings the lovely "+HIR+"rose "+NORM+"to "+this_player()->query_possessive()+" nose closing "+this_player()->query_possessive()+" eyes as "+this_player()->query_pronoun()+" smells.\n");
   return 1;
   
}

brush(str) {
   object ob;
   
   if(!str) { 
      write("You must brush someone.\n"); return 1; 
   }
   
   ob = present(str,environment(this_player()));
   if(!ob){  
      write("You must be in the same room as "+capitalize(str)+".\n");
      return 1;
   }
   
   if(ob->query_invis() > 20){
      notify_fail("You must be in the same room as "+capitalize(str)+".\n");
      return 1;
   }
   
   if(!find_living(str)) {
      notify_fail("You can't do that!\n");
      return 1;
   }
   
   tell_object(ob,this_player()->query_name()+" brushes the soft "+HIR+"rose petals"+NORM+" across your cheek.\n");
   write("You gently brush the "+HIR+"rose "+NORM+"across "+capitalize(str)+"'s cheek.\n");
   say(this_player()->query_name()+" brushes "+str+"'s cheek with the "+HIR+"rose"+NORM+".\n",ob);
   return 1;
}

