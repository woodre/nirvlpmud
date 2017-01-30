#include <ansi.h>
inherit "obj/monster.c";
#define ATTACKED (this_object()->query_attack())
object sword;
int called;

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("trunks");
  set_short(HIY+"Trunks"+NORM);
  set_long(
  "  The son of Bulma and Vegeta stands before you.  A \n"+
  "calm in the center of the storm.  His future master,\n"+
  "Gohan, has taught him to control his Super Saiyan powers.\n"+
  "He never is one to start a fight, but he is usually the\n"+
  "one to end it.\n");

  set_level(25);
  set_hp(1000);
  set_al(1000);
  set_ac(23);
  set_aggressive(0);
  set_heart_beat(1);
  set_chance(10);
  set_spell_dam(20);  
  set_spell_mess1(
    "Trunks let go a flurry of "+BOLD+"ENERGY SHOTS"+NORM+" at his foe!\n");
  set_spell_mess2(
    "\n    Trunks blasts you with a flurry of "+BOLD+"ENERGY SHOTS"+NORM+"\n"+
    "    at you sending you realing in pain.\n");
  sword = clone_object("/players/catacomb/dbz/items/Tsword.c");
  move_object(sword, this_object());
  command("wield sword", this_object());
  set_wc(44);
  int NoOfHeals;
  NoOfHeals = 10;

}
  heart_beat()
  {
    int x;
    x = random(20);
    ::heart_beat();
    if(!environment())
    {
      return;
    }
    if (!ATTACKED)
    {
      return;
    }
    if ((NoOfHeals != 0) && (hit_point <= ((max_hp/10)*5)))
    {
      tell_room(environment(ATTACKED), 
      "\n     Trunks reaches into a pouch and grabs a sensu bean\n");
      heal_self(100+random(50));
      NoOfHeals =NoOfHeals - 1;
    }
    if ((x >=17) && (called != 1))
    {
      tell_room(environment(ATTACKED), 
         "\n   A sudden rush of energy blinds you, when the blindness\n"+
         "   clears Trunks stands before you with "+HIY+"Golden Hair"+NORM+"\n\n");
      weapon_class += random(10);
      called = 1;

    }
    if (x <= 7)
    {
     Swordplay();
    }
  }
  
  Swordplay()
  {
     tell_room(environment(ATTACKED), 
        "\n       Trunks brings down his adamantium sword with a powerful\n"+
        "\n"+RED+BOLD+"                       SLICE!!!!\n"+NORM+
        HIR+"       Chunks of flesh and a fountain of blood fall from your body\n\n"+NORM);
    ATTACKED->heal_self((random(50))-70);
    return 1;
  }
 
