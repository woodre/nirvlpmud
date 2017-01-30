/* approved by Wizardchild and Sandman */
#include "/players/wocket/closed/ansi.h"
inherit "/obj/treasure";

reset(arg){
    set_id("balloon");
this_object()->setshort();
    set_long("This is a balloon filled with helium.  If you get it you might be\nable to 'suck' out the helium.\n");
}

init(){
    add_action("suck","suck");
    add_action("pop","pop");
call_out("boom",90+random(2000));
}

int suck(string str){
if(str != "balloon"){
return 0;
}
if(environment(this_object()) != this_player()){ 
notify_fail("You need to get the balloon before you can suck it.\n");
return 0;
}

write("You suck out all the helium of the balloon.\n");
say(this_player()->query_name()+" sucks the balloon dry.\n");
move_object(clone_object("/players/wocket/junk/squeaktalk.c"),this_player());
destruct(this_object());
return 1;
}

int pop(string str){
if(str != "balloon")
{
notify_fail("What would you like to pop?\n");
return 0;
}
write("You pop the balloon.\n");
this_object()->boom();
return 1;
}

void boom(){
remove_call_out("boom");
say(BOLD+"PPPPOOOOWWWW!!!!!!"+NORM+"\nYou think a balloon just popped.\n");
destruct(this_object());
}

setshort(){
int color;
string colortyp;
color = random(6);
switch(color){
case 0:    colortyp = HIR; break;
case 1:    colortyp = HIG; break;
case 2:    colortyp = HIB; break;
case 3:    colortyp = HIY; break;
case 4:    colortyp = BOLD; break;
case 5:    colortyp = HIM; break;
case 6:    colortyp = HIR; break;
}
set_short(colortyp+"A balloon"+NORM);
}
