/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   2/21/01           */
/*    Realm:      Acadie            */
/************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"                    /*color header*/
#include "/players/vital/dest/include/dest.h"

inherit "room/room";
int open;

reset(arg) {
    open = 0;
    if(!arg) { 
    set_light(1);
    short_desc = "A Home";
    long_desc =
    "  Ingvaard's House\n\
The lights inside the house comes from small globes that are \n\
mounted along the ceiling. Ingvaard has simple tastes, and \n\
they are reflected in the rather crude, but very solid furniture.\n\
Ingvaard's interests are belied by the locked cases of weapons \n\
mounted to the walls.\n ";

items = ({
    "lights",
    "The light in the room provided by the little globes that are somehow mounted into the ceiling",
    "globes",
    "These globes glow brightly with a sharp light that pierces the darkness",
    "ceiling",
    "The ceiling is full of the light globes and barely 7 feet high",
    "furniture",
    "The furniture is hardwood and constructed to support the massive weight of great friends who come to visit",
    "floor",
    "The floor is covered with the skins of the many kills of Ingvaard",
    "skins",
    "These skins are cured and preserved. They provide warmth and a cushion to the floor",
    "pelts",
    "These animal skins are from strange and exotic beasts that you have never seen before. They have been reverse tanned so that the hair remains upon the large pieces of leather",
    "walls",
    "There are large paintings of great battles commissioned by Ingvaard",
    "paintings",
    "These paintings are great murals that present some of the greatest battles of human history",
    "painting",
    "These paintings are great murals that present some of the greatest battles of human history",
    "cases",
    "These cases are great trophy cases created to display the weapons that Ingvaard has found to be useful in his travels",
    "case",
    "The case turns out to be several cases of weapons"
});

dest_dir = ({
    ACADIE+"room/sidewalk18.c","out"
  });

  }
}

init() {
    ::init();
    add_action("search_me","search");
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
