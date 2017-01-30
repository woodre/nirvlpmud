/******************************************************************************
 *  File:           channeld.c
 *  Function:       
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 2004 v-Dev Code Factory
 *                  All Rights Reserved.
 *  Source:         02/05/2004
 *  Notes:          
 *  Change History:
 *****************************************************************************/

#include "../inc/def.h"

mapping Channels;

void
reset(int arg)
{
    if(arg) return;
    Channels = ([ ]);
}

void
login(object ob)
{
}

void
unlogin(object ob)
{
}
