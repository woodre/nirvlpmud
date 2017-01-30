/* This is armor that does nothing by itself, if it is used with the Legendary
   spear of yelm it gives the weapon a special */

inherit "obj/armor";
#include "/players/jareel/ansi.h"
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())

string *Armor_pieces;


     reset() {
       
       set_name("elite armor");
       set_alias("armor");
       set_short(RED+"["+BOLD+YEL+"Yelmalian"+NORM+RED+"]"+BOLD+YEL+" Elite Platemail"+NORM);
       set_long(
         "This armor is very well crafted the golden glow reflects\n"+
         "the surounding light.  A sun has been crested in the middle\n"+
         "of the chest.  The Plate emits a lot of light.\n");
       set_ac(5);
       set_light(2);
       set_type("armor");
       set_weight(3);
       set_value(6500);
       Armor_pieces = ({ "yelm_spear" });
}

status id(string arg) { return ( ::id(arg) || arg == "elite_armor" || arg == "armor" || arg == "elite plate" || arg == "plate"); }

status check_full_set() {
  int i;

  i = sizeof(Armor_pieces);

  while(i--) {
    object t;
    t = present(Armor_pieces[i], USER);

    if (!t || !((status)t->query_wielded()))
      return 0;
  }
  return 1;
}

string short() {

  if (check_full_set())
    return (RED+"["+NORM+HIY+environment()->query_name()+NORM+RED+"]"+NORM+HIY+" Elite Platemail "+NORM+BOLD+" ("+NORM+HIG+"Set of the Sun"+NORM+BOLD+")"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return(RED+"["+NORM+HIY+environment()->query_name()+NORM+RED+"]"+NORM+HIY+" Elite Platemail"+NORM+" (worn)");

  return RED+"["+NORM+HIY+environment()->query_name()+NORM+RED+"]"+NORM+HIY+" Elite Platemail"+NORM+NORM+NORM;
}


     do_special(owner) {
       int i;
         if (random(100) > 33) /* It only hits 33% of the time is a weapon special that requires the wep and armor worn */
           return 0; 
         i = sizeof(Armor_pieces);
           while(i--) {
             object t;
         t = present(Armor_pieces[i], USER);
           if (!t || !((status)t->query_wielded()))
         return 0;
  }

     if(ATT->is_npc())
       ATT->heal_self(-(5+random(5)));
     else ATT->add_hit_point(-(5+random(5)));

       tell_room(environment(USER),   
""+BOLD+"The legendary spear of Yelm unleashes itself...."+NORM+"\n"+
"\n");

       tell_room(environment(USER),
"                                                       "+BOLD+HIY+" ,___  ____"+NORM+"\n"+
"            "+YEL+".__________________    ______________    "+BOLD+HIY+"__/   /__\\  '\\"+NORM+"\n"); 

tell_room(environment(USER),
"            "+YEL+"||_"+HIY+"\\"+NORM+YEL+"_"+HIY+"\\"+NORM+YEL+"_"+HIY+"\\"+NORM+YEL+"_"+HIY+"\\\\"+NORM+YEL+"________"+MAG+"|==|"+YEL+
"__"+HIY+"\\"+NORM+YEL+"__"+HIY+"\\"+NORM+"");
tell_room(environment(USER),
""+YEL+"__"+HIY+"\\"+NORM+YEL+"_____"+MAG+"|==|"+BOLD+HIY+"__ "+RED+"---"+HIY+"___"+RED+"  --"+BOLD+HIY+" >"+NORM+"     \n");

tell_room(environment(USER),
"                                                       "+BOLD+HIY+"\\___\\  /__,/"+NORM+" \n"+
"\n");

tell_room(environment(USER),
"\n"+
"\n");

tell_room(environment(USER),
""+BOLD+"                                                 .........Solar energy burns flesh"+NORM+"\n");  

  return 100;
}
