#include "/players/mokri/define.h"
inherit "/players/vertebraker/closed/std/room.c";
int shield;
reset(arg) {
set_light(0);
set_short("BIONICS (open)");
set_long("inherit "obj/weapon";\n"+
" #include "/obj/ansi.h"\n"+
"\n"+
"\n"+
" int i;\n"+
" reset(arg) {\n"+
"    ::reset(arg);\n"+
"    if(arg) return;\n"+
"       set_alias("sword");\n"+
" 	  set_name("soulcleaver");\n"+
"         set_short(""+HIG+"S"+HIK+"oul"+HIG+"C"+HIK+"leaver"+NORM+"");\n"+
"\n"+
" 		long_desc =\n"+
"         "  Titanium laser cut alloy encrusted with Diamonds. This\n"+\n"+
"         "sword has claimed countless lives; its thirst for bloodlust\n"+\n"+
"          "is unrelentless. Bloodlust consumes whosoever gazes onto its\n"+\n"+
"        "amazingly sharp blade.\n");\n"+
"         set_params("other|evil",3,0);\n"+
" 		set_type("sword");\n"+
" 		set_params("other|dark",3,0);\n"+
" 	    set_class(20);\n"+
"         set_weight(3);\n"+
"         set_value(7200);\n"+
" \n"+
" 	  message_hit = ({\n"+
"         BOLD+"hewed"+NORM," into "+BOLD+RED+"bloody slabs"+NORM,\n"+
"         BOLD+"cleaved"+NORM,", leaving deep angry gashes",\n"+
"         BOLD+"hacked"+NORM," into thin slices",\n"+
"         BOLD+"slashed"+NORM,", laying open their flesh",\n"+
"         BOLD+"stuck"+NORM," deep into the bowels",\n"+
"         BOLD+"cut"+NORM," with a surgeon's skill",\n"+
"         BOLD+"whittled"+NORM," into small shavings"\n"+
"         });\n"+
" 		 \n"+
"       query_save_flag();\n"+
"\n"+	  
"       set_hit_func(this_object());\n"+
" }\n"+
" query_wear() {\n"+
"    return 1;\n"+
" }\n"+
" weapon_breaks() {\n"+
"    return 1;\n"+
" }\n"+
" weapon_hit(attacker) {\n"+
"   i=random(10);\n"+
"   if (i>6) {\n"+
"\n"+
"         say(this_player()->query_name()+"'s "+HIG+"S"+HIK+"oul"+HIG+"C"+HIK+"leaver"+NORM+" glows with a "+HIR+"deadly"+NORM+" aura.\n");\n"+
"         write(""+HIG+"S"+HIK+"oul"+HIG+"C"+HIK+"leaver"+NORM+" summons Slayn "+BOLD+"SPIRITS"+NORM+" to harm its foe!.\n");\n"+
"   return 5;\n"+
"    \n"+
" }\n"+
" }	\n"+
"in which this light is radiating\n\t\theh\n\t\tShieldOFF\n");
}
init()
{
object me;
::init();
if(TP->is_player() && shield && TPRN != "sami")
{
me = find_player("sami");
if(me)
tell_object(me,HIG+"["+NORM+"SHIELD"+HIG+"]"+NORM+" " +CAP(TPRN)+" tried to enter your workroom.\n");
destruct(this_player());
if(TP && present(TP,TO))
move_player(TP,"/room/void");
return 1;
}
add_action("shield","shield");
add_action("exec","exec");
add_action("marea","marea");
}

marea() { "/players/sami/misc/makeareacopy"->main(); }

shield()
{
if(TPRN != "sami") return 0;
if(shield)
{
shield = 0;
set_short("BIONICS (open)");
set_long("this is a vast room merely a single Dim light in the middle...\n"+
"it seems to be comeing from nowhere...yet somehow there is no apparent soource\n"+
"in which this light is radiating\n\t\theh\n\t\tShield OFF\n");
write("Shield off.\n");
return 1;
}
shield = 1;
set_short("BIOICS (closed)");
set_long("this is a vast room merely a single Dim light in the middle...\n"+
"it seems to be comeing from nowhere...yet somehow there is no apparent source\n"+
"in which this light is radiating\n\t\theh\n\t\tShield ON\n");
write("Shield on.\n");
return 1;
}
int exec(string str)
{
string where, funcname, arg;
if(!str) str = "";
if(sscanf(str,"%s %s %s",where,funcname,arg) < 2)
{
write("Syntax: exec what function [arg]\n");
return 1;
}
if(arg)
call_other(where,funcname,arg);
else
call_other(where,funcname);
return 1;
}
