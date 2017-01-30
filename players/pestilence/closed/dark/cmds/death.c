#include "/players/pestilence/ansi.h"

main(){
        object target, comp, USER;
        int spamount, here;
        int cost;
        int gr;
        USER = this_player();
        if(USER->query_ghost()) return 0;
if(this_player()->query_guild_rank() < 2){ write("You can't use ability yet.\n"); return 1; }
        if(!USER->query_attack()){
                tell_object(USER,
                "You can only do this in combat!\n");
                return 1;
        }
   if(!USER->query_weapon()){
      tell_object(USER,
      "You must have a weapon wielded!\n");
      return 1;
      }
        target = USER->query_attack();
        if(!target->query_npc()){
                tell_object(USER,
                "You cannot do this to players!\n");
                return 1;
        }
   if(!living(target)){
      tell_object(USER,
      "That didn't work.\n");
      return 1;
      }
        cost = target->query_hp()/3;
        if(cost > USER->query_sp()){
                tell_object(USER,
                "You are too weak.\n");
                return 1;
        }
        
        if(USER->query_attack() && target->query_hp() < 60){
         if((target->query_hp()*10)/(target->query_mhp()) < 1){
        
/*
tell_object(USER,
HIK+"You pierce your opponent's heart with a solid blow"+HIW+"..."+NORM+"\n\n"+
HIR+"                   |          |          |\n"+
HIR+"               -"+HIW+"     ["+HIR+"  D  E  A  T  H"+HIW+"  ]"+HIR+"    - "+NORM+"\n"+
HIR+"                   |          |          |\n"+
target->query_name()+" crumbles from your blow!\n"+NORM);
*/
here = environment(this_player());

tell_room(here,
HIK+"\n               ...\n"+
HIK+"             ;::::;\n"+
HIK+"           ;::::; :;\n");
 tell_room(here,HIK+"        ;:::::'   :;\n"+
HIK+"        ;:::::;     ;.\n"+
HIK+"       ,:::::'       ;           OOO\\ \n");
tell_room(here,HIK+"       ::::::;       ;          OOOOO\\\n"+
HIK+"       ;:::::;       ;         OOOOOOOO\n"+
HIK+"      ,;::::::;     ;'         / OOOOOOO\n");
 tell_room(here,HIK+"   ;:::::::::`. ,,,;.         /  / DOOOOOO\n"+
HIK+"  .';:::::::::::::::::;,     /  /     DOOOO\n");
tell_room(here,HIK+" ,::::::;::::::;;;;::::;,   /  /        DOOO\n"+
HIK+";`::::::`'::::::;;;::::: ,#/  /          DOOO\n"+
HIK+":`:::::::`;::::::;;::: ;::#  /            DOOO\n");
tell_room(here,HIK+"::`:::::::`;:::::::: ;::::# /              DOO\n"+
HIK+"`:`:::::::`;:::::: ;::::::#/              "+HIR+" DOO\n"+
HIK+" :::`:::::::`;; ;:::::::::##              "+HIR+"  OO\n");
tell_room(here,HIK+" ::::`:::::::`;::::::::;:::#              "+HIR+"  OO\n"+
HIK+" `:::::`::::::::::::;'`:;::#               "+HIR+" O\n"+
HIK+"  `:::::`::::::::;' /  / `:#\n");
 tell_room(here,HIK+"  ::::::`:::::;'  /  /   `#"+NORM+"\n");
   
   tell_room(here,"\n"+target->query_name()+" crumbles from "+USER->query_name()+"'s blow!\n");
                USER->add_spell_point(-cost);
                    if(target)
                        target->death();
                        return 1;
                }
                tell_object(USER, "Your opponent is still too strong.\n");
                return 1;
        }
        tell_object(USER, "Your opponent is still too strong.\n");
        return 1;
}
