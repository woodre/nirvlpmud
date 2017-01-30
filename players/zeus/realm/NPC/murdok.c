/*
  give him the ruby amulet and get 3500-5000 coins
  give him the onyx platemail and get the nightpikeS in return.
*/

inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
int present, dmg, a, c, sa, wc_bus, hp_bus;
object dagger, meat, *s;

reset(arg) {
   ::reset(arg);
   if (!arg) {

  dagger = CO("/players/zeus/realm/OBJ/nightpike.c");
  MO(dagger, TO);
  init_command("wield pike");

  me = 0;
  meat = 0;
  present = 0;
  wc_bus = 24;
  hp_bus = 0;
  set_name("murdok");
  set_alt_name("murdok");
  set_short("Murdok the Treasure Hunter");
  set_race("elf");
  set_long(
"This is Murdok the Treasure Hunter.  He is a well built elf, about five\n"+
"feet tall and around 170 lbs.  He is wearing a brown leather vest and\n"+
"pants.  His face is one of utter determination.  He is holding in his\n"+
"left hand a beautifully crafted pike, the tip pointing into the air.\n");
  set_gender("male");
  set_level(27); 
  set_ac(25);
/* extra params added by Illarion may 2005 */
  set_armor_params("magical",15,0,0);
  set_wc(64);
  set_wc_bonus(wc_bus);
  set_hp(1420+random(190));
  add_money(4000+random(16000));
  set_heal(1,1);
  set_al(0);
  set_aggressive(0);
  set_chat_chance(4);
  set_a_chat_chance(4);
  load_chat("Murdok glances into the forest.\n");
  load_chat("Murdok asks:  What are you doing here?\n");
  load_chat("Murdok searches the area.\n");
  load_chat("Murdok runs his hands along one of the pillars.\n");
  load_chat("Murdok glances up at you.\n");
  load_chat("Murdok looks closely at a crack in the floor.\n");
  load_chat("Murdok says:  Go away, I'm busy.\n");
  load_chat("Murdok says:  I am looking for a ruby amulet.\n");
  load_chat("Murdok says:  I am looking for a suit of onyx platemail.\n");
  load_chat("Murdok mumbles to himself.\n");
  load_chat("Murdok looks up for a second.\n");
  load_a_chat("Murdok hits you with a crushing blow!\n");
  load_a_chat("Murdok dodges your attack!\n");
  load_a_chat("Murdok grins evily at you.\n");
  set_dead_ob(this_object());
} }

monster_died()
{
  if(meat && (attacker_ob == meat))
  {
    write_file("/players/zeus/log/bigmon",
    ctime(time())+" - "+attacker_ob->query_name()+" [L "+
    attacker_ob->query_level()+"+"+attacker_ob->query_extra_level()+
    "] killed Murdok [bastard].\n");
    this_object()->set_wc_bonus(5);
    this_object()->set_hp_bonus(96);
  }
  else
  {
    write_file("/players/zeus/log/bigmon",
    ctime(time())+" - "+attacker_ob->query_name()+" [L "+
    attacker_ob->query_level()+"+"+attacker_ob->query_extra_level()+
    attacker_ob->query_level()+"+"+attacker_ob->query_extra_level()+
    "] killed Murdok.\n");
  }
  return 1; 
}

yay()
{
  if(me)
  {
    TR(environment(), "\nMurdok says:  Thank you "+me->QN+"!\n"+
      "Murdok says:  Here, for your work...\n\n");
  }
}

yay2()
{
  object money;
  TR(environment(), "Murdok uncovers a pile of coins on the ground.\n\n");
  money = CO("/obj/money");
  money->set_money(3500+random(1500));
  MO(money, environment());
}

yay3()
{
  if(me)
  {
    TR(environment(), "\nMurdok says:  Thank you "+me->QN+"!\n"+
      "Murdok says:  I've been looking for this for ages.\n"+
      "Murdok says:  Here, for your work...\n\n");
  }
}

yay4()
{
  object pk, pk2;
  pk = CO("/players/zeus/realm/OBJ/nightpikeS.c");
  pk2 = present("nightpike", this_object());
  if(pk2)
    destruct(pk2);
  if(!me->add_weight(5))
  {
    TR(environment(), "Murdok says:  Heh, you can have my NightPike...\n"+
      "Murdok says:  But you can't seem to carry it.\n\n"+
      "Murdok drops the NightPike on the ground.\n\n");
    move_object(pk, environment());
  }
  else
  {
    TR(environment(), "Murdok hands you his NightPike in exchange.\n");
    move_object(pk, me);
  }
}


