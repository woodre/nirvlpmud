
inherit "room/room";

reset(arg) {
   object obj;
   if(arg) return;
    short_desc = "Bond's base" ;
    long_desc = "You left your car and you arrive in Bond's secret base.\n"+
    "There are many scientist working on some different strange objects\n"+
    "and you can see also a rocket. Your boss is here to congrats with you\n"+
    "for the good job you done in this mission!\n";
   dest_dir =
   ({
    "/players/hurtbrain/quest/bondquest","exit",
    } ) ;
    obj=clone_object("/players/hurtbrain/quest/boss.c");
    move_object(obj,this_object());
    set_light(1) ;
}
realm(){return "NT";}
