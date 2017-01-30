#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("Ion");
  set_alt_name("drive");
  set_race("hard drive");
  set_alias("ion");
  set_short("Ion hard drive");
  set_long("\
  Ion combo 3.5 160GB external hard drive with a maximum\n\
capacity of 160GB, you can store large multimedia files,\n\
digital photos, MP3s and other important documents in it. It\n\
supports extremely high data transfer rates of up to 400\n\
Mbps. It has a FireWire and 480Mbps USB 2.0. The Ion combo\n\
3.5 160GB external hard drive connects to USB 2.0/1.1 and\n\
uses a Macfee firewall.\n");
  set_level(22);
  set_hp(590 + random (120));
  set_ac(22 + random (9));
  set_wc(38 + random (9));
  set_al(0);
  set_chat_chance(15);
  load_chat(query_name()+" says, \"I am about to fry you to pieces!\"\n");
  load_chat("The firewall runs through your circuits checking for viruses!\n");
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  add_spell("Zap","#MN#'s firewall $HR$Zaps$N$ the virus in you.\n",
                     "#MN#'s firewall $HR$Zaps$N$ the virus #TN#.\n",
                     60,60,"other|electric");
}
