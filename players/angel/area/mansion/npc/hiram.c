#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

inherit "obj/monster";

int lives;
int H;
  
reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("Hiram Abif");
  set_alt_name("mason");
  set_alt_name("abif");
  set_race("master mason");
  set_alias("Hiram");
  set_short(HIB+"Hiram Abif"+NORM);
  set_long("\Grand Master Hiram Abif is the Grand Architect of\n\
King Solomon’s Temple. Hiram knows secret which, by its mere\n\
possession, a person would be allowed to pass himself off as a\n\
Master Mason, or journeyman builder. Secrets that can only be\n\
obtained by the death of Hiram Abif.\n");
  set_level(28);
  set_hp(1666 + random (400));
  set_ac(30 + random (12));
  set_wc(48 + random (12));
  set_al(0);
  set_ac_bonus (30);
  set_wc_bonus (60);
  set_hp_bonus (2500);
  set_dead_ob(this_object());
  set_aggressive(0);
  set_chat_chance(5);
  load_chat(query_name()+" says, \"Come be "+HIW+"Re-Born"+NORM+"!\"\n");
  gold=clone_object("obj/money");
  gold->set_money(50000);
  move_object(gold, this_object());
  weapon=clone_object("/players/angel/area/mansion/obj/masonic_sword_01.c");
  move_object(weapon, this_object());
  command("wield sword", this_object());
  add_spell("sword","#MN# slices his "+HIY+"M"+HIW+"asonic"+NORM+" "+HIY+"S"+HIW+"word"+NORM+" through you.\n",
                     "#MN# slices his "+HIY+"M"+HIW+"asonic"+NORM+" "+HIY+"S"+HIW+"word"+NORM+" through #TN#.\n",
                     50,100,"other|fire");
}

life_check()
{
  if(!present(attacker_ob, environment())) return;
  lives--;
  if(lives == 3) set_heal(3,1);
  else
  if(lives == 1) set_heal(4,1);
  tell_room(environment(), HIW +
            "\nHiram prays to God for devine intervention!\n\n" + NORM);
  hit_point += 900+random(300);
  set_wc(query_wc() + 10 + random(8));
  set_ac(query_ac() + 6 + random(5));
}

heart_beat()
{
  object ob;
  ::heart_beat();
  corpse_grab();
  if(attacker_ob)
  {
    already_fight=0;
    attack();
    H = random(10);
    if(attacker_ob)
    {
      if(H <= 2) H_dodge();
      if(H == 3) H_strike();
      if(H == 4) H_heal();
      if(H == 5) H_heal2();
      if(H == 6) H_rath();
      if(H >= 7) H_revitalize();
    }
  }
  if(lives && hit_point <= 400)
    life_check();
}

H_dodge()
{
  tell_room(environment(this_object()),
  "Hiram dodged your pathetic attack.\n");
  return;
}

H_strike()
{
  tell_room(environment(this_object()),
    "Hiram shatters "+attacker_ob->query_name()+
    " to pieces with the hilt of his sword.\n");
  call_other(attacker_ob,"hit_player",random(30)+15);
  return;
}

H_heal()
{
  tell_room(environment(this_object()),
    "Hiram takes a heal from his apron.\n"+
    "Hiram drinks a "+BROWN+"kahula"+NORM+".\n");
  heal_self(random(50));
  return;
}

H_heal2()
{
  tell_room(environment(this_object()),
           "Hiram takes a heal out of a apron.\nHiram eats some " + HIY + "cheese"+NORM+".\n");
  heal_self(random(50));
  return;
}

H_revitalize()
{
  tell_room(environment(this_object()),
    "Hiram summons his God to revitalize his sword with the spirt.\n\n"+
    "The sword exuberates the "+BLINK+HIW+" F O R C E "+NORM+
    " with in the spirit.\n\n");
  call_other(attacker_ob,"hit_player",random(30)+5);
  return;
}

H_rath()
{
  tell_room(environment(this_object()),
           "Hiram summons the rath of God..\n"+HIW+"\n"+
           "       God's enraged Spirit "+BLINK+HIW+"lacerate's"+NORM+" "+attacker_ob->query_name()+".\n"+NORM+"\n");
  call_other(attacker_ob,"hit_player",random(40)+50);
  return;
}

corpse_grab()
{
  object ob;
  if((ob = present("corpse", environment())) && (int)ob->is_corpse())
  {
    tell_room(environment(),
    "Hiram takes: "+(string)ob->short()+".\n");
    move_object(ob, this_object());
    corpse_grab();
  }
}

monster_died()
{
  say(""+BOLD+"King Solomon comes forward!\n\n\n\
King Solomon starts praying for the salvation of the fallen martyr!\n\
\n\nO' come to life again, RISE from the dead!\n\
\n\nO' come to LIFE again, RISE from the DEAD!\n\
\n\nO' COME TO LIFE AGAIN AND NOW RISE FROM THE DEAD!"+NORM+"\n");
  move_object(clone_object("/players/angel/area/mansion/npc/hiram_02.c"),
              environment(this_object()));
}
