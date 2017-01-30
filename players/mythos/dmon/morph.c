#include "/players/mythos/closed/ansi.h"
int based,subs,sswitch;
inherit "players/mythos/dmon/mon";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("lesser sand walker");
  set_alias("sand");
  set_race("sandwalker");
  set_short("Lesser Sand Walker");
  set_long("A Lesser SandWalker.\n"+
           "A creature made of molten silver particles.\n"+
           "Its form everchanging- a horn appears, a spine appears,\n"+
           "a wing appears, scales appear...etc.. The only unchanging\n"+
           "factor is a single white 'eye' that roves around on its\n"+
           "body....\n");
  set_level(16);
  set_hp(450);
  if(random(3) > 0) set_al(-random(1000));
  else set_al(random(500));
  set_wc(19);  /* note base = 19... so the creature ranges wc 0 - 38 and ac 
                  of 38 - 0 
                  at level 16 rules state wc 22 ac 13 -> 22 + 13 = 35
                     35/2 = 17
                  also note: that wc and ac changing spells will not effect
                  this creature 
               */
  set_ac(19);
  set_heal(10,10);
  if(random(3) > 0) set_aggressive(1);
  set_chat_chance(20);
  set_a_chat_chance(2);
  load_chat("Silver particles fly into the air...\n");
  load_chat("The SandWalker warbles.\n");
  load_chat("Sunlight glints off the molten form of the SandWalker.\n");
  load_a_chat("The SandWalker screams!\n");   
  load_a_chat("Silver particles fly at you!\n");
  set_chance(10);
  set_spell_dam(150);
  set_spell_mess1("The form of the SandWalker flows and strikes out at its enemy!\n");
  set_spell_mess2("Suddenly, Silver light flashes and\n"+
                  "searing heat pounds into you!\n"); 
  set_mult(3);
  based = 19;
  subs = 0;
  sswitch = 0;
  set_dead_ob(this_object());
}

query_prevent_shadow() { return 1; }

monster_died() {
object leave;
   switch(random(2)) {
     case 0: leave = clone_object("/obj/money.c");
             leave->set_money(1500 + random(1000));  /* with ever changing wc
                                                        and ac and multiple attacks
                                                        the amount of coinage has 
                                                        been increased to the amount
                                                        of a level 19 = 2000 */
             break;
     case 1: leave = clone_object("/players/mythos/dmisc/eye.c");
             break;
   }
  move_object(leave,this_object());
}

heart_beat() {
  ::heart_beat();
  if(!sswitch) subs++; 
  else subs--; 
  if(based < subs - 1) sswitch = 1;
  if(subs < -based + 1) sswitch = 0;
  set_ac(based - subs);
  set_wc(based + subs);
  set_mult(1 + random(4));
  set_heal(10,10);
}
