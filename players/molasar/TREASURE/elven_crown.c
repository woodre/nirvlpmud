
inherit "obj/treasure";

reset(arg) {
     if(arg) return;
     set_id("elven crown");
     set_short("An elven crown");
     set_long("The fabled lost crown of Elven Kings.  The crown was rumored\n"+
          "to have been stolen and hidden by the Orc's under the mountain.\n");
     set_weight(1);
     set_value(500);
}

init() {
     add_action("not","trump");
     add_action("not","use");
     add_action("not","sneak");
     add_action("not","escape");
     add_action("not","invoke");
     add_action("not","teleport");
     add_action("give_crown","give");
}

not() {
     write("The magical properites of the crown interfere with your teleportation device.\n");
     return 1;
}

give_crown(str) {
   object ob, ob1, ob2, ob3, qstob;
   string me;
   me = this_player()->query_name();

   if(!str) {
     write("Give what to whom?\n");
     return 1;
   }
   if(str == "elven crown to king" || str == "elven crown to King" ||
      str == "elven crown to elendil" || str == "elven crown to Elendil") {
     ob = present("elven crown", this_player());
     ob1 = present("elendil", environment(this_player()));
     if(!ob) {
       write("You do not have an elven crown.\n");
       return 1;
     }
     if(!ob1) {
       write("Elendil is not here.\n");
       return 1;
     }
     destruct(ob);
     write("Elendil says:  Thank you for returning my crown to me.\n"+
           "               Take this boat to the sea and sail to the isle.\n"+
           "               There you will fullfil your quest.  Good luck.\n");
     write("Elendil gives you a folding boat.\n");
     say("Elendil gives "+capitalize(me)+" a folding boat.\n");
     ob2 = clone_object("players/molasar/MAGIC/boat");
     ob3 = clone_object("players/molasar/OBJ/qstob");
     move_object(ob2, this_player());
     move_object(ob3, this_player());
     qstob = present("qstob2", this_player());
     if(qstob) {
       destruct(qstob);
       return 1;
     }
     return 1;
   }
}

