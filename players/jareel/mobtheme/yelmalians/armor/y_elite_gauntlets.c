inherit "obj/armor";
#include "/players/jareel/ansi.h"
#define USER environment(this_object())
#define ATT USER->query_attack()
object ob;

     reset() {
       set_name("Elite Platemail");
       set_alias("battle armor");
       set_short(RED+"["+BOLD+YEL+"Yelmalian"+NORM+RED+"]"+BOLD+YEL+" Elite Battle Armor"+NORM);
       set_long(
         "The Yelmalian gauntlets are crafted the golden metel.  One\n"+
         "inch spikes protrude from the knuckles, the gauntlets look \n"+
         "like they would provide quite a wallop.\n");
       set_ac(1);
       set_light(1);
       set_type("armor");
       set_weight(1);
       set_value(1200);
       }

     short(){
       string heh;
         heh = ""+RED+"["+BOLD+YEL+"";
           if(environment()){
           if(environment()->is_player()) heh += environment()->query_name()+NORM+RED+"] "+BOLD+YEL+"Elite Battle Armor"+NORM+" ";
           else heh += "Yelmalian"+NORM+RED+"]"+NORM+BOLD+YEL+" Elite Battle Armor"+NORM;
       }

       else heh += "Yelmalian"+NORM+RED+"]"+NORM+BOLD+YEL+" Elite Battle Armor"+NORM;
       /*if(broke) heh += " [BROKEN]";
         if(wielded) heh += " (wielded)";*/
         if(worn) heh += " (worn)";
       return heh;
       }

     do_special(owner) {
       int i;
         i = random(10);
           if(i==1){
             if(ATT->is_npc())
               ATT->heal_self(-(1+random(3)));
             else ATT->add_hit_point(-(1+random(3)));
               tell_room(environment(USER),
               CAP(ATT->query_name())+" is cut open by spiked gauntlets.\n"+
               ""+ATT->query_name()+"'s "+RED+"blood"+NORM+" flows from an open gash.\n");
     return 0;}
     return 0;}
