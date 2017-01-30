/*
 *  A moving monster/room in the shape of a cloud for the Bards Guild of Ryllian
 *  Based on the code from Merlyn (Ted S.) (thankx Ted!)
 *  The cloud can only fly to players that are standing in a room with a "storm" in it.
 *  v3.0 by Saber / Geoffrey Z.
 *
 */


inherit "obj/monster";

#define TP this_player()
#define TO this_object()


object ob, ob2, MASTER, climb_ob;
int climb_mode;
string where, str2, MASTER_NAME;

reset(arg)  {
  ::reset(arg);
  if (!arg) {
    set_level(15);
    set_hp(100000);
    set_wc(0);
    set_alias("cloud");
    set_ac(10000);
    enable_commands();
    set_heal(5,50);
        }
        }

set_master(obj) { MASTER = obj; MASTER_NAME = MASTER->query_real_name(); }

/*
id(str) { return (str == "cloud" || str == "storm cloud " || str == "guild_monster"); }
*/

short() { return "A dark storm cloud"; }

attacked_by(obj) { tell_room(TO,"The storm cloud is attacked by "+obj->query_name()+"!\n"); }

long()  {
  write("A large, solitary storm cloud that hangs in the sky with effortless grace.  It\n"+
        "folds and twists around itself as it drifts with the wind, leaving small wisps\n"+
        "of dark vapor trailing off into the distance.  Occasional flashes of lightning\n"+
        "illuminate the cloud, revealing that there appears to be someone riding it...\n");
 if(TP == MASTER)  {
   write("Master commands: soar, pickup, dropoff, disperse, lookdown, speak, rain, thunder\n");
        }
 if(environment(TP) == TO)  {
   write("Cloud commands: climbdown, lookdown\n");
        }
        }


init()  {
  add_action("fly", "soar");
  add_action("speak", "speak");
  add_action("pickup", "pickup");
  add_action("dropoff", "dropoff");
  add_action("disperse", "disperse");
  add_action("rain", "rain");
  add_action("thunder", "thunder");
  add_action("climbup", "climbup");
  add_action("lookdown", "lookdown");
  add_action("climbdown", "climbdown");
        }


adjust_path(str)  {
string mod;

  switch (str) {
    case "n":   mod = "north";     break;
    case "s":   mod = "south";     break;
    case "e":   mod = "east";      break;
    case "w":   mod = "west";      break;
    case "u":   mod = "up";        break;
    case "d":   mod = "down";      break;
    case "sw":  mod = "southwest"; break;
    case "se":  mod = "southeast"; break;
    case "nw":  mod = "northwest"; break;
    case "ne":  mod = "northeast"; break;
      default:  mod = str;         break;
        }
  return(mod);
        }


parse_path(str)  {
  string rest;
  int num, cnt, rep, kickout;
  while (str && !kickout) {
    num = sscanf(str,"%s,%s",str,rest);
    if (num == 2) {
      if (sscanf(str,"%d%s",rep,str) == 2) {
        cnt = 0;
        while (cnt < rep && !kickout) {
          cnt++;
          kickout = !command(adjust_path(str),this_object());
        }
      } else {
        kickout = !command(adjust_path(str),this_object());
      }
      str = rest;
    } else {
      if (sscanf(str,"%d%s",rep,str) == 2) {
        cnt = 0;
        while (cnt < rep && !kickout) {
          cnt++;
          kickout = !command(adjust_path(str),this_object());
        }
      } else {
        kickout = !command(adjust_path(str),this_object());
      }
      str = 0;
        }
        }
  if (kickout) write("The cloud hits something solid.\n");
        }


marked_location(str)  {
string dest;

 switch(str) {
    case "church": dest = "/room/church"; break;
    case "hotel": dest = "/players/boltar/hotel/hotel"; break;
    case "shop": dest = "/room/shop"; break;
    case "lockers": dest = "/players/catwoman/tl"; break;
    case "daycare": dest = "/players/boltar/sprooms/daycare"; break;
    case "portal": dest = "/players/saber/ryllian/portal"; break;
    case "orin": dest = "/players/saber/ryllian/orin1"; break;
    case "bard": dest = "/players/saber/closed/bard/teleport"; break;
    case "market": dest = "/players/saber/ryllian/ms4"; break;
        }
  if (!dest) return;
  if (environment(this_object())->realm() == "NT") {
    write("The cloud is unable to fly from here.\n");
    return(1);
        }
  call_other(TP, "add_spell_point", 10);
  write("Ok.\nYou guide the storm cloud skillfully through the air.\n");
  tell_room(environment(),"The wind has blown the storm cloud out of sight.\n");
  move_object(this_object(), dest);
  tell_room(environment(),"A storm cloud drifts into the room.\n");
  tell_room(this_object(), "The storm cloud glides through the skies...\n");
  return 1;
        }


/* move cloud */
fly(str)  {

  if (TP->query_real_name() != MASTER_NAME) return;

  ob = find_living(str);
 
  if(!ob) {
    if (marked_location(str)) return 1;
    if (!command(adjust_path(str),TO)) {
      parse_path(str);
        }
    return 1;
        }

  if(environment(ob) == TO) {
    write("The cloud says: I'm already carrying " + ob->query_name() + "!\n");
    return 1;
        }
        
  if(environment(ob)->realm() == "NT" || environment()->realm() == "NT") {
    write("The cloud is unable to fly there.\n");
    return 1;
        }

  if(!present("storm", environment(ob)))  {
    write(ob->query_name()+" is not standing within a storm.\n");
    return 1;
        }
        
  call_other(TP, "add_spell_point", -20);
  write("Ok.\nYou guide the cloud skillfully through the air.\n");
  tell_room(environment(),"The wind has blown the storm cloud out of sight.\n");
  move_object(TO, environment(ob));
  tell_room(environment(),"A storm cloud drifts into the room.\n");
  tell_room(TO, "The storm cloud glides through the skies ...\n");
  tell_room(TO, call_other(environment(TO), "short")+"\n");
  return 1;
         }


