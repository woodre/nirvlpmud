inherit "/players/mizan/opl/core/monster.c";
#include "/players/mizan/opl/definitions.h"
#include "/obj/ansi.h"

int count;

reset(arg)
{
    object gold;
    string my_name;

    ::reset(arg);
    if (arg) return;


    my_name = WOOKIE_DM->get_name();

    set_name(my_name);
    set_race("wookiee");
    set_alt_name("wookie");
    set_alias(lower_case(my_name));
    set_short("A Wookiee named " + my_name);
    set_long(
"    Before you stands a hairy, tall, yet noble creature of the trees.\n"+
"  Excepting that there are no trees in sight, only gigantic fungal stalks,\n"+
"  this would seem like a perfectly normal situation. However it is far from\n"+
"  normal, and you know this. New strategy? Let the Wookiee win. \n");
    set_level(STATS_DM->get_level_medium());
    set_hp(STATS_DM->get_hp_medium());
    set_al(700);
    set_wc(STATS_DM->get_wc_medium());
    set_ac(STATS_DM->get_ac_medium());
    set_hp_bonus(STATS_DM->get_hp_bonus_medium());

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 2;

    set_heal(65, 3);

    set_chance(30);
    set_spell_dam(200);
    set_spell_mess1(short() + " goes for Pugachev's Gambit...\ni.e. he tries to " + HIR + "RIP YOUR FREAKING ARMS OFF.\n" + NORM);
    set_spell_mess2(short() + " clobbers you in the jimmy with such spectacular force...\nYou wish your arms were ripped off instead.\n");

    gold = clone_object("obj/money");
    gold->set_money(STATS_DM->get_gold_medium());
    move_object(gold,this_object());

    if (1 == random(5)) set_random_move_time(60);

/*  Moved this code to heart_beat so it won't run when there's nobody around to see it. - ill 2015.08.18

    remove_call_out("fake_beat");
    call_out("fake_beat", 15);
    */
}

heart_beat() {
  ::heart_beat();
  if(count++ > 8 )
  {
    count = 0;
    if(!attacker_ob) comment();
  }
}

/*
fake_beat()
{
    if (!attacker_ob) comment();
    remove_call_out("fake_beat");
    call_out("fake_beat", 15);
}
*/

comment()
{
    string result;
    string haiku;
    object ob, oc, room;

    room = environment(this_object());
    if(!room) return;

    result = WOOKIE_DM->get_aargh();
    haiku = WOOKIE_DM->get_fact();

    ob = first_inventory(room);

    while(ob)
    {
        oc = next_inventory(ob);

        if(ob->is_player())
	{
	    if(present("wookiee-translator", ob))
                tell_object(ob, query_name() + " says: " + HIW + haiku + NORM + "\n\n");
            else
		tell_object(ob, query_name() + " grunts: " + HIW + result + NORM + "\n");

        }
        ob = oc;
    }
}
