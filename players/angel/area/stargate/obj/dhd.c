/*                                                                        *
 *      File:             /players/angel/area/stargate/obj/computer.c     *
 *      Function:         computer screen                                 *
 *      Author(s):        Angel@Nirvana                                   *
 *      Copyright:        Copyright (c) 2006 Angel                        *
 *                                All Rights Reserved.                    *
 *      Source:           12/28/06                                        *
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
"    *                                                 *\n"+
"    *   CLEARED PLANETS                               *\n"+
"    *       SG1 N11          SG1 Command / Nirvana    *\n"+
"    *       ST3 438          Atlantis                 *\n"+
"    *       P3X 774          Nox Homeworld            *\n"+
"    *       PS2 888          Gas City                 *\n"+
"    *                                                 *\n"+
"    *   NOT CLEARED                                   *\n"+
"    *       W3S 765          The Land of Lowthar      *\n"+
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
"    *          Dial the desired location              *\n"+
"    *         with no spaces and all Caps.            *\n"+
"    *                                                 *\n"+
"    *     As the SG-1 team clears new world's for     *\n"+
"    *     exploration they will be added to the       *\n"+
"    *     computers data base.                        *\n"+
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