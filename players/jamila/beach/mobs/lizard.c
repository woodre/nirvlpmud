#include "/players/jamila/define.h"

inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  set_dead_ob(this_object());
  if(arg) return;
  set_name("small lizard");
  set_alt_name("lizard");
  set_alias("reptile");
  set_short("A Small Lizard");
  set_long(
"The small lizard is running around with no direction, it\n"+
"rushes quickly over your feet and you think that this small\n"+
"creature is very cute.\n"
  );
  set_gender("female");
  set_race("reptile");
  set_level(5);
  set_wc(9+random(2));
  set_ac(5+random(2));
  set_hp(60+random(15));
  set_al(100);
  set_chat_chance(6);
  set_a_chat_chance(8);
  load_chat("The lizard runs over your feet.\n");
  load_a_chat("The lizard darts by you quickly.\n");
  set_chance(5);
  set_spell_mess1(
"\n\tThe lizard runs over its opponent's body leaving\n"+
"\t\tsmall scratches all over their flesh.\n\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"\n\tThe lizard runs over your body leaving small scratches\n"+
"\t\tall over your flesh.\n\n"
  ); /* 1ST PERSON */
  set_spell_dam(5);
}
monster_died() {
tell_room(environment(this_object()),
  "The lizard dies and you notice that its skin falls off at\n"+
  "your feet and grows large enough to fit your body.\n");
move_object(clone_object("players/jamila/beach/mobs/skin"),
        environment(this_object()));
return 1; }