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
   add_action("ctouch", "grasp");
   add_action("meld", "meld");
   add_action("rain", "rain");
   add_action("lightning", "lightning");
   add_action("heal_friend", "aid");
   add_action("scry", "scry");
   add_action("hail", "hail");
   add_action("wolf_hound", "hound");
}

