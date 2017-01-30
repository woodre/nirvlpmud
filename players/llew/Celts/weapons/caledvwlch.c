#include "/players/llew/closed/ansi.h"

inherit "obj/weapon";
int xhit;
string atta_name;

reset(arg) {
if(!arg) {
   xhit=0;
   set_id("caledvwlch");
   set_name(BOLD+"Caledvwlch"+NORM);
   set_class(20);
   set_weight(3);
   set_value(2000);
   set_alt_name("caledvwlch");
   set_alias("sword");
   set_short(BOLD+"Caledvwlch"+NORM);
   set_long("A bright longsword which is extremely sharp and never dulls.\n");
   set_light(1);
   set_hit_func(this_object());
   }
}

query_wear() { return 1; }
weapon_breaks() { return 1; }

weapon_hit(attacker) {
   int W;
   W=random(100);

   if(W-(xhit/2) < 0) {
      int dam;
      tell_room(environment(this_player()),BOLD+"Caledvwlch "+NORM+"explodes with light covering "+attacker->query_name()+" and burning your hands.\n");
      tell_room(environment(this_player()),BOLD+"\n\t\t           *\n\n\t\t           *\n"+
         "\t\t      *         *\n\t\t           *\n"+
         "\t\t        *     *\n\t\t          * *\n"+
         "\t\t*  *  *  *   *  *  *  *\n\t\t          * *\n\t\t        *     *\n\t\t           *\n\t\t      *         *\n\t\t           *\n\n\t\t           *\n\n");
      tell_room(environment(this_player()),NORM);
      dam=random(22);
      attacker->heal_self(-dam);
      environment(this_object())->heal_self(-(2*dam)/5);
      xhit=0;
      return 10;
   }

   if(W>84) {
      tell_room(environment(this_player()),"White light flows from "+BOLD+"Caledvwlch "+NORM+"into "+attacker->query_name()+".\n");
      xhit++;
      return 5;
   }
   if(W>74) {
      tell_room(environment(this_player()),"Light arcs down the blade of "+BOLD+"Caledvwlch "+NORM+"engulfing "+attacker->query_name()+".\n");
      xhit+=2;
      return 7;
   }

   /*  If attacker has less than 7.5% hp left and less than 50 hp and 
       it has enough extra hit energy stored it will reduce the monster 
       to 0 hitpoints, but it will dest everything in the inventory and 
       the corpse as well.
   */

   if(W>59 && xhit > 10 && attacker->query_hp() < ((3*attacker->query_mhp())/40) && attacker->query_hp() < 50) {
      object *ob1;
      int n;
      tell_room(environment(this_player()),"A pure shaft of blazing light descends from the heavens disintigrating "+attacker->query_name()+" where it stands.\n");
      tell_room(environment(this_player()),BOLD+"\n\t\t   |   |\n"+
         "\t\t   |[ ]|\n"+
         "\t\t   |[*]|\n"+
         "\t\t   |[*]|\n"+
         "\t\t   |[*]|\n"+
         "\t\t   |[*]|\n"+
         "\t\t   |[*]|\n"+
         "\t\t*  |[*]|  *\n"+
         "\t\t * |[*]| *\n"+
         "\t\t  *|[*]|*\n"+
         "\t\t   *****\n"+
         "\t\t***********\n"+
         "\t\t    ***\n\n"+NORM);
      atta_name=attacker->query_real_name();
      attacker->hit_player(attacker->query_hp()-1);
      attacker->heal_self(-attacker->query_hp());
      ob1=all_inventory(attacker);
      attacker->transfer_all_to("players/llew/Celts/misc/dest_object");
      call_out("death_dest",1);
      xhit=0;
      return 20;
   }
}

death_dest() {
   if(present("corpse of "+atta_name,environment(environment(this_object())))) {
      destruct(present("corpse of "+atta_name,environment(environment(this_object()))));
      transfer(clone_object("/players/llew/Celts/weapons/caled_dust.c"),environment(environment(this_object())));
   }
   else call_out("death_dest",1);
}
