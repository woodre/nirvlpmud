#include "/players/tristian/lib/ClubFeddefine.h"
inherit "/players/vertebraker/closed/std/monster.c";
id(str) { return (::id(str) || str == "con" || str == "convict" || str == "joey" || str == "snitch" || str == "joey_the_snitch"); }

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("joey"); 
  set_alias("snitch");
  set_short("Joey the Snitch");
  set_long(
    "This is Joey.  No one knows what he's in for, but he has made a killing\n"+
    "on the inside selling information, cigarettes, and dope.  Perhaps you should\n"+
    "'trade' your unwanted smokes to him.\n");
  set_race("human");
  set_gender("male");
  set_level(20);
  set_wc(50);
  set_ac(30);
  set_hp(600);
  add_money(0);
  set_aggressive(0);
  set_al(-200);
  load_chat(
    "Joey whispers: 'Psst, got anything to trade?'\n");
  load_chat(
    "Joey whispers: 'Hey, wanna 'list' of what I have for sale?'\n");
  set_chat_chance(60);
  load_a_chat(
    "Joey says: 'Wow, you want to die?'\n");
  load_a_chat(
    "Joey beats you into a "+RED+"bloody pulp"+NORM+".\n");
  set_a_chat_chance(30);
  set_chance(40);
  set_spell_dam(40+random(20));

  set_spell_mess1(
    "\nJoey pulls out a shank and " +HIM+"plunges"+NORM+" it into your "+BLINK+BRED+"chest"+NORM+".\n");
  set_spell_mess2(
    "\nJoey pulls out a shank and " +HIM+"plunges"+NORM+" it into your "+BLINK+BRED+"chest"+NORM+".\n");
}

monster_died(){
  tell_room(environment(),
    "As the convict dies he drops his shiv.\n"+NORM);
  move_object(
    clone_object(OBJ+"shiv.c"),
    this_object());
}

heart_beat()
{
  int a,i;
  ::heart_beat();
  if(attacker_ob && present(attacker_ob,environment(this_object())))
  {
  i = 1;
  for(a=0;a<i;a++)
    {
    already_fight = 0;
    this_object()->attack(attacker_ob);
    }
  }
}
