/*
*  ssuit.c
*  Katya@Nirvana
*  Copyright (c) 2004 Katya
*  All Rights Reserved.
*/


inherit "obj/armor";

#include <ansi.h>

reset(arg){
   if(arg) return;
   ::reset(arg);

   set_name("superman suit");
   set_alias("suit");
   set_short(HIR+"Superman suit"+NORM);
   set_long("                   "+HIB+" !!!!!"+HIR+"'`.zcdSSSSc,.'"+NORM+" "+HIB+".,..  !!!!!!!!!! "+NORM+" \n"+
"                   "+HIB+" !!!'`"+HIR+",cSSSSSSSSSSSShc,"+NORM+""+HIB+" !!!!!!!!!!!!!"+NORM+"  \n"+
"                   "+HIB+" !!"+HIR+"'.`?SSSSSSSSSSSSSSSSc,"+NORM+""+HIB+"!!!!!!!!!!!!"+NORM+"  \n"+
"                   "+HIB+" !"+HIR+" .'%c '?SSSSSSSSSSSSSSSScc "+NORM+""+HIB+"!!!!!!!! "+NORM+" \n"+
"                   "+HIB+" ! "+HIR+" ',`'%.`?SSSSSSSSS???''''' "+NORM+" "+HIB+"!!!!!!"+NORM+"  \n"+
"                   "+HIB+" !   "+HIR+" `=,`?c,''SSSP''"+NORM+" "+HIY+",cdSSSSSSSS"+NORM+""+HIB+" !!! "+NORM+" \n"+
"                   "+HIB+" !      "+HIR+" `=.'?r '"+NORM+" "+HIY+"',JSSSSSSSSSSSS"+NORM+" "+HIB+" !! "+NORM+" \n"+
"                   "+HIB+" !>   "+HIR+"      ?c`?"+NORM+" "+HIY+" cSSSSSSSSSSSSSS"+NORM+""+HIB+" !!!"+NORM+"  \n"+
"                   "+HIB+" !!.       "+HIR+"   '"+NORM+" "+HIY+" zSSSSSSSS???'''' "+NORM+""+HIB+" !! "+NORM+" \n"+
"                   "+HIB+" !!!;       "+HIY+"   <SSSSSSSF'"+NORM+" "+HIB+"  !!!!!!!!!"+NORM+"  \n"+
"                   "+HIB+" !!!!!;,    "+HIY+"   JSSSSSSSL "+NORM+" "+HIB+"  !!!!!!!!! "+NORM+" \n"+
"                   "+HIB+" !!!!!!!!;,   "+HIY+" <SSSSSSSS. "+NORM+" "+HIB+" !!!!!!!!!"+NORM+"  \n"+
"                   "+HIB+" !!!!!!!!!!;   "+HIY+"`SSSSSSSSSc, "+NORM+" "+HIB+" !!!!!!! "+NORM+" \n"+
"                   "+HIB+" !!!!!!!!!!!>   "+HIY+"`SSSSSSSSSShc,"+NORM+""+HIB+" !!!!!! "+NORM+" \n"+
"                   "+HIB+" !!!!!!!!!!!!>   "+HIY+" 'SSSSSSSSSSSc"+NORM+""+HIB+" !!!!! "+NORM+" \n"+
"                   "+HIB+" !"+HIY+"'`'`"+NORM+""+HIB+"!!!!!"+HIY+"''"+NORM+"      "+HIY+" '?SSSSSSSSSS."+NORM+""+HIB+" !!!"+NORM+"  \n"+
"                   "+HIB+" !  "+HIR+"  =c,.,c,`%.  "+NORM+" "+HIY+"     '?SSSSSSSS"+NORM+""+HIB+"';! "+NORM+" \n"+
"                   "+HIB+" !  "+HIR+"    '?SSSc, '-.    "+NORM+" "+HIY+"  ?SSSSSSS"+NORM+""+HIB+";!! "+NORM+" \n"+
"                   "+HIB+" !      "+HIR+"  ''SSSSh.`%.  "+NORM+" "+HIY+"  <SSSSSSS"+NORM+" "+HIB+"!! "+NORM+" \n"+
"                   "+HIB+" !.       "+HIR+"   '?SSShc,'= "+NORM+" "+HIY+" SSSSSSSF"+NORM+" "+HIB+"!! "+NORM+" \n"+
"                   "+HIB+" !!!;     "+HIY+"     .,.'.,,,cdSSSSSS'"+NORM+""+HIB+" <!!! "+NORM+" \n"+
"                   "+HIB+" !!!!!>;      "+HIY+" ?SSSSSSSSSSSSSS'"+NORM+""+HIB+" !!!!!"+NORM+"  \n"+
"                   "+HIB+" !!!!!!!!;    "+HIY+" JSSSSSSSSSSSS'"+NORM+""+HIB+" ;!!!!!! "+NORM+" \n"+
"                   "+HIB+" !!!!!!!!!!;, "+HIY+" SSSSSSSS??''"+NORM+""+HIB+",;!!!!!!!!"+NORM+"  \n"+
"                   "+HIB+" !!!!!!!!!!!!>.,..``..,;;!!!!!!!!!!!!"+NORM+"  \n");
   set_ac(4);
   set_type("armor"); 
   set_weight(2);
   set_value(2000);

  }
