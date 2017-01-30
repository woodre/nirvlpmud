#include <ansi.h>

id(string str) {

   return str == "paper" || str == "newspaper";
}


init() {
   add_action("view","view");
}
reset(arg){
  if(arg) return;
}

short() { 
  return "A King County Newspaper";
}

long() {
write("\n\
\\ \\      / /__  _ __| | __| | |_ _|_ __  / _| ___  ___| |_ ___  __| |\n\
 \\ \\ /\\ / / _ \\| '__| |/ _` |  | || '_ \\| |_ / _ \\/ __| __/ _ \\/ _` |\n\
  \\ V  V / (_) | |  | | (_| |  | || | | |  _|  __/ (__| ||  __/ (_| |\n\
   \\_/\\_/ \\___/|_|  |_|\\__,_| |___|_| |_|_|  \\___|\\___|\\__\\___|\\__,_|\n");
   
write("\n\
The Zombie Apocalypse has arrived.  Within the past few days, a virus\n\
that infects humans has blazed through the area.  It seems that every-\n\
one has become infected.  When death occurs, the virus takes control\n\
of the brainstem and re-animates the corpse as a Walker.  The Walker\n\
is a shell of the person they were.  Only the low level functions of\n\
the brain continue to function.  The Walker only cares about its next\n\
meal.  It has no concept of mercy, self perservation, or pity.\n"+
"Extreme caution must be taken when dealing with a Walker.  They are\n\
especially dangerous in groups.  They tend to join into larger and\n\
larger groups as they run into other Walkers.  These larger groups\n\
are deadly and should be avoided at all costs.\n"+
"\nWalkers do have some weaknesses so not all is lost.  They are slow\n\
so they can be out run for short distances if you move quickly, but they\n\
will attempt to follow once you have gotten their attention.  They are of\n\
course very aggressive, and will attack on sight.  It is best to be quiet\n\
and move as quickly as possible.  Walkers are not very coordinated, so \n\
they are unable to open doors.  They do possess a great deal of strength\n\
however, and they are very single minded so they will use their strength\n\
to break through whatever barrier is in the way.\n"+
"\nWe have managed to obtain some pictures of what Walkers look like.\n\
You can view page 2 and page 3 if you dare take a look at what happens when\n\
the virus turns a dead human into a Walking Dead.\n");
}

view(string str) {
  string junk;
  int page;
  if( !str )
    return;
  sscanf( str, "%s %d", junk, page );
  if( !junk || junk != "page" || !page )
    return;
  switch(page) {
    case 2:
      z1();
      break;
    case 3:
      z2();
      break;
    default:
      write("You can't seem to find page "+page+"\n");
      break;
  }
  return 1;
}

