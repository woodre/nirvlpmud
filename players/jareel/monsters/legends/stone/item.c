#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())

     reset(arg) {
       ::reset(arg);

     set_name("crystaline helm");
     set_ac(2);
     set_value(2000);
     set_weight(2);
     set_type("helmet");
     set_short(
       "Crystaline helm");
     set_long(
       "\n"+
       "\n"+
       "\n"+
       "\n");
     }

do_special(owner) {
   int i;
   
   i = random(3);
     if(!ATT) return;
       if(i==0){
      tell_room(environment(USER),
         capitalize(USER->query_name())+" crystaline helm glows with power.\n", ({ USER }));
      tell_object(USER, "Your crystaline helm glows with power.\n");
        this_player()->add_stuffed(-1);
        this_player()->add_soaked(-1);
      return 0;}
   return 0; }

do_stone_special(object owner)
{
   if(!random(20))
      {
      object bug, dis, poi;
        bug = present("flu",this_player());
        dis = present("disease",this_player());
        poi = present("poison", this_player());
      if(dis) {
        write("The helm covers you with a glowing aura, eradicating the disease!\n");
          destruct(dis);
      }
      if(bug) {
        write("The helm covers you with a blue aura, cleansing your body!\n");
          destruct(bug);
      }
      if(poi) {
        write("The helm glows a bright red and destroys a poison!\n");
          destruct(poi); 
      }
    }
}
