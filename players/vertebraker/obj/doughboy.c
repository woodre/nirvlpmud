#include <ansi.h>

inherit "/obj/monster";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("Poppin' Fresh");
  set_short(HIW+"Poppin' Fresh the Pillsbury Dough Boy"+NORM);
  set_long("\
A doughman, puffy and ready to poke!\n");
  set_level(10);
  set_race("dough");
  SetMultipleIds(({"poppin' fresh","fresh","poppin","dough boy","boy","dough"}));
}

init(){
  ::init();
  add_action("cmd_poke","poke");
}

cmd_poke(str)
{
  if(id(str))
  {
    call_out("tee_hee", 3);
  }
}

tee_hee()
{
  say(query_name()+" lets out a bellowing \""+HIW+"TEE HEE"+NORM+"\"!\n");
}
