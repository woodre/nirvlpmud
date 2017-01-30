/*********************************************/
/* rmaster.c: room master                    */
/* this file should never be updated         */
/*********************************************/
#define VER "0.1"
#define ROOT "/players/wizardchild/congo/"
#define ROOMS "/players/wizardchild/congo/rooms/"
#define log_error(s) write_file("/players/wizardchild/congo/RMASTER.ERROR",\
                     "["+ctime(time())+"] "+s)
 
object *rooms;
int *nums;
int num_rooms;
int num_with_exits;
int num_exits;
int total;
status reboot_flag;
 
query_version() { return "Version "+VER; }
remove_room(num) {
  num_rooms--;
  num_with_exits--;
  nums -= ({num}); /* we can do this, since num is unique */
}
short() {
  return "Room Master ["+query_version()+"]"; 
}
id(str) { return str == "master" || str == "room master" || str == "room"; }
long()  {
  write(short()+"\n");
  write("It is responsible for all the rooms in the Congo.\n");
  write(total+" rooms found at load time.\n");
  write("As of now, "+num_rooms+" have been created with "+num_exits+" exits.\n");
  write("Of the rooms created, "+num_with_exits+" have been entered.\n");
  write("Percentage of castle loaded: "+(num_rooms*100/total)+"%.\n");
  if(this_player()->query_level() > 30) {
    write("Type \"mass_update\" to update the entire castle.\n");
    write("Type \"which_up\" for a list of active rooms.\n");
    write("Type \"room <num>\" to go to a room.\n");
    write("Type \"load <num>\" to load a room without entering it.\n");
  }
  write("This product brought to you by Wizardchild Productions (Woo).\n");
}
init() {
  if(this_player()->query_level() > 30) {
    add_action("mass_update","mass_update");
    add_action("which_up","which_up");
    add_action("room", "room");
    add_action("load", "load");
  }
}
mass_update() {
  if(reboot_flag) {
    write("A castle reboot is already in progress.\n");
    return 1;
  }
  if(this_player() != find_player("wizardchild") && find_player("wizardchild"))
    tell_object(find_player("wizardchild"),"[ Congo reboot started ]\n");
  say("Castle evaluation sequence initiated!\n");
  write("There will be a 1 minute evacuation delay. After that, the castle\n"
       +"will reboot completely.\n");
  log_error(" - CASTLE UPDATE - called by "+this_player()->query_real_name()+"\n");
  chan_castle("Castle update initiated. Evacuation commencing.\n"
  +"  If you do not leave the castle in 1 minute, you will be moved to the\n"
  +"  church. This is 1 minute real time.");
  call_out("update_castle", 60);  
  reboot_flag = 1;
  return 1;
}
update_castle() {
  int i,so;
  if(!reboot_flag) return ;
  chan_castle("Rebooting castle...");
  so = sizeof(rooms);
  for(i = 0; i < num_rooms; i++) {
    if(rooms[i] && rooms[i] != 0)
      rooms[i]->wizard_reset();
  }
  say(" [ Congo ] Castle reboot completed. Removing driver...\n");
  destruct(this_object()); /* either this or manually 0 */
}
which_up() {
  int i,so;
  write(total+" rooms found, "+num_rooms+" rooms loaded.\n");
  for(i = 0,so=sizeof(rooms); i < total && i < so; i++) {
    if(rooms[i] && rooms[i] != 0) 
      write(cushion(rooms[i]->query_num())+"\t");
  }
  write("\nDone.\n");
  return 1;
}
room(str) {
  int i,so,n;
  if(!str || !sscanf(str, "%d", n)) {
    write("Usage: room <n> where <n> is a valid room number.\n");
    return 1;
  }
  if(n < 0 || n > total) { 
    write("That is not a valid choice.\n"); 
    return 1; 
  }
  if(!has_num(rooms,n)) {
    write("Room not loaded. Loading now.\n");
    create_room(n);
  }
  for(i=0,so=sizeof(rooms);i<so;i++) {
    if(rooms[i]->query_num() == n)
      break;
  }
  if(i==so) { 
    write("Error! Array reached without finding room.\n");
    return 1;
  }
  this_player()->move_player("into the congo#"+file_name(rooms[i]));
  return 1;
}
load(str) {
  int i;
  if(!str || !sscanf(str,"%d",i)) {
    write("Usage: load <num> where <num> is a valid number.\n");
    return 1;
  }
  if(i < 0 || i > total) {
    write("That is not a valid number.\n");
    return 1;
  }
  if(has_num(rooms,i)) 
    write("Room already loaded.\n");
  else {
    create_room(i);
    write("Room created.\n");
  }
  return 1;
}
chan_castle(str) {  
  object ob; int i,so;
  string s;
  s = "/players/wizardchild/congo/croom"->query_version();
  for(ob = users(), so = sizeof(ob), i = 0; i < so; i++) {
    if(!environment(ob[i])) continue;
    if(file_name(environment(ob[i])) == s)
      tell_object(ob[i], " [ Congo ] "+s+"\n");
  }
}
cushion(x) {
  string out;
  if(x < 10)
    out = "00"+x;
  else if(x < 100)
    out = "0"+x;
  else
    out = "0\b"+x;
  return out;
}
reset(arg) {
  if(arg) return 0;
  /* load first room, room000.c */
  /* 000 has a special exit to the outside world */
  rooms = ({create_room(0)});
  total_rooms();
}
/* this is a lag generator, and should only be run at load time */
total_rooms() {
  int i;
  string f;
  f = ROOMS+"room";
  for(i = 0; i < 999; i++) {
    if(file_size(f+cushion(i)) < 0)
      break;
  }
  total = i;
}
/* takes room number as arg, returns type object (room) */
create_room(num) {
  string fn, file,sh,ln,xtra,foo;
  string *actions;
  object ob;
  int i,so;
  if(num < 0) return ;
  fn = ROOMS+"room"+cushion(num);
  if(file_size(fn) < 1) {
    log_error("Unknown file: "+fn+"\n");
    return ;
  }
  file = read_file(fn);
  sscanf(file, "%s\n**\n%s", sh, ln);
  if(sscanf(ln, "%s\n**\n%s", foo, xtra) == 2)
    ln = foo;
  ob = clone_object(ROOT+"croom");
  ob->set_short(sh);
  ob->set_long(ln);
  ob->set_num(num);
  if(xtra) {
    if(sscanf(xtra,"%sNOOBJ%s",sh,ln)) { ob->set_no_objects(); xtra=sh; }
    while(sscanf(xtra, "%s\n", foo)) xtra = foo; /* handle xtra newlines */
    ob->set_xcmdf(xtra);
  }
  if(!random(3))
    ob->set_realm(1);
  ob->delayed_reset();
  if(!sizeof(rooms)) rooms = ({ob});
  else rooms += ({ob});
  num_rooms++;
  if(!sizeof(nums)) nums = ({num});
  else nums += ({num});
  return ob;
}
/* this is where exits are setup */
init_setup(ob) {
  int i,x,n,z,so,t,a;
  object *exits;
  string *dirs,*dout;
  status *done;
  dirs = ({"north","east","south","west","up","down","northwest","northeast",
           "southwest","southeast"});
  x = random(9)+2;        
  a = ob->query_num();
  if(x > total-1) x = total-1;
  for(i = 0; i < x; i++) {  
    if(total == 1) return ;
    while((n = random(total)) == a || (sizeof(exits) && 
    has_num(nums,n) != -1 && member_array(get_room(n),exits) == 0)) ;
    /* since i really don't want to allocate room for 200 objects, we have to
       sort through stuff, and find the ob with this number */
    if((z = has_num(nums, n)) != -1) {
      so = sizeof(rooms);
      for(t = 0; t < so; t++) {
        if(nums[z] == rooms[t]->query_num())
          break;
      }
      if(t != so) {
        if(!sizeof(exits)) exits = ({rooms[t]});
        else exits += ({rooms[t]});
      }
    } else {
      if(!sizeof(exits)) exits = ({create_room(n)});
      else exits += ({create_room(n)});
    }
  }
  done = allocate(10);
  for(i = 0; i < x; i++) {
    t = random(10);
    /* this should eventually bring up one that hasn't been used */
    while(done[t]) t = random(10);
    done[t] = 1; 
    if(!sizeof(dout)) dout = ({dirs[t]});
    else dout += ({dirs[t]});
  }
  if(sizeof(dout) != sizeof(exits))
    log_error("Unmatched dout/exits sizes: dout - "+sizeof(dout)+", exits - "+sizeof(exits)+"\n");
  ob->set_erooms(exits);
  ob->set_exits(dout);
  num_exits += x;
  num_with_exits++;
}
has_num(arr,num) {
  int i, so;
  for(i=0,so=sizeof(arr); i < so; i++) {
    if(arr[i] == num)
      return i;
  }
  return -1;
}
get_room(n) {
  int i,so;
  for(i=0,so=sizeof(rooms);i<so;i++) {
    if(rooms[i]->query_num() == n)
      return rooms[i];
  } 
  return ;
}
