#include "/players/tristian/lib/ClubFeddefine.h"
inherit "/players/vertebraker/closed/std/monster.c";

id(str) { return (::id(str) || str == "con" || str == "convict" || str == "oscar"); }

reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("Oscar");
  set_race("human");
  set_alias("criminal");
  set_gender("male");
  set_short("Oscar Schmidt");
  set_long(
    "Oscar is a grey haired older man who has gotten flabby since coming to\n"+
    "prison.  He is in for counterfeiting Rolex (tm) watches and selling\n"+
    "them to jewerly stores as the real deal.  He got caught when he tried to\n"+
    "sell them to an authorized Rolex (tm) dealer who knew them for fakes and\n"+
    "called the authorities.\n\n"+
    HIB+"Counterfeiting"+NORM+": Occurs when someone copies or imitates an item\n"+
    "without having been authorized to do so and passes the copy off for the genuine\n"+
    "or original item. Counterfeiting is most often associated with money, however \n"+
    "can also be associated with designer clothing, handbags, and watches.\n\n");
  set_level(20);
  set_ac(50+random(10));
  set_wc(30+random(10));
  set_hp((900)+random(100));
  set_al(-250);
  set_aggressive(0);
  set_chat_chance(5);
  load_chat(
    "Oscar whines: 'How was I supposed to know he was a dealer'\n");
  set_death_emote(
    "\n\nAs #MN# dies, cigarettes fall out of #MP# pockets.\n");

  set_dead_ob(this_object());
  set_chance(40);
  set_spell_dam(40+random(20));

  set_spell_mess1(
    "\nThe convict pulls out a shiv and " +HIY+"plunges"+NORM+" it into your "+BLINK+BRED+"chest"+NORM+".\n");
  set_spell_mess2(
    "\nThe convict pulls out a shiv and " +HIY+"plunges"+NORM+" it into your "+BLINK+BRED+"chest"+NORM+".\n");
}

monster_died()
{
 int s;
   s=5;
   while(s--)
   move_object(clone_object(OBJ+"cig.c"));

  tell_room(environment(),
    "As the convict dies he drops his shiv.\n"+NORM);
  move_object(
    clone_object(OBJ+"shiv.c"),
    this_object());
}