z1() {
write( "\                                                                       \n\
              .:.......:...;;;;::777;;;;::;7;7;;:;;7;;::::.:...                 \n\
      .     .:;::...:.::;;;;;;;:;:::;;::;7v77;7v#77;;;7;;;;;;::..     .         \n\
 .      ...:::...:::.::;;;;:;;:;;:. ..  .777;;:;;;:;7777;;;;:;:;;.   . .        \n\
  .   ....:.....::::;;;.:::.;....:;...::.   .:;::::::;7vvvv;;;;;;:.             \n\
 . . ..::;.......::;:. . .:;;;.. .;7;...;:;;...;;;::;;::;77L4njU47;...     . .  \n\
    ..::;;:::.......  ..  :JJ;;.;:.:777::::::::::.;;777::..;vjn4nLn7;....   . . \n\
 ...:;::.....::.::........ :Jj;;;7::;V7v;;;777:;;7;;:;;777:.   :7J4Cv:.... . .  \n\
..:;:.:...::::;.:.;..;:.....vZ4v7vv;;;#4V77;7##;;;77::::;JV77.   :;;jJ..:.. . . \n\
 :::.:...:;;;;.:::;;:;7;;;;7;4UL4JLjv#;7#Lnv:;JV777;;;;;;77VLU;;77;. J7:.:..    \n\
....::..;77;;;;;77;;7;;;7Vn;77O2YCyDDOL77vU44;7#4v77v;77VvvJ#744J##v77Vv:....   \n\
 ..:...;74#77#7#77777;777LO;7y2MGhZZMNhO4JjfUOVvj4V77#77j2LVvVfnv#7v77;v;;:.::  \n"+
"::.:::77VJv;v7##7:Jv7;Jv7vLvCDhXOI2ZMNhZMfffZZG2U4247V7::vUU44fj44J7v7;;77;:.:: \n\
:;:;:;7777;.7L7:.:vJ##777vVCfFONFNFSMFDhhN2DhAAAUj4Y#Lj:.vLUy22yCJv77#77;777::..\n\
;;..::;;v4J;nn7;77v#L#vvv;74NyY2GXFNFMKAMAKFNAOAO7V7: .:#j2fyCIZnJVv;7#7v;777;:.\n\
...::;v4LyCULUfyJ44nfU44#7;74LC2fODhYDAKGAMRhhYXJ;L7;  .UCY24j4YjV7VJ;;v7777;;;:\n\
...;77VLf4Inff2V5nYIXIfUCL7:;vZXODMX22hhSNSKXC2yLvOyIO4fNhIyVvUL4777UJ;77;7#7;;;\n\
 .;7#LU4;JCfUILfU2LIXOXhMGA7;7jyFgpESRNNGSRGNSFKhnDNyhIODSDFXnfnV4v7747;;7;7#7;;\n\
 .;7#Lf#yOYJUZL4ZLnU22hhFFEMhU4LCXRBBENNKNKNEQgKNIFMKIKF2ONMR2XJ#Vn777J7;:7;7vV7\n\
 .;7v4LffY4#IhXfnCYZ22yhXGNSMSDf#VfD2XZMFgSMMSGShQRh2hMpNGhN2fUn7;vv7vvv77;;:;74\n\
 .;7#7VVLLnZhOZ54YGFGXYXDhhYDZZZ4#VZyV442FMDhANGRQK2hIGMgSSGZLLL4;;v7vv7777;7;:;\n\
 .777;744fjy44Vj#77VV4J44nLUZYy2ARBBBSG22hUVDKFSQghMDX2AMSpRFhynVv7vv7vJ;;77:;;;\n\
  ;;7:.:vJfCnnI2D54v44ULfIOYhMhDhSQQBQBBBBpVVCS2BKhSpKF2hDFNGAC4n77;#7v#J;;;;..:\n\
 .;47;  7v5YnZZ2IXIn4f5nUyYMMNMFMQBQSRQBBBBBnV5MFF2SKSNG22DhA2VVUJ:;77777;;7;v7;\n"+
" .7Gv.: 7LZ5FNGONMNY4##VCZJ;7vygBBQOMhKRSGKSE2fOhZ4UpNgRF2h2U4L###7;777;7;:7L#7;\n\
 .;Xv;#;74yCfAMOgQgghII4fh:7vv;4GpRNSBBpjnGBBBRSN#77INhRGhFFYC4Jv77;77;77#v;7##v\n\
. :7nff44#L2D2NGpSKRgXX2hRFYhY77yjDRSNMZy4U2QRZ4fZDNKpMOhFNFN2L7vvv:;#7;777jDO5#\n\
.  7#4L54UVLLfDNKEKGGfVffMRphA2U77v4J;:..;4OGD;77LDNLvgg2YDSMKNnJ777.;7777:7Lj4L\n\
.. ;V45Un##v4Vj4OFNCFfV77v4fYL#7J77.    ..    . .:v:  VBBSZYhMSGyjv#;.:;v77..;v#\n\
.. ;v77v7;;;:;v4j4LL2IMpZv;;7##j:.. .;JBBQBBXURZ7;;7.::7FQRRFGFKM24777;:;7Jf#;7#\n\
...;7;:..       . .;7v#CK247#DD777;LY:7gE;LBBQBBgLJ4fv.:7DRUSSSSIDX777;:.;Uhy7vL\n\
...;.:..   77:.;      ;CMRNFU2YnFn#hM#7IAyFQgOYV44CGXhfLLOADNQCOCMF#:7;::7#V7#4L\n\
....::;.; 7RG7QBI2V.:.:fNQBgggRSXVJ::;#v7vV7777#2DRhMMR2DMKKEgQU4gK7:77;7v77#VV7\n\
.....:77:.##JMI2FBBL   nDgBBQgFGSFAf7;7v7.74LnFRFSGKKSAONQSSRQggQBD;:;;v##Vnn47;\n\
..... vL: .:;7JVV7#;  ;2RNBQBQQSRRgRKhGICjhDG2hFQgSRgFMRQpQgQQQBBY77:.;#47fDV;;;\n\
..... ;A7..:.::;77#;.:7XIGQQMGQBBRQBgEpQpgFAZNGSRSKQggQQppNgpEBB2:vY:.;77;;7.::;\n"+
"..... .nN#;7J#JVUnC;:;JL4XQFVMBQSFEBBgQEFLgA22CYXDhOROUGSRgRgpQ4:;Oy7.77;. ..:;.\n\
.......7pQL7v4VfUI5;.v;4CMQGOQg2ZgYfBBBBRQgM77777fAUhQgDgQRpFgM..YAV7;vv7. ..:.:\n\
.......:fQghOAOOhIn7v77YRRpFgBFhSQMOO4OGBSOppIfhRFIV4ApBBMDZXNhj5fC47777;:..:::.\n\
.:.......7LMhN#77J7#v.4XyMSQQBgGBQgh. .77YC4VRKYhXYf7VVVUL5X2h4#5f457.77;;...;;.\n\
........:;#XFXL.7;;;7;4U2RQgSQgRBBBKAfv;;;77;O#7#VNhy777ZXXUX4vLCIJ#7:;77;:...;:\n\
.:.......;vUV44v;;7..;;#GSAIORU; ...7L4jv: :..LU7:4Yv:;;74VLLVV2XK;.;7.;7.:;.:;;\n\
....:......;;.    :...  .;;75UVVMBp;;V#;: .7;  .77J;7Yfy77##L7nDY#:;7;;:v:;;;;;;\n\
.:.:.:.......:    .;:7:  ;777;JJv54f;:;;#7:;7:  ;jv;.7JFJ;..44755777v::7V;;;:;;;\n\
..:.:.:..........  ..7Y777#v:.C;.;;.:.7.7;: :..  #4v::;Jv;..V77#VJj#v..7v:.:;::;\n\
.:...:...:...:.... .. :;7.   .;J4VZYJ:..:v.7LLB; ;7V7;;;77.;4;777Vn#::;;77..;;:;\n\
.::.:.:.:.....:...  . .   :7 ;7..#7::XBv.RhypJ;;;.:;;;;;;;::7:;JV#4..7Y4fI; .;;:\n\
.:.:.:.:.:.:.:.:.:.    .;7DB:KBf:EBn BBS.QZ     7v7;::.:::::. :4##..7V#f2Y2: ;;;\n"+
".::...::..:.:.:::....    .;BgVGBMBBh 4J:      #.74j.:7;7:..;. J4j;.7v7vj4vKC..77\n\
.:.:.:.:.:.:.:.:.:::..     .;           ;7yBQ7n#Vv.;.:Jh7..::777;:;V7.JnvJKg4..7\n\
.::.:.:.:.:.:.:.:.:::.      ;;777;.J:pB7pBLnBn ..;.:..:V7 ::jJ;:;777.:v4vLNGRU;:\n\
.:::::::::::::::::::::. .#v .;7n;2.5J.Q7 7; ;##. :.. 7 :...754;::::Zv4VVJnhFhF57\n\
::::::::::::;:;:;::::::. .Y.   ...  ;   .. :7.;. ....;: .:v7j;::;;7f2YJv4YSMhXDU\n\
:;:;:;:;;;;;;;;;;;;;:;:.. .:.:7:7:     .:.:7..7;;; . ....;7;;:.:;7V4LnV4yh2MhA2M\n\
;;;;;;;;;;;;;;;;;;;;;;;:....:.77;.:.   .v#v7. ;;;.      .7..;:..#5X2VvVnDCyLYhhh\n\
:;;;;;;;;;;;;;;7;7;;;;:..;:  ;..;7;;    7#;.  .:;.. . ...;::7vL57LIyvJ5XDD55YF2h\n\
;77;7;777777777;;::::::.;;;.  :..:7J: :;;;.   ....::.:7.:777#7vVLV5VjOSFDV#KQgRR\n");
  return 1;
}

