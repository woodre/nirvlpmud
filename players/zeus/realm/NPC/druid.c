inherit "/obj/monster";
#include "/players/zeus/closed/all.h"

reset(arg) {
   ::reset(arg);
   if (!arg) {

  set_name("druid");
  set_short("A druid");
  set_long(
"This man is a druid.  He is wearing a large robe with a hood that hangs\n"+
"over his face, casting much of it in a shadow.  He has a very pleasant\n"+
"smile, as though he is only here to help.\n");
  set_level(20);
  set_race("human");
  set_ac(18);
  set_hp(800+random(200));
  set_wc(30);
  set_al(500);
  set_heal(1,1);
  set_aggressive(0);
  set_gender("male");
  set_chat_chance(4);
  set_a_chat_chance(5);
  load_chat("The druid says: A strange evil resides to the east.\n");
  load_chat("The druid says: I fear the demons of the forest.\n");
  load_chat("The druid says: The mists are evil, stay far away.\n");
  load_chat("The druid smiles at you.\n");
  load_chat("The druid looks out into the forest.\n");
  load_chat("The druid glances towards the pond.\n");
  load_chat("The druid stands patiently.\n");
  load_chat("The druid says: How are you this day traveller?\n");
  load_chat("The druid looks up towards the sky.\n");
  load_a_chat("The druid says: Your death will mean nothing to me.\n");
  load_a_chat("The druid stares coldly at you.\n");
  load_a_chat("The druid says: It is time for you to die.\n");
  set_dead_ob(TO);
} }

id(str){ return str == "druid"; }

heart_beat(){
  ::heart_beat();
  if(!environment()) 
    return ;
  if(!AO) 
    return ;
  if(AO == TO)
  {
    tell_room(environment(), 
      "The druid shakes it off and keeps fighting...\n");
    this_object()->stop_fight();
    this_object()->stop_fight();
    return ;
  }
  if(!random(11))
  {
    TR(environment(),
      "\nThe druid raises his hand into the air...\n"+
      "A flash of light folds in upon his hands...\n"+
      "They begin to glow with a powerful fury...\n\n");
    weapon_class += 5;
    return ;
  }
  if(!random(11))
  {
    TR(environment(),
      "\nThe druid raises his hand into the air...\n"+
      "A soft cloud forms around his body...\n\n");
    hit_point += weapon_class;
    return ;
  }
  if(!random(7))
  {
    TR(environment(),
      "The druid casts a small heal spell upon himself...\n");
    hit_point+= 10+random(15);
    return ;
  }
  if(!random(11))
  {
    TR(environment(),
      "\nThe druid raises his hand into the air...\n"+
      "A cold wind blows through the room...\n"+
      "The druid radiates a mighty aura...\n\n");
    AO->hit_player(25);
    armor_class += 2;
    return ;
  }
}

monster_died()
{
  write_file("/players/zeus/log/grove",
  ctime(time())+"  "+AO->QN+" [L "+AO->query_level()+
  "+"+AO->query_extra_level()+"]  ");
   if(AO->query_weapon()) write_file("/players/zeus/log/grove", 
	   AO->query_weapon()->short()+"\n");
    else write_file("/players/zeus/log/grove", "\n");
  return 1; 
}

mist_info(object x)
{
  if(!x) return 0;
  tell_object(x,
"\n\nThe druid tells you:\n"+
"  A strange darkness lurks within the mists to the east.  I\n"+
"  have heard of a legendary blade that is guarded by a gigantic\n"+
"  creature cursed to forever protect it with its life.  Legend\n"+
"  also speaks of strange vortices of mist which have been seen\n"+
"  among the trees.  You should beware of the mists fare traveler!\n\n");
  TR(environment(), "The druid says something to "+x->QN+".\n", ({x}));
}

vortex_info(object x)
{
  if(!x) return 0;
  tell_object(x,
"\n\nThe druid tells you:\n"+
"  I have seen them myself once.  It swirled between the trees with\n"+
"  a fierce intensity, mist constantly flying from it feeding the\n"+
"  giant creature.  It was an amazing sight to behold, but I ran\n"+
"  as quickly as possible knowing my life was in grave danger.\n\n");
  TR(environment(), "The druid says something to "+x->QN+".\n", ({x}));
}

void catch_tell(string str)
{
  string tmp1, tmp2;
  if(sscanf(str, "%smist%s\n", tmp1, tmp2))
  {
    me = TP;
    if(me != this_object() && me->is_player() && !me->query_attack())
      call_out("mist_info", 1, me);
  }
  if(sscanf(str, "%svortex%s\n", tmp1, tmp2) ||
    sscanf(str, "%svortices%s\n", tmp1, tmp2))
  {
    me = TP;
    if(me != this_object() && me->is_player() && !me->query_attack())
      call_out("vortex_info", 1, me);
  }
}


