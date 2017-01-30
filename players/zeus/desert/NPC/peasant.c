#include <ansi.h>
inherit "/obj/monster";
string x,y;

reset(arg){
  ::reset(arg);
  if (!arg){

  x =({ "George", "Willy","Neil", "Hank", "Billy-Bob", "Paul", "Cletus" });

  y = x[random(sizeof(x))];
  set_name(lower_case(y));
  set_alias("peasant");
  set_short("A lost peasant named "+y);
  set_race("human");
  set_gender("male");
  set_long(
"This is what appears to be a lost peasant.  He is wearing an old, faded\n"+
"shirt and blue jeans.  He seems to be holding onto some sort of white\n"+
"basket very tightly.  He looks confused about where he is.\n");
  set_level(15);
  set_ac(14);        /*  12  */
  set_wc(20);        /*  20  */
  set_hp(225);       /*  225 */
  set_al(200);
  set_chat_chance(3);
  set_a_chat_chance(1);
  load_chat(y+" asks, \"Who are you?\"\n");
  load_chat(y+" asks, \"Where am I?\"\n");
  load_chat(y+" asks, \"Could you help me find my family?\"\n");
  load_chat(y+" says, \"I don't know where I am.\"\n");
  load_chat(y+" says, \"I hate this desert.\"\n");
  load_chat(y+" says, \"Stay back stranger!\"\n");
  load_a_chat(y+" says, \"Wait til my pa hears about this!\"\n");
  load_a_chat(y+" says, \"You can't have my basket, I won't let'cha!\"\n");
  load_a_chat(y+" says, \"Someone...  won't someone please help...\"\n");
  load_a_chat(y+" says, \"I wish my pa was here, he'd whoop yur ass!\"\n");
  set_chance(20);
  set_spell_dam(15);      /* mguide ? */
  set_spell_mess1(y+" works himself up.\n");
  set_spell_mess2(y+" smashes you in the face.\n");
  set_dead_ob(this_object());
  }
}

id(str){ return str == "zeus_inculta_npc"
             || str == name || str == alt_name || str == alias; }

monster_died(){
  object g;
  tell_room(environment(), "\n\n"+y+" screams, \"You bastard!\"\n\n");
  g = present("corpse", environment()); 
  if(g)
  {
    g -> set_short("The mutilated body of "+y);
    g -> set_long(
      "This is what is left of "+y+".  You really did a number on him.\n"+
      "His body is covered in spots of blood.  His clothes now look\n"+
      "really bad, after having been torn apart from fighting with you.\n"+
      "Staring at his mutilated body, you can't help but feel bad for\n"+
      "killing him.\n");
  }
  move_object(clone_object("/players/zeus/heals/berries.c"), environment());
  if(!(random(8)))
    move_object(clone_object("/players/fred/closed/bloodfist/obj/gem.c"), environment());
}
