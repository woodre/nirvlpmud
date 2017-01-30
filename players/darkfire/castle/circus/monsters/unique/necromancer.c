/*    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */
inherit "/obj/monster";
inherit "/players/darkfire/obj/color";
inherit "/players/darkfire/obj/dfroom";

#include <ansi.h>
#include "/players/darkfire/castle/circus/circus.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("necromancer");
  set_alt_name("hinata");
  set_race("monster");
  set_alias("20k");
  set_short("Hinata the Necromancer");
  set_long("A boring necromancer. Although, unlike most necromancers, she wears a " + TIE_DYED + " shirt.\n");
  set_level(20);
  set_hp(1600);
  set_al(0);
  set_wc(30);
  set_ac(22);

	add_spell("death",
		"D: \n" + SPELL_DEATH + "\n",
		"D: \n" + SPELL_DEATH + "\n",
		10,"20-40","physical", 3 );


	add_spell("toxic",
		"T: \n" + SPELL_TOXIC + "\n",
		"T: \n" + SPELL_TOXIC + "\n",
		10,"20-40","physical", 3 );

	add_spell("cold",
		"C: \n" + SPELL_COLD + "\n",
		"C: \n" + SPELL_COLD + "\n",
		10,"20-40","physical", 3 );

	add_spell("fire",
		"F: \n" + SPELL_FIRE + "\n",
		"F: \n" + SPELL_FIRE + "\n",
		10,"20-40","physical", 3 );

}