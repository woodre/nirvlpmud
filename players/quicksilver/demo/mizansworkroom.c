int i;
id(str) { return str == "workroom"; }
short() { return "Plane of Etheriel [infinite exits]"; }
long() {
  write("\tYou are drifting in a ever-changing environment of pure color\n"+
"  and sounds. Typically, no naturally occuring laws of natural physics\n"+
"  apply here. Entropy is an sharp understatement.\n"+
  "There are infinite obvious exits.\n");
if(i) write("A protective aura prevents entry.\n");
}

reset() { 
  write("Everything fades into a swirling eddy.\n");
  return 1;
}

query_light() { return 1; }
init() {
  object od;
  od=find_player("mizan");
 /*
    if(!od) {
      write("You are not allowed here when Mizan is not logged in.\n");
      write_file("/players/mizan/logs/ENTRY", (this_player()->query_name())+
    " tried to enter main workroom at "+ctime()+".\n");
      move_object(this_player(), "room/church");
      return 1;
    }
 */
    tell_object(od, (this_player()->query_real_name())+", level "+
    (this_player()->query_level())+ " fades into view.\n");
  add_action("church","church");
  add_action("bleat","bleat");
  add_action("shop","shop");
  add_action("adven","adven");
  add_action("group","group");
  add_action("rresetrm","resetroom");
  add_action("ether","ether");
  add_action("lock","lock");
  add_action("trans","trans");
 /*
  checkstate();
 */
}

group() {
  this_player()->move_player("X#players/blue/group/share/forum");
  return 1;
}
rresetrm() {
  this_player()->move_player("reboot room#players/mizan/closed/RandomRoomDM.c");
  return 1;
}
checkstate() {
  object ob;
  ob=first_inventory(this_object());
while(ob) {
  object oc;
  oc=ob;
  ob=next_inventory(ob);
    if(!oc->short()) {
  tell_room(this_object(), "Illegal invisible object of origin: "+creator(oc)+" destructed.\n"+
  "Filename: [" + file_name(oc) +"]\n");
      destruct(oc);
      return 1;
    }
  }
return 1;
}

bleat(str) {
  call_other("/players/mizan/closed/LiquidRoomDM.c", "area_tell", str);
  return 1;
}

church() {
  this_player()->move_player("church#room/church");
  return 1; }
shop() {
  this_player()->move_player("shop#room/shop");
  return 1; }
ether(str) { 
  this_player()->move_player("to the Plane of Etheriel#players/mizan/etheriel/ROOMS/"+str);
  return 1; }
adven() {
  this_player()->move_player("to the adventurers guild#room/adv_guild");
  return 1; }
trans(arg) {
  object ob;
  ob=find_player(arg);
  if(!ob) return 0;
  tell_room(environment(ob), (ob->query_name())+" fades from view.\n");
  move_object(ob, this_object());
  tell_object(ob, "Blinking and looking about, you arrive elsewhere.\n");
  write("Ok.\n");
  return 1;
}

lock() {
  if(i) {
    say("The aura fades away.\n");
    i=0;
    return 1; 
  } else {
  say("An inherently indestructable aura of ether-muck suddenly encapsulates the area.\n");
  call_out("checkstate", 2);
  i=1;
  return 1;
  }
}
