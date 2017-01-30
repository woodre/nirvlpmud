
/* Sharpen action approved by Fakir, coded by Jaraxle */
/* [8/9/02] - Stolen from Vertebraker with permission. */

#include "/players/jaraxle/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("valkarn");
set_alt_name("weapon_owner");
set_alias("weaponsmith");
set_race("human");
set_short("Valkarn the Master Weaponsmith");
set_long(
"  This is a very short and aged man.  A long white beard hangs from his\n"+
"chin and down to his chest. He stands about five and a half feet tall\n"+
"with a wirey body. He seems very old but full of energy.\n"+
"If you ask, he may sharpen your weapons for 750 coins.\n");
set_level(8);
set_hp(150);
set_al(800);
set_wc(35);
set_ac(5);
set_aggressive(0);

set_chat_chance(5);
  load_chat("Valkarn says: Ahhhh, searching for a weapon my friend?\n");
  load_chat("The weaponsmith shuffles around the room lost in his work.\n");
  load_chat("Valkarn holds up a fine longsword for inspection.\n");
set_a_chat_chance(15);
  load_a_chat("Valkarn sneers: You think I am an easy target because I am old?\n");
  load_a_chat("Valkarn lunges at you with a thin rapier!\n");
gold = clone_object("obj/money");
gold->set_money(250);
move_object(gold,this_object());
}

init(){
::init();
if(present("KnightTemplar", this_player())){
call_out("bow_motion", 3, this_player());
  }
   add_action("cmd_sharpen","sharpen");
}


bow_motion(object who){
if(!present(who, environment())){
return 1;
}
tell_object(who,
"Valkarn smiles at you.\n");
return 1;
}

cmd_sharpen(string str)
{
    int broken;
    string sh;
    object a, b;

    if(!str)
    {
      notify_fail("\Valkar asks: \"What would you like me to sharpen?\"\n");
      return 0;
    }

    if(!(a = present(lower_case(str), (b = this_player()))))
    {
      notify_fail("\Valkarn says, \"You don't have that weapon!\"\n");
      return 0;
    }

    sh = (string)a->short();

    if(!a->weapon_class() || !sh)
    {
      notify_fail("\Valkarn says, \"That's not a weapon!\"\n");
      return 0;
    }

    if(((int)a->query_hits() <= 1) && ((int)a->query_misses() <= 1))
    {
      notify_fail("\Valkarn says, \"That weapon is as ready for battle as it\n\ will ever will be.\"\n");
      return 0;
    return 0;
    }

    if((int)b->query_money() < 750)
    {
      notify_fail("\Valkarn says, \"You don't have enough money.\"\n");
      return 0;
    }

    if((status)a->query_wielded())
      command("unwield", b);

    write("\Valkarn takes " + sh + " from you and inspects it.\n\
He rapidly grinds it against a sharpening stone and\n\
hands it back to you.\n\
You pay him the money and he nods to you.\n\
He mutters, \"Have a good one, friend.\"\n");
    say("Valkarn sharpens " + sh + " for " + 
      (string)b->query_name() + ".\n", b);
    a->set_hits(1);
    a->set_hits(1);
    a->set_misses(1);
    b->add_money(-750);
    return 1;
}
      
