/*                                                                        *
 *      File:             /players/angel/area/atlantis/obj/dhd.c          *
 *      Function:         DHD Terminal to open Gate                       *
 *      Author(s):        Angel@Nirvana                                   *
 *      Copyright:        Copyright (c) 2008 Angel                        *
 *                                All Rights Reserved.                    *
 *      Source:           01/02/08                                        *
 *      Notes:                                                            *
 *                                                                        *
 *                                                                        *
 *      Change History:                                                   *
 */

#include <ansi.h>

id(str) {
  return str=="DHD" || str== "dhd";
}


long()
 {
  write("                                               \n"+
"    ***************************************************\n"+
"    *                Plantary Listings                *\n"+
"    *   CURRENT PLANETS                               *\n"+
"    *       PS2 888          Gas City                 *\n"+
"    *       SG1 N11          SG1 Command / Nirvana    *\n"+
"    *       ST3 438          Atlantis                 *\n"+
"    *   OPENING SOON                                  *\n"+
"    *       W3S 765          The Land of Lowthar      *\n"+
"    *       SRT 963          Nox Homeworld            *\n"+
"    *       EV4 539          Elvandar                 *\n"+
"    *       TSD 171          Thanagar                 *\n"+
"    *       HR6 907          Acheron                  *\n"+
"    *       SNO 823          Arachnos                 *\n"+
"    *       PBJ 748          Halla                    *\n"+
"    *       DKR 239          Kandahar                 *\n"+
"    *       TWC 542          Twilight City            *\n"+
"    *       NHS 989          Nulato Hills             *\n"+
"    *       JLH 736          Selangor                 *\n"+
"    *       SSH 612          Gehenna                  *\n"+
"    *                                                 *\n"+
"    *                                                 *\n"+
"    *          Dial the desired location              *\n"+
"    *         with no spaces and all Caps.            *\n"+
"    *                                                 *\n"+
"    *     As the SG-1 team clears new world's for     *\n"+
"    *     exploration they will be added to the       *\n"+
"    *     computers data base.                        *\n"+
"    *                                                 *\n"+
"    ***************************************************\n");
}

short() {
  return ""+HIR+"D.H.D."+NORM+"";
}

init() {
  add_action("cmd_read","view");
}

int cmd_read(string str) {
  if(str != "dhd") return 0;
  long();
  return 1;
}
