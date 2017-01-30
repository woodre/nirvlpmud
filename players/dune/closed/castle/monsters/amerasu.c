inherit "obj/monster";
#include "definitions.h"

int sung;


reset(arg)
{
  sung = 0;

  ::reset(arg);
  if(arg) return;
  set_name("Amerasu");
  set_alias("amerasu");
  set_short("Amerasu, First Grandmother of the Sithi");
  set_level(15);
  set_race("sithi");
  set_hp(225);
  set_wc(20);
  set_ac(11);
  set_al(900);
  set_long(
"     Amerasu is the last Queen of the Sithi. She is an exotic beauty.\n"+
"Long white hair rests upon her small shoulders. Her eyes are those\n"+
"of an ancient being, one who has seen centuries flow by like water in a\n"+
"stream.\n");
  enable_commands();
  set_chat_chance(25);
  load_chat("Amerasu says: I need your help.\n");
  load_chat("Amerasu weeps.\n");
}


catch_tell(string str)
{
  string msg;

  str = lower_case(str);

  if (this_player() == this_object()) return;

  if (sscanf(str,"%shelp%s", msg))
  {
    TE(TP, 
    "Amerasu tells you:\n"+
    "     Noble adventurer, I am in desperate need of your help!\n"+
    "My people, the Sithi, have been enslaved by an ancient and horrible\n"+
    "devil named Demosater. He deceived his way into the Sithi\n"+
    "high leadership and poisoned the minds of our lords, whom he now\n"+
    "commands for his own. Our civilization has collapsed, and our great\n"+
    "cities have fallen. I have fled the cities to rest here in the garden,\n"+
    "but I am not safe for long.\n"+
    "     You must destroy him! Bring back to me the seven Sithi Stones,\n"+
    "which you will find on each of the Sithi Lords. Each Lord is the\n"+
    "ruler of the seven lost Sithi cities. Thus, you will need to find\n"+
    "all the lost cities... which will not be easy.\n"+
    "     If you are successful, then I will tell you how to use the\n"+
    "Stones to find Demosater. Ask me about the Diagram when you are ready.\n"+
    "     Now seek first the Moonshrine, for only in certain phases of the\n"+
    "Lothlorien moon will you be able to enter the magical Sithi cities.\n"+
    "     If you are confused about the Moonshrine, I can explain more.\n");
    return 1;
  }

  if (sscanf(str,"%smoon%s", msg))
  {
    TE(TP,
    "Amerasu tells you:\n"+
    "     The lost Cities can only be reached during proper phases\n"+
    "of the moon. You must learn patience, and you must learn where\n"+
    "the cities will appear. For when the moon shifts phase, the city\n"+
    "of the old phase shifts out of dimension, and the city of the\n"+
    "new phase shifts into dimension. Only one city will exist\n"+
    "in your dimension at any one time. Furthermore, cities do not appear\n"+
    "in the same place all the time. So, you must know where to look\n"+
    "and when to look.\n"+
    "     Because you have no way of leaving a city once you enter it,\n"+
    "you should get a moonstone. I believe my good friend Doctor Morgenes\n"+
    "had one last. Seek the Elemental Tower, you will find him there.\n");
    return 1;
  }

  if (sscanf(str,"%sdoctor%s", msg)   ||
      sscanf(str,"%smorgenes%s", msg) ||
      sscanf(str,"%stower%s", msg))
  {
    TE(TP,
    "Amerasu tells you:\n"+
    "     Doctor Morgenes is first and foremost a historian.\n"+
    "He is also a practioner of magick. His home is the Elemental Tower,\n"+
    "which is located in the Lothlorien foothills. Seek him out and\n"+
    "get a moonstone, otherwise you will be able to enter a Sithi city\n"+
    "but not return.\n");
    return 1;
  }

  if (sscanf(str,"%sdiagram%s", msg))
  {
    TE(TP,
    "Amerasu tells you:\n"+
    "     Long ago, my people built a secret chamber. A place protected\n"+
    "from all forms of magick and dimensional travel. In this chamber,\n"+
    "we placed our history, lore, and mystical secrets... and we secured\n"+
    "this chamber with an unbreakable door. This door is the Sithi Diagram,\n"+
    "a portal requiring seven keys: the seven Sithi Stones, for entry.\n"+
    "     Demosater is using the secret chamber's dimensional energies\n"+
    "to transport himself into Lothlorien. Once this happens, he will be\n"+
    "unstoppable. So, you must unlock the Diagram and destroy Demosater.\n"+
    "Once you have defeated him, come back to Lothlorien and you will be\n"+
    "rewarded. Use the shimmering portal in the chamber to return.\n");
    if (!sung)
    {
      TE(TP,
      "     If you wish me to guide you to the Diagram, then ask me to\n"+
      "sing the song of Jingizu.\n");
    }
    return 1;
  }

  if (sscanf(str,"%sjingizu%s", msg))
  {
    if(!sung)
    {
      TE(TP,
      "Amerasu tells you:\n"+
      "     We now depart for the Diagram. Follow me!\n\n"+
      "Amerasu leaves the garden.\n");
      load_chat("Unlock the Diagram and destroy Demosater!\n");
      move_object(this_object(), CASTLEROOM+"/green6.c");
      sung = 1;
      call_out("guide1", 15, this_object());
    }

    return 1;
  }

  return 1;
}


guide1(object ob)
{
  command("south", TO);
  call_out("guide2", 15, this_object());
  return 1;
}

guide2(object ob)
{
  command("west", TO);
  call_out("guide3", 15, this_object());
  return 1;
}

guide3(object ob)
{
  command("south", TO);
  call_out("guide4", 15, this_object());
  return 1;
}

guide4(object ob)
{
  command("west", TO);
  call_out("guide5", 15, this_object());
  return 1;
}

guide5(object ob)
{
  command("west", TO);
  call_out("guide6", 15, this_object());
  return 1;
}

guide6(object ob)
{
  command("west", TO);
  call_out("guide7", 15, this_object());
  return 1;
}

guide7(object ob)
{
  command("north", TO);
  call_out("guide8", 15, this_object());
  return 1;
}

guide8(object ob)
{
  command("north", TO);
  call_out("guide9", 15, this_object());
  return 1;
}

guide9(object ob)
{
  command("west", TO);
  call_out("guide10", 15, this_object());
  return 1;
}

guide10(object ob)
{
  command("north", TO);
  call_out("guide11", 15, this_object());
  return 1;
}

guide11(object ob)
{
  command("enter", TO);
  return 1;
}
