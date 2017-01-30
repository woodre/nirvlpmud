id(str) {return str == "map";}
reset() {}
long() {write("    This is a map of the main roads/castles that you will\n"+
              "find in Nirvana.  The individual areas are not mapped due\n"+
              "to the enormous amount of work required (plus I am lazy).\n"+
              "Just <read map> to see the main roads and marks for important\n"+
              "areas such as the shop and church.  <read map2> lets you see\n"+
              "the descriptions of the marked places.  Hope you like this!!!\n");}
short() {return "A map of Nirvana";}
init() {
        add_action("Read","read");
}
Read(arg) {
           if(arg== "map") {
           write("                               1\n"+
                 "                               |\n"+
                 "                               *\n"+
                 "                               |\n"+
                 "                               *\n"+
                 "                               |\n"+
                 "                               *\n"+
                 "                               |\n"+
                 "                               *\n"+
                 "                               |\n"+
                 "                               *                     u/d-2\n"+
                 "                               |                      |\n"+
                 "                               * <- can go up here-> u/d\n"+
                 "                               |\n"+
                 "                           3-4-5-*               6\n"+
                 "                             | | |               |\n"+
              "                             *-7-*               8\n"+
              "                             | | |               |\n"+
              "                     *-*-9-0-A-*-B-C         D-E-F\n"+
              "                             | | |               |\n"+
              "                         *   *-G-H     I       * J\n"+
              "                         |     |       |       | |\n"+
              "                         *     K       @     $ * L\n"+
              "                         |     |       |     | | |\n"+
              "                       M-*-N-O-P-Q-R-S-T-U-*-*-*-V-W-*-X-Y\n"+
              "                           |               | | | |\n"+
              "                           Z               a b * c\n"+
              "                           |               |\n"+
              "                           d               %\n"+
              "                           |\n"+
              "                   e-*-*-f-g\n"+
              "                   |\n"+
              "          >Crescent lake area<\n"+
                 "\n"+
                 "For explanations just <read map2>.\n");
return 1;
}
           if(arg=="map2") {
           write("This is a listing of the marks which appear upon reading the map.\n"+
                 "****************************************************************\n"+
                 "* 1= Noonelse-Vampire Guild and Manor House                    *\n"+
                 "* 2= Rumplemintz-Town Central                                  *\n"+
                 "* 3= Bern-Cleric Guild, Area                                   *\n"+
                 "* 4= Yaeger-Tower of Balgarion                                 *\n"+
                 "* 5= Static-Waterslide                                         *\n"+
                 "* 6= Deus-Orb                                                  *\n"+
                 "* 7= Hurtbrain-Machine of the TIme                             *\n"+
                 "* 8=Death-Tomb and Doctor-Police Box                           *\n"+
                 "* 9= Oderus-HELL-O                                             *\n"+
                 "* 0= Orion-Castle                                              *\n"+
                 "* A= Morgoth-Castle                                            *\n"+
                 "* B= Slothie-Portal to 301 Madera                              *\n"+
                 "* C= Catt-Gates                                                *\n"+
                 "* D= Molasar-Keep and Dragnar-Castle                           *\n"+
                 "* E= Gorgan-Castle                                             *\n"+
                 "* F= Haji-Trail to the Northwest                               *\n"+
                 "****************************************************************\n"+
                 "****       Continued on <read map3> and <read map4>         ****\n"+
                 "****    WARNING: Some castles are not open at this moment   ****\n"+
                 "\n");
return 1;
}
	if(arg=="map3") {
	write("A continued legend for the map.\n"+
              "*******************************************************************\n"+
              "* G= Blue-Castle of Sir Elvis                                     *\n"+
              "* H= Lancer-Huge Space Fortress                                   *\n"+
              "* I= Trix-Trix's Realm and Ladyfinger-Vale                        *\n"+
              "* J= Pavlik-Trail Upwards                                         *\n"+
              "* K= Blackadder-Castle                                            *\n"+
              "* L= Catwoman-Revenge Shop and City                               *\n"+
              "* M= Haji-Base                                                    *\n"+
              "* N= Boltar-Santa's Workshop                                      *\n"+
              "* O= Haji-Road to Texas and Turk-Castle                           *\n"+
              "* P= Zek-Whateverness and Morgar-Tower of the Gates               *\n"+
              "* Q= Darq-A Very Darq Passage                                     *\n"+
              "* R= Mathiast-Rift in Time and Space and Mizan-Tub of Orange Jello*\n"+
              "* S= Persephone-The Portal of Fate                                *\n"+
              "* T= Grimm-Doppleganger Guild, Area, Shop                         *\n"+
              "* U= Catt-Small path to the North                                 *\n"+
              "* V= Vulture-Nirvana International Airport                        *\n"+
              "*******************************************************************\n"+
              "****            Once Again Continued in <read map4>            ****\n"+
              "*******************************************************************\n"+
              "\n");
return 1;
}
	if(arg=="map4") {
	write("The last map of Nirvana!!!\n"+
              "*******************************************************************\n"+
              "* W= Haji-Land of Wonder and Bop-Gap to the South                 *\n"+
              "* X= Sweetness-Alchemists Guild-Hole in Gound                     *\n"+
              "*                               and Demoder-Rope Ladder           *\n"+
              "* Y= Bastion-Island and Omega-Kingdom of Omega                    *\n"+
              "*                               and Scathe-A Large Cavern         *\n"+
              "* Z= Boltar-Big House to the west                                 *\n"+
              "* a= After going down the hole; Sandman-A Bed                     *\n"+
              "* b= Adventurer's Guild; under Guild-> Nightshade-Crack           *\n"+
              "*                               and Lew-Silver Train              *\n"+
              "* c= Hawkeye-Time Portal to 1953                                  *\n"+
              "* d= Bagera-Dense Jungle                                          *\n"+
              "* e= Dersharp-Unsharpened Sword in the Ground                     *\n"+
              "* f= Deathmonger-Volcanic Island                                  *\n"+
              "* g= Airwoman-Fountainhead                                        *\n"+
              "* @= Church                                                       *\n"+
              "* $= Shop                                                         *\n"+
              "* %= Post office                                                  *\n"+
              "*******************************************************************\n"+
              "**** That is all, if you have any bugs/typos/suggestions mail me****\n"+
              "****                                  -Dersharp                ****\n"+
              "*******************************************************************\n"+
              "\n");
return 1;
}
return 0;
}
get() { return 1; }
query_weight() { return 1; }
query_value() { return 0;}
