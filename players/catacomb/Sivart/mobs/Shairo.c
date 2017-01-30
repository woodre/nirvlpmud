#include "/players/catacomb/saiyan/def.h"
inherit "obj/monster.c";
object sword, cloak;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("shairo");
set_race("durkor");
set_short("Shairo Jacor");
set_long(
  "  Shairo is the patriarch of the Jacor house.  Through years of\n"+
  "intense training he has become the foremost blademaster of the\n"+
  "Durkor.  His pale gray face shows a single scar along his right\n"+
  "cheek, given to him by another feuding house.  His lean muscular\n"+
  "arms show the dedication Shairo has for his discipline.  He has \n"+
  "given up care for anything except finding the person who handed\n"+
  "him his scar.\n");
 
set_level(23);
set_hp(1000);
set_al(-300);
set_dead_ob(this_object());
set_aggressive(0);
add_money(random(2000)+3000);
set_chat_chance(5);
  load_chat("Shairo says: I will find the person who gave me this scar.\n");
  load_chat("Shairo goes through his forms with "+BOLD+YEL+"Hex"+RED+"fire"+NORM+".\n");
  load_chat("Shairo tells you: I know it was one of those bloody Werjor that did this.\n");
set_chance(10);
set_spell_dam(random(20)+15);
set_spell_mess1(			
  "\n           Shairo brings his blade around into The Mountain \n"+
    "           Rises and slices clean through his foe's torso.\n");
set_spell_mess2(			
  "\nShairo feints left the enters The Mountain Rises and slices through your\n"+
    "        torso. You double over in excruciating pain.\n");

sword = clone_object("players/catacomb/Sivart/items/hexfire.c");
move_object(sword, this_object());
command("wield sword",this_object());
set_wc(42+ random(5));

cloak = clone_object("/players/catacomb/Sivart/items/Ccloak.c");
move_object(cloak, this_object());
init_command("wear cloak", this_object());
set_ac(23);

}
heart_beat()
{
  int chance;
  chance = random(100);
 ::heart_beat();
  if(!environment())
    return;
  if(!HOSER)
    return;
  
  if(chance >= 90)
  {
    tell_object(HOSER,
      "\n\n  Shairo goes into Parting The Silk, disappearing\n"+
          "  then reappearing behind you as you reel over in pain\n"+
          "          blood fleeing from your side.\n\n");
    HOSER->hit_player(random(50)+25);
    return 1;
  }
  if (chance > 75)
  {
    tell_object(HOSER,
          "\n\n   Shairo charges at you with Boar Rushing Down The\n"+
              "  Mountain overwhelming you with a vicious onslaught.\n\n");
    HOSER->hit_player(random (25)+10);
    return 1;
  }
  if (chance <= 5)
  {
    tell_object(HOSER,
         "\n\n  Shairo gets a strange gleam in his eye and attacks,\n"+
         HIY+"   The Wind Uppercuts the Willow follows \n"+
         BOLD+RED+"     The River Undercuts the Bank follows \n"+
         HIR+"      The Dark One Breaks Free.\n\n"+NORM);
    HOSER->hit_player(random(75)+50); 
    return 1;
  }
  else
  { return 1; }
}

  