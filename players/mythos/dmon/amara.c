/*  10/08/06 - Rumplemintz: moved inherit above #include statements  */
inherit "players/mythos/dmon/mon";
#include "/players/mythos/closed/ansi.h"
#include "/players/beck/MortalKombat/MKQuestNPC.h"
mixed nulled;
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("amara");
  set_alias("defender");
  set_race("avatar");
  set_short("Amara- Defender of the Sands");
  set_long("Before you stands a woman wearing a blood red robe.\n"+
           "She stands with a haughty air and calmly looks you over.\n"+
           "She then whispers: Be gone, intruder upon the Sacred Sands.\n"+
           "                   Else feel the wrath of a Defender!\n");
 set_level(25);
  set_hp(1200);
  set_al(0);
  set_wc(40);
  set_ac(17);
  set_heal(5,17);
  if(random(2)==0) set_aggressive(1);
  set_gender("female");
  set_chat_chance(20);
  set_a_chat_chance(2);
  load_chat("Amara chants quietly.\n");
  load_chat("Sand blows around.\n");
  load_a_chat("Amara lashes out with her staff!\n");   
  load_a_chat("Sand blows everywhere.\n");
  set_chance(20);
  set_spell_dam(500);
  set_spell_mess1("Amara shouts and the wind blasts into her enemy!\n");
  set_spell_mess2("Amara shouts and a great wind blows sand everywhere!\n"+
                  "The sand strikes you and cuts into you.\n"); 
  set_mult(2);
  set_dead_ob(this_object());
  nulled = ({});
  move_object(clone_object("/players/dragnar/MKScar/scar.c"),this_object());
}

query_prevent_shadow() { return 1; }

monster_died() {
object leave;
   switch(random(2)) {
     case 0: leave = clone_object("/obj/money.c");
             leave->set_money(3000 + random(2000));
             break;
     case 1: leave = clone_object("/players/mythos/darmor/skin.c");
             break;
   }
  move_object(leave,this_object());
}

hit_player(dam,zap) {
int damm;
  damm = dam;
  damm = damm/2;
  :: hit_player(damm,zap);
}

heal_self(n) {
int h;
  h = n;
  if(h < 0) h = h/2;
  ::heal_self(h);
} 

init() {
#ifndef __LDMUD__
 add_action("nulls");add_xverb("");
#else
  add_action("nulls", "", 3);
#endif
}

nulls(str) {
  if(!str) return 0;
  if(member_array(str,nulled) == -1) {
    nulled += ({str});
    nulled += ({1});
  }
  else {
     if(nulled[member_array(str,nulled) + 1] > 5) {
       if(random(100) < 5+nulled[member_array(str,nulled) + 1]) { 
         write("Amara smiles at you and you find that \n"+
               "you can not do that action.\n");
       return 1; } 
     } 
       nulled[member_array(str,nulled) + 1] = nulled[member_array(str,nulled) + 1] + 1;
   }
}
