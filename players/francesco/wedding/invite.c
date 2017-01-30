#include "/players/francesco/univ/ansi.h"
inherit "/obj/treasure.c";

id(str) { return str == "invite" || str == "wedding invite" || str==" invitation"; }
int opened;

reset(arg) {
   if (arg) return;
   }

long() { write("A folded white card with silver decorations. It reads: \n"+
               "           You Are Invited To Our Wedding. \n"+
               "It's possible to 'open' the card and 'read' its contents.\n"); }

short() { return ""+HIB+"Wedding invite"+NORM+""; }

init() {
    add_action("open","open");
    add_action("read","read");
    add_action("send","send");
    return 1;
}

open(arg) {
    if(!present("invite",this_player())) {notify_fail("You dont have any invite.\n");return 0;}
    if(!arg) {notify_fail("Open what?\n"); return 0; }
    if(arg=="card" || arg == "invite" || arg =="invitation" || arg=="wedding invite") { opened = 1; return 1;}
   notify_fail("Open what?\n");
 return 0;   
}

read(arg) {
    if(!present("invite",this_player())) {notify_fail("You dont have any invite.\n");return 0;}
    if(!arg) {notify_fail("read what?\n"); return 0; }
    if(opened){
    if(arg=="contents" || arg=="card" || arg =="invite") { 
     write("                      Wedding invitation\n\n"+
           "   Sir Fantasy Warrior                  Lady Ceres Warrioress\n\n"+
           "                           at Nirvana\n"+
           "                    Thursday, June 27th, 2002\n");
     return 1;}
     notify_fail("Open the invite to read it.\n"); 
     return 0;}
   notify_fail("read what?\n");
 return 0;   
}

drop(){ return 1;}

query_weight() { return 0; }

query_value() { return (1); }

query_save_flag() { return 1; } 
