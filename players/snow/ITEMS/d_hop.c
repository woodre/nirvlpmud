inherit "obj/treasure";
 
reset(arg)  {
  if(arg) return;
 
   set_id("hopper");
   set_short("A D-Hopper");
   set_long(
   "This a D-Hopper. In other words- it takes you where you want to go..\n"+
   "to check settings, type 'where'. After you type the command, you will \n"+
   "be instantly transported with a small sensation of movement. It's a\n"+
   "bit disorienting at first but the experienced D-Hopper quickly adjusts.\n"+
   "Good luck...\n");
   set_weight(0);
   set_value(0);
}
 
init()   {

if(this_player()->query_level() < 20) {destruct(this_object());}

  add_action("where", "where");
  add_action("hop","hop");
  add_action("geto","geto");
  }

where() {
  write ("Church\n" +"Shop\n" +"Hotel\n" +"Lockers\n" +"Pub\n" +"Mount\n"
  +"Ryllian\n" +"51\n" +"Post\n" +"Inner\n" +"Chamber\n");
return 1;  }
  

hop(arg) {
  if(!this_player()->query_invis())
  say(call_other(this_player(),"query_name")+ 
       " presses some buttons on a rod and disappears.\n");
  write("You input your coordinates...\n"+"\n"+
            "You feel a gut wrenching sensation...\n");
if (arg == "church") {
    move_object(this_player(),"/room/church");
  }
if (arg == "shop") {
  move_object(this_player(),"/room/shop");
  }
if (arg == "hotel") {
  move_object(this_player(),"/players/boltar/hotel/hotel");
  }
if  (arg == "lockers") {
  move_object(this_player(),"/players/catwoman/tl");
  }
if (arg == "pub") {
  move_object(this_player(),"/room/pub2");
  }
if (arg == "mount") {
  move_object(this_player(),"/room/plane10");
  }
if (arg == "ryllian") {
  move_object(this_player(),"/players/saber/ryllian/ryllian1");
  }
if (arg == "51") {
  move_object(this_player(),"/players/hippo/games/fo_room");
}
if (arg == "post") {
  move_object(this_player(),"/room/post");
}
if (arg == "inner") {
  move_object(this_player(),"/room/adv_inner");
}
if (arg == "chamber") {
  move_object(this_player(),"/players/saber/ryllian/portal");
}
  write("You have appeared and are alive and well.\n");
  if(!this_player()->query_invis())
  say(call_other(this_player(),"query_name")+ 
        " appears from another dimension.\n");
command("look",this_player());
return 1;  }

geto (arg) {
    object who,where;
    who= find_living(arg);
     if(!who) {
        write("No players with that name on.\n");
        return 1;
      }
    where=environment(who);
    move_object(this_player(),where);
    write("You have appeared.\n");
command("look",this_player());
    return 1;
  }
