/* single shot, 35/35 intox - intox 7 */
/* Can be thrown to other players */

inherit "/obj/treasure.c";
#include "/players/jaraxle/define.h"
reset(arg){
   
   set_short("A slab of "+HIM+"ooze"+NORM);
   set_weight(1);
   set_value(800);
   set_long(
      "This is a slimy slab of ooze.  You can '"+HIM+"eat"+NORM+"'\n"+
      "it or you can '"+HIM+"sling"+NORM+"' it at someone.\n");
}
id(str){ return str == "ooze" || str == "slab"; }
is_heal(){return "food";  }
query_potence(){return 35;      }
query_save_flag(){return 1;       }

void init(){
   ::init();
   add_action("pop_cmd", "eat");
   add_action("throw_me", "sling");
}


pop_cmd(str){
   int NM;
   if(environment(TO) != TP) return 0;
   if(str != "slab" && str != "ooze") return 0;
   if(!call_other(TP,"eat_food", 6)) return 1;
   if(TP->checkNM())  NM = 1;
   write("You greedily consume the slab of ooze.\n");
   this_player()->heal_self(35);
   write(HIM+"HP ["+TP->query_hp()+"/"+TP->query_mhp()+"]  ");
   write(HIM+"SP ["+TP->query_spell_point()+"/"+
      TP->query_msp()+"]\n"+NORM);
   say(TPN+" swallows a slab of "+HIM+"ooze"+NORM+".\n");
   destruct(this_object());
   this_player()->recalc_carry();
   return 1;
}

throw_me(str){
   object player2,new_slab;
   string what,who;
   if(environment(this_object()) != this_player()) return 0;
   if(!str){
      notify_fail("What would you like to sling?\n");
      return 0;
   }
   sscanf(str,"%s at %s",what,who);
   if(!who) what = str;
   if(!id(what)){
      notify_fail("You do not have that to sling.\n");
      return 0;
   }
   if(!who){
      write("Who would you like to sling your "+HIM+"ooze"+NORM+" at?\n");
      return 1;
   }
   player2 = find_player(who);
   if(!player2){ 
      write(capitalize(who)+" is not around to receive the "+HIM+"slab of ooze"+NORM+".\n");
      return 1;
   }
   if(player2->query_invis()){
      write("You do not see anyone by the name of "+capitalize(who)+".\n");
      return 1;
   }
   if(player2->query_level() > 19){
      write(HIR+"No."+NORM+" [Jaraxle]\n");
      return 1;
   }
   if(environment(this_player())->realm() == "NT" || environment(player2)->realm() == "NT" )
      {
      write("The "+HIM+"slab of ooze"+NORM+" refuses to be slung.\n");
      return 1; }
   write("You sling the "+HIM+"slab of ooze"+NORM+" towards "+player2->query_name()+".\n");
   say(TPN+" slings a "+HIM+"slab of ooze"+NORM+" towards "+player2->query_name()+".\n");
   tell_object(player2, "A "+HIM+"slab of ooze"+NORM+" flys into your hands, courtesy of "+TPN+".\n");
   new_slab = clone_object("/players/jaraxle/3rd/ooze/mon/slab.c");
   move_object(new_slab,player2);
   destruct(this_object());
   TP->recalc_carry();
   return 1;
}
