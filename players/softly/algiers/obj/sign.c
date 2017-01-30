/******************************************************************************
 *  
 *  File:           sign.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:			Started 2/26/01.
 *  
 *  Notes:			
 *  
 *  Change History: 
 *  
 *  
 *****************************************************************************/

#include "/players/softly/closed/ansi.h"

read_sign() {
    object ohat, omisc, oarmor, ohelmet, oboots, oshield, oring;
    string shat, smisc, sarmor, shelmet, sboots, sshield, sring;
    int vhat, vmisc, varmor, vhelmet, vboots, vshield, vring;
    object hat, misc;
    hat = clone_object(random_hat());
    misc = clone_object(random_misc());
    ....etcetera....
    shat = ohat->query_short();
    smisc = omisc->query_short();
    ....etcetera....
    vhat = ohat->query_value();
    vmisc = omisc->query_value();
    ....etcetera....
    write("+++++++++++++++++++++++++++++++++++++++++++++");
    write("+ (1) "+pad(shat, 10)+"     "+pad(vhat, -5)+"                        +") ;
    
