inherit "obj/treasure";

 id(str) { return str == "piece of paper" || str == "instructions"; }

reset(arg) {
 if(arg) return;
   set_short("A piece of paper");
    set_alias("paper");
   set_long("This paper looks like it tells how to  'Assemble' a powerful weapon!\n"+
    "However, it looks fairly complex and the parts are missing...\n");
   set_weight(2);
    set_value(150);
}

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
 if(!present("box",this_player())) {
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
ob1 = present("box",this_player());
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
