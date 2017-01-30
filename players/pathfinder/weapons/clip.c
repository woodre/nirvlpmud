inherit "/obj/treasure";
reset(arg){
   set_id("m16clip");
   set_short("11mm Clip");
   set_short("m16 clip");
    set_long("An 11mm clip just <insert clip> to load an 11mm.");
    set_value(20);
    set_weight(1);
}
init()
{
     add_action("insert","insert");
}
insert(str){
     object weapon;
     if(!str){write("Insert what?\n");
return 1;}
     if(str !="clip"){write("Insert what?\n");return 1;}
     weapon=present("11mm",this_player());
     if(!weapon){write("Where do you want it dick?\n");return 1;}
     call_other(weapon,"load");write("You load the weapon.\n");
     say (capitalize(this_player()->query_real_name())+" loads the 11mm.\n");
     destruct(this_object());
     return 1;}
