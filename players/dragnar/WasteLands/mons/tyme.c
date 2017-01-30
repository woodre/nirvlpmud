inherit "obj/monster";

#include <ansi.h>

/******************************************************************************
 * Program: tyme.c
 * Path: /players/dragnar/WasteLands/mons
 * Type: Mob
 * Created: 1993 by Dragnar
 *
 * Purpose: A high level monster in the Wastelands area Mob has high WC/AC 
 *          and higher than normal spell damage. Multi-cast is on so it
 *          makes spells especially dangerous, up to 300 dam with WC.
 * History:
 *          09/18/2013 - Dragnar
 *            Updated stats, spells.
 ******************************************************************************/

string text;	/*  For catch_tell string */
object receiver;	/* Player receving the text */

reset(arg){
  object weapon;
  ::reset(arg);
  if(arg) return;
  set_name("tyme");
  set_race("human");
  set_alias("grand master");
  set_short("Tyme, the grand master of the mortals");
  set_long("As you take a step closer to Tyme, you look into his eyes\n" +
  "and notice the emptyness that fills his soul. He looks as if he\n" +
  "is in superior shape, and well schooled in assassination. His\n" +
  "presence makes you tremble with fear. As he continues to stare you down\n" +
  "you decide it wouldn't be a wise choice to attack him.\n");
  set_level(27);
  set_hp(1400+random(300));
  add_money(random(19000)+5000);
  set_al(random(1000));
  set_wc(60);
  set_ac(45);
  set_heal(50,3);
  set_aggressive(0);
  set_multi_cast(1);
  
  add_spell("sonic_blast",
    "#MN# casts a $HM$S O N I C    B L A S T $N$ at you!\n",
    "#TN# is smashed by a $HM$S O N I C    B L A S T $N$ casted by #MN#!\n",
    20,"60-120","other|energy", 0 );
  
  add_spell("swing_reaper",
    "#MN# twists violently and swings his $HM$Reaper$N$ in a wide arc!\n",
    "#TN# is caught by #MN#'s $HM$Reaper$N$ as he swings it in a wide arc!\n",
    10,"80-120","physical", 3 );
  
  set_chat_chance(7);
  load_chat("Tyme says: Beware, the evil in this place is powerful.\n");
  load_chat("Tyme says: Adventure on if you believe you are powerful enough.\n");
  load_chat("Tyme says: If you've lost your MK scar, just ask for my help.\n");
  load_chat("Tyme says: If you want to save this world, ask me about the quest.\n");
  set_a_chat_chance(2);
  load_a_chat("Tyme screams: I am the only good in this place and you dare to attack me?\n");
  
    weapon=clone_object("players/dragnar/WasteLands/weap/death.c");
  move_object(weapon, this_object ());
  
}
void long(string id)
{
    ::long(id);
    if (!text) {
	receiver = this_player();
   text = " If you want to save this land, ask me about the quest.\n";
	call_out("DoTalk", 3);
    }
}
void catch_tell(string str)
{
    string      who, what;

    if (sscanf(str, "%s says: %s\n", who, what) == 2 ||
	sscanf(str, "%s asks: %s\n", who, what) == 2 ||
	sscanf(str, "%s tells you: %s\n", who, what) == 2) {

	what = lower_case(what);
	if (sscanf(what, "%squest", who))
     text = read_file("/players/dragnar/WasteLands/mons/tyme/quest");
   else if(sscanf(what, "%sscar", who)) {
     receiver = this_player();
     call_out("ResetScar", 2);
   }
   else return;
   receiver = this_player();
   call_out("DoTalk", 3 );
   }
}

void DoTalk() {

 if (!text || !receiver) { text = 0; return;}
   tell_object(receiver, "\nTyme whispers to you:");
    tell_object(receiver, text);
    text = receiver = 0;
}
ResetScar() {

  if( !receiver ) {
    return 1;
  }
   tell_object(receiver, "Tyme says: Sorry, I can't do that right now.\n");
  return 1;
  command("reset_scar_obj", receiver);
  return 1;
}
