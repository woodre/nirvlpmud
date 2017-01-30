/* Coded for Forbin's prison.  4/25/02 */
/*  Jaraxle  */

#include "/players/jaraxle/define.h"
#define moose this_object()->query_attack()
#define moosen capitalize(moose->query_name())
#define dam_count query_dam_taken_this_round()
inherit "/players/vertebraker/closed/std/monster.c";
reset(arg)  
{
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name("Xen"+HIG+"-"+NORM+"Xion");
   set_alias("xenxion");
   set_alt_name("cave_mob");
   set_race("alien");
   set_aggro(1, 10, 90);
   set_short("Xen"+HIG+"-"+NORM+"Xion, Coorquak "+HIR+"Champion"+NORM);
   set_long("  Xen"+HIG+"-"+NORM+"Xion is the ultimate "+HIR+"Champion"+NORM+" from the Coorquak clan.\n"+
      "It has six lenghty "+BLK+BOLD+"tentacles"+NORM+" that sway elegantly behind its back.\n"+
      "It's skin, reflective in nature, has a distinct combonation of blue\n"+
      "and green hues.  It has enormous hands with large metallic talons\n"+
      "for fingers and long, deep black hair that is braided in strands.\n"+
      "It is without eyelids, eyes; black as onyx, deep as any black-hole,\n"+
      "and sparkling with wetness, glare stonely forward.\n");  
   set_level(25);
   set_hp(1000+random(150));
   set_al(0);
   set_wc_bonus(72);

   /* Total: hit_player(75)* 55% = 41.25  + 122/4 (random damage of 4 spells) * 55% = 30.5 
   for wc_bonus of 71.75 or 72.  */

   set_ac_bonus(11);

   /* Total: heal_self 30% chance for total damage taken+random total damage take
   in a round of combat if over 30points of damage taken.  This was a little harder to
   calculate - 30*30%*2 = 19. That's the bare minimum, if damage is at 30 w/o calculating the
   random.  I put it at 11 for playability sake, after continuous testing w/ a 19+5 player
   solo, using sonic & wc20 weapon he healed about 50 each time it went off which = 15.
   */

   set_ac(24+random(5));
   set_aggressive(0);
   set_wc(45+random(6));
   set_dead_ob(this_object());
   set_chat_chance(4);
   load_chat("Xen"+HIG+"-"+NORM+"Xion breathes heavilly.\n");
   MOCO("/players/jaraxle/closed/forbin/mon_heal.c"),TO);
}

monster_died() {
   object b, c;
   c = present("corpse", environment());
   if(c){
      destruct(c);
      b = clone_object("/players/jaraxle/closed/forbin/body.c");
      b->set_name(cap_name);
      b->set_long("This is the dead body of Xen"+HIG+"-"+NORM+"Xion.  Legend has it that\nthe corpses of the Coorquak held treasures abound.\n");
      move_object(b, environment());
   }
   write_file("/players/jaraxle/closed/forbin/killed.log",ctime(time())+" "+HIB+""+this_player()->query_name()+""+NORM+" killed Xen"+HIG+"-"+NORM+"Xion.\n");
   tell_room(environment(this_object()),
      "Xen"+HIG+"-"+NORM+"Xion crashes heavilly to the ground.\n");
   return 0; }     


spec1(){
   
   string ATT_NAME,msg;
   int total_damage, i;
   string hit_type;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   say("\nXen"+HIG+"-"+NORM+"Xion's "+BLK+BOLD+"tentacles"+NORM+" scream at "+ATT_NAME+"...\n");
   for(i = 0; i < 6; i++) {
      switch(random(7)){
         case 0: hit_type = ""+HIB+"lashes"+NORM+"";
         total_damage +=14;
         break;
         
         case 1: hit_type = ""+HIY+"slashes"+NORM+"";
         total_damage +12;
         break;
         
         case 2: hit_type = ""+HIC+"slices"+NORM+"";
         total_damage +=9;
         break;
         
         case 3: hit_type = ""+HIG+"thrashes"+NORM+"";
         total_damage +=8;
         break;
         
         case 4: hit_type = ""+HIM+"whips"+NORM+"";
         total_damage +=5;
         break;
         
         case 5: hit_type = ""+HIR+"welts"+NORM+"";
         total_damage +=3;
         break;
         
         case 6: hit_type = ""+HIW+"misses"+NORM+"";
         total_damage +=0;
         break;
       }
      
      say("\tA "+BLK+BOLD+"tentacle"+NORM+" "+hit_type+" at "+ATT_NAME+"\n");
   }
   
   attacker_ob->hit_player(total_damage);
   /*
   say(HIY+"\t Damage: "+HIR+total_damage+NORM+"\n");
   */
   
}

