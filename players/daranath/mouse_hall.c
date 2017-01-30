#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>

inherit "room/room";

reset(arg) {
  if(arg) return;

set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(City Ward)");
long_desc =
"                   /`.    /`.\n"+
"                  f   \\  ,f  \\\n"+
"      Gee Brain,  |    \\/-`\\  \\      The same thing we do\n"+
"   what do you    i.  _\\';.,X j      every night, Pinky.\n"+
"     want to do    `:_\\ (  \\ \\',-.   Try to take over\n"+
"          tonight?   .'\"`\\ a\\eY' )   the world!  _,.\n"+
"                     `._\"\\`-' `-/            .-;'  |\n"+
"                       /;-`._.-';\\.        ,',\"    |\n"+
"                     .'/   \"'   | `\\.-'\"\"-/ /      j\n"+
"                   ,/ /         i,-\"        (  ,/  /\n"+
"                .-' .f         .'            `\"/  /\n"+
"               / ,,/ffj\\      /          .-\"`.'-.'\n"+
"              / /_\\`--//)     \\ ,--._ .-'_,-'; /\n"+
"             f  \".-\"-._;'      `._ _.,-i; /_; /\n"+
"             `.,'   |; \\          \\`\\_,/-'  \\'\n"+
"              .'    l \\ `.        /\"\\ _ \\`  j\n"+
"              f      : `-'        `._;.\"/`-'\n"+
"              |      `.               ,7  \\\n"+
"              l       j             .'/ - \\`.\n"+
"             .j.  .   <            (.'    .\\ \\f`. |\\,'\n"+
"            ,' `.  \\ / \\           `|      \\,'||-:j\n"+
"          .'  .'\\   Y.  \\___......__\\ ._   /`.||\n"+
"  __.._,-\" .-\"'\"\")  /' ,' _          \\ |  /\"-.`j\"\"``---.._\n"+
"    .'_.-'\"     / .(\"-'-\"\":\\        ._)|_(__. \"'\n"+
"   ;.'         /-'---\"\".--\"'       /,_,^-._ .)\n"+
"   `:=.__.,itz `---._.;'           \"\"      \"\"\n"+
"\n";
set_light(0);


dest_dir = ({
  "players/maledicta/workroom.c","west"
});

}

init(){
::init();
add_action("get_tool", "tool");
add_action("withdraw","withdraw");
add_action("list", "list");
add_action("deposit","deposit");
add_action("buylocker","buy");
}

deposit(str){
"/players/catwoman/tl.c"->deposit_item(str);
return 1;
}
buylocker(str){
"/players/catwoman/tl.c"->buy_locker(str);
return 1;
}
list(){
"/players/catwoman/tl.c"->list();
return 1;
}
withdraw(str){
"/players/catwoman/tl.c"->withdraw_item(str);
return 1;
}
get_tool(){
if(this_player()->query_level() < 70 && this_player()->query_real_name() != "malice"){
return 0;
}
move_object(clone_object("/players/maledicta/tellobj.c"), this_player());
return 1;
}



  
query_spar_area(){ return 1; }
player_spar_only(){ return 1; }