void catch_tell(string str)
{
 string tmp1, tmp2, tmp3, str1, str2, str3;
 object am;
  if(sscanf(str, "%s gives amulet to Murdok%s\n", tmp1, tmp2) ||
    sscanf(str, "%s gives ruby amulet to Murdok%s\n", tmp1, tmp2)){
    am = present("ruby amulet", this_object());
    if(am)
    {
      str1 = file_name(am);
      sscanf(str1,"%s#%s",str2,str3);
      if(str2 == "players/zeus/realm/OBJ/ruby_amulet")
      {
        destruct(am);
        if(find_player(lower_case(tmp1)))
          me = find_player(lower_case(tmp1));
        call_out("yay", 1);
        call_out("yay2", 3);
        write_file("/players/zeus/log/murdok",
        ctime(time())+" - "+me->QN+" [L "+me->query_level()+
        "+"+me->query_extra_level()+"] traded the amulet.\n");
      }
    }
  } /* end if */
  if(sscanf(str, "%s gives armor %sto Murdok%s\n", tmp1, tmp3, tmp2) ||
    sscanf(str, "%s gives platemail to Murdok%s\n", tmp1, tmp2) ||
    sscanf(str, "%s gives onyx platemail to Murdok%s\n", tmp1, tmp2)){
    am = present("onyx platemail", this_object());
    if(am && !present)
    {
      str1 = file_name(am);
      sscanf(str1,"%s#%s",str2,str3);
      if(str2 == "players/zeus/realm/OBJ/onyx_platemail")
      {
        present = 1;
        init_command("wear onyx platemail");
        armor_class = 35;
        weapon_class = 56;
        if(find_player(lower_case(tmp1)))
        {
          me = find_player(lower_case(tmp1));
          meat = find_player(lower_case(tmp1));
        }
        call_out("yay3", 1);
        call_out("yay4", 3);
        write_file("/players/zeus/log/murdok",
        ctime(time())+" - "+me->QN+" [L "+me->query_level()+
        "+"+me->query_extra_level()+"] traded the armor.\n");
      }
    }
    else
      TR(environment(), "Murdok says:  Thanks for the armor.\n");
  } /* end if */

}

heart_beat(){
  ::heart_beat();
  if(!environment()) 
    return;
  if(!attacker_ob) 
    return;
  if(present(attacker_ob, environment()))
  {
    if(!random(16))
    {
      tell_room(environment(),
        "\nMurdok pulls a small red gem out of his pouch.\n"+RED+
        "As he holds it a bright flash of light explodes outward!\n"+NORM);
      s = all_inventory(environment());
      sa = sizeof(s);
      for(c = 0; c < sa; c++)
      {
        if(s[c]->is_player())
        {
          if(!random(5))
            tell_object(s[c], "\nYou manage to avert your eyes.\n");
          else {
            tell_object(s[c], RED+
              "\nThe red light saps your energy!\n\n"+NORM);
            tell_room(environment(), RED+s[c]->query_name()+
              " staggers as the red light drains "+s[c]->query_objective()+
              ".\n"+NORM, ({ s[c] }));
            if(s[c]->query_sp() > 300)
              s[c]->add_spell_point(-250);
            else if(s[c]->query_sp() > 200)
              s[c]->add_spell_point(-175);
            else if(s[c]->query_sp() > 100)
              s[c]->add_spell_point(-100);
            else
              s[c]->add_spell_point((-s[c]->query_sp()) + 10);
            s[c]->hit_player(100+random(40));
          }
        }
      }
      return;
    }
    else if(!random(14))
    {
      tell_room(environment(), "\n"+
        "Murdok grabs a handful of powder from a small pouch on his belt.\n"+
        "Murdok whispers something as he throws the powder at "+
        attacker_ob->query_name()+".\n"+RED+attacker_ob->query_name()+
        " is engulfed in a gigantic ball of fire!\n\n"+NORM,
        ({ attacker_ob }));
      tell_object(attacker_ob,
        "Murdok grabs a handful of powder from a small pouch on his belt.\n"+
        "Murdok whispers something as he throws the powder at you.\n"+RED+
        "You are engulfed in a gigantic ball of fire!\n\n"+NORM);
      attacker_ob->hit_player(70+random(50), "other|fire");
      return;
    }
  }
  if(meat && attacker_ob == meat && !random(10))
  {
    if(present(meat, environment()))
    {
      hit_point += 12;
      tell_room(environment(), 
        "Murdok pulls out a glistening dagger from his belt.\n"+
        "Murdok rips into "+meat->QN+" with a violent thrust!\n");
      meat->hit_player(30+random(70));
    }
  }
}

calculate_worth(){
  if(meat)
  {
    wc_bus += 5;
    hp_bus = 96;
  }
  set_wc_bonus(wc_bus);
  set_hp_bonus(hp_bus);
  return ::calculate_worth();
}


