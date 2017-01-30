/* approved by Mythos on <6-19-96>
   if anyone has a problem with this monster 
  please contact me (mythos)
*/
#include <ansi.h>

inherit "obj/monster";

int big_att;

reset(arg) {
   string adj;
   int money_crystals;
   money_crystals=0;
   big_att=0;
   ::reset(arg);
   if(arg) return;
   adj=({"grotesque","deformed","squat","mutated","bloody","writhing","black","green",
      "rippling","irate","snivelling","decayed","screaming","horrible","putrid",
      "smelly","yellow","rotting","horned","huge","barbed","infuriated","maniacal",
      "pestulent","scaled","angry","insane","wailing","psychotic","deranged","cackling"});
   set_name("xetra");
   set_level(20);
   set_race("demon");
   /*raised Base hp by 300 points and random by 100-Sami-*/
   set_hp(random(400)+700);
   set_al(-500-random(600));
   set_aggressive(1);
   set_short("A "+adj[random(sizeof(adj))]+" Xetra");
   set_long("\tA Xetra sucking the light from all around.  Bigger and bigger he\n"+
      "becomes with each particle of blue light.  The light touches the skin of the\n"+
      "Xetra and fades to nothing.\n");
/* Wimpy added by Snow 4/99 as these monsters are being massacred */
  if(random(2)) set_whimpy();
   set_wc(random(18)+20);
   set_wc_bonus(24);
   set_ac(random(8)+12);
   /* Set resistances to Fire, and Evil, since it is a "Demon" and needs to be stronger-Sami-*/
   set_armor_params("other|evil",0,20,0);
   set_armor_params("other|fire",0,20,0);
   set_dead_ob(this_object());
   set_message_hit(({"mutilated"," to a pulpy red mass","slashed"," spraying the room with blood","thrashed"," with blood dripping claws","sliced"," cleanly","cut","","grazed","","scratched"," a glancing blow"}));
   set_chance(10);
   set_spell_mess2("The Xetra reaches into your soul with icy fingers.\n"+
      "Cold evil invades your blood, draining your life.");
   set_spell_mess1("The Xetra eats at a soul.");
   set_spell_dam(20);
   set_a_chat_chance(10);
   load_a_chat("The Xetra eats the blue light.\n");
   load_a_chat("Xetra says:  Hurocdt rufk tri!\n");
   load_a_chat("Xetra says:  Tlurrk bsiri corr.\n");
   load_a_chat("The Xetra reaches for your soul.\n");
     add_spell("hell_fire",
    "#MN# engulfs you in "+HIR+"hellfire"+NORM+".\n",
    "#TN# is quickly engulfed by #MN#'s "+HIR+"hellfire"+NORM+".\n",
   20,({20,20}),({"other|fire","other|evil"}),1);
   while(!random(money_crystals/2)) {
      move_object(clone_object("/players/llew/closed/crystal/money_crystal"),this_object());
      money_crystals++;
   }
}

heart_beat() {
   object *ri,first;
   object here;
   int X,x,so,ba;
   if(!this_object() || !environment()) return;
   if(big_att || !random(12)) {
      if(attacker_ob && environment(attacker_ob) == environment()) {
         here = environment();
         switch(big_att) {
            case 0: 
               tell_room(environment(),BOLD+"The Xetra stops fighting.\n"+NORM);
               big_att++;
               break;
            case 1:
               tell_room(environment(),BOLD+"The Xetra sucks in the "+HIC+"Blue"+NORM+BOLD+" light.\n"+NORM);
               big_att++;
               break;
            case 2:
               big_att++;
               break;
            case 3:
               tell_room(environment(),BOLD+"The Xetra unleashes all its rage!\n"+NORM);
               tell_room(environment(),RED);
               for(big_att=5+random(6),ba=0;ba<big_att;ba++) {
                  already_fight=0;
                  attack();
               }
               tell_room(here,NORM);
               big_att=0;
               break;
         }
         return;
      }
/* Temporary fix for players running out and missing this attack -
 * this attack being one of the reasons this monster is approved */
   else if(big_att < 3) big_att = 3;
   }

   ::heart_beat();
   /*  Didn't like spells that made them attack themselves.  
         I gave it a little bit of chance before they retaliate,
         and it does leave them disoriented.   */
   if(attacker_ob==this_object() && !random(3)) {
      object rob;
      tell_room(environment(),"The xetra screams in rage!\n");
      rob=first_inventory(environment());
      attacker_ob=0;
      while(!attacker_ob && rob) {
         if(living(rob) && rob->query_race() != "demon") {
            attacker_ob=rob; }
         else rob=next_inventory(rob);
      }
   }
   first=attacker_ob;
   if (environment()) {
   for(x=0,ri=all_inventory(environment()),so=sizeof(ri);so>x;x++) {
      /*  Here it checks everything in the room to see if its attacking.
         It switches back to the original attack when it's done.
*/
  if(ri[x]) if(living(ri[x]))
      if(ri[x]->query_attack() == this_object() && ri[x] != first && ri[x]->is_player()) {
         already_fight=0;
         attack_object(ri[x]);
         attack();
      }
/* Added by Vertebraker [5.24.01] */
         if(first)
         attack_object(first);
   }
   /*  The multi hits per round.  Each time it hits the chance it hits again is reduced. */
   X=2;
   while(!random(X)) {
      already_fight=0;
      attack();
      X++;
   }
  }
}

monster_died() {
   say("The Xetra screams in agony as light explodes from it's dying body.\n"+
      "A small fragment of light falls to the ground where it stood.\n");
   move_object(clone_object("/players/llew/closed/crystal/fragment.c"),environment(this_object()));
}

/* Reduces chance of players running in and out without taking damage -Snow 3/99 */
hit_player(arg) {
  if(!attacker_ob) return 0;
  return ::hit_player(arg); }
