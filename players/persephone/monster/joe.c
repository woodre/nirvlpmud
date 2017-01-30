inherit "obj/monster";
#include "/players/persephone/rooms.h"
object juicet;
reset(arg) {
  ::reset(arg);
    if(arg) return;
      juicet = clone_object("players/persephone/heal/juice.c");
      move_object(juicet, TOB);  
      set_name("joe");
      set_alias("rat");
      set_alias("wererat");
      set_short("Joe The Rat");
      set_long("Joe is an evil wererat who seems to have been\n"+
               "mutated somehow.  He looks quick and agile and\n" +
               "is carrying a six pack of something under his arm.\n");
      set_level (16);
      set_wc (22);
      set_ac (13);
      set_hp(400);
      set_al(0);
      set_aggressive(0);
      set_gender ("male");
      set_chance(20);
      set_spell_dam(30);
      set_spell_mess1("Joe gnashes his fangs\n");
      set_spell_mess2("Joe sinks his fangs into your neck\n");
}

