#include "/players/feldegast/closed/ansi.h"
#include "/players/feldegast/closed/shortcut.h"
inherit "/obj/monster";

reset(arg) {
  object cane;
  ::reset(arg);
  if(!present("cane")) {
    cane=clone_object("/obj/weapon");
    cane->set_name("cane");
    cane->set_short("A wooden cane");
    cane->set_long(
"This is a meter long length of varnished wood with\n"+
"a handle carved in the shape of an elephant.\n");
    cane->set_type("polearm");
    cane->set_ac(1);
    cane->set_class(6);
    cane->set_weight(1);
    cane->set_value(200);
    move_object(cane,this_object());
  }
  if(arg) return;
  set_name("chief");
  set_short("Chief Man of the Village");
  set_long(
"     The chief man of the village was once an active and\n"+
"vigorous man.  Now he is stooped with age and grey fills\n"+
"his hair.  He leads the villagers in war and peace with\n"+
"his wisdom and guidance.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(5);
  set_wc(9);
  set_ac(5);
  set_hp(75);
  set_al(50);
  set_chat_chance(15);
  load_chat(
"\nChief says: I cannot die!\n"+
  "            My spirit's weary,\n"+
  "            My body aches,\n"+
  "            But I cannot die\n"+
  "            Till Ngana wakes!\n"
  );
  load_chat(
"\nChief says: I cannot die!\n"+
  "            Lame are my legs\n"+
  "            And blind my eyes,\n"+
  "            But I cannot sleep\n"+
  "            Till Ngana rise!\n"
  );
  load_chat(
"\nChief asks: Who will go across the jungle to awaken Ngana?\n"
  );
}

