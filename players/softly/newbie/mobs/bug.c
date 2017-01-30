#include "/players/softly/closed/ansi.h"
inherit "/obj/monster";

int type;
object gold;
reset(arg) 
{
   ::reset(arg);
   if (arg) return;
   if(!random(5)) pbfly();
   else if(!random(5)) ybfly();
   else if(!random(5)) bbfly();
   else if(!random(5)) brant();
   else if(!random(5)) blant();
   else beetle();
}

pbfly()
{
   type = 0;
   set_name("butterfly");
   set_race("insect");
   set_alias("bfly");
   set_short(HIM+"Butterfly"+NORM+"");
   set_long("A "+HIM+"bright pink butterfly "+NORM+"flutters amongst the flowers.\n");
   set_level(2);
   set_hp(30);
   set_al(1000);
   set_wc(6);
   set_ac(3);
   set_aggressive(0);
   set_chat_chance (1);
   load_chat("The "+HIM+"pink butterfly "+NORM+"flutters about.\n");
   load_chat("The flower nods when the butterfly lands on it.\n");
   load_chat("The butterfly brushes your face.\n");
   load_chat("The "+HIM+"pink butterfly "+NORM+"flies just out of reach.\n");
   set_dead_ob(this_object());
}

ybfly()
{
   type = 1;
   set_name("butterfly");
   set_race("insect");
   set_alias("bfly");
   set_short(HIY+"Butterfly"+NORM+"");
   set_long("A "+HIY+"bright yellow butterfly "+NORM+"flutters amongst the flowers.\n");
   set_level(2);
   set_hp(30);
   set_al(100);
   set_wc(6);
   set_ac(3);
   set_aggressive(0);
   set_chat_chance (1);
   load_chat("The "+HIY+"yellow butterfly "+NORM+"flutters about.\n");
   load_chat("The flower nods when the butterfly lands on it.\n");
   load_chat("The butterfly brushes your face.\n");
   load_chat("The "+HIY+"yellow butterfly "+NORM+"flies just out of reach.\n");
   set_dead_ob(this_object());
}

bbfly()
{
   type = 2;
   set_name("butterfly");
   set_race("insect");
   set_alias("bfly");
   set_short(HIB+"Butterfly"+NORM+"");
   set_long("A "+HIB+"bright blue butterfly "+NORM+"flutters amongst the flowers.\n");
   set_level(2);
   set_hp(30);
   set_al(500);
   set_wc(6);
   set_ac(3);
   set_aggressive(0);
   set_chat_chance (1);
   load_chat("The "+HIB+"blue butterfly "+NORM+"flutters about.\n");
   load_chat("The flower nods when the butterfly lands on it.\n");
   load_chat("The butterfly brushes your face.\n");
   load_chat("The "+HIB+"blue butterfly "+NORM+"flies just out of reach.\n");
   set_dead_ob(this_object());
}

brant()
{
   type = 3;
   set_name("ant");
   set_race("insect");
   set_alias("ant");
   set_short(YEL+"Ant"+NORM);
   set_long("An ant scurries toward his hill.\n");
   set_level(1);
   set_hp(15);
   set_al(-300);
   set_wc(5);
   set_ac(3);
   set_aggressive(0);
   set_chat_chance (1);
   load_chat("The ant carries something back to the anthill.\n");
   load_chat("An ant walks across your foot..\n");
   set_dead_ob(this_object());
}


blant()
{
   type = 4;
   set_name("ant");
   set_race("insect");
   set_alias("ant");
   set_short(BLK+BOLD+"Ant"+NORM);
   set_long("An ant scurries toward his hill.\n");
   set_level(1);
   set_hp(15);
   set_al(-400);
   set_wc(5);
   set_ac(3);
   set_aggressive(0);
   set_chat_chance (1);
   load_chat("The ant carries something back to the anthill.\n");
   load_chat("An ant walks across your foot..\n");
   set_dead_ob(this_object());
}

beetle()
{
   type = 5;
   set_name("beetle");
   set_race("insect");
   set_alias("beetle");
   set_short(CYN+"Beetle"+NORM);
   set_long("A glossy beetle casually wanders across the path.\n");
   set_level(1);
   set_hp(15);
   set_al(-100);
   set_wc(5);
   set_ac(3);
   set_aggressive(0);
   set_chat_chance (1);
   load_chat("The beetle basks in the sunlight.\n");
   load_chat("A beetle hides beneath a flower..\n");
   set_dead_ob(this_object());
}



monster_died() 
{
  if(type == 0)
  {
  tell_room(environment(this_object()),
  "As the "+HIM+"pink butterfly "+NORM+"dies you\n"+
  "see a few coins lying on the ground nearby.\n");	
  gold = clone_object("obj/money");
  gold->set_money(60+random(30));
  move_object(gold,environment(this_object()));
  return 1; 
  }

  if(type == 1)
  {
  tell_room(environment(this_object()),
  "As the "+HIY+"yellow butterfly "+NORM+"dies you\n"+
  "see a few coins lying on the ground nearby.\n");	
  gold = clone_object("obj/money");
  gold->set_money(75+random(15));
  move_object(gold,environment(this_object()));
  return 1; 
  }

  if(type == 2)
  {
  tell_room(environment(this_object()),
  "As the "+HIB+"blue butterfly "+NORM+"dies you\n"+
  "see a few coins lying on the ground nearby.\n");	
  gold = clone_object("obj/money");
  gold->set_money(80+random(10));
  move_object(gold,environment(this_object()));
  return 1; 
  }

  if(type == 3)
  {
  tell_room(environment(this_object()),
  "As the ant dies you see that the anthill was covering a few coins.\n");	
  gold = clone_object("obj/money");
  gold->set_money(40+random(25));
  move_object(gold,environment(this_object()));
  return 1; 
  }

  if(type == 4)
  {
  tell_room(environment(this_object()),
  "As the ant dies you see that the anthill was covering a few coins.\n");	
  gold = clone_object("obj/money");
  gold->set_money(50+random(15));
  move_object(gold,environment(this_object()));
  return 1; 
  }

  else  
  {
  tell_room(environment(this_object()),
  "The dead beetle rolls over revealing a few coins.\n");	
  gold = clone_object("obj/money");
  gold->set_money(65+random(25));
  move_object(gold,environment(this_object()));
  return 1; 
  }
}
