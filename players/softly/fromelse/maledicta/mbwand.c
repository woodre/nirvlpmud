#include "/players/softly/closed/ansi.h"
inherit "/obj/treasure.c";
#define ATT this_player()->query_attack()
int delayed;

reset(){
    set_id("blue wand");
    set_alias("wand");
    set_short(HIB+"Blue Wand"+NORM);
    set_long("\
The thin bright blue wand looks insignificant\n\
 but for an yellow-white electric charge that\n\
 flows steadily along its considerable length.\n");
    set_weight(1);
    set_value(3000);
    }

init(){ 
 add_action("fire_it", "invoke");
 }


fire_it(str){
int damage,X;
if(environment(this_object()) != this_player()) return;
if(!str){ write("invoke what?\n"); return 1; }
if(str != "wand") return;
if(!ATT){
  write("You are not currently fighting anything!\n");
  return 1;
  }
if(ATT->is_player()){
  write("Your wand fails against a player!\n"); 
  return 1;
  }
if(delayed){ write("Your wand has not recharged yet!\n"); return 1; }
damage = random(14) + 5;

    X = random(4);

      switch(random(2))
      {
        case 0:
          say("\nThe "+HIB+"blue wand"+NORM+" crackles as "+HIY+"lightning "+NORM+"pierces " + ATT->query_name() + "."+NORM+"\n\n", ATT);
          tell_object(ATT,"The "+HIB+"blue wand"+NORM+" crackles as "+HIY+"lightning "+NORM+"pierces you."+NORM+"\n\n");
          write(HIB+"\n\
      ~~~~~~~~~\n\
"+HIY+"               Z\n\
"+HIB+"                ~~~~~~~~~\n\
"+HIY+"                         Z\n\
"+HIB+"                          ~~~~~~~~~\n"+NORM);
          break;

        case 1:
          say(HIB+"\nSparks fly from the blue wand toward "+ATT->query_name()+"\n\n"+HIB+
"      *  "+HIY+" *"+HIB+"   *        * "+HIY+"  *"+HIB+"   *"+NORM+"\n\n", ATT);
          tell_object(ATT,HIB+"\n\
          *                *\n\
        *   *            *   *\n\
      *  "+HIY+" *"+HIB+"   *        * "+HIY+"  *"+HIB+"   *\n\
        *   *            *   *\n\
          *                *\n\n"+NORM);
          write(HIB+"\nSparks fly from the blue wand . . . \n\n"+
"      *  "+HIY+" *"+HIB+"   *        * "+HIY+"  *"+HIB+"   *"+NORM+"\n\n");
          break;
      }
ATT->do_damage( ({ damage }), ({ "magical" }));
delayed = 1;
call_out("get_delay", 100);
return 1;
}

get_delay(){ 
remove_call_out("get_delay");
delayed = 0;
tell_object(environment(), "The wand is recharged and ready...\n");
}

query_save_flag() { 
  return 1; 
}