z2() {
write("\
BMHMHMHMHMHMHMHMHMHMHMBMBMBMBMABWHGG66oL0otIloo66DhDOOC6wCwCwC0L0Cowo0I0t0t0totw\n\
MBMBMBMBMBMBMBMBMBMBMBMBMBMBMHEbh6600IwILtII0totwICObGAGRDG8DODOhO868COCOL6LCwCC\n\
HMBMBMBMBMBMBMBMBMBMBMBMEAGbwotIltitltilil7ilt777l777llww868L6wLowowowI0I0totol0\n\
MBMBMBMBMBMBMBMBMBMBMEEbG6h0ItoitlIiIltltlI7l7li77l7i77777loOCO0L0LowowI0I0totII\n\
BMBMBMBMBMBMBMBMEHARDARDwoilltitlIlIlottioll7tit777llt7l77777ilCLLowI0t0totolol0\n\
MBMBMBMBMBMARhhOAbGGAb8ltii7litlIltlIlItoltlIlIltii7liotIi77i77;ilC00lIltllilitl\n\
BMBBAHAGO8LL08hWR8bG6Cioll7l7lltltlIlIloloIoiItotoIl7l7llt7i7777;;;lw600ltil7l7l\n\
8D6LCL6w606hRREAhhGt0lIi77i7titlIlIlIiliItolIlIlIl0oIllil7l7l77777;;;l6wCwC0CIoI\n\
0DLOCOC60DbAAWWDLOloII7i777lltilltititilltltlIlttIl0IotIllllil7i7i77;:;lltltltlo\n"+
"6hOCOLC0EEAHBWGLDwwIl7l777l7l7i7lil7lllitlIlIlIlIill0IItIltltil7l77777;:7ll77777\n\
LbLOLLwHAMWEGAh6I07777777i7i7l7i7i7l7l7l7lilil7IltlliIllititltll7i7i7l7;:;777777\n\
Oh6wwoBGWAAhIooil7777777i7lil7i7l7i7l7lilil7l7IltlIlliIllil7titltll777l77:;7l7i;\n\
7wtotWGHBIwo;7it7777777i777i7l7l7l7l7lilitlIiltIltltlIitlI777lllilii7i7l7;:;77;:\n\
:::.OAAEt;l7ii7;77777777l7i7l7Illil7IlIlll0tolIlIlllItl7til7l7lil7l7lllil7;:;:. \n\
CbwGRwCl;7;777;7;77777777lil7;;77IillIt0t0o00LIotIioltlollilii7l777l7llIti;;:;.:\n\
8bRhll7;;;;77;7;7777777777tl7;;:;;;lolttolI06wL00oLIwlotolilI7l7i7i77it7wI7;;;;.\n\
wbClll;;;;;7;777777777;777;;:;:::;;ot0t0Iwl;:;l8CCwLo6wwt0o0Ilii7i777llllL7;;;;7\n\
Lblll;;;;;;;;;77777;7;77;:;:::77oI60077;7lCl.  ;000il;7IwwI;t777i7777iollll;;;;B\n\
wG7i7;:;;;;;:;;77i77;7;;::::;ll77;:;7; .. .;:;;77ltw7. :::;:;i;777777tII7ll7;;;A\n"+
"h877;;;:;:;;;;;;777777;:;:;:;;7:7;.:77;7;..;oI78LIooLII7;:::7ll77il7ll0ol7l77:;7\n\
h677;;;;:;;;:;:7777i7l77;;.;.::.:liIlw660L77777ott7ItwoIII;:;77I7l7liolw77777;:7\n\
67;;:;;:::;;;:;;7.;;.;t777;:: :::;77t77lL0ol77l7ll0LolllIowil7i7iitlIlIll7777;;;\n\
L7:;:;:::::;;::;;:::.:::;7;;;;i;...;;;.;;;7Ill77;0IoI0ttiIltiIlollltlIlIl7;77;;;\n\
w;;;;;::;:;;;:::;;:.::..:;7::;; :;7;. :.. :;7ii7ilIltlwlIlot0owo0I0I0I0li777i;;;\n\
l7:;:;:;::;;:::;;: .;t7;.:;77;::7l;;;7i7;;;;;7il7llto0I0Iw0wowoolIillotw777777;;\n\
I;:;;:::::;;;:;:;:.;i77;;..;I;7LO0t0b8hLl0Ot77tt0io0LLCwCowIl7l7777;77ll0777i;;;\n\
l7:;:;:::;:::::;.:;;;;;;:;;;7777777il66Llwtiiw00I0itiolIi7777777777777;7iL7i77;;\n\
oI;:::;:::;:;:;::;;::;;;;;7;;;;:;;;;;;;7t77;77l7li7;7;;;;;;;;;;:;;;;7;7;;7oll7;;\n\
i0;::;:::;:;:::::;;;;;;;;:.........::::;;;;777;7;7;7;;::   .   .  .::;;;777o77:7\n"+
";7;;;:::::::::;:;:;;;;;:. .::.;;..: . ::::;;7700I77;;:..;;;;;;b;::  .:;;77ltl7;;\n\
t0;;;;:::;::::;;;;;;;;.:;t7l7;;;:;;. . ..;;7;7ittl77;:;it67;;;7;77:..:;7;7iCll;t\n\
:::.;;;:::::::;;;;7;;..:;;7;7;77i;;::.. ::;;7;77oll77:;;;7l;7.:7l;;:::;;77ii8t;b\n\
.:...;;::;:;:;;;;7;;;:::.:.:.::;;;;;:;:::;;77;;ltoili;:::;;;;;:;:::;;;;;;i7io6:M\n\
:.:.::;:;;;;7;;;7;77;:;;;;;;;;;;;;;:::;:;;;;77i7til7ti7:::;;;;;;;;7;7;77lililo7R\n\
::.:..:;;;;;:;;77lt7;;;;;7;;;7;;:;:;;;7;;777;7;;;7;77tii;;:;;;;;;777;77liIl7iL7w\n\
::;.....;;;;:;;;i;7;;;;;;;;;;;;;;;77777;;;7;7;;;;;;:;7lll77;;;;;;;7;7777tI0li7l0\n\
.:::.:..:7;;;;;777777;;;;;;7;7;;7l77;;;;77;;;;;;;;;;;;7li77i77;7;777777littt77;C\n\
;.:...:..;;.::;;77l7l7i777i7l7;7l77;7;7;;;;;;;;:;;7;;:77lll777i7i7liIlotoltil7;H\n\
6; :.....:;:..:77itllt7tlII77ll777;77777:;:7;;;;;777;;;;77;l777i7i7tloo0lt7l777M\n"+
"86: .....:;;;:.:::77;;;:::;;l7;;;;7;777:;:;;;;;;77t77;;::.:7i777777;;;77i777l;0B\n\
IDw; ..:.:;;;; . :;:.;   . 7l;:;;77;;;;::;;;:;:;;7;;;;;;.::;7i7;;7;:.;;777;:7;LM\n\
owCC7  .::;:;;;:::    . ::;.7;:;777:;;;;:.::.   :;;;: ;;;;;:77;;7;7;;;;;777;;:MB\n\
tCIwOO;  .;;::;7;;:::::..;.  7;7;:..;7;;:. .   . ::;.::;7i7;7i;777;;;7;7;;;; LBM\n\
I0oIwLh7:  :;:::;77;7;::. . :;7:..: ;;;:;::.;;:::.;;7;:;777;i777777;;;;:::;;:AMB\n\
tCt0I008C07::;:::77;::.:.: .:;::.. ..:.:::::;7:::;;;:::7;.:;;77777;;7;.::7;.;MBM\n\
ow0I0I0ILwD;::::;:. ..:.. ::..:.:.. ....:::.;;;::;;.;;7;;:;7;;7;7;7;7..;77. CBMB\n\
lCt0Iot0t0wI.::::;;; . ...::.. :..:..: .:. .:;:7;;::;;;;:;:77;;777;7;;;;;...RMBM\n\
0w0I0totIt00;.:::;;:;.....:.. ..;.. ::  :.      .:;.  . .::7I77;777;;;;:::.7MBMB\n\
t6I0I0totoIC7:.:.::;;:...:.:.. .:  .:l; :; .:7; .C;; ;L;.7:.;i;;;i;7;:::::.MBMBM\n"+
"0w0I0totol00I::.:.:;;:: .:::: :......;i.;;:;77C:76It.;b7:;; .;7;;;;7;:;.; :BMBMB\n\
tCtotototIlwt:.::..::: . :::.::::; . . ..:.:;;:.:7;;  .      ;;;:;;7:7::;::MBMBM\n\
owotototIlIIo.:.:.:.:::...;...;.:.  .               ..:.  .  .;;:;i;;;:.:;.6MBMB\n\
tCt0totolIlot;.:::...::: .::...:.: ....:.:   . . .::::.:. :: :7;:77;:;..:;.GBMBM\n\
owototolIlIl0i. :::.::;:. ..;.::::. . ..::;::....:;:. . ..;. ;i;;i; ;;::: ;WMBMB\n\
tCtotIlIlIlItL; .:::...;....:;.:.::;:...  .;:. . .  .:;7:;: .7;77l.:;:.:::;MBHEB\n\
o0IlolIlIltiIto;...::...;:. ::.:. .:;.7;::;.:;. ;; :I;7o7;. ;7777::::.::::tCllw7\n\
lLlIlIlIltilillo7; ..:..:;  .:.;.. .:.;7 :::;t:.l7 ;l:;;.. .7li77::;:;.:.:;l;7;;\n\
I0IlIlIlIltilillot7.... .;. ..::;:: . ::. . .:: ;: :: ..;  7l7i7:.;:;;: ;;:77;::\n\
lLlIlIlIltltililiIli7;...;:. ..:..:. . .::.:.:;:.:.;:;:. :7l7777.;:;;. .;;:;io7;\n"+
"IoIlIlIltililil7l7ll0t;.:.;::.: . .:. ..: ....: . .:::: ;it7i7i::;;;;:::;:777;77\n\
lLlIlIltltltilil7l7lit7;:.::.: . : ::. ... : . .   ..;:;77777t;..;;7:;;;;:77;:.;\n\
o0IlIltltltilil7l7l7i7l;:::;:.. . :.;:::....:..:;;77l77777l77;;:.:;:::;::;7;:...\n\
lLlIlIltltilil7l7l7i77oG:::;;;::.:.:::::.... .:;;;;7;;;77lli;;:::;:::;:..;;;..:;\n\
Iotltltltililil7l7770bMB7:::;::::.:.:::.. ....::;:;;;;77777;7;:.;..:.:;.......;;\n\
lwlIltltltll7l7l77lAAh7::;::;:.::;:. :.. . :;77777;7;777;;;;;:.;;..::7:. :;: .:;\n\
toIlIltltililii;lAMhl7; .;;.:::.:;:::......;7;777il7i;7;777;:.;;;;;:;7;.:l; .:;:\n\
lwlIltltilil777OA8lII;...;;:.::;;:.:..:::;;7;7777l7777;777;::7;;:;;;::::;;. .::;\n\
tItltililil77lAGt;;;: ...:;::.. ::;;:...::;;;7777777777;;:;;777;;;;:. .;7. .::::\n\
lwlIltitil77oALl77:  ... :::::.. ..::. :::::;7;;;77;;;:::;;7;;:. . ...;l: .:.:::\n"+
"tItltltll7l6G;::: ..:.:..:;.:::.....:.:.....:.:.;::.::;;;;;:.   ...;7;;:..:::.;:\n\
l0itltil7tOC7: .:;;;:;.. ;:::;::.:.:.:.:.:.:::;;::.::::;::.. ::;.:::.;;. :.:.:::\n\
lw0I0tol6GLoLIl77;;:;::  :::;:::::::::::::;:;;:...:::.. :...;:;:::::;;. ..;::.::\n");
return 1;
}

get() { return 1; }
drop() { return 0; }
query_weight() { return 0; }
query_value() { return 0; }

