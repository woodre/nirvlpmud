/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   4/19/01           */
/*    Realm:      Acadie            */
/************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"                    /*color header*/
#include "/players/vital/dest/include/dest.h"

inherit "room/room";
int open, sit;

reset(arg) {
    open = 0;
    sit = 0;
    if(!arg) { 
    set_light(1);
    short_desc = "A Home";
    long_desc =
"  The House of Myrrdin\n\
This is a large one-room home with hardwood floors and white, stone \n\
walls. There is little furniture, but each piece is very nice. In the \n\
center of the north wall is a large hearth, burning with a cheerful \n\
fire. Above the hearth is a locked, display case containing a sword. \n\
In front of the hearth is a large bear's skin used for a rug, and two \n\
large oak chairs, each with a wolf's skin draped over the back. In the \n\
back corner is a bed piled high with skins. In the other corner is a \n\
small table with four small wooden chairs surounding it. In the center \n\
of the south wall is a window with a large oak bookshelf on either side.\n";

items = ({
    "lights",
    "The light in the room provided by the little globes that are somehow mounted into the ceiling",
    "globes",
    "These globes glow brightly with a sharp light that pierces the darkness",
    "ceiling",
    "The ceiling is full of the light globes and barely 7 feet high",
    "furniture",
    "The furniture is hardwood and very comfortable",
    "piece",
    "The furniture is hardwood and very comfortable",
    "pelts",
    "These animal skins are from strange and exotic beasts that you have never seen before. They have been reverse tanned so that the hair remains upon the large pieces of leather",
    "floors",
    "These are simple hard wood floors made of sturdy oak",
    "floor",
    "This is a simple hard wood floor made of sturdy oak",
    "walls",
    "These are simple white stone walls",
    "wall",
    "These are simple white stone walls",
    "furniture",
    "There are several pieces of furniture",
    "hearth",
    "There is a large stone hearth with a fire burnig in it",
    "fire",
    "There is a fire lit in the hearth",
    "case",
    "Just above the mantle you see a locked glass case. There is a sword in it",
    "sword",
    "This is a beutiful longsword. Its hilt is desined to look like a pair of serpents coiling around each other",
    "skin",
    "This is a large wolf skin draped over the back of a chair",
    "rug",
    "There is a large bear skin used as a rug",
    "chairs",
    "There are some small wooden chairs set around the table",
    "back",
    "This is the back of a chair, There is a wolf skin draped over the back of it",
    "corner",
    "This is the corner of the room",
    "table",
    "There is a small, round table used for eating",
    "chair",
    "There is a large beautifully carved oak chair",
    "window",
    "You see a large window looks out onto the side wall of the next house",
    "bookcase",
    "There is a large oak bookcase filled with books. Chief among the books seems to be The Lord of the Rings, by J.R.R. Tolkien",
    "shelf",
    "This is one of many shelves in the bookcase"
});

dest_dir = ({
    ACADIE+"room/sidewalk25.c","out"
  });

  }
}

init() {
    ::init();
    add_action("search_me","search");
    add_action("sit_down","sit");
    add_action("stand_up","stand");
}

search_me(str) {
    if(!str) {
        notify_fail("What are trying to search?\n");
        return 0;
    }
    if(str == "case" || str == "cases") {
        write("You take a closer look at the weapons case.\n\n");
        write("As you search the case, you find that it is locked.\n");
        return 1;
    }
    else write("You furiously search the "+str+" but find nothing.\n");
    return 1;
}

sit_down() {
    write("You sit down.\n");
    say(CTPN+" sits down.\n");
    return 1;
}

stand_up() {
    write("You rise to your feet.\n");
    say(CTPN+" rises to "+TPP+" feet.\n");
    return 1;
}
