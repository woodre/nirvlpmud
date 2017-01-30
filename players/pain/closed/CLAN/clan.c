/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
/*                                                                    */
/*      Guild Item for the Clan McKay                                 */
/*                                                                    */
/*	Pain 01/23/95                                                 */
/*                                                                    */
/*	Main Object Filename: clan.c                                  */
/*      Slave Object Filename: clan_slave.c                           */
/*                                                                    */
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

#define SLAVE "/players/pain/closed/CLAN/clan_slave.c"
#define KILT this_object()
#define member this_player()
#define m_name member->query_real_name()
#define m_sp this_player()->query_sp()
#define m_hp this_player()->query_hp()
#define m_gl this_player()->query_guild_level()
#define m_gx this_player()->query_guild_exp()

inherit "/obj/treasure";

int muff;
int color;
string faction;

query_muffs() { return muff; }
set_muffs(str) { muff = str; }
query_faction() { return faction; }
set_faction(str) { faction = str; }
query_color() { return color; }
set_color(str) { color = str; }


reset(arg) {
   if(arg)
	return;
   set_short("Kilt of the Clan McKay (worn)");
   set_long("A beautiful kilt made of wool with the Tartan of the Clan\n"+
	    "displayed proudly on it. The Kilt pin displays the crest of\n"+
	    "Clan and bears the motto 'Manu Forti'\n");
   set_weight(0);
   set_value(0);
   set_alias("kilt");
   muff = 0;

   /* Clone the factions object to the player */

   if(faction == "clan_druid") {
      object druid;
      druid = clone_object("/players/pain/closed/CLAN/druid_obj.c");
      move_object(druid,member);
      }
   if(faction == "clan_sword") {
      object sword;
      sword = clone_object("/players/pain/closed/CLAN/sword_obj.c");
      move_object(sword,member);

   /* For players who just joined the guild we must set their guild rank
      and guild experience */
   if(m_gl < 1)
	member->add_guild_rank(1);
   if(m_gx < 1)
	member->add_guild_exp(1);
}
}


drop() { return 1; }

get() { return 1; }

init_arg(arg) {
   if(m_gl < 20)
	cat("/players/pain/closed/CLAN/clan_news");
}

init() {
   ::init();
   add_action("help_clan", "clanhelp");
   add_action("clan_levels", "clan_levels");
   add_action("clan_costs", "level_costs");
   add_action("call_to_action", "call");
   add_action("quick_hp", "hps");
   add_action("clan_talk", "chat");
   add_action("clan_emote", "chate");
   add_action("apprentice", "apprentice");
   add_action("members", "members");
   add_action("mud_who", "mw");
   add_action("guild_title", "set_title");
   add_action("muffles", "muffles");
}

help_clan() { SLAVE->help_clan(); return 1; }
clan_levels() { SLAVE->clan_levels(); return 1; }
call_to_action() { SLAVE->call_to_action(); return 1; }

quick_hp() {
   write("[ "+m_name+": HP: "+m_hp+" SP: "+m_sp+" ]\n");
   return 1;
}

clan_talk(str) { SLAVE->clan_talk(str); return 1; }
clan_emote(str) { SLAVE->clan_emote(str); return 1; }
apprentice(str) { SLAVE->apprentice(str); return 1; }
members() { SLAVE->members(); return 1; }
mud_who() { SLAVE->mud_who(); return 1; }
guild_title() { SLAVE->guild_title(); return 1; }

muffles(str) {
   if(!str) {
      write("Usage: muffles <on/off> \n");
      return 1;
   }
   if(str == "off") {
      if(str == 1) {
	 write("You are not on the Clan's Channel!\n");
	 return 1;
      }
      muff = 1;
      write("You close the Clan's Channel.\n");
      return 1;
   }
   if(str == "on") {
      if(str == 0) {
	 write("You are already on the Clan's Channel!\n");
	 return 1;
      }
      muff = 0;
      write("You rejoin the Clan's Channel.\n");
      return 1;
   }
}
