/*
 *      File:                   /wiz/bin/_more.c
 *      Function:               More command
 *      Author(s):              Nirvana
 *      Copyright:              Copyright (c) 2005 Nirvana
 *                                      All Rights Reserved.
 *      Source:                 11/06/05
 *      Notes:                  See 'wizhelp more' 
 *      Change History:
 */

#include <ansi.h>
#include <security.h>

/* 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */
 
int cmd_more(string str)
{
 object ob;
 
 if (!str || str == "here")
   str = "/"+object_name(environment(this_player()))+".c";
 else
   str = resolve_path(str);
 
/* diag write -Bp
 write("file-name-passed-to-more: "+str+"\n");
*/
 ob = clone_object("obj/more_ob");
 ob->more(str);
 return 1;
}

