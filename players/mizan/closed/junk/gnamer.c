id(str) { return str == "gnamer"; }

short() { return "A clunky gnamer"; }

long() { write("Type 'gname'.\n"); }

init() { add_action("guildnameme","gname"); }

guildnameme() {
this_player()->set_guild_name("\n              .,,;;;;;;;;,,..\n"+
"           .,;;;;;;;;;;;;;;;;;;;,.\n"+
"         ,;;,;;;;;;;;;;;;;;;;;;;;;;;,.\n"+
"       ,;;,;;;;;;;;;;;;;;;;;;,;;;;;;;;;;.  ..,,.\n"+
"    .,;,;;;;;;;;;;;;;;;;;;;,;;;;;;;;;;;;;,;;;;;;;,.\n"+
" ,;;;;;;;;;;;;;;;,;;;;;;vv;;;;;;vvvnnnnvv;;;;;;;;;,;,.\n"+
";;;;;;;;;;;;;;,;;;;;vvvvv;;;vvvnnnnnnnvv;;,;;;;;;;;,;;;,.\n"+
";;;;;;;;;;;,;;;;;vvvvvvv;;vvvnnnnnnnnvv;;;;;,;;;;;;;,;;;;;.\n"+
"`;;;;;;;;';;;;vv......vvv;vvv.......vvvv;;;;;;,;;;;;;;;;;;;;,\n"+
"         .;;vv..vvvvvvv.vnnn.vvvvvvv...vvv;;;;;;;;;;;;;;;;;;;;,\n"+
"        ;;;;v.vvvvvvnvv%;mnnvvvvvvvvvvv.vvvvvv;;;;;;;;;;;;;;;;;;.\n"+
"       ;;;;;va@@@@@avvv%;mnnvva@@@@@@avvnnnnnnvv;;;;;;;;;;;,;;;;;,\n"+
"      ;;;;;;v@@@@@@@avv%;mnvva@@@@@@@@avvnnnnnnvv;,;;;;;;;;;;,;;;;\n"+
"     ;;;;,;;v@'   `@@vv;mnnvva@'   `@@@vvnnnnnnvv;;,;;;;;;;;;;,;;;\n"+
"    ;;;;,;;;va,   .@@v;mnnnnvva,   .@@vvnnnnnnnvv;;;;,;;;;;;;;,;;'\n"+
"    ;;;;,;;;vvvvvvvvv;mnnnnnnnvvvvvvvnnnnnnnnnnvv;;;;;;,;;;;;;,;'\n"+
"    ;;;';;;;vvvvvvv%;mnnnnnnnnnnnvvvnnnnnnnnnnvv;;;vvv;;,;;;;;';'\n"+
"    ;' ;;;;,;vvnnvv%;mnnnnnnnnnnvvnnnnnnnnnnnvv;vvnnv;;,;,;;;; '\n"+
"    `  ;;;,;;;vvnnv%;vnnnnnnnnm%vvvvnnnnnnnnnvv;vvnv;;,;;,;;;'\n"+
"      ;;'';;;;;vvnnnv%%%%%%%%%%vvvvnnnnnnnnnnvv;vvv;;;;,;;;;'\n"+
"      ` .;;,;;;;vvnm`#############'mnnnnnnnnvv;v;;;;;;,;;;'\n"+
"        ;;';;;;;;vvvm,  .:::;::::.mnnnnnnnvv;%vv;;;;;';'\n"+
"         ` ;;;;;;;vvnn%mmmmmmmmm%nnnnnnnvv;%vvvv;;; ' '\n"+
"            `;';';;vvnnn%%%%%%%nnnnnnnvv;%vvnnvv;'`\n"+
"                 v%;vvnnnnnnnnnnnnnnvv;%vvnnnnvv\n"+
"                 vvv%;vvnnnnnnnnnnvv;%vvnnnnnnvv\n"+
"                ,vvnvv%;vvnnnnnnvv;%vvnnnnnnnnvv\n"+
"               ,vvnnnnnv%;%;%;%;%vnnnnnnnnnnnnvv\n"+
"         .,%%%;vvnnnnnnnvvvvvvvvvnnnnnnnnnnnnnnn;%,.\n"+
"    .,%%%%%%%;vvnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn;v;%%%,.\n"+
".v;%%%%%%%%%;vvnnnnnnvvvvvvvnnnnnnnnvvvvvvvnnn;vvv;%%%%%,.\n"+
"vvv;%%%%%%%;vvnnnnnnnnn%%%%vvvvvvvvvv%%%%nnnnn;vvvv;%%%%%%%,.\n"+
"vvv;%%%%%%%;vvnnnnnnnnmmmmm%%%%%%%%%%mmmmmnnnnnnvvvv;%%%%%%%%%,\n"+
"vvv;%%%%%%%;vvnnnnnnnnnnnnnmmmmmmmmmmnnnnnnnnnnnnnvvv;%%%%%%%%%%.\n"+
"vvv;%%%%%%%;vvnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnvv;%%%%%%%%%%,.\n"+
"vvvv;%%%%%%%;vvnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnvv;%%%%%%%%%%%%%,.\n"+
"vvvvv;%%%%%%%%;vvnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnvv;%%%%%%%%%%%%%;vvv.\n"+
"vvvvvv;%%%%%%%%%vvnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnvv;%%%%%%%%%%%%%%;vvvv,.\n"+
"vvvvvvvvv%%%%%%%%%%vvnnnnnnnnnnnnnnnnnnnnnnnnnnvv;%%%%%%%%%%%%%%%;vvvvvv,.\n"+
"vvvvvvvvvvvv;%%%%%%%%%;vvnnnnnnnnnnnnnnnnnnnnvv;%%%%%%%%%%%%%%%%;vvvvvvvv,.\n"+
"vvvvvvvvvvvvvvvv;%%%%%%%%%;vvnnnnnnnnnnnnnvv;%%%%%%%%%%%%%%;vvvvvvvvvvvvvvv.\n"+
"rrrrrrvvvvvvvvvvvvvv;%%%%%%%%%;vvnnnnnnvv;%%%%%%%%%%%;vvvvvvvvvvvvvvvvvvvvvv.\n"+
"rrrrrrrrrrvvvvvvvvvvvvvvv;%%%%%%%%%;vv;%%%%%%%%;vvvvvvvvvvvvvvvvvvvvvvvvvvvv,.\n"+
"rrrrrrrrrrrvvvvvvvvvvvvvvvvvvv;%%%%%%%%%%%;vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv.\n"+
"rrrrrrrrrvvvvvvvvvvvvvvvvvvvvvvvv;%%%%;vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv.\n");
write("Ok.\n");
return 1;
}
