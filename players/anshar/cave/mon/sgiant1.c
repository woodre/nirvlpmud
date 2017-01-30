/*The heart beat code was done completely by Zeus
  Much appreciated!*/
#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#include "/players/anshar/closed/mydef.h"

inherit "obj/monster";

reset(arg)
{
  object club;
  ::reset(arg);
  if(arg) return;
  set_name("stone giant");
  set_race("giant");
  set_alias("giant");
  set_short("A stone giant");
  set_long(
"   This 12' tall man has grey skin and metallic looking eyes. Wearing\n\
drab grey clothing and wielding a huge club made of stone, the giant\n\
blends in easily with the caves walls.\n");
  set_level(20);
  set_hp(500);
  set_al(0);
  set_wc(30);
  set_ac(17);
  set_aggressive(0);
  call_out("whip_ass",5);
  set_chat_chance(2);
  set_a_chat_chance(15);
  load_chat("The giant grins stoically.\n");
  load_chat("Sinews creak as the giant stretches.\n");
  load_a_chat("The giant growls as it attacks.\n");
  set_chance(25);
  set_spell_dam(30);
  set_spell_mess1("The giant slams its opponent with a crushing blow.\n");
  set_spell_mess2("The giant slams you with its huge club.\n");
  club=clone_object(CWEP+"club.c");
  move_object(club,this_object());
}

whip_ass()
{
  object target;
  object envto;
  remove_call_out("whip_ass");
  envto=environment(this_object());
  if(!present(this_object())->query_attack(),envto)
  {
    target=first_inventory(envto);
    while(target)
    {
      if(target->is_player())
      {
        this_object()->attack_object(target);
        remove_call_out("whip_ass");
        call_out("whip_ass",5);
        return 1;}
        target=next_inventory(target);
    }
    remove_call_out("whip_ass");
    call_out("whip_ass",5);
    return 1;
  }
}
