/******************/
/* Rabbit         */
/* Hogath         */
/* created 05/13  */ 
/**************** */

#include <ansi.h>;
#include "/players/hogath/tools/def.h";

inherit "/obj/monster";

string color;

reset(arg) {
    ::reset(arg);
    if (!arg)  {
       
          switch (random(4))  {
           case 0: color=HIW; break;
           case 1: color=YEL; break;
           case 2: color=WHT; break;
           case 3: color=HIY; break;
           default: color=HIW; break;
                              }
       

        set_name("Rabbit");
        set_alt_name("bunny");
        set_alias("bunny");
        set_short(color+"Rabbit King"+NORM);  
        set_race("rabbit");
        set_long(
"This is a Rabbit King.  He is by far the largest rabbit you have\n"+
"ever seen.  You should think twice before attacking him.\n");
        set_gender("male");
        set_level(15);
        move_object(clone_object("/players/hogath/area/items/rring.c"));
        init_command("wear armor");
        set_ac(10);
        set_wc(18);
        set_hp(260);
        set_al(-250);
        }
        set_chat_chance(5);
        load_chat("The "+color+"Rabbit king"+NORM+" munches on some roots.\n");
        load_chat("The "+color+"Rabbit king"+NORM+" thunders:  Who are you?!?  What do you want?!?\n");
        add_spell("wabbit teeth",
                  ""+color+"#MN# "+NORM+""+HIR+"A T T A C K S "+NORM+""+BOLD+" you.\n"+NORM+""+
                  "\n\tWith sharp pointy "+HIW+" T E E T H!"+NORM+"\n",  
                  ""+color+"#MN# "+NORM+""+HIR+"A T T A C K S"+NORM+"\n"+
                  "\n\t"+BOLD+"#TN#"+NORM+" with sharp pointy "+HIW+" T E E T H!\n",
                  25,30,"physical",6);
                  }
id(str){return (::id(str) || str == "rabbit" || str == "king" || str == "rabbit king" || str == "bunny" || str == "wabbit");} 
