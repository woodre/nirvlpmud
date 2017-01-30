/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2005 Forbin
//                  All Rights Reserved.
//  Realm:        Qual'tor Miniquest
//  Function:     room atmosphere
//  Create Date:  2005.02.17
//  Last Edit:    2005.02.17 -Forbin
*/

#include "/players/forbin/realms/cave/cavedefine.h"

id(str) { return str == "bloodfist_gob"; }

short() 
{
  string shirt;
  return RED+"A blood crystal"+NORM+
         "\nA small torch ("+RED+"lit"+NORM+")";
}

get() { return 0; }