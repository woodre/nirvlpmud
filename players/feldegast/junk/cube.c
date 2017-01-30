#define DUST "players/mizan/etheriel/environs/dustpile"
#define SURGE "players/mizan/etheriel/environs/exploder.c"

int invis_tl;

id(str) { 
  if(invis_tl) { return 0;
  } else return str == "cube";
}

short() {
  if(invis_tl) {
    return 0;
  } else return "The Borg cube";
}

long() {
  write("Faintly visible because it is cloaked in a strange, blurring\n"+
  "kind of light, the cube must be somewhat far away, because it's every\n"+
  "movement creates a heck of a current surge, and takes a bit of time\n"+
  "in reaching you. A strange, ominous and terrifying emotion rockets up\n"+
  "your spine as you stare at the cube. It seems to be fear, in it's purest\n"+
  "and most frightening form.\n");
}

reset(arg) {
  string testog;
  testog=call_other("players/mizan/closed/RandomRoomDM.c","one_random");
  move_object(this_object(), "/players/mizan/etheriel/ROOMS/" + testog);
  if(arg) return;
  call_out("fake_heart_beat", 1);
}

init() {
  add_action("enter_cube","enter");
  add_action("envir_cube","ec");
}

query_where_the_heck() {
  return(file_name(environment(this_object())));
}
envir_cube() {
     if(environment(this_object()))
    return 0;
   move_object(this_player(), environment(this_object()));
  return 1;
}
enter_cube(str) {
  if(str) if(str == "cube") {
  write("Are you nuts??? You don't have the kind of weaponry or allies\n"+
        "to survive for in it more than ten seconds! Bah!\n");
  return 1;
}
}

fake_heart_beat() {
  object room;
  int i;
  room=environment(this_object());
  if(!room) return 1;
    i=random(20);
  if(i==1 && !invis_tl) {
    object ob;
    ob=first_inventory(room);
    if(ob && living(ob)) {
      if(ob->query_level() > 15 && 1==random(2) && ob->query_real_name() != "mizan") {
        tell_room(room, "A plasma discharge erupts from the Borg cube.\n");
        tell_room(room, (ob->query_name()) + " is blown to bits.\n");
        tell_object(ob, "You get a tingly feeling as a pulsewave from the Borg cube zaps you to bits.\n");
  write_file("/players/mizan/logs/BORG-ZAP", (ob->query_name()) + " got zokked at " + ctime() + ".\n");
        ob->destruct_inventory();
        destruct(ob);
        move_object(clone_object(DUST), room);
      } else {
        tell_room(room, (ob->query_name()) + " is analyzed by the Borg cube.\n");
        tell_object(ob, "You feel as your mind was emptied and your every move was being watched.\n");
      }
    }
  }
  if(i==2 && !invis_tl) {
    tell_room(room, "The Borg cube drifts by at a steady pace and vector.\n");
  }
  if(i==3 && !invis_tl) {
    tell_room(room, "You feel as if everything you do is being watched.\n");
  }
  if(i==4 && !invis_tl) {
    object ob2;
    tell_room(room, "The Borg cube accelerates hard, then suddenly stops.\n");
    ob=clone_object(SURGE);
    move_object(ob, this_object());
    ob->init();
  }
  if(i==5 && !invis_tl) {
    tell_room(room, "The Borg cube fades from view.\n");
    call_out("visible", random(50));
    invis_tl=1;
  }
  if(i=9 && 1==random(5)) {
    string mover;
    mover=call_other("players/mizan/closed/RandomRoomDM.c", "one_random");
    this_object()->move_me(mover);
  }
  if(test_if_any_here()) call_out("fake_heart_beat", 5);
}

static visible() {
  object room;
  room=environment(this_object());
  tell_room(room, "The Borg cube fades into view.\n");
  invis_tl=0;
  return 1;
}

static move_me(str) {
  object room;
  room=environment(this_object());
  if(!room) return 1;
  if(!str) return 0;
  if(!invis_tl) {
  tell_room(room, "The Borg cube drifts " + str + ".\n");
  }
  move_object(this_object(), "/players/mizan/etheriel/ROOMS/" + str);
  if(!invis_tl) {
    tell_room("/players/mizan/etheriel/ROOMS/" + str, "The Borg cube drifts into view.\n");
  }
  return 1;
}

test_if_any_here() {
  object ob;
  ob = environment();
  if(!ob) return;
  ob = first_inventory(environment());
  while(ob) {
    if(ob != this_object() && living(ob) && !call_other(ob, "query_npc")) return 1;
    ob = next_inventory(ob);
  }
  return 0;
}