spec2(){
   string ATT_NAME,msg;
   int total_damage, i;
   string body_part;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   for(i = 0; i < 1 + random(6); i++)
   {
      switch(random(6)){
         case 0: body_part = "foot";
         total_damage +=2;
         break;
         case 1: body_part = "thigh";
         total_damage +=5;
         break;
         case 2: body_part = "chest";
         total_damage +=8;
         break;
         case 3: body_part = "arm";
         total_damage +=10;
         break;
         case 4: body_part = "stomach";
         total_damage +=12;
         break;
         case 5: body_part = "bicept";
         total_damage +=3;
         break;
       }
      say("A "+BLK+BOLD+"tentacle"+NORM+" "+RED+"stabs"+NORM+" into "+ATT_NAME+"'s "+body_part+"!\n");
      /*
      say(HIY+"\t Damage: "+HIR+total_damage+NORM+"\n");
      */
   }
      attacker_ob->hit_player(total_damage);
}


/* [ Borrowed from Fred's Bloodknight, w/ permission ] */
/* Thanks Fred.  [ J ] */

spec3(){
   object *inv;
   int lil_doggy, i;
   inv = all_inventory(environment());
   lil_doggy = sizeof(inv);
   tell_room(environment(moose),
      "Xen"+HIG+"-"+NORM+"Xion roars in "+RED+"rage"+NORM+"!\n"+
      "\tXen"+HIG+"-"+NORM+"Xion's "+BLK+BOLD+"tentacles"+NORM+" angrily lash around the room . . .\n"); 
   tell_room(environment(moose),
      ""+HIR+"\t\tflaying"+NORM+" any "+HIR+"flesh"+NORM+" they come in contact with!\t\n\n");
   for(i = 0; i < lil_doggy; i++)
   {
      if(inv[i]->query_name() != "Xen-xion")
         {
         if(living(inv[i]))
            {
            tell_object(inv[i], "\t"+BRED+HIW+"A wild tentacle cuts into your skin leaving a deep burning sensation."+NORM+"\n");
            inv[i]->hit_player(50 + random(25));
         }
       }
   }
}  
/*  [ End of borrowed code. ]  */

spec4(){
   string ATT_NAME,msg;  if(attacker_ob) 
      ATT_NAME = attacker_ob->query_name();
   say("Xen"+HIG+"-"+NORM+"Xion hacks "+ATT_NAME+"'s chest maliciously with both clawed hands!\n");
   say(HIW+"\t --                 --\n"+
      "\t    --           --\n");
   say("\t       --    --\n"+
      "\t          -"+HIR+"-\n"+
      "\t       --    --\n");
   say("\t    --           --\n"+
      "\t --                 --\n"+NORM);
   say(HIW+"~ "+NORM+RED+"Blood seeps from deep gashes in "+ATT_NAME+"'s chest. "+HIW+"~\n"+NORM);
   attacker_ob->hit_player(25+random(36));
}

void heal_special(int dmg)
{
   if(dmg == 0) return;
   
   else if(dmg > 25)
      this_object()->heal_self(dmg+random(dmg));
   tell_room(environment(), ""+BGRN+HIY+"\tXen-Xion gurgles, writhing in pleasure."+NORM+"\n");
   /*
   tell_room(environment(), ""+HIB+"Healed: "+HIW+dmg+NORM+"\n");
   */
   dmg =0;
}

heart_beat(){
   int i;
   ::heart_beat();
   if(attacker_ob && present(attacker_ob, environment())) {
      i = random(21);
      switch(i){
         
         case 0..2: spec1();
         break;
         
         case 3..8: spec2();
         break;
         
         case 9..10: spec3();
         break;
         
         case 11..14: spec4();
         break;
         
         case 15..20: return 0;
         break;
      }
   }
}
