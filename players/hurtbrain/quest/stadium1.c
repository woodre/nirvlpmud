
inherit "room/room";

reset(arg) {
   int k;
   int num;
   object obj;
   if(arg) return;
    short_desc = "The stadium" ;
    long_desc = "You are in a very big stadium with one hundred of thousands"+
    "spectators looking at the football match. Many of them are shouting and"+
    "screaming at the players. Everyone here seems to be a little strange."+
    "You always think you'll simply find your informer?\n";
   dest_dir =
   ({
    "/players/hurtbrain/quest/stadium2","south",
    "/players/hurtbrain/quest/stbar","north",
    "/players/hurtbrain/quest/stadium4","east",
    "/players/hurtbrain/quest/ent_stadium","west",
    "/players/hurtbrain/quest/stadium3","southeast",
    "/players/hurtbrain/quest/stadium5","northeast"
    } ) ;
    num=random(3);
    for(k=0;k<=5+num;++k)  {
        obj=clone_object("players/hurtbrain/quest/spect.c");
        move_object(obj,this_object());
        }
    num=random(2);
    if(num)  {
        obj=clone_object("players/hurtbrain/quest/bibit.c");
        move_object(obj,this_object());
        }
set_light(1);
}
realm(){return "NT";}
