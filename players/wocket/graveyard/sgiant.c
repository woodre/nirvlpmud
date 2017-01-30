#include "/players/wocket/closed/ansi.h"
inherit "obj/monster";

reset(arg){
int i;
object gold;
    ::reset(arg);
gold = clone_object("/obj/money.c");
gold->set_money(700+random(301));
move_object(gold,this_object());
    if(arg) return;
    set_name("dryant");
    set_race("seussian");
    set_alias("skeleton");
    set_short(HIC+"A "+NORM+"dryant"+HIC+" skeleton"+NORM);
    set_level(17);
    set_hp(425);
    set_wc(30);
    set_ac(13);
if(random(5) == 1){
set_aggressive(1);
}
set_al(0-random(1000));
i = random(4);
switch(i){
case 0: sfrost(); break;
case 1: sfire(); break;
case 2: sstone(); break;
case 3: swind(); break;
}
}


sfrost(){
    set_long("This frail body of bones is covered in icicles.  Many nicks\n"+
    "cover the surface of his bones as this giant apparently died a horrible\n"+
    "bloody death.  Red gleams from the eyes of this walking\n"+
    "undead.\n");
}

sfire(){
    set_long("A glowing blue aura of flame surrounds the walking bones \n"+
    "of this giant skeleton.   Many bones seem to be crushed, implying that\n"+
"he fell from a great distance, dying on impact.\n");
}

sstone(){
    set_long("Even though this dryant is reduced to bones it still shakes\n"+
    "the ground as he walks.  The bones themselves seem to be made from \n"+
    "stone as well, but a closer look would be required to verify that.\n");
}

swind(){
    set_long("These bones are supported by the actual wind currents of the\n"+
    "area.  They dont seem to flow together as he walks, but rather\n"+
    "floating independant of each other.  Also it seem as if they were made\n"+
   "of compressed air, as they are transparent.  A ghostly green \n"+
    "rises from the holes that were this dryant's eyes.\n");
}

