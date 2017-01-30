inherit "obj/monster";
#include "/players/persephone/rooms.h"
 object shield;
reset (arg){
 object hook;
 object key;
 ::reset(arg);
  if(!arg){
   key = clone_object("players/persephone/closed/goldkey");
   move_object(key, TOB);
   hook = clone_object("players/persephone/closed/arhook");
   move_object(hook, TOB);
   init_command("wield hook");
   set_name("vvladimir");
   set_alias("pirate");
   set_short("Vvladimir Lord of the Seas");
   set_long("Vvladimir the infamous and perhaps most evil of the\n" +
            "pirates to have set up a stronghold in the once Idyllic.\n" +
            "port of Stormhold.  It is rumoured that he has murdered\n" +
            "all those who try and seize control of this town.\n" +
            "Only Jeny now remains to challenge his ultimate rule.\n");
   set_level(35);
   set_wc(60);
   set_ac(32);
   set_hp(1250);
   set_al(-700);
   set_aggressive(1);
   set_gender("male");
   set_chance(20);
   set_spell_dam(40);
   set_spell_mess1("Vvladimir swings his hook around violently");
   set_spell_mess2("Vvladimir gouges your eye with his hook almost blinding you.");
   set_a_chat_chance(35);
    load_a_chat("Vvladimir screams: So you think you can mutiny\n");
    load_a_chat("Vvladimir barks out: At them men they are nothing but landlubbers.\n");
    load_a_chat("Vvladimir bellows: You will walk the plank for this\n");

 }
}

second_life()
{
    shield=clone_object("players/persephone/closed/dong");
    move_object(shield, TPL);
    this_player()->add_exp(500);
    write_file("/players/persephone/log/vvlad", capitalize(
    this_player()->query_real_name())+" killed Jeny. Level:"+
    this_player()->query_level()+". Time: "+ctime(time())+".\n");
    ::second_life();
}
