inherit "/obj/monster";
#include "/players/fred/closed/bloodfist/defs.h"
object morningstar,breastplate,boots,helm,home,who;


reset(arg){
  if(arg) return;
  ::reset(arg);

  helm = clone_object("/obj/armor.c");
  helm->set_weight(2);
  helm->set_value(2300);
  helm->set_type("helmet");
  helm->set_name("fullhelm");
  helm->set_alt_name("helm");
  helm->set_alias("fullhelm");
  helm->set_short("A fullhelm");
  helm->set_long(
    "This fullhelm protects the wearers entire head.  Steel bars extend\n"+
    "from beneath the eye slits down over the wearers mouth and chin.\n"+
    "At the very top of the helm is a steel point which protrudes into\n"+
    "the air.\n");
  helm->set_ac(0);
  move_object(helm, this_object());
  init_command("wear helmet");

  boots = clone_object("/obj/armor.c");
  boots->set_weight(2);
  boots->set_value(800);
  boots->set_type("boots");
  boots->set_name("black leather boots");
  boots->set_short("Leather boots");
  boots->set_long(
    "A pair of leather boots.  They are well made however would\n"+
    "only provide moderate protection.  They look as though they were\n"+
    "recently cleaned, however still hand sand and dirt on them.\n");
  boots->set_ac(0);
  move_object(boots, this_object());
  init_command("wear boots");

  breastplate = clone_object("/obj/armor.c");
  breastplate->set_weight(2);
  breastplate->set_value(500);
  breastplate->set_type("armor");
  breastplate->set_name("beastplate");
  breastplate->set_alias("plate");
  breastplate->set_short("A light breastplate");
  breastplate->set_long(
    "This is a well made breastplate with an insignia of swirling\n"+
    "sand on the front.  It looks moderately heavy.\n");
  breastplate->set_ac(0);
  move_object(breastplate, this_object());
  init_command("wear armor");

  morningstar = clone_object("/obj/weapon.c");
  morningstar->set_weight(3);
  morningstar->set_class(20);
  morningstar->set_type("club");
  morningstar->set_alias("morningstar");
  morningstar->set_name("honor of the sand");
  morningstar->set_short("A broadsword");
  morningstar->set_long("This is a simple looking broadsword.\n");
  morningstar->set_value(1400);
  move_object(morningstar, this_object());
  init_command("wield morningstar");

  set_name("guard");
  set_short("A Bloodfist Guard");
  set_long(
"This guard of the Bloodfist guild has the dutiful task of escorting\n"+
"people to and from the guild hall.  He is well clad in armor and looks\n"+
"prepared to fight should the opportunity arise.\n");
  set_race("human");
  set_level(20);
  set_ac(17);
  set_wc(40);
  set_hp(1000);
  set_gender("male");
  set_chat_chance(1);
  set_a_chat_chance(1);
  load_chat("The guard looks around casually.\n");
  load_a_chat("The guard attacks with his broadsword.\n");
  set_dead_ob(this_object());
}

id(str){ return str == name || str == "bloodfist guard"; }

void init(){
  ::init();
  add_action("accept_invitation", "accept");
  add_action("decline_invitation", "decline");
}

void invite(object p, object w){  who = p; home = w; }

void dest(){
  object *blah;
  int a, sa;
  blah = all_inventory();
  sa = sizeof(blah);
  for(a = 0; a < sa; a++)
    destruct(blah[a]);
  destruct(this_object()); 
}

status accept_invitation()
{
  if(this_player() != who) return 0;
  write("The guard ties a blindfold around your "+
    "eyes and escorts you away.\n\n\n");
  tell_room(environment(),
    this_player()->query_name()+" is escorted away by the guard.\n",
    ({ this_player() }));
  tell_room(home, "\nA guard escorts "+this_player()->query_name()+
    " into the room.\n");
  this_player()->move_player("away#"+file_name(home));
  tell_room(environment(), "A guard leaves...\n");
  tell_room(home, "\nA guard leaves west.\n");
  home->accepted();
  call_out("dest", 1);
  return 1;
}

status decline_invitation()
{
  if(this_player() != who) return 0;
  write("The guard nods and leaves.\n");
  home->declined((string)this_player()->query_real_name());
  call_out("dest", 1);
  return 1;
}

