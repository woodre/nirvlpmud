/* 
 * Forbin
 * Created:   2003.09.03
 * Last edit: 2003.09.08 -forbin
 * Change log:
 */

#include "/players/forbin/define.h"
inherit "/players/vertebraker/closed/std/monster.c";
#define ROOT "/players/snow/dervish/trials/trial1/"

int asked;
int injured;

id(str) { return (::id(str) || str == "man"); }

reset(arg) {
  object gold;
  ::reset(arg);
  if(arg) return;

  set_name("a thin man");
  set_race("human");
  set_gender("male");
/*  set_short("Murwallabi the Expedition Guide "+RED+"("+NORM+"injured"+RED+")"+NORM); */
  set_short("A thin man "+RED+"("+NORM+"injured"+RED+")"+NORM);
  set_long("\n");
  set_level(15);
  set_hp();
  set_wc();
  set_wc();
  set_al(800);
  set_wc_bonus(0);
  set_ac_bonus(0);
  set_dead_ob(this_object());
  set_chat_chance(5);
    load_chat("Murwallabi says, \"I can tell you my story if you ask.\"\n");
    load_chat("\"If you say the word, I'll see if I can help you out,\" says Murwallabi.\n");
    load_chat("\n");
    load_chat("\n");
    load_chat("\n");
    load_chat("\n");
    load_chat("\n");
  set_a_chat_chance(10);
    load_a_chat("The "+TUROKHAN+" grabs at your unprotected neck, barely missing.\n"); 
  asked = 0;
  injured = 1;  
}                                    

init(){
  ::init();
  add_action("cmd_ask","ask")
  if(injured) {
    if(this_object()->query_hp() > ((this_object()->query_mhp())/4)) {
      this_object()->set_hp(this_object()->query_mhp()/2);
    }
  }       
}

/* mix the ask command and a catchtell to account for both */
/*
 * story_tell:     -story
 * quest_tell:     -quest, nar-tuith, nar tuith, scroll, scrolls,
 *                  scroll of nar-tuith, scrolls of nar-tuith
 * jungle_tell:    -jungle, woods, forest
 * mountain_tell:  -mountain, peak
 * beach_tell:     -beach
 * desert_tell:    -desert, jibboo, jibboo desert, desert of jibboo
 * pillar_tell:    -pillar, pillars, pillars of dar'khune, dar'khune
 * herb_tell:      -herb, herbs, remedy, cocapsi, cocapsi herbs
 */

catch_tell(string str) {
  string msg;
  string what;
  what = lower_case(str);
  if(sscanf(what,"quest%s",msg) || sscanf(what,"%squest%s",msg) ||
     sscanf(what,"%squest",msg) ) {
    call_out("qtell",3,this_player());
    return 1;
  }
  if(sscanf(what,"swords%s",msg) || sscanf(what,"%sswords%s",msg) ||
     sscanf(what,"%sswords",msg) ) {
    call_out("swtell",3,this_player());
    return 1;
  }
  if(sscanf(what,"smith%s",msg) || sscanf(what,"%ssmith%s",msg) ||
     sscanf(what,"%ssmith",msg) ) {
    call_out("smtell",3,this_player());
    return 1;
  }
  return 1;
}

cmd_ask(string str) {
  string msgone, msgtwo;
  if(!str) return;
  if(str == "man" || str == "murwallabi") {
    tell_room(environment(this_object()),
              ".\n");
  }
  str = lower_case(str);
  if(sscanf(str,"%sswamp%s",msgone,msgtwo)) {
    call_out("swamp",3,this_player());
      return 1; 
   }
  if(sscanf(str,"%sswamp%s",msgone,msgtwo)) {
    tellplayer("swamp");
      return 1; 
   }
  if(sscanf(str,"%sswamp%s",msgone,msgtwo)) {
    tellplayer("swamp");
      return 1; 
   }
  tellplayer("nothing");
    return 1; 
}

answer(str) {
  switch(random(3)) {
    case 0: tell_room(environment(this_object(),
              "Juribel furrows his brow in concentration.\n"); break;
    case 1: tell_room(environment(this_object(),
              "Juribel furrows his brow in concentration.\n"); break;
    case 2: tell_room(environment(this_object(),
              "Juribel furrows his brow in concentration.\n"); break;
  }
  switch(str) {
    case "swamp": call_out("whattell",3,this_player()); break;
  } 
}

celia() {
   tell_room(USER,"Juribel says:\n\n"+
      "\" Celia is a young child from our small village.  Her mother worries\n"
      +"  that she may have been lost to the SwampLands, but I cannot sense\n");
   tell_room(USER,"  her death.  I feel she is very much alive, although scared.  We\n"
      +"  sent a few of our remaining guards to patrol the swamp, looking\n"
      +"  for her.  They have not yet returned.\"\n\n");
   return 1; }

nothing() {
  switch(random(3)) {
    case 0: tell_room(environment(this_object()),
              "Juribel says, \"On second thought, I know nothing about that.\"\n"); break;
    case 1: tell_room(environment(this_object()),
              "Juribel says, \"On second thought, I know nothing about that.\"\n"); break;
    case 2: tell_room(environment(this_object()),
              "Juribel says, \"On second thought, I know nothing about that.\"\n"); break;
   }
    return 1; 
}

/********************************************************************/

quest_tell(object ob) {
  call_out("quest_tell1",3,this_player());
  call_out("quest_tell2",10,this_player());
  call_out("quest_tell3",15,this_player());
}

quest_tell1(object ob) {
  tell_object(ob, 
    "Glarvinthal whispers to you:\n"+
    "  'Give the three great swords to the smith of darkness.'\n");
  tell_object(ob,
    "  'Fulfill the mighty purpose.'\n"+
    "  'Seek above the trees for your final task.'\n");
    return 1; 
}