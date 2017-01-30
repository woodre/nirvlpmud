#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/khirstel";

int mood_count;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Khirstel");
  set_short("A Khirstel");
  set_long("A Khirstel.\n");
  set_race("khirstel");
  if(!random(2)) set_gender("male");
  else set_gender("female");
  set_level(1);
  set_hp(100 + random(100));
  set_wc(15 + random(15));
  set_ac(10);
  set_al(200);
  set_can_kill(1);
  set_mood("grinning");
  set_follow(1);
  set_follow_msg("waddles");
  mood_count = 0;
  enable_commands();
  set_heart_beat(1);
}

id(str)
{
  string o;
  if(!owner) o = "noone";
  else o = owner->query_real_name();
  return str == o+"'s khirstel" || str == "khirstel" ||
    str == "mage_pet" || str == o+"'s pet";
}

short()
{
  if(!owner) return "A Khirstel ("+mood+")";
  else if(tp == owner) return "Khirstel ("+mood+")";
  else return OWN+"'s Khirstel ("+mood+")";
}

long()
{
  if(tp == owner)
    write(
    "This is your "+HIY+"Khirstel"+NORM+", a magically conjured creature from another\n"+
    "realm.  The Khirstel is a small round animal with fur so thick and deep that who\n"+
    "knows what could be hidden within.  The small hairball-like Khirstel is known\n"+
    "to be very moody.\n"+
    "Khirstel has "+HIC+this_object()->query_hp()+NORM+" hps left.\n"+
    "\n"+
    "Kristel Commands are: \n"+
    "  klook <str>    - have your khirstel take a look <dir>.\n"+
    "  kdismiss       - dismiss your khirstel.\n"+
    "  kemote         - emote with khirstel.\n"+
    "  kdrop <item>   - have khirstel drop <item>\n" +
    "  kget <item>    - have your khirstel get <item>\n" +
    "  kget <item> from <what>  - have khirstel get something from <what>\n" +
    "  kgive <item> to <who>    - give item to person.\n" +
    "\n");
  else
    write(
    "This is "+OWN+"'s Khirstel. The Khirstel is a small hairball-like creature\n"+
    "summoned from another realm.  Khirstels are tiny round animals with fur so thick\n"+
    "and deep that who knows what might be hidden within.  The Khirstel is known to\n" +
    "be a very moody critter.\n");
    return;
}

init()
{
  ::init();
  if(tp == owner)
  {
	add_action("klook","klook");
	add_action("kdismiss","kdismiss");
	add_action("ktest","ktest");
	add_action("kkick","kick");
	add_action("kemote","kemote");
	add_action("pet_get", "kget");
	add_action("pet_give","kgive");
	add_action("pet_drop","kdrop");
  }
}

heart_beat()
{
  ::heart_beat();

  if(!owner)
  {
	destruct(this_object());
	return 1;
  }

  pet_follow();

  if(mood == "snarling" && !query_attack())
	khir_attack();
  else if(mood != "snarling" && query_attack())
	khir_stopattack();

  mood_count++;

  if(mood_count == 20 || mood_count == 40)
  {
	do_khirstel();
  }

  if(mood_count >= 60)
  {
	mood_shift();
	mood_count = 0;
  }

}

