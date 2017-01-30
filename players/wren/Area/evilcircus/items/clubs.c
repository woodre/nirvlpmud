	/* indian clubs, for juggling */

inherit "obj/weapon";
#include "/players/wren/ansi.h"
int b,c;

reset(arg)  {
   ::reset();
    c=5; 
    if(arg) return;

set_name("clubs");
set_alias("club");
set_short("a set of juggling clubs");
set_long("A set of juggling clubs. These look much like brightly    \n"+
         "painted bowling pins. They are balanced toward the middle \n"+
         "so that they spin. You think you can 'throw' or 'bonk' \n"+
         "opponents with them. Or maybe just 'juggle' them. \n");
set_type("club");   /*sword,knife,club,axe,bow,polearm */
set_class(12);
set_weight(1);
set_value(1000);
set_hit_func(this_object());

}

void init() {
  ::init();
  add_action("cmd_bonk","bonk");
  add_action("cmd_bonk","throw");
  add_action("juggle","juggle");
            }

weapon_hit(attacker) {
int W;
W = random(13);
if(W>9)  {
    say("The club bangs painfully on foes head.\n");
    write("You bonk your opponent painfully with the club. \n");
    return 5;
          }
return;
}

cmd_bonk(str) { 
       object targ;
if(!str) {write("Bonk what?\n"); return 1; }
       targ = present(str,environment(this_player())); 

       b=random(5);

       

       if(!targ) {write("That is not here to bonk!\n"); return 1; }

       if(c>1) {write("You start juggling the clubs...\n");
                write("Picking up speed you pass at "+capitalize(str)+"'s head\n");
                write("You grin evilly as they miss and catch it upside the head\n");
                say(capitalize(str)+" deflects an indian club with their skull\n");
       
                targ->hit_player(20);  /*damage*/
                c = c - 1;

                if(b==1) {
                write("The club bounces off and you deftly catch it. \n"); 
                c = c + 1;
                return 1; 
                         }
                return 1;
               }
                   
       if(c=1) {write("You don't want to lose the last club.\n"); return 1;}         
                return 1;
                }

juggle() {
       
     if(this_player()->query_attrib("ste") < 15) {
       write("You bungle and drop the clubs all around your feet\n");
       say(this_player()->query_name()+" attempts to juggle but bungles and drops the clubs.\n");
       return 1;
                                  }

     if(this_player()->query_attrib("ste") >=15) {
       write("You demonstrate your dexterity and masterfully spin the clubs about in a high arch.\n");
       say(this_player()->query_name()+" masterfully juggles the clubs in a complicated pattern.\n");
       return 1;
                                  }
         }
