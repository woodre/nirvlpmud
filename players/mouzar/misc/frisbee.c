inherit "obj/treasure";

reset(arg) {
    string color;
    int r;
    /*::reset(arg);*/
    if (arg)
       return;
    set_id("frisbee");
    r = random(10);
    if (r == 0)
        color = "A black";
    else if (r == 1)
        color = "A brown";
    else if (r == 2)
        color = "A red";
    else if (r == 3)
        color = "An orange";
    else if (r == 4)
        color = "A yellow";
    else if (r == 5)
        color = "A green";
    else if (r == 6)
        color = "A blue";
    else if (r == 7)
        color = "A violet";
    else if (r == 8)
        color = "A gray";
    else if (r == 9)
        color = "A white";
    else if (r == 10)
        color = "A transparent";
    set_short(color + " frisbee");
    set_long(color + " plastic frisbee.  (Type 'throw frisbee to <player>'). \n");
    set_value(0);
    set_weight(1);
    return 1;
}

  init() {
    ::init();
    add_action("throw","throw");
}

throw(str) {
   object ob;
   string what, who;
   if(!str || sscanf(str, "%s to %s", what, who) != 2){
     write("Who do you want to throw it to?\n");
     return 1;
   }
   what = lower_case(what);
   who = lower_case(who);
   ob = find_living(who);
   if(!ob || !living(ob) || ob == this_player() || ob->invis()) {
     write("Who do you want to throw it to?\n");
     return 1;
   }
   if(!ob->query_level()>20 || !ob->query_real_name() == "mouzar" ||
     !ob->query_real_name() == "saber" || !ob->query_real_name() == "sado" ||
     !ob->query_real_name() == "rumplemintz" ||
     !ob->query_real_name() == "turk" || !ob->query_real_name() == "arrina"){
     write("This must be a Grumpy wiz so you can't throw the frisbee to them.\n");
     return 1;
   }
   write("You throw the frisbee to " + ob->query_name()+ ".\n"); 
   say(this_player()->query_name() + " throws the frisbee. \n");
   if(random(10)<1){
     say(ob->query_name() + "Ack! Bad throw!\nThe frisbee floats off never to be found.\n");
     destruct(this_object());
     return 1;
   }
   transfer(this_object(), ob);
   if(random(10)<5){
     tell_object(ob, "You make a diving catch for a frisbee!\n");
     say(ob->query_name() + " dives to catch a frisbee.\n");
   } else {
     tell_object(ob, "You catch a frisbee.\n");
     say(ob->query_name() + " catches a frisbee.\n");
   }
   return 1;
}
