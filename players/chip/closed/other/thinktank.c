/*
*      Function:
*      Change History:
*/
#include <ansi.h>
inherit "/room/room";
string *temp;
int x,y;

reset(arg)
{
::reset(arg);
if(arg) return;
set_light(1);
short_desc = "Prison Sex";
  long_desc =
	"You can't do a god damn thing worth doing here.\n";
  items =
({
"walls",
"The walls are plain white, but seem to fluctuate a little bit, as\n"+
"if they are alive",
});
}
  init(){
    add_action("block", "gossip");
    add_action("block", "emotes");
    add_action("block", "load");
    add_action("block", "update");
    add_action("block", "who2");
    add_action("block", "who");
    add_action("block", "twho");
    add_action("block", "s_who");
    add_action("block", "fri");
    add_action("block", "friends");
    add_action("block", "cwho");
    add_action("block", "awho");
    add_action("block", "templar");
    add_action("block", "users");
    add_action("block", "p");
    add_action("block", "people");
    add_action("block", "devs");
    add_action("block", "star");
    add_action("block", "shout");
    add_action("block", "babble");
    add_action("block", "risque");
    add_action("block", "tell");
    add_action("block", "say");
    add_action("block", "net");
    add_action("block", "onet");
    add_action("block", "id");
    add_action("block", "te");
    add_action("block", "tt");
    add_action("block", "gt");
    add_action("block", "gpt");
    add_action("block", "rt");
    add_action("block", "rte");
    add_action("block", "att");
    add_action("block", "at");
    add_action("block", "newbie");
    add_action("block", "wiz");
    add_action("block", "dest");
    add_action("block", "idest");
    add_action("block", "emote");
    add_action("block", "tc");
    add_action("block", "tl");
    add_action("block", "force");
    add_action("block", "vibe");
    add_action("block", "whisper");
    add_action("block", "farem");
    add_action("block", "mail");
    add_action("block", "echo");
    add_action("block", "echoto");
    add_action("block", "echoall");
    add_action("block", "echochan");
    add_action("block", "quit");
    add_action("block", "page");
    add_action("block", "i");
    add_action("block", "I");
    add_action("block", "IR");
    add_action("block", "htell");
    add_action("block", "stell");
    add_action("block", "ed");
    add_action("block", "home");
    add_action("block", "place");
    add_action("block", "move");
    add_action("block", "execute");
    add_action("block", "kick");
    add_action("block", "smack");
    add_action("block", "ping");
    add_action("block", "ripsack");
    add_action("block", "tp");
    add_action("block", "teleport");
    add_action("block", "summon");
    add_action("block", "accept");
    add_action("block", "clone");
    add_action("block", "hand");
    add_action("block", "xfer");
    add_action("block", "escape");
    add_action("block", "panic");
    add_action("block", "castle");
    add_action("block", "edit");
    add_action("block", "cp");
    add_action("block", "rm");
    add_action("block", "tt");
    add_action("block", "te");
    add_action("block", "tf");
    add_action("block", "rt");
    add_action("block", "rte");
    add_action("block", "at");
    add_action("block", "att");
    add_action("block", "ate");
    add_action("block", "gt");
    add_action("block", "gpt");
    add_action("block", "net");
    add_action("block", "nem");
    add_action("block", "onet");
    add_action("block", "onem");
    add_action("block", "junk");
    add_action("block", "announce");
    add_action("block", "admin");
    add_action("block", "derv");
    add_action("block", "derve");
    add_action("block", "vibe");
    add_action("block", "nc");
    add_action("block", "nce");
    add_action("block", "echostar");
    add_action("block", "emotestar");
    add_action("block", "ct");
    add_action("block", "ht");
    add_action("block", "bf");
    add_action("block", "id");
    add_action("block", "ide");
    add_action("block", "mt");
    add_action("block", "dragon");
    add_action("block", "mount");
    add_action("block", "deathknight");
    add_action("block", "dk");
    add_action("block", "lich");
    add_action("block", "changeform");
    add_action("block", "sc");
    add_action("block", "sc2");
    add_action("block", "rsc");
    add_action("block", "goto");
    add_action("block", "church");
    add_action("block", "green");
    add_action("block", "farem");
    add_action("block", "createchat");
    add_action("block", "addmem");
    add_action("block", "emotef");
    add_action("block", "exec");
    add_action("block", "imprison");
    add_action("block", "run");
    add_action("block", "do");
    add_action("block", "wkrm");
    add_action("block", "cat");
    add_action("block", "tail");
    add_action("block", "dump");
    add_action("block", "more");
    add_action("block", "nmore");
    add_action("block", "mv");
    add_action("block", "cd");
    add_action("block", "pwd");
    add_action("block", "cp_dir");
    add_action("block", "mkdir");
    add_action("block", "rmdir");
    add_action("block", "clear_dir");
    add_action("block", "upd_dir");
    add_action("block", "clean");
    add_action("block", "update_items");
    add_action("block", "reset");
    add_action("block", "log");
    add_action("block", "free");
    add_action("block", "localcmd");
    add_action("block", "light");
    add_action("block", "hands");
    add_action("block", "invis");
    add_action("block", "vis");
    add_action("block", "earmuffs");
    add_action("block", "wizlist");
    add_action("block", "peace");
    add_action("block", "grep");
    add_action("block", "instances");
    add_action("block", "identify");
    add_action("block", "wizbook");
    add_action("block", "errormsgs");
    add_action("block", "in");
    add_action("block", "at");
    add_action("block", "authcheck");
    add_action("block", "add_xp");
    add_action("block", "heal");
    add_action("block", "money");
    add_action("block", "valias");
    add_action("block", "vhistory");
    add_action("block", "attrib");
    add_action("block", "set_attrib");
    add_action("block", "demote");
    add_action("block", "fix_guild");
    add_action("block", "zap");
    add_action("block", "climbin");
    add_action("block", "set_extra");
    add_action("block", "vnickname");
    add_action("block", "put!");
    add_action("block", "idest");
    add_action("block", "set_home");
    add_action("block", "approve");
    add_action("block", "drop");
    add_action("block", "get");
    add_action("block", "snoop");
    add_action("block", "set_level");
    add_action("block", "exiv");
    add_action("block", "give!");
    add_action("block", "get");
    add_action("block", "drop");
    add_action("block", "put");
    add_action("block", "give");
    add_action("block", "statall");
    add_action("block", "load_dir");
    add_action("block", "gauge");
    add_action("block", "ruler");
    add_action("block", "trans!");
    add_action("block", "setmhome");
    add_action("block", "work");
    add_action("block", "review");
    add_action("block", "1000");
    add_action("block", "group_convert");
    add_action("block", "mysql");
    add_action("block", "mysqlshow");
    add_action("block", "player_convert");
    add_action("block", "remove_player");
    add_action("block", "shutdown");
    add_action("block", "time");
    add_action("block", "valid_list");
    add_action("block", "boot");
    add_action("block", "nuke");
    add_action("block", "soul");
    add_action("block", "help");
    add_action("block", "wizhelp");
    add_action("block", "xpnext");
    add_action("block", "bootxp");
    add_action("block", "status");
    add_action("block", "mi");
    add_action("block", "sh");
    add_action("block", "fi");
    add_action("block", "so");
    add_action("block", "kill");
    add_action("block", "assist");
    add_action("block", "register");
    add_action("block", "beatfix");
    add_action("block", "bug");
    add_action("block", "typo");
    add_action("block", "idea");
    add_action("block", "patch");
    
    
    y = sizeof((temp = get_dir("/bin/soul/")));

    for(x=0; x < y; x++)
      if(sscanf(temp[x], "_%s.c", temp[x]) == 1)
         add_action("block", temp[x]);
    
}

catch_tell(string str){
	 tell_room("/players/chip/myworkroom.c", str);
}

block(string str){
if(this_player()->query_real_name() != "chip"){ write("You aren't trying hard enough yet.\n"); return 1; }
if(this_player()->query_real_name() == "tristian"){ write("Tristian is stuck. As usual. Teach you to be a fucking smartass!\n"); return 1; } return 0; }

