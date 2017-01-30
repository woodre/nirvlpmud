inherit "obj/monster";

int one, given;


reset(arg)
{
  object gold;

  one = 0;
  given = 0;

  ::reset(arg);
  if(arg) return;
  set_name("Morgenes");
  set_race("human");
  set_alias("doctor");
  set_alt_name("morgenes");
  set_short("Doctor Morgenes");
  set_long("Doctor Morgenes is a rather old man.\n"+
    "He has much wisdom and should be treated with respect.\n");
  set_level(16);
  set_hp(300);
  set_al(0);
  set_wc(5);
  set_ac(3);
  enable_commands();
  set_chance(40);
  set_spell_dam(random(20)+5);
  set_spell_mess1("The doctor casts a fireball at you.");
  set_spell_mess2("The doctor shoots bolts of magic at you.");
  set_chat_chance(15);
  load_chat("The Doctor says: Judge yourself before others.\n");
  load_chat("Morgenes says: I wonder what Ookequk is doing?\n");
  load_chat("The Doctor plays with some frogs.\n");
  gold=clone_object("obj/money");
  gold->set_money(random(1000)+500);
  move_object(gold,this_object());
}


heart_beat()
{
  if((this_object()->query_attack()) && 
     (this_object()->query_hit_point() <= 0))
  {
    if ((one == 0) && (this_object()->query_attack()))
    {
      log_file("dune.mon", capitalize
        ((this_object()->query_attack())->query_real_name())+
        "("+(this_object()->query_attack())->query_level()+")"+
        " killed doctor.c\n");
      one = 1;
    }
  }
  ::heart_beat();
}


catch_tell(string str)
{
  string msg;

  str = lower_case(str);

  if (sscanf(str,"%sebudee%s", msg))
  {
    tell_object(this_player(), 
"Doctor Morgenes tells you: \n"+
"     Well let me tell you about Ebudee. She knows much of the recent\n"+
"events regarding the lost Sithi Cities. Perhaps if you asked her about\n"+
"the cities, then she could tell you more. Ebudee, the Nature Wytch,\n"+
"lives a very solitary life in the swamps.\n"+
"     I believe Ebudee's diet consists of various greens, perhaps some\n"+
"furry swamp critters as well. She is rumored to have a pet, a mugwort.\n"+
"Mugworts are rather myserious animals... for they are completely\n"+
"invisible and asleep all the time.\n");
    return 1;
  }

  if (sscanf(str,"%smoonstone%s",msg))
  {
    if (!given)
    {
      tell_object(this_player(), 
"Doctor Morgenes tells you: \n"+
"     I know you have come for my moonstone, Amerasu has informed me.\n"+
"Hmm, now let me think, where did I put that thing. Ah, on top of my bedpan!\n"+
"Now take good care of it. By the way, Ebudee may help you on your quest.\n");
      given = 1;
      move_object(clone_object("players/dune/closed/castle/objects/stone.c"),
                  this_player());
    }
    else
    {
      tell_object(this_player(), 
"Doctor Morgenes tells you: \n"+
"     What? Amerasu has sent me more adventurers? I'm sorry,\n"+
"I already gave away my moonstone. First come, first serve...\n");
    }
    return 1;
  }

  return 1;
}

