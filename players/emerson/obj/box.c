inherit "obj/treasure";

reset(arg) {
 if(arg) return;
   set_short("A box of parts");
    set_alias("box");
   set_long("This box of parts look like it could be 'Assembled' to form an awesome weapon!\n"+
    "However, it looks fairly complex and some parts may be missing...\n");
   set_weight(2);
    set_value(0);
}
 id(str) { return str == "box" || str == "box"; }

     init() {
     add_action("assemble","assemble");
    }
     assemble(str) {
object ob,ob1;
     if(str != "weapon" || !str) return 0;
     write("You attempt to assemble the weapon.\n");
if(!present("clip",this_player())) {
write("You don't have everything needed to assemble the weapon!\n");
return 1; 
}
else {
 if(!present("instructions",this_player())) {
write("You don't have everything needed to assemble the weapon!\n");
return 1;
}
else {
write("You carefully read over the instructions...\n");
write("You take the parts from the box and assemble them...\n");
write("It begins to start taking shape...it looks like an oozie!!\n");
write("You take the clip and insert it in the oozie.\n");
write("CLICK!\n");
write("You have successfully completed the weapon!\n");
move_object(clone_object("players/emerson/weap/test.c"),this_player());
ob = present("clip",this_player());
ob1 = present("instructions",this_player());
destruct(ob);
destruct(ob1);
destruct(this_object());
return 1;
}
}
}


/*
     {if(present("clip",this_player())) ; else {
write("You don't have everything needed to assemble the weapon!\n");
     return 1; }
     {if(present("instructions",this_player())) ; else {
     write("You don't have everything needed to assemble the weapon!\n");
return 1; }
     write("You have successfully completed the weapon!\n");
     clone_object("players/emerson/weap/test.c");
     return 1;
     }
     }

*/
