/*
=======================================================
=         DEMON GUILD MASTER OBJECT                   =
=            ->Catt, december 1993                    =
=======================================================
*/


#include "/players/catt/GUILD/DEMON/LIB/demon_guild_defines.c"


/*  GLOBAL VARIABLES */
string p1, p2, p3, p4, p5, p6, p7, p8, p9, p10;
string p11, p12, p13, p14, p15, p16, p17, p18, p19, p20;
int talk_ok, health;
reset(arg) {
    if(arg) return;
           }

query_auto_load() {
   return "players/catt/GUILD/DEMON/demon_soul:"+
        p1+"&"+p2+"&"+p3+"&"+p4+"&"+p5+"&"+
        p6+"&"+p7+"&"+p8+"&"+p9+"&"+p10+"&"+
        p11+"&"+p12+"&"+p13+"&"+p14+"&"+p15+"&"+
        p16+"&"+p17+"&"+p18+"&"+p19+"&"+p20;

       /* These are for body parts (and additional powers) */
             }

init_arg(arg) {
   sscanf(arg, "%s&%s&%s&%s&%s&%s&%s&%s&%s&%s"+
               "&%s&%s&%s&%s&%s&%s&%s&%s&%s&%s",
               p1, p2, p3, p4, p5, p6, p7, p8, p9, p10,
               p11, p12, p13, p14, p15, p16, p17, p18, p19, p20);
   set_talk_ok("on");

   return;
              }
id(str) { return str == "demon_soul"; }
drop() { return 1; }
get() { return 1; }
short() { return 0; }
long() {
   write("=================================================\n");
   write("= Later this will be a general info doc for     =\n");
   write("= the guild members. *set up alias soul*        =\n");
   write("=================================================\n");
       }

query_talk_ok() { return talk_ok; }
query_health() { return health; }

init() {
      /* GENERIC GUILD COMMANDS */
   add_action("demon_talk", "de"); /*guild com channel*/
   add_action("set_talk_ok","mute"); /*guild earmuffs*/
   add_action("demon_who", "dwho"); /*guild who*/
   add_action("demon_news", "dnews"); /*guild news*/
   add_action("advance_member", "advance"); /*level advance*/
   add_action("gate_home", "sanctuary"); /*guild teleport*/
   add_action("guild_levels", "levels"); /*guild levels*/

      /* COMMANDS YOU CAN'T DO */
   add_action("dont_do", "missile");
   add_action("dont_do", "mi");
   add_action("dont_do", "shock");
   add_action("dont_do", "sh");
   add_action("dont_do", "fi");
   add_action("dont_do", "fireball");
   add_action("dont_do", "zap");
      /* GUILD SPECIFIC COMMANDS */
   add_action("guild_command", "drain"); /* corpse heal */
   add_action("guild_command", "escape"); /* cloaked teleport */
   add_action("guild_command", "form"); /* form summoning circle */
   add_action("guild_command", "summon"); /* Demon Summoning */
   add_action("guild_command", "chaos"); /* Damage spell */
   add_action("guild_command", "aura"); /* Magic Shield */
   add_action("guild_command", "disguise"); /* Guild Disguise */
   add_action("guild_command", "command"); /* Demon Command */
}

demon_talk(str) {
   object ob, guild;
   int i;
   if(!str) {
      write("Tell Demons What?\n");
      return 1;
            }
   ob = users();
   for(i=0; i < sizeof(ob); i++) {
      guild = present("demon_soul", ob[i]);
   if(guild && guild->query_talk_ok() == 1) return 1;
      if(guild && guild->query_talk_ok() == 0) {
      tell_object(ob[i], "{"+PLAYER_NAME+"} "+str+"\n");
      return 1;
      }}}


set_talk_ok(str) {
   if(!str) {
      write("Useage: {mute on/off} \n");
      return 1;
            }
   if(str == "on") talk_ok = 1;
   if(str == "off") talk_ok = 0;
   return 1;
                 }

demon_who() {
   object ob, guild;
   int i;
   string muff;
   if(query_talk_ok() == 1) muff = "yes";
   if(query_talk_ok() == 0) muff = "no";
   ob = users();
   write("========================================\n");
   write("=         DEMON GUILD MEMBERS          =\n");
   write("========================================\n");
   write("\n");
   for(i=0; i<sizeof(ob); i++) {
      guild = present("demon_soul", ob[i]);
      if(guild) {
   write("<"+ob[i]->query_level()+"> "+ob[i]->query_name()+
       "--------<muffled: "+muff+">\n");
            }
            }
   write("\n");
   write("========================================\n");
   return 1;
            }

demon_news() {
   cat(DEMON_LIB+"news");
   return 1;
             }

guild_levels() {
   cat(DEMON_LIB+"guild_levels");
   return 1;
}
guild_command(str) {
object target;
int i;

   if(!str) return 1;
      /* aura, disguise */
   if(sscanf(str, "%s %s %s", s1, s2, s3) == 2) {
   /* drain, escape, summon, form */
      return 1;
   }
   if(sscanf(str, "%s %s %s", s1, s2, s3) != 3) return;
      /* command, chaos */
}

