inherit "obj/treasure";
reset(arg){
   set_id("clip");
   set_short("A 9mm Beretta clip");
   set_long("A 9mm Beretta clip, just <insert clip> and rock and roll.\n");
   set_value(500);
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
     weapon=present("beretta",this_player());
     if(!weapon) { write("Where do you want it?\n"); return 1;}
     call_other(weapon,"load");write("You load the weapon.\n");
     say(capitalize(this_player()->query_name())+" loads the beretta.\n");
     destruct(this_object());
     return 1;}
