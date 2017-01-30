/*
 *      File:                   tank.c
 *      Function:               
 *      Author(s):              Gemini@Nirvana
 *      Copyright:              Copyright (c) 2004 Gemini
 *                                      All Rights Reserved.
 *      Source:                 05/24/2004
 *      Notes:                  
 *      Change History:
 */

inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("tank");
  set_alias("tank");
  set_short("Tank");
  set_long(
"     Tank is a member of the Bloods Gang. He looks very strong and\n"+
"aggitated. He is wearing a red bandana and shirt with black jeans.\n"+
"He is a life long member of any one in the Crips gang. His shoes\n"+
"look very worn like he has been running a lot.\n"
);
  set_gender("male");
  set_race("human");
  set_level(14);
  set_wc(18);
  set_ac(11);
  set_hp(220);
  set_al(0);
  set_chat_chance(4);
  load_chat("Tank tells you: You betta not be fakin da funk holmes!\n");
  load_chat("Tanks flexes his muscles.\n"+
            "You become jealous.\n");
  load_chat("Someone tells you: Listen to Tank and don't fake the funk!\n");
  load_a_chat("Tank Punches you!\n");
  load_a_chat("Tank shouts: YOU WILL ONLY GET MY BANDANA OVER MY DEAD BODY!\n");
  set_dead_ob(this_object());
}

monster_died(ob) {
  object tband;
  write("Tank's muscles go limp, and he falls to the floor.\n");
  tell_room(environment(),
            this_player()->query_name()+" has killed \n",
            ({ this_player() })
  );
  tband=clone_object("/obj/armor");
  tband->set_id("bandana");
  tband->set_short("A red bandana");
  tband->set_long(
"This is a red bandana from a dead Bloods gang member.\n"
  );
  tband->set_value(750);
  tband->set_weight(1);
  tband->set_type("helmet");
  tband->set_ac(1);
  move_object(tband,environment(ob));

}

