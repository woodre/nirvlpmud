#include "/players/blue/closed/lib/color.h"
#include "/players/blue/closed/shadow/cpdefine.h"
#include "/players/blue/closed/shadow/help.h"
#include "/players/blue/closed/shadow/cost.h"



 /* #######       VARIABLES       ####### */


  /*# general #*/

int muffled, summon, i, heal_count;
string short, command_str, rep_tell;

 /*## monitor ##*/

  /*monitor_count counts in the heart_beat*/
  /*to match the variable 'monitor'. When*/
  /*matched, shadow_monitor() is executed.*/

int monitor, monitor_count;
object at_ob;

  /*## shadow points, shadow level, experience points, etc ##*/

int shpoints, shlevel, shxp, point_select, max_shp;

   /*## spell variables ##*/

object servant, follow, pearl;
int shlevel, shxp, point_select, max_shp, drain_damage, spell_time;


 
id(string str) { return str == "mark"||str == "shadow-mark"||
   str == "guild_object"; }
long() {
   write("This is the Mark of the Shadow Guild.\nType 'info help'"+
         " to see a list of help topics.\n");
}
drop() { return 1; }
get() { return 1; }
value() { return 0; }
weight() { return 0; }
query_auto_load() {
   return THIS_FILE+":"+monitor+"#"+point_select+"#"+shlevel+
                 "#"+shxp+"#"+drain_damage;
}

init_arg(str) {
    sscanf(str,"%d#%d#%d#%d#%d",monitor, point_select,
   shlevel, shxp, drain_damage);
}

update_arg(str) {
       sscanf(str,"%d#%d#%d#%d#%d#%d#",monitor,
        point_select, shlevel, shxp, shpoints, drain_damage);
   return 1;
}

query_update_arg() {
     return monitor+"#"+point_select+"#"+shlevel+"#"+shxp+"#"+
          shpoints+"#"+drain_damage;
}

reset(arg) {
   

/*
   write_file(PATH+"logs/clone",ctime(time())+"\n");
  */
   if(!arg) {

      set_light(1);
      monitor = 0;
      summon = 0;
      command_str = 0;
      drain_damage = 5;
      i = 0;
      follow = 0;
      shlevel = 1;
      heal_count = 0;
      servant = 0;
      shpoints = 7;
      monitor_count = 0;
      at_ob = 0;
      set_heart_beat(1);
      call_out("lost_mark",1);

   }
}

heart_beat() {
   object tmproom;
   heal_count += 1;
   if(heal_count > 5) {
      if(shpoints < max_shp) shpoints+=1;
      heal_count = 0;
   }
   if(monitor > 0) {
      if(!(monitor_count % monitor)) {
         shadow_monitor();
         monitor_count = 0;
      }
      monitor_count++;
   }
    if(monitor < 0 &&( ENVTO->query_attack()||(servant&&
           servant->query_attack())))
      shadow_monitor();
   if(follow&&!present(follow, ENV(ENVTO))) {
      TEOWN("You follow "+CAP(follow->query_real_name())+".\n");
      tmproom = ENV(ENVTO);
      tell_room(ENV(follow), CAP(ENVTO->query_name())+" arrives, "+
        "following "+CAP(follow->query_name())+".\n");
      move_object(ENVTO, ENV(follow));
      tell_room(tmproom, CAP(ENVTO->query_name())+" leaves, follow"+
          "ing "+CAP(follow->query_name())+".\n");
      command("look", ENVTO);
   }
}

init() {

   if(TP->query_real_name() == "renee"||TP->query_real_name() == "moria") {
      write("You are no longer a shadow due to your pking other shadows.\n"+
      "If you have any problems with this, please mail Blue.\n");
      TP->add_guild_rank(-TP->query_guild_rank());
      TP->set_guild_name("0");
      TP->add_guild_exp(-TP->query_guild_exp());
      TP->set_al_title(" ");
      destruct(TO);
      return 1;
   }
   /*# standard functions #*/
   
   add_action("muffle_me","muffle");
   add_action("repeat_tell","te");
   add_action("catch_the_tell","tell");
   add_action("catch_repeat"); add_xverb("");
   add_action("do_repeat","r");

   /* more add actions, etc.... */
   }

chain_fireball() {
   int n, cost;
   object ob, tmp;
   if(!level_check(9)) return;
   ob = first_inventory(ENVTP);
   n = 0;
   if(!time_check()) return 1;
   while(ob) {
       if(!ob->is_player()&&living(ob)&&!ob->query_pet()) {
         n+=1;
      }
      ob = next_inventory(ob);
   }
   if(n < 2) cost = 5;
      else if(n<6) cost = 4;
      else cost = 3;
   if(n==0) {
      write("There is nothing in here you can attack.\n");
      return 1;
   }
   n = 0;
   ob = first_inventory(ENVTP);
   while(ob&&less_pts(shlevel*cost)) {
      tmp = next_inventory(ob);
        if(!ob->is_player()&&living(ob)&&!ob->query_pet()) {
         if(n == 0) {
            say(CN+" raises "+query_possesive()+" hands into the air.\n");
            say("Dark purple fire pours out!!!\n");
            write("Fire shoots out of your finger tips!\n");
         }
         n+=1;
         tell_room(ENVTP, ob->short() +" is completely enveloped"+
              " by purple fire!!!\n");
         ob->hit_player(shlevel * 5);
         if(ob) ob->attack_object(TP);
      }
      ob = tmp;
   }
   spell_time = time();
   return 1;
}

drain_monster(str) {
   object att;
   if(!str) str = 0;
   if(!time_check()) return 1;
   att = get_attacker_object(str);
   if(!att)  
      return 1;
   if(!less_pts(drain_damage)) return 1;
   write("You reach out to "+att->short()+" and drain its energy.\n");
   say(CN +" reaches out to "+att->short() +" and drains its energy.\n");
   att->hit_player(drain_damage);
   spell_time = time();
   if(att&&!att->query_attack()) att->attack_object(TP);
   return 1;
}

death(str) {
   object att;
   if(!str) str = 0;
   if(!level_check(12)) return;
   if(!time_check()) return 1;
   att = get_attacker_object(str);
   if(!att) return 1;
   if(!less_pts(70)) return 1;
   write("Ok.\n");
   tell_room(ENVTP, att->short() +" is surrounded by darkness!\n");
   tell_room(ENVTP, "You hear a hideous scream.\n");
   att->hit_player(85);
   TP->hit_player(15);
   spell_time = time();
   if(att&&!att->query_attack()) att->attack_object(TP);
   return 1;
}

get_attacker_object(string str) {
   object att;
   if(!str&&!TP->query_attack()) {
      write("What are you going to attack?\n");
      return 0;
   }
   if(!str || str == "0") att = TP->query_attack();
      else att = present(str, ENVTP);
   if(!att) {
      write("There is no "+str+" here.\n");
      return 0;
   }
   if(!living(att)) {
      write("That is not a living thing!\n");
      return 0;
   }
   if(!att->query_npc()) {
      write("You cannot use guild spells on players.\n");
      return 0;
   }
   if( TP->query_attack() && att != TP->query_attack()) {
      write("You are already attacking something else.\n");
      return 0;
   }
   return att;
}

