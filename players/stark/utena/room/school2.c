inherit "/players/stark/room";
#include "/players/stark/defs.h"
int opendoor=0;

reset(arg){
    if(arg) return;
    set_light(1);
    set_listen("Muffled but still strong, the din of student life can be heard from the south.");
    set_smell("Settled dust ruffles up your nose hairs.");
    set_search("The high dust level exposes footprints leading toward the bookcase.");
    short_desc="Student Council Office";
    long_desc=
"   This is a small office.  There are a few binders and parchments out \n"+
"on a table.  There are four chairs placed on each side of the table.  \n"+
"A bookcase takes up the entire back wall.\n";

items=({
"office","This is the office of the Student Council",
"table","A small wood table",
"binders","A few empty binders are scattered on the table",
"parchments","The few parchments are unused",
"chairs","There seems to be no room for these chairs",
"bookcase","The bookcase is crammed full of books",
"books","Most of the books are about french and japanese history.  One title stands out; Revolution",
"revolution",
"The title done in gold leaf shines out the other books.\n"+
"It seems stuck out, perhaps you could "+HIR+"push"+NORM+" it in",
"book","There are many books"
});

dest_dir=({
"/players/stark/utena/room/school.c", "south"
});

}

init() {
::init();
add_action("push","push");
add_action("north","north");
}
push(arg) {
if(!arg) {
write("Push what?\n");
return 1;
}
if(arg == "book") {
write("Which book?\n");
return 1;
}

if(arg == "revolution") {
if(opendoor == 1) {
write("The book springs back and the door closes.\n");
say(TPN+" pushes a book in and the bookcase closes.\n");
opendoor=0;
return 1;
}

write("You push the book in and the bookcase opens in.  There is a passage to the north.\n");
say(TPN+" pushes a book in and the bookcase opens up.\n");
opendoor=1;
return 1; }
}

north() {
if(opendoor == 0) {
return 0;
}
write("You pass by the bookcase and enter a hallway.\n");
TP->move_player("north#/players/stark/utena/room/school3");
return 1;
}

