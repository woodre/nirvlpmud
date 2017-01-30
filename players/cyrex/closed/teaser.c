id(str) {return str=="teaser";}
Fail(str) {write("Couldnt find " + str + "\n"); }
short();
long() {write(short() + "\n");}
get() {return 1;}
init() {add_action("tease","tease");}
tease(str) {
  string name;
  int dsa;
  object tob;
  if(!str) {
    write("Usage : tease <argument> \n"+
          " arguments :    d < death-message > \n"+
          "                a < attack-message > \n"+
          "                w < drop-wielded-weapon-message> \n"+
          "                piss [player]\n"+
          "                relax [player]\n"+
          "                hi [player]\n"+
          "                chair \n"+
          "                mount [player]\n"+
          "                zap [player] \n"+
          "                faint\n"+
          "                fart\n"+
          "                face [player]\n"+
          "                dont pan [player]\n"+
          "                pat [player]\n"+
          "                hug [player]\n"+
          "                \n");
    return 1;
  }
  if(sscanf(str,"pat %s", name) == 1) {
    tob = find_player(name);
    if(!tob) { Fail(name); return 1; }
    tell_object(tob, "Cyrex pats you extremely hard on the head.\n");
  }
  else
  if(sscanf(str,"hug %s", name) == 1) {
    tob = find_player(name);
    if(!tob) { Fail(name); return 1; }
    tell_object(tob, "Cyrex hugs you with a bone crushing sound.\n");
  }
  else
  if(sscanf(str,"piss %s", name) == 1) {
    tob = find_player(name);
    if(!tob) { Fail(name); return 1; }
    tell_object(tob, "     PPPPP     I    SSSSSS      SSSSSS           OOOOO     FFFFFFFF   FFFFFFFF\n");
    tell_object(tob, "    PPPPPPP   II   SSSSSSSS    SSSSSSSS         OOOOOOO   FFFFFFFF   FFFFFFFF\n");
    tell_object(tob, "   PP   PPPP III  SS     SSS  SS     SSS       OO    OOO FFF        FFF\n");
    tell_object(tob, "  PPP    PPP III SSS     SS  SSS     SS       OOO    OOO FFF        FFF\n");
    tell_object(tob, "  PPP    PP  III  SS         SSS              OOO    OOO FFFFFFF    FFFFFFF\n");
    tell_object(tob, "  PPP   PP   III   SSSSSSS    SSSSSSSS        OOO    OOO FFFFFF     FFFFFF\n");
    tell_object(tob, "  PPPPPPP    III    SSSSSSS    SSSSSSSS       OOO    OOO FFF        FFF\n");
    tell_object(tob, "  PPPPPP     III         SSS         SSS      OOO    OOO FFF        FFF\n");
    tell_object(tob, "  PPP        III SS      SSS SS      SSS      OOO    OOO FFF        FFF\n");
    tell_object(tob, "  PPP        III  SS     SSS  SS     SS       OOO    OO  FFF        FFF\n");
    tell_object(tob, "  PPP        II    SSSSSSSS    SSSSSSS         OOOOOOO   FF         FFF\n");
    tell_object(tob, "  PPP        I      SSSSS       SSSSS           OOOOO    F          FFF\n");
    tell_object(tob, "  PP                                                                FF\n");
    tell_object(tob, "  P                                                                 F\n");
  }
  else if(sscanf(str,"face %s", name) == 1) {
    tob = find_player(name);
    if(!tob) { Fail(name); return 1; }
    tell_object(tob, " MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM  MM''MMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM  M'  MMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM!\" ''' \"!MMMMMMMMMMMMMMMMMMMMM  M  MM\"'MM\n");
    tell_object(tob, " MMMMMM'\"M' MMMMMMMMMMMMMMMV'                '\"MMMMMMMMMM.  'MM  M  M' .MM\n");
    tell_object(tob, " MMMM'M :M ;MV MMMMMMMMMM'                      \"MMMMMMMMMM.  \": M .! .MMM\n");
    tell_object(tob, " MMM; M  M :M' AMMMMMMV'                          \"MMMMMMMMM.  .'''. AMMMM\n");
    tell_object(tob, " MMMM ;  ; M:  MMMMMM'                              'MMMMMMM'        MMMMM\n");
    tell_object(tob, " MMMM. ; . M  AMMMMV                                 'MMMM\"\" ' '.   .MMMMM\n");
    tell_object(tob, " MMMMM  .    MMMMMV                                    '. ..    ;  .MMMMMM\n");
    tell_object(tob, " MMMM  '\"@\"  MMMMV                                      MMMMMM.'   MMMMMMM\n");
    tell_object(tob, " MMMM.  ;        '                                      'MMMMMM.   MMMMMMM\n");
    tell_object(tob, " MMMMM..'.   .MM'                                        MMMMMMM    VMMMMM\n");
    tell_object(tob, " MMMMMM  AMMMMMV                                         'MMMMMM.    MMMMM\n");
    tell_object(tob, " MMMMM'  MMMMMM:                                     ..   MMMMMMM     MMMM\n");
    tell_object(tob, " MMMMM   MMMMMM: @@.                              .'  @@  : 'MMMM.     MMM\n");
    tell_object(tob, " MMMM'   MMM''': :@: '.                         .' ..@@@  :            .MM\n");
    tell_object(tob, " MMMV   ''     : '@@@@: '.                    .'  .@@@@@  ........./MMMMMM\n");
    tell_object(tob, " MMM           :  @@@@@. .' .              .' A. .@@@@@'  MMMMMMMMMMMMMMMM\n");
    tell_object(tob, " MMM:..........:  '@@@@@@@.  ! '. - - - . '.  .@@@@@@@@   MMMMMMMMMMMMMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMM   '@@@@@@@@@@@@.    !    .@@@@@@@@@@@@'  MMMMMMMMMMMMMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMMM   '@@@@@@@@@@@@@...@@'..@@@@@@@@@@@@'  AMMMMMMMMMMMMMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMMMA   '@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   .MMMMMMMMMMMMMMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMMMMA    @@@@@@@@@@@@\"'O'OOOO'@@@@@@@'   .MMMMMMMMMMMMMMMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMMMMMA    '@@@@@@@VOOOOOOO.OOO @@@V     AMMMMMMMMMMMMMMMMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMMMMMMMA     '@@@@OOOOOOOOO.OOO@'     .MMMMMMMMMMMMMMMMMMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMMMMMMMMMA        '.@@.OOOOO.OO     .AMMMMMMMMMMMMMMMMMMMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMMMMMMMMMMMA.          OOOOO OOOO .MMMMMMMMMMMMMMMMMMMMMMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMMMMMMMMMMMMMMA..      OOOOOOOOOOOMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMOOOOOOOOOO.MMMMMMMMMMMMMMMMMMMMMMMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM OOOOOOO.MMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM---MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
  }
  else if(sscanf(str,"dont pan %s", name) == 1) {
    tob = find_player(name);
    if(!tob) { Fail(name); return 1; }    
    tell_object(tob, "Cyrex tells you:\n\n");
    tell_object(tob, "                DDDDDD   OOOOO  N     N     ''  TTTTTTT \n");
    tell_object(tob, "                 D    D O     O N     N     ''     T    \n");
    tell_object(tob, "                 D    D O     O NN    N     '      T    \n");
    tell_object(tob, "                 D    D O     O N N   N    '       T    \n");
    tell_object(tob, "                 D    D O     O N  N  N            T    \n");
    tell_object(tob, "                 D    D O     O N   N N            T    \n");
    tell_object(tob, "                 D    D O     O N    NN            T    \n");
    tell_object(tob, "                 D    D O     O N     N            T    \n");
    tell_object(tob, "                DDDDDD   OOOOO  N     N            T    \n");
    tell_object(tob, "\n");
    tell_object(tob, "                PPPPPP     A    N     N  IIIII   CCCCC  \n");
    tell_object(tob, "                 P    P   A A   N     N    I    C     C \n");
    tell_object(tob, "                 P    P  A   A  NN    N    I    C       \n");
    tell_object(tob, "                 P    P A     A N N   N    I    C       \n");
    tell_object(tob, "                 PPPPP  AAAAAAA N  N  N    I    C       \n");
    tell_object(tob, "                 P      A     A N   N N    I    C       \n");
    tell_object(tob, "                 P      A     A N    NN    I    C       \n");
    tell_object(tob, "                 P      A     A N     N    I    C     C \n");
    tell_object(tob, "                 P      A     A N     N  IIIII   CCCCC  \n");
  }
  else if(sscanf(str,"hi %s", name) == 1) {
    tob = find_player(name);
    if(!tob) { Fail(name); return 1; }
    tell_object(tob,"Cyrex tells you:\n\n");
    tell_object(tob, "          ******      *****     ***************\n");
    tell_object(tob, "         *    **     *   **    *             **\n");
    tell_object(tob, "        *    * *    *   * *   *             * *\n");
    tell_object(tob, "       *    *  *   *   *  *  *             *  *\n");
    tell_object(tob, "      ******   *  ******  * ***************  *\n");
    tell_object(tob, "      ******   *  ******  * *************** *\n");
    tell_object(tob, "      ******   *  ******  * ****************\n");
    tell_object(tob, "      ******   *  ******  *    ********  *\n");
    tell_object(tob, "      ******************  *    ********  *\n");
    tell_object(tob, "      ******************  *    ********  *\n");
    tell_object(tob, "      ******************  *    ********  *\n");
    tell_object(tob, "      ******   * *******  *    ********  ****\n");
    tell_object(tob, "      ******  *  *******  *    ******** *   *\n");
    tell_object(tob, "      ****** *   ******* *  ************** *\n");
    tell_object(tob, "      *******    ********   ***************\n");
    tell_object(tob, "      ******     *******    **************\n");
  }
  else if(sscanf(str,"relax %s", name) == 1) {
    tob = find_player(name);
    if(!tob) { Fail(str); return 1; }
    tell_object(tob, "Cyrex tells you:\n\n");
    tell_object(tob, "      *******  ****** **       **    **    **\n");
    tell_object(tob, "      ******** ****** **      ****   **    **\n");
    tell_object(tob, "      **    ** **     **     **  **   **  **\n");
    tell_object(tob, "      **    ** **     **    **    **   ****\n");
    tell_object(tob, "      ******** *****  **    **    **    **\n");
    tell_object(tob, "      *******  *****  **    ********    **\n");
    tell_object(tob, "      **  **   **     **    ********   ****\n");
    tell_object(tob, "      **  **   **     **    **    **  **  **\n");
    tell_object(tob, "      **   **  ****** ***** **    ** **    **\n");
    tell_object(tob, "      **    ** ****** ***** **    ** **    **\n");
  }
  else if(str == "faint") say("Cyrex faints from utter confusion.\n");
  else if(str == "fart") say("Cyrex farts loudly in your general direction.\n");
  else if(str == "d") say("\nYou die.\nYou have a strange feeling.\nYou can see your own dead body from above.\n\n");
  else if(str == "a") {
    int n;
    n = random(7);
     if(n == 0)
       say("The invisible stalker tickled you in the stomach.\n");
    if(n == 1)
      say("The invisible stalker grazed you.\n");
    if(n ==2)
      say("The invisible stalker hit you.\n");
    if(n == 3)
      say("The invisible stalker hit you hard.\n");
    if(n == 4)
      say("The invisible stalker hit you very hard.\n");
    if(n == 5)
      say("The invisible stalker smash you with a bone crushing sound\n");
    if(n == 6)
      say("The invisible stalker missed you.\n");
  }
  else if(str == "w") say("You drop your wielded weapon.\n");
  else if(str == "chair") {
    say("Cyrex magically creates a comfortable recliner and sits down.\n");
    write("You create a comfortable recliner to rest upon.\n");
  }
  else if(sscanf(str, "mount %s", name) == 1) {
    say("Cyrex magically creates a whip, mounts " + capitalize(name) +  " and rides into the sunset.\n");
    write("You mount " + capitalize(name) + "\n");
  }
  else if(sscanf(str,"zap %s", name) == 1) {
    tob = find_player(name);
    if(!tob) { Fail(name); return 1; }
    tell_object(tob, "Cyrex summons a fury flash from the sky.\n" +
                     "It seems to be coming towards you!\n\n" +
                     "Zzzzzzzaaaaaaaaaaaaaaaaappppppp!!!\n\n" +
                     "You die.\n" +
                     "You have a strange feeling.\n" +
                     "You can see your own dead body from above.\n\n");
    write("You 'zap' " + capitalize(name) + "\n");
  }
  else { write("Failed.\n"); return 1; }
  write("Ok.\n"); return 1;
}
