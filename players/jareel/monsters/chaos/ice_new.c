/* Demon is made of Darkness 
I made it vunerable to light 
and invulnerable to Darkness 
Change made 05/17/2006 */

inherit "obj/monster.c";
#include "/players/jareel/define.h"

  reset(arg)  {
    ::reset(arg);
      if(arg) return;

  set_name("Dark Demon");
  set_alt_name("dark");
  set_short(HIK+"Dark Demon"+NORM);
  set_alias("demon");

  set_long(
    "The demon is an enormous writhing mass, formed out of ropy\n"+
    "black tentacles.  Here and there, the demon's surface is \n"+
    "covered with great hungry mouths dripping a vile green acidic\n"+
    "substance.  The demon sprawls over the floor on it's slime  \n"+
    "covered tentacles.  Your soul screams in terror as you look\n"+
    "at it.\n");
  set_spell_mess1("The demon whips its tentacles.\n");
  set_spell_mess2("The demon whips its tentacles at you.\n");
  set_chance(5);
  set_spell_dam(70);
  set_race("demon");
  set_al(-1000);
  set_level(22);
  set_hp(600);
    
    MOCO("/players/jareel/heals/stone.c"),this_object());

  set_wc(80);
  set_ac(10);
  set_heal(5,1);
  set_aggressive(1);
  add_money(1000+random(3000));

}

init() {
  ::init();
    add_action("nogo","up");
}

nogo() {
  write("Demon blocks your path.\n");
  return 1;}