/* let player move on to cloud */
pickup(str)  {
  if (TP->query_real_name() != MASTER_NAME) return;

  ob = present(str,environment());

  if(!ob) {
    write("You cannot see that person present!\n");
    return 1;
        }
  
  if (!interactive(ob)) {
    write("You can only pick up players!\n");
    return 1;
        }
        
  tell_room(environment(),"Someone's arm pokes down through the clouds!\n");
  tell_object(ob,"The arm extends its hand out to you.\n"+
    "To take ahold of the arm, type 'climbup'.\n");
  write("You extend your arm towards " + ob->query_name() + ".\n");
  climb_ob = ob;
  climb_mode = 1;
  return 1;
        }


/* drop play off of cloud */
dropoff(str)  {
  if (TP->query_real_name() != MASTER_NAME) return;
  ob = present(str,TO);
  if (ob->query_real_name() == MASTER_NAME) {
    write("You cannot drop yourself!\n");
    return 1;
        }
  if (!ob) {
    write("The storm cloud peers at you quizzically.\n");
    return(1);
        }
  tell_room(TO, ob->query_name() + " suddenly falls through the storm cloud!\n");
  tell_object(ob, "You suddenly drop through the storm cloud and fall to the ground.\n");
  tell_room(environment(),ob->query_name() + " drops down from the storm cloud and falls to the ground.\n");
  move_object(ob,environment());
  write("Ok.\n");
  return 1;
        }


/* get rid of cloud */
disperse(str)  {
  if (TP->query_real_name() != MASTER_NAME) return;
  tell_room(environment(), "The storm cloud suddenly explodes !!\n");
  tell_room(this_object(), "The storm cloud billows into a neat explosion and you crash to the ground.\n");
  ob = first_inventory(this_object());
  while (ob) {
    ob2 = next_inventory(ob);
    tell_room(environment(),ob->query_name() + " falls from the sky!\n");
    move_object(ob,environment());
    ob = ob2;
  }
  destruct(TO);
  return 1;
        }


/* lets invited player move onto cloud */
climbup()  {
  if (!climb_mode) return;
  if (TP != climb_ob) {
    write("The hand isn't extended towards you.\n");
    return 1;
  }
  tell_room(environment(),TP->query_name()+" reaches out and grasps the outstretched arm ...\n"+
      "And is instantly pulled up into the storm cloud!\n");
  write("You take ahold of the hand, which pulls you into the storm cloud.\n");
  move_object(TP, TO);
  tell_room(TO, capitalize(MASTER_NAME) + " pulls "+TP->query_name()+" onto the storm cloud.\n");
  climb_mode = 0;
  write("To get back down again, type 'climbdown'.\n");
  return 1;
        }


/* emotes */
rain()  {

  if (TP->query_real_name() != MASTER_NAME) return;

   tell_room(environment(),"Suddenly the room grows very dark as the storm cloud lets loose with\n"+
                           "a fierce rain.\n");
   write("Ok.\nYou gesture and the storm cloud begins to rain.\n");
   tell_room(TO, TP->query_name() + " raises a hand.\n"+
                                    "The storm cloud lets loose a fierce rain.\n");
  return 1;
        }


/* emotes */
thunder()  {
  if (TP->query_real_name() != MASTER_NAME) return;
  write("Ok.\nYou call forth a clap of thunder from the the storm cloud.\n");
  tell_room(environment(),"A large thunderbolt deafens you.\n");
  tell_room(TO,"The cloud splits the silence with a booming thunderbolt.\n");
  return 1;
        }


/* lets player look at what is below */
lookdown()  {
  environment()->long();
  ob = first_inventory(environment());
  while (ob) {
    write(ob->short() + ".\n");
    ob = next_inventory(ob);
        }
  return 1;
        }


/* give message to those in room */
speak(str)  {
  write("You shout down from the storm cloud: "+str+"\n");
  tell_room(TO, TP->query_name()+" shouts down, '"+str+"'\n");
  tell_room(environment(TO),"A voice booms down from overhead, '"+str+"'\n");
  return 1;
        }


/* get off of cloud */
climbdown()  {
  if (TP->query_real_name() == MASTER_NAME) return;
  write("You close your eyes and leap off the cloud.\n");
  tell_room(TO, TP->query_name() + " takes a flying leap off the cloud.\n");
  move_object(TP, environment());
  say(TP->query_name() + " jumps from the storm cloud and drops towards the ground.\n"+
      TP->query_name()+" lands gracefully.\n");
  write("You land gracefully.\n");
  return 1;
        }


move_player(str)  {
  sscanf(str,"%s#%s",where,str2);
  tell_room(TO,"The storm cloud drifts " + where + ".\n");
  tell_room(environment(TO),"The storm cloud drifts "+where+".\n");
  move_object(TO,str2);
  tell_room(environment(TO),"The storm cloud drifts "+where+".\n");
        }


query_save_flag() { return 1;     }
is_pet()          { return 1;     }
