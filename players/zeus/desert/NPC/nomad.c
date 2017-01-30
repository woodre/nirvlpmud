inherit "/obj/monster";

reset(arg){
  ::reset(arg);
  if (!arg){

  object a,b;
  a = clone_object("/players/zeus/desert/OBJ/robe.c");
  move_object(a, this_object());
  init_command("wear robe");
  b = clone_object("/players/zeus/desert/OBJ/scimitar.c");
  move_object(b, this_object());
  init_command("wield scimitar");
  
  if(!random(2))
  {
    set_name("wanderer");
    set_short("A desert wanderer");
  }
  else
  {
    set_name("nomad");
    set_short("A desert nomad");
  }
  set_race("human");
  set_gender("male");
  set_long(
"This slender figure is cloaked in a baggy brown hooded robe which\n"+
"conceals nearly his entire figure.  It appears to be encrusted with\n"+
"sand and filth.  His slender fingers are just barely visible at\n"+
"the end of each long sleeve.  A large scimitar is slung around his\n"+
"waist.  He seems to be oblivious of your presence.\n");
  set_level(14+random(2));
  set_ac(10);             /* mguide 12   for level 15 */
  set_wc(24);             /* mguide 20  */
  set_hp(215);            /* mguide 225 */
  set_chat_chance(3);
  set_a_chat_chance(3);
  load_chat("A desert wanderer clutches at his scimitar.\n");
  load_chat("A desert wanderer moves slowly across the desert.\n");
  load_chat("A desert wanderer seems to glance off into the desert.\n");
  load_chat("A desert wanderer stands silently as winds blow around him.\n");
  load_a_chat("A desert wanderer hits you with a crushing blow.\n");
  set_chance(15);
  set_spell_dam(10);      /* mguide ? */
  set_spell_mess1("A desert wanderer clutches at his scimitar.\n");
  set_spell_mess2("A desert wanderer stabs you with his scimitar!\n");
  set_dead_ob(this_object());
  }  
}

id(str){ return str == "zeus_inculta_npc"
             || str == name || str == alt_name || str == alias; }

void heart_beat(){
  ::heart_beat();
  if(!environment())
    return;
  if(!attacker_ob)
    return;
  if(0 == random(9))
  {
    tell_room(environment(),
      "A desert wanderer pulls out a small bottle and drinks from it.\n");
    hit_point += 10;
    if(!random(3))
      armor_class +=1;
    else if(!random(3))
      weapon_class += 1;
  }
}

monster_died(){
  if(!(random(8)))
    move_object(clone_object("/players/fred/closed/bloodfist/obj/gem.c"), environment());
}
