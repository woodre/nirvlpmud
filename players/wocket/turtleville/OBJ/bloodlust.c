#include "/players/wocket/closed/ansi.h"
inherit "/obj/weapon";

reset(arg){
    if(arg) return;
    ::reset(arg);
    set_alt_name("bloodlust");
    set_alias("broadsword");
    set_name(RED+"Bloodlust"+NORM+" the mighty broadsword");
    set_long("This finely sharpened broadsword is stained with the blood of its many foes.\n"+
    "The hilt is decorated in silver and rubies and the blade has many ancient\n"+
    "runes carved into it.  It looks menacing.\n");
set_read("You can't seem to understand the deep runes.\n");
set_class(19);
    set_weight(3);
    set_type("sword");
    set_weight(3);
    set_value(2000);
    set_hit_func(this_object());
}


weapon_hit(attacker){
int i;
i = random(13);
if(i==1){
write(RED+"Bloodlust"+NORM+" the mighty broadsword leaps from your hands slashing your opponent\n"+
"as it "+HIR+"F_E_E_D_S "+NORM+"upon the spilled "+RED+"blood"+NORM+" it has created...\n");
}
if(i==0){
write("Light flashes upon the "+RED+"blood stained"+NORM+" blade.\n");
}
if(i==2){
write(RED+"Bloodlust"+NORM+" the mighty broadsword sinks deep into the flesh of its adversary.\n");
}
if(i==5){
write(HIR+"PAIN"+NORM+" rips through your veins as "+HIR+"BLOODLUST"+NORM+" drains life from you.\n\n"+HIR+
"      MMMMMMMMM     MMM   MMM       MMMMMMM,      MMM     MMM    \n"+
"      MMM  _        MMM   MMM       MMM   MM       MMM   MMM     \n"+
"      MMMMMM        MMM   MMM       MMMMMMM'         MMMMM       \n"+
"      MMM  ~        MMM_ _MMM       MMM  MMM          MMM         \n"+
"      MMM            `MMMMM'        MMM   MMM         MMM          \n\n"+
"erupts as the sword causes blood to flow....\n"+NORM);
say(HIR+"\nFURY"+NORM+" is unleashed as "+RED+"Bloodlust"+NORM+" hits "+NORM+attacker->query_name()+".\n\n");
return 6;
}
if(i==12){
write(HIR+"SUDDENLY"+NORM+" you're filled with...\n\n"+HIR+
" MMMMMM,  MMM      MMMMMMM  MMMMMMM  MMMMm      MMM      MM   MM   MMMMM,  MMMMMMMMM\n"+
" MMM  MM  MMM      MM~ ~MM  MM~ ~MM  MMM `MM    MMM      MM   MM  `MM~  `  MMMMMMMMM\n"+
" MMMMM~   MMM      MM   MM  MM   MM  MMM  `MM   MMM      MM   MM    MMM,      MMM\n"+
" MMM  MM  MMM      MM_ _MM  MM_ _MM  MMM  MM    MMM      MM   MM  m_ MMMm     MMM\n"+
" MMMMMM'  MMMMMMM  MMMMMMM  MMMMMMM  MMMMM~     MMMMMMM  `MMMMM'  MMMMMM'     MMM\n\n"+NORM+
"As you hack at your opponent chunks of "+HIR+"BLOODY FLESH"+NORM+" fly in every direction.\n");
say(HIR+"\nBLOODLUST"+NORM+" is unleashed as "+RED+"Bloodlust"+NORM+" hits "+NORM+attacker->query_name()+".\n\n");
return 6;
}
if(i==11){
write("Warm "+HIR+"BLOOD POURS"+NORM+" across your hands as "+RED+"Bloodlust"+NORM+" the mighty broadsword\n"+
"tears into its opponent's neck.  As "+HIR+"BLOOD"+NORM+" spurts uncontrollably\n\n"+HIR+
"   MMMMMMMMM   MMMMMMMM   MMMMMMM     MMMMMMM,    MMMMMMM   MMMMMMM,   \n"+
"   MMMMMMMMM   MMM        MMM  MMM    MMM   MM    MM~ ~MM   MMM   MM   \n"+
"      MMM      MMMMM      MMMMMMM     MMMMMMM'    MM   MM   MMMMMMM.   \n"+
"      MMM      MMM        MMM  MMM    MMM  MMM    MM_ _MM   MMM  MMM   \n"+
"      MMM      MMMMMMMM   MMM   MMM   MMM   MMM   MMMMMMM   MMM   MMM  \n\n"+NORM+
"is released.  Your adversary shivers in "+HIR+"PAIN"+NORM+"...\n");
say(HIR+"\nTERROR"+NORM+" is unleashed as "+RED+"Bloodlust"+NORM+" hits "+NORM+attacker->query_name()+".\n\n");
return 6;
}

}
