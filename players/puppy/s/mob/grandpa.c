#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/monster";
inherit "/obj/monster";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("grandpa");
   set_alt_name("smurf");
   set_short(""+HIB+"Grandpa Smurf"+NORM+"");
   set_race("smurf");
   set_long(
      "Grandpa Smurf is the oldest of all Smurfs. His energy after\n"+
      "all these years is quite impressive.  He has not taken Papa\n"+
      "Smurf's leading role, but is still a huge influence over all\n"+
      "the Smurfss.\n");
   set_level(3);
   set_hp(125);
   set_wc(4);
   set_ac(3);
   set_al(120);
   set_chance(90);
   set_spell_dam(10);
   set_spell_mess2("Grandpa Smurf bashes his staff against your knee.\n");
   move_object(clone_object("/players/puppy/s/eq/gpants.c"), this_object());
   init_command("wear boots");
   move_object(clone_object("/players/puppy/s/eq/staff.c"), this_object());
   init_command("wield weapon");
   move_object(clone_object("/players/puppy/s/eq/glasses.c"), this_object());
   
}

get_spell_mess1()
{
   return ("Grandpa Smurf bashes " + BOLD + attacker_ob->query_name() + NORM + "'s knee\n");
}
