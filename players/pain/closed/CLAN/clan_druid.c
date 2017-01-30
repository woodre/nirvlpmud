/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
/*
/*   Druid object for the Clan  (clan_druid.c)
/*
/*   Pain 1/24/95
/*
/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

#define SLAVE "/players/pain/closed/CLAN/clan_slave.c
#define DRUID this_object()
#define member this_player()

inherit "/obj/treasure";

reset() {
   set_short("A Druid's Staff");
   set_long("An old wooden, knarled staff, worn with age.\n"+
	    "This is no ordinary stick however, you sense some\n"+
	    "magic surrounding it.\n");
   set_weight(0);
   set_value(0);
   set_alias("staff");
}

init() {
   add_action("grasp", "grasp");
   add_action("meld", "meld");
   add_action("rain", "rain");
   add_action("lightning", "lightning");
   add_action("heal_friend", "aid");
   add_action("scry", "scry");
   add_action("hail", "hail");
   add_action("wolf_hound", "hound");
}

/*
grasp(str) {SLAVE->grasp(str); return 1;}
*/
meld() {SLAVE->meld(); return 1;};
rain(str) {SLAVE->rain(str); return 1;};
lightning(str) {SLAVE->lightning(str); return 1;};
heal_friend(str) {SLAVE->heal_friend(str); return 1;};
scry(str) {SLAVE->scry(str); return 1;};
hail(str) {SLAVE->hail(str); return 1;};
wolf_hound() {SLAVE->wolf_hound(); return 1;};




