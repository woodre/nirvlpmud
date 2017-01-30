#define ENVTP environment(this_player())
#define PAL "/players/heroin/closed/paladin/pal_daemon.c"
#define TP this_player()
#define ENVENTO environment(this_object())
#define RN this_player()->query_real_name()
#define CAP capitalize
#define ENVTP environment(this_player())
#define TO this_object()
int muffled;
int misc_1, misc_2, misc_3, misc_4;
inherit "/obj/treasure";
reset(arg) {
 if(arg)
   return;
set_short("The Amulet of Thelma (worn) ");
set_weight(0);
set_value(0);
set_alias("amulet");
set_heart_beat(1);
 
id(str){ return str == "amulet" || str == "thelma" || 
    str == "amulet of thelma" || str == "notarmor"; }
 
query_auto_load() {
 return "players/heroin/closed/paladin/amulet:"
}
 
drop() {
    return 1;
}
 
long() {
write("Securily fastened around your neck is the \n"+
       "Amulet of Thelma.  The amulet stands as a reminder of\n"+
       "the golden age when Paladins still roamed Nirvana.\n"+
       "For more information type help_amulet.\n");
       return 1;
}
extra_look() {
return""+capitalize(TP->query_name())+"wears the Amulet of Thelma. (Paladin) ;
}
get() {
   return 1;
}
 
init_arg(arg) {
 }
int_arg(str) {
PAL->quild_echo("($) "+CAP(RN)+", a lawbringer, has joined you.\n");
TP->set_al_title("<PALADIN>");
}
 
}
 
init() {
::init();
 me = this_player()->query_real_name();
  add_action("recruit","recruit");
  add_action("quit", "quit");
  add_action("pal_say","psay");
  add_action("locate_player","locate");
  add_action("set_starting","setstart");
  add_action("read_news","news");
  add_action("help_files","phelp");
  add_action("pal_who", "pw");
  add_action("muffles","pal channel");
  add_action("muffles","pchan");
  add_action("pal_tell","pt");
  add_action("pal_emote","me");
/*EXTRAS NOT ACCESSABLE AT THIS TIME*/
  add_action("watch", "watch");
  add_action("send","send");
  add_action("escape", "escape");
  add_action("register","");
  add_action("follow", "follow");
}
 
 
set_starting() { PAL->set_starting(); return 1; }
recruit(str) {  PAL->recruit(str); return 1; }
battle_who() { PAL->battle_who(); return 1; }
pal_say(str) { PAL->pal_say(str); return 1; }
amulet(str) { PAL->amulet(str); return 1; }
locate_player(str) { PAL->locate_player(str); return 1; }
read_news() { PAL->news(); return 1; }
help_files(str) { PAL->help_files(str); return 1; }
pal_who() { PAL->merch_who(); return 1; }
escape() { PAL->escape(); return 1; }
}
register() { PAL->register(); return 1; }
merch_tell(str) { PAL->merch_tell(str); return 1; }
merch_emote(str) { PAL->merch_emote(str); return 1; }
quit() {
iquit = 911;
command("channel msg",this_player());
command("quit",this_player());
return 1;
}
 
/* -------- The Big Quiet -------------- */
muffles(str) {
     if(!str) {
    write("Usage: pchan <on/off>\n");
       return 1;
     }
     if(str == "off") {
       if(muffled == 1) {
   write("You are already being UNSOCIABLE.\n");
         return 1;
       } else
       muffled = 1;
   write("You close the Paladin Channel.\n");
       return 1;
     }
     if(str == "on") {
       if(muffled == 0) {
     write("You are already on the Channel.\n");
         return 1;
       } else
       muffled = 0;
    write("Paladin Channel is now open.\n");
       return 1;
     }
} 
