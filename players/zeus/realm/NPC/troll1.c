inherit "/obj/monster";
#include "/players/zeus/closed/all.h"

object hatchet;
int hug;

void reset(status arg){
  ::reset(arg);
  if(!arg){

  hatchet = CO("/players/zeus/realm/OBJ/hatchet.c");
  MO(hatchet, TO);
  init_command("wield hatchet");

  set_name("troll");
  set_short("A troll");
  set_long(
"This is a nasty looking little troll.  His pale green skin is speckled\n"+
"with brownish spots and protruding bumps.  His narrow head is\n"+
"highlighted with a tuft of greasy black hair.  His face is creased\n"+
"in a constant scowl.\n");
  set_level(19);
  set_ac(17);
   /* Traditional troll vulnerability <illarion> */
  set_armor_params("other|fire",0,-25,0);
  set_res(20);
  set_wc(30);
  set_hp(550);
  set_race("troll");
  set_gender("male");
  set_al(-100);
  add_money(3000+random(500));
  set_chat_chance(4);
  load_chat("The troll scowls at you.\n");
  load_chat("The troll murmurs to himself.\n");
  load_chat("The troll scratches his skin.\n");
  load_chat("The troll looks around nervously.\n");
  load_chat("The troll grins.\n");
  set_chance(30);
  set_spell_dam(40);
  set_spell_mess1("The troll lunges at you!\n");
  set_spell_mess2("The troll smashes you with his hatchet!\n");
}  }

int hug(){   return hug();  }

void init(){
  ::init();
  add_action("hug_cmd", "hug");
  hug = 0;
}

hug_cmd(str)
{
  me = TP;
  if(id(str))
  {
    write("You give the troll a big, friendly hug...\n");
    if(hug != 0)
      call_out("hug_p3", 1);  
    else
      call_out("hug_p2", 1);
  }
}

hug_p2()
{
 TR(environment(TO),
   "The troll scowls at "+me->QN+".\n", ({ me }));
  tell_object(me, "The troll pushes you away and scowls at you.\n");
  hug = 1;
}

hug_p3()
{
  TR(environment(TO),
   me->QN+" walks over to the troll and hugs him.\n"+
 "The troll pushes "+me->QN+" away, then lunges at "+me->OBJ+"!\n",({me}));
  tell_object(me, "The troll pushes you away, then lunges at you!\n");
  me->attack_object(TO);
  TO->attack_object(me);
  hug = 0;
}
