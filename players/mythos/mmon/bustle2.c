inherit "obj/monster";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_alias("messenger");
  set_level(1);
  set_hp(1000);
  set_al(-1000);
  set_wc(0);
  set_ac(1000);
  set_aggressive(0);
  set_chat_chance(15);
    load_chat("A breeze whispers in your ear, \n"+
             "'Enter the HUT for LOW to MID level adventuring.'\n");
    load_chat("The wind speaks of the pub and shop that \n"+
              "exist at the enterance to the village.\n");
    load_chat("Enter the fields and head to the forest for a high level area.\n");
    load_chat("Goto the Shrine to be healed/resurrected/cured.\n");
    load_chat("Goto the village smithy or shrine.\n");
    load_chat("Find the Path within the forest to the Dark Tower!\n");
    load_chat("Seek the sandy place- the Great Ones reside there.\n");
}
