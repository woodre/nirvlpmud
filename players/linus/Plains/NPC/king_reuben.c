#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/monster.c";
#define moose this_object()->query_attack()
#define moosen capitalize(moose->query_name())
int i;
object wep;
id(str) { return str=="king reuben" || str=="king" || str=="reuben" || str=="spirit"; }
reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_name("King Reuben");
 set_short("King Reuben");
 set_long(
 "  King Reuben was the most powerful man in all of Celestia.  He was a\n"+
 "great king and loved by his people.  King Reuben shared his realm with\n"+
 "his beautiful wife, Queen Delencia.  Unfortunately Delencia fell ill, and\n"+
 "passed away at an early age.  Reuben was devastated.  He maintained rule\n"+
 "of the kingdom for several more years, but grief overcame him, and he took\n"+
 "his own life.  Anthazar, Reuben's personal assistant, cast a spell over\n"+
 "his body, preserving it.  He also laid a curse on the chamber, such that\n"+
 "if anyone disturbs it, King Reuben's spirit will rise once again.\n");
 set_level(27);
 set_hp(1500+random(205));
 set_wc(45);
 set_wc_bonus(25+random(35));
 set_ac(24);
 set_heal(20,8);
 wep=CO("/players/linus/Plains/obj/ensword.c");
     MO(wep,TO);
 set_dead_ob(this_object());
 set_chance(15);
 set_spell_dam(50+random(55));
 set_spell_mess1("King Reuben strikes his attacker with his "+BYEL+MAG+"enchanted"+NORM+" sword.");
 set_spell_mess2("King Reuben strikes you with his "+BYEL+MAG+"enchanted"+NORM+" sword.");
}
heart_beat(){
 ::heart_beat();
  if(attacker_ob){
  i = random(50);
    switch(i){
    case 0..5: whap_whap();break;
    case 6..25: return 0;break;
    case 26..29: mega_ouch();break;
    case 30..40: return 0;break;
    case 41..45: help_me();break;
    case 46..49: hit_everyone();break;
  }
 }
}
whap_whap(){
if((attacker_ob) && (attacker_ob->query_ghost())) return;
tell_room(ENV(TO),"\n  King Reuben raises his hand.\n\n   Magical energies flow from "+attacker_ob->query_name()+"\n\n",({ attacker_ob }));
tell_object(attacker_ob,"\n  King Reuben raises his hand.\n\n   Magical energy flows from you!\n\n");
if((attacker_ob->query_npc()) && (attacker_ob->query_sp() >=25))
attacker_ob->heal_self(-20-random(20));
else
attacker_ob->add_spell_point(-20-random(30));
}
mega_ouch() {
 if((attacker_ob) && (attacker_ob->query_ghost())) return;
tell_room(ENV(TO),"\n  King Reuben "+HIB+"C H A R G E S"+NORM+" at "+attacker_ob->query_name()+",\n\n     severely mutilating "+attacker_ob->query_objective()+".\n\n",({ attacker_ob}));
tell_object(attacker_ob,"\n  King Reuben "+HIB+"C H A R G E S"+NORM+" at you,\n     severely mutilating you!\n\n");
if(attacker_ob->query_npc())
 attacker_ob->heal_self(-100-random(101)); else
 attacker_ob->hit_player(100+random(101));
}
help_me() {
  object mon;

  /* This will move a mob that is aggressive to the person that's 
   * tanking the big mob himself into the room, and set him to attack
  */

  mon=CO("/players/linus/Plains/NPC/assist_spirit.c");
  move_object(mon,environment(this_object()));
  tell_object(attacker_ob,"Reuben says a small prayer.\n  "+HIM+"  A spirit comes to his aid!\n"+NORM);
   say("Reuben says a prayer.\n\n    "+HIM+"A spirit comes to his aid!\n"+NORM, attacker_ob);
  mon->attacked_by(attacker_ob);
 mon->set_master(TO);
}

hit_everyone() {
/* Jaraxle is god */
   object *inv;
   int blah, i;
   inv = all_inventory(environment());
   blah = sizeof(inv);
  tell_room(ENV(moose),
   "King Reuben takes a mighty swing with his "+BYEL+MAG+"enchanted sword"+NORM+"\n"+
   "  destroying all that comes in contact with it.\n");
   for(i = 0; i < blah; i++)
   {
      if(inv[i]->query_name() != "King Reuben")
         {
         if(living(inv[i]))
            {
          tell_object(inv[i], "King Reuben's "+BYEL+MAG+"enchanted sword"+NORM+" sears your flesh as it passes.\n");
            inv[i]->hit_player(25 + random(25));
         }
       }
   }
}  
/*  [ End of borrowed code. ]  */

monster_died() {
 object corpse;
 corpse = present("corpse",environment(TO));
 tell_room(environment(TO),"Something drops to the ground as the skeleton crumbles into a pile of dust.\n\n"+HIY+
 "       * *  F L A S H  * *\n"+NORM+"\n          The glow of the eyes fades away.\n");
 MO(CO("/players/linus/Plains/obj/skull.c"),environment(TO));
 if(corpse) destruct(corpse);
 return 1;
}
