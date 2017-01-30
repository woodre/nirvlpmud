inherit "/obj/monster";
#include "/players/stark/defs.h"
int expneeded;
int minexp;
int fae;
int luck;

reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_short("Rakh");
    set_name("Elder Rakh");
    set_alt_name("guild_adv");
    set_alias("rakh");
    set_gender("male");
set_level(30);
}

init(){
add_action("rj","rj");
add_action("raise","raise");
add_action("advance","advance");
}

raise(string str){
fae=(present("rakh_guild"),TP)->query_fae();
if(!str){write("Raise what?\n");}
if(str=="fae"){
    if(fae==1){expneeded=1548;}
    if(fae==2){expneeded=1548;}
    if(fae==3){expneeded=1548;}
    if(fae==4){expneeded=1548;}
    if(fae==5){expneeded=1548;}
    if(fae==6){expneeded=1548;}
    if(fae==7){expneeded=1548;}
    if(fae==8){expneeded=1548;}
    if(fae==9){expneeded=1548;}
    if(fae==10){expneeded=1548;}
    if(fae==11){expneeded=1548;}
    if(fae==12){expneeded=1548;}
    if(fae==13){expneeded=1548;}
    if(fae==14){expneeded=1548;}
    if(fae==15){expneeded=1548;}
    if(fae==16){expneeded=1548;}
    if(fae==17){expneeded=1548;}
    if(fae==18){expneeded=1548;}
    if(fae==19){expneeded=1548;}
    if(present("rakh_guild"),TP)->query_stored_exp)<expneeded){
          write("You don't have the training to raise that skill.\n");
	  return 1;
    }
    present("rakh_guild"),TP)->add_stored_exp(-expneeded);
    present("rakh_guild"),TP)->raise_fae();
    write("You raise your knowledge of the fae.\n");
    return 1;
}
if(str=="luck"||"luc"){
    if(TP->query_luck()<20){
        write("You should rise this elsewhere.\n");
	return 1;
    }
    if(luck==20){expneeded=1548;}
    if(luck==21){expneeded=1548;}
    if(luck==22){expneeded=1548;}
    if(luck==23){expneeded=1548;}
    if(luck==24){expneeded=1548;}
    if(luck==25){expneeded=1548;}
    if(luck==26){expneeded=1548;}
    if(luck==27){expneeded=1548;}
    if(luck==28){expneeded=1548;}
    if(luck==29){expneeded=1548;}
    if(present("rakh_guild"),TP)->query_stored_exp)<expneeded){
        write("You don't have the training to raise that skill.\n");
	return 1;
    }
    present("rakh_guild"),TP)->add_stored_exp(-expneeded);
    TP->raise_luck();
    write("Your luck and agility are raised.\n");
    return 1;
}
write("You will need to raise that elsewhere.\n");
return 1;}

rj(){
MOCO("/players/stark/rakh/gob.c"),TP);
write("You join rakh\n");
return 1;}
