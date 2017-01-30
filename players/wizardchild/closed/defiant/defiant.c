#define OK_SEE(o) (o->query_real_name() == "wizardchild" ||\
                   o->query_level() >= cloak ||\
                   environment(o) == this_object())
#define IS_WIZ(o) (o->query_real_name() == "wizardchild")
#define CP(s)     capitalize(s)
#define ME        this_player()
#define ROOT      "/players/wizardchild/closed/defiant/"

int cloak;
status ok_enter, hover, weapons, no_rescue;
object croom;
int allow_cmd;
status viewer, eview;
status listen;
object view_ob;
short() {
  if(!OK_SEE(ME)) return 0;
  return "The USS Defiant ("+(hover?"hovering":"landed")+")";
}
id(str) {
  if(!OK_SEE(ME) || environment(ME) == this_object())  
    return 0;
  return str == "defiant";
}
reset(arg) {
  object ob;
  if(arg) return ;
  ok_enter = 0;
  hover = 0;
  cloak = 0;
  weapons = 0;
  allow_cmd = 60;
  call_out("fake_hb", 3);
  ob = clone_object(ROOT+"mon.c");
  move_object(ob, this_object());
  enable_commands();
  set_light(1);
}
long()  {
  if(!OK_SEE(ME)) return 0;
  if(environment(ME) == this_object()) {
    write("You are standing on the bridge of the USS Defiant.\n");
    write("This ship appears to be maintained by very few people - in fact, it is\n");
    write("mostly run by its owner, Wizardchild.\n");
    if(ME->query_level() >= allow_cmd || IS_WIZ(ME)) {
      if(!IS_WIZ(ME))
        write("You are allowed to execute minimal commands on this ship.\n");
      write("Type \"defiant_cmd\" for information on what commands you can use.\n");
      write("In the front of the bridge sits the viewer. It is currently "+(viewer?"on":"off")+".\n");
      write("To your right is the helm. Our current room is "+(croom?file_name(croom):"nowhere")+".\n");
      write("We are currently "+(hover?"hovering above":"landend in")+" this room.\n");
      write("To your left is tactical. Cloak is at "+cloak+", weapons are "+(weapons?"enabled":"disabled")+".\n");
    }
    if(IS_WIZ(ME))
      write("Entry is"+(ok_enter?" ":" not")+" allowed.\n");
  } else {
    write("A sleek looking United Federation of Planets warship. This ship is obviously\n");
    write("the fastest, and best equipped, ship in the galaxy.\n");
    if(IS_WIZ(ME))
      write("Type \"board\" to board her.\n");
  }
  return 1;
}
ship_comm(str,who) {
  object ob;
  if(!who) who = "[Computer]";
  ob = first_inventory(this_object());
  while(ob) {
    if(living(ob) && (IS_WIZ(ob) || ob->query_level() >= allow_cmd))
      tell_object(ob, who+": "+str);
    ob = next_inventory(ob);
  }
  return 1;
}
checked_say(str) {
  object ob;
  if(!environment(this_object())) return 1;
  ob = first_inventory(environment(this_object()));
  while(ob) {
    if(living(ob) && OK_SEE(ob))
      tell_object(ob, str);
    ob = next_inventory(ob);
  }
  return 1;
}
remote_say(str, env) {
  object ob;
  ob = first_inventory(env);
  while(ob) { 
    if(living(ob)) tell_object(ob, "[Defiant]: "+str);
    ob = next_inventory(ob);
  }
  return 1;
}
fake_hb() {
  object w;
  remove_call_out("fake_hb");
  if(environment(this_object()) != croom) 
    ship_comm("Move recorded to "+environment(this_object())->short()+".\n");
  croom = environment(this_object());
if(find_call_out("auto_rescue") == -1 && no_rescue == 0) {
  if(!present("wizardchild", this_object()) && find_player("wizardchild")) {
    w = find_player("wizardchild");
    tell_object(w, "[Defiant] You have abandoned ship. 15 seconds to auto-rescue.\n");
    tell_object(w, "[Defiant] Type \"no_rescue\" to abort.\n");
    call_out("auto_rescue", 15);
  }
}
  call_out("fake_hb",3);
  if(!find_player("wizardchild")) update_self();
}
set_no_rescue() { no_rescue = 1; }
auto_rescue() {
  string s;
  if(no_rescue) return 0;
  if(!find_player("wizardchild")) update_self();
  tell_object(find_player("wizardchild"), "You are brought back to the defiant.\n");
  s = file_name(this_object());
  find_player("wizardchild")->move_player("X#"+s);
  return 1;
}
/* auto-removal - the smaller modules are just that, small */
update_self() {
  object ob;
  ob = first_inventory(this_object());
  while(ob) {
    if(living(ob)) {
      tell_object(ob, "Wizardchild has left, Defiant self-destructing.\n");
      ob->move_player("church#room/church");
    } else
      destruct(ob);
    ob = first_inventory(this_object());
  }
  destruct(ROOT+"defiant");
  destruct(this_object());
}
init() {
  if(this_player()==find_player("wizardchild") && find_player("wizardchild"))
  no_rescue = 0;
  if(!find_player("wizardchild"))
    update_self();
  if(environment() && environment(environment())) {
    move_object(this_object(), environment(environment(this_object())));
    return 1; /* avoid add_action errors */
  }
  if(environment(ME) == this_object()) {
    if(!ok_enter && !IS_WIZ(ME)) {
      write("You are not allowed to enter this area.\n");
      ME->move_player("elsewhere#room/church");
      ship_comm("Intruder: "+CP(ME->query_real_name())+". Removed.\n");
      return 1;
    }
    if(IS_WIZ(ME) || ME->query_level() >= allow_cmd) {
      ship_comm(CP(ME->query_real_name())+" has boarded the ship.\n");
      add_action("defiant_cmd", "defiant_cmd");
      add_action("screen", "screen");
      add_action("onscreen", "onscreen");
      add_action("enhances", "enhances");
        add_action("listen", "listen");
        add_action("osay", "osay");
      if(IS_WIZ(ME)) {
        add_action("launch",    "launch");
        add_action("land",      "land");
        add_action("cloak",     "cloak");
        add_action("decloak",   "decloak");
        add_action("impulse",   "impulse");
        add_action("warp",      "warp");
        add_action("weap",      "weap");
        add_action("photon",    "photon");
        add_action("phaser",    "phaser");
        add_action("scan",      "scan");
        add_action("rscan",     "rscan");
        add_action("beam",      "beam");
        add_action("tbeam",     "tbeam");
        add_action("beamoff",   "beamoff");
        add_action("hail",      "hail");
        add_action("set_enter", "set_enter");
        add_action("set_allow", "set_allow");
        if(!present("defiant_comm", ME))
          move_object(clone_object(ROOT+"comm"), ME);
      }
    }
  } else if(IS_WIZ(ME) && !hover) 
    add_action("board", "board");
}
defiant_cmd() {
  write("Commands:\n");
  write("screen [on/view]    Turn on the main viewer, or view the screen.\n");
  write("onscreen <room/who> Put something in particular on screen.\n");
  write("enhances            Enhance the viewer to detail mode.\n");
  if(IS_WIZ(ME)) {
    write("launch              Launch the ship.\n");
    write("land                Land in the current environment.\n");
    write("cloak [num]         Enable ship cloaking.\n");
    write("decloak             Disable ship cloaking.\n");
    write("impulse <dir>       Move [allows speedster].\n");
    write("warp <who/room>     Move [direct].\n");
    write("weap [on/off]       Toggle tactical abilities.\n");
    write("photon <who>        Vaporize someone with a photon torpedo.\n");
    write("phaser [who] <what> Vaporize something with a phaser blast.\n");
    write("scan <what>         Scan something (continuous).\n");
    write("rscan <what>        Remove a scan.\n");
    write("beam [where]        Beam down to the surface, or to another place.\n");
    write("tbeam <who>         Place someone in a tractor beam.\n");
    write("beamoff <who>       Remove a tractor beam.\n");
    write("hail <who>          Hail a player.\n");
    write("wizardchild to <w>  Hail a player.\n");
    write("set_enter [on/off]  Enable/disable ok_enter.\n");
    write("set_allow [lev]     Adjust allow_cmd num.\n");
    write("listen [on/off]     Toggle outside hearing.\n");
    write("osay <str>          Say something outside.\n");
  }
  return 1;
}
screen(str) {
  object ob;
  if(!str || str == "view") {
    if(!viewer) {
      write("You must turn on the viewer first.\n");
      return 1;
    }
    if(!view_ob) view_ob = croom;
    if(eview) write("[-> Extended viewer enabled <-]\n");
    write("Looking at the viewer, you see the following:\n");
    if(eview) write("["+file_name(view_ob)+"]\n");
    write("["+view_ob->short()+"]\n");
    view_ob->long();
    write("[-Contents-]\n");
    ob = first_inventory(view_ob);
    while(ob) {
      if(ob && ob != this_object()) {
        if(eview) write("  ["+file_name(ob)+"]\n");
        write("   <"+ob->short()+">\n");
      }
      ob = next_inventory(ob);
    }
  } else {
    viewer = (str == "on"?1:0);
    write("The external viewer is now "+(viewer?"on":"off")+".\n");
  }
  return 1;
}
onscreen(str) {
  object ob;
  if(!str) {
    write("Usage: onscreen <someone/someroom>\n");
    return 1;
  }
  if(str[0] == 'E') {
    sscanf(str, "E%s", str);
    ob = find_player(str);
    if(ob) ob = environment(ob);
  } 
  if(!ob)
    ob = find_player(str);
  if(!ob) {
    if(str[0] != '/') str = "/players/wizardchild/"+str;
    if(str[(strlen(str)-2)] != '.') str += ".c";
    if(file_size(str) > 0) {
      call_other(str, "??");
      ob = find_object(str);
    }
  } 
  if(!ob) {
    write("Object not found.\n");
    return 1;
  }
  view_ob = ob;    
  ship_comm("The viewer has been set to "+file_name(view_ob)+".\n");
  write("Ok.\n");
  return 1;
}
enhances() {
  eview = !eview;
  write("Enhanced view is now "+(eview?"on":"off")+".\n");
  return 1;
}
launch() {
  if(hover) {
    write("We are already airborn.\n");
    return 1;
  }
  hover = 1;
  ship_comm("Defiant launching. All systems normal.\n");
  checked_say("The Defiant launches, creating a swirl of dust.\n");
  return 1;
}
land()  {
  if(!hover) {
    write("We are already on the ground.\n");
    return 1;
  }
  hover = 0;
  ship_comm("Defiant landing. All systems normal.\n");
  write("Ok.\n");
  checked_say("The Defiant lands, sinking into the ground.\n");
  return 1;
}
cloak(str) {
  int i;
  if(!str || !sscanf(str, "%d", i)) {
    write("We are currently at cloak "+cloak+".\n");
    return 1;
  }
  cloak = (i<0?0:i);
  ship_comm("Cloaking device enabled to level "+cloak+".\n");
  write("Ok.\n");
  checked_say("The Defiant wavers slightly.\n");
  return 1;
}
decloak() {
  if(!cloak) {
    write("We are not currently cloaked.\n");
    return 1;
  }
  cloak = 0;
  ship_comm("Cloaking device disabled.\n");
  write("Ok.\n");
  checked_say("The Defiant appears.\n");
  return 1;
}
impulse(str) {
  object lead; /* frown, frown, frown */
  string tmp, tmp2;  
  if(!hover) {
    write("You must first take off.\n");
    return 1;
  }
  if(!str) {
    write("You must specify a destination.\n");
    return 1;
  }
  lead = clone_object(ROOT+"leadm");
  move_object(lead, environment(this_object()));
  tmp = str;
  while(sscanf(tmp, "%s,%s",tmp2, tmp)) 
    local_move(tmp2, lead);
  local_move(tmp, lead);
  destruct(lead);
  if(view_ob == croom) view_ob = environment(this_object());
  croom = environment(this_object());
  command("screen", ME);
  write("Done.\n");
  return 1;
}
local_move(s, lead) {
  command(s, lead);
  if(environment(lead) == environment(this_object())) 
    write("Invalid move.\n");
  else {
    checked_say("The Defiant flys off.\n");
    move_object(this_object(), environment(lead));
    checked_say("The Defiant flys in.\n");
    ship_comm("Ship has moved to "+file_name(environment(this_object()))+"\n");
  }
}
warp(str) {
  string end;
  object ob;
  if(!hover) {
    write("You must first take off.\n");
    return 1;
  }
  if(!str) {
    write("You must specify a room or a player/monster.\n");
    return 1;
  }
  if(ob=find_living(str)) {
    write("Moving to "+str+".\n");
    ship_comm("Ship going into Warp.\n");
    checked_say("The Defiant warps out of the room.\n");
    if(!ob->is_player() && !ob->query_npc()) 
     move_object(this_object(),ob);
     else
    move_object(this_object(), environment(ob));
    ship_comm("Ship has arrived in proximity of "+str+".\n");
    checked_say("The Defiant warps into the room.\n");
  } else {
    end = str;
    if(end[0] != '/') end = "/players/wizardchild/"+end;
    if(end[(strlen(end)-2)] != '.') end += ".c";
    if(file_size(end) < 1) {
      write("No such room.\n");
      return 1;
    }
    ship_comm("Ship going into Warp.\n");
    checked_say("The Defiant warps out of the room.\n");
    move_object(this_object(), end);
    ship_comm("Ship has arrived in "+end+"\n");
    checked_say("The Defiant warps into the room.\n");
  }
  if(view_ob==croom) view_ob=environment(this_object());
  croom = environment(this_object());
  return 1;
}
weap(str) {
  if(str == "on") 
    weapons = 1;
  if(str == "off")
    weapons = 0;
  write("Weapons systems now "+(weapons?"online":"offline")+".\n");
  return 1;
}
photon(str) {
  string fn,foo;
  object ob, ob2;
  if(!str) return 0;
  ob = find_living(str);
  if(!ob) {
    if(ob = present(str, environment(this_object()))) {
      ship_comm("Target: "+ob->short()+".\n");
    tell_room(ob, "You have been targeted by a torpedo from the USS Defiant.\n");
    checked_say("The Defiant warms up its torpedo banks.\n");
    ship_comm(" Preparing torpedos.\n");
    checked_say("The Defiant launches a photon torpedo at "+ob->short()+"\n");
    tell_room(ob,"The torpedo comes flaring towards your ship!\n"+
       "You take evasive action!\n");
    ship_comm(" Torpedo fired!\n");
    tell_room(environment(),"The Defiant launches a torpedo, flaring towards "+ob->short()+"!\n");
    move_object(ob,(environment(ob)->query_dest_dir())[1]);
    tell_room(environment(), ob->short()+" evacuates!\n");
    return 1;
  } else {
    write("Not found.\n");
    return 1;
  }
  }
  ship_comm("Warming up photon torpedo banks...Ready.\n");
  checked_say("The Defiant warms up its torpedo banks.\n");
  ship_comm("Photon torpedo launched at "+capitalize(str)+".\n");
  checked_say("The Defiant launches a photon torpedo.\n");
  ob2 = environment(ob);
  remote_say("The Defiant launches a photon torpedo directly at you!\n", 
             ob2);
  tell_object(ob, "You are hit by a photon torpedo.\n");
  ship_comm("Target hit.\n");
  destruct(ob);
  if(!(random(100)%3)) { /* muhahaha */
    ship_comm("Environment destroyed.\n");
    if(sscanf(str, "%s#%s", fn, foo) != 2) return 1;
    destruct(fn);
  }
  return 1;
}
phaser(str) {
  object ob, env;
  string who, what;
  if(!str) return 0;
  if(sscanf(str, "%s %s", who, what) != 2) {
    env = environment(this_object());
    what = str;
  } else {
    if(!find_player(who)) {
      write("Player not found.\n");
      return 1;
    }
    env = environment(find_player(who));
  }
  ob = present(what, env);
  if(!ob) {
    write("Object not found.\n");
    return 1;
  }
  ship_comm("Phaser banks at full power. Firing.\n");
  if(!who) 
    checked_say("The Defiant fires its phasers.\n");
  else {
    tell_object(env, "[Defiant]: The Defiant blasts you with a phaser blast. When you look, you\n");
    tell_object(env, "notice that something has been vaporized.\n");
  }
  destruct(ob);
  write("Ok.\n");
  return 1;
}
scan(str) {
  object scanner, ob;
  scanner = present("external scanner", this_object());
  if(!scanner) {
    write("Scanner not found.\n");
    return 1;
  }
  if(!str) {
    write("No object specified.\n");
    return 1;
  }
  ob = find_living(str);
  if(!ob) {
    write("Object not found.\n");
    return 1;
  }
  if(scanner->has_ob(ob)) {
    write("The scanner is already watching that object.\n");
    return 1;
  }
  if(scanner->add_ob(ob) == -1) 
    write("Error adding object to scan list.\n");
  else {
    ship_comm("Object "+ob->query_name()+" added to scan list.\n");
    write("Ok.\n");
  }
  return 1;
}
rscan(str) {
  object scanner,ob;
  scanner = present("external scanner", this_object());
  if(!scanner) {
    write("Scanner not present.\n");
    return 1;
  }
  if(!str) {
    write("No object specified.\n");
    return 1;
  }
  ob = find_living(str);
  if(!ob) {
    write("Object not found.\n");
    return 1;
  }
  if(!scanner->has_ob(ob)) {
    write("The scanner isn't watching that object.\n");
    return 1;
  }
  if(scanner->remove_ob(ob) == -1) 
    write("Error removing object from scan list.\n");
  else {
    ship_comm("Object "+ob->query_name()+" removed from scan list.\n");
    write("Ok.\n");
  }
  return 1;
}
beam(str) {
  if(!str || str == "surface") {
    beam_out("the surface", environment(this_object()));
  } else {
    if(find_player(str)) 
      beam_out(capitalize(str), environment(find_player(str)));
    else {
      if(str[0] != '/') str = "/players/wizardchild/"+str;
      if(str[(strlen(str)-2)] != '.') str += ".c";
      if(file_size(str) > 0) 
        beam_out(str, str);
      else 
        write("Destination unknown.\n");
    }
  }
  return 1;
}
beam_out(str, ob) {
  write("You beam down to "+str+".\n");
  checked_say(ME->query_name()+" beams down.\n");
  move_object(ME, ob);
  ship_comm(ME->query_name()+" beams down to "+str+".\n");
  command("look", ME);
  return 1;
}
tbeam(str) {
  object ob;
  if(!str) {
    write("You must specifiy a player.\n");
    return 1;
  }
  if(!find_player(str)) {
    write("Player not found.\n");
    return 1;
  }
  ship_comm("Activating tractor beam on "+str+".\n");
  checked_say("The Defiant activates a tractor beam on "+str+".\n");
  tell_object(find_player(str), "You have been immobilized by a tractor beam from the Defiant.\n");
  ob = clone_object(ROOT+"tbeam");
  move_object(ob, environment(find_player(str)));
  move_object(find_player(str), ob);
  return 1;
}
beamoff(str) {
  object ob, env;
  if(!str || !find_player(str)) {
    write("Player not found.\n");
    return 1;
  }
  env = environment(find_player(str));
  if(env) env = environment(env);
  if(env)
    ob = present("tractor_beam", env);
  else {
    write("They are not in a tractor beam.\n");
    return 1;
  }
  if(!ob) {
    write("They are not in a tractor beam.\n");
    return 1;
  }
  ship_comm("Tractor beam removed for "+capitalize(str)+".\n");
  tell_object(find_player(str), "The Defiant has removed its tractor beam.\n");
  move_object(find_player(str), env);
  destruct(ob);
  return 1;
}
hail(str) {
  return command("defiant to "+str, ME);
}
set_enter(str) {
  if(str == "on")
    ok_enter = 1;
  else if(str == "off")
    ok_enter = 0;
  write("Ok enter is now "+(ok_enter?"on":"off")+".\n");
  return 1;
}
set_allow(str)  {
  int x;
  if(str && sscanf(str, "%d", x))
    allow_cmd = (x < 0 ? 0 : x);
  write("Commands allowed for players level "+allow_cmd+" and above.\n");
  return 1;
}
board(str) {
  if(id(str)) {
    write("You board the Defiant.\n");
    ship_comm("Wizardchild boards the Defiant.\n");
    move_object(ME, this_object());
    checked_say("Wizardchild boards the Defiant.\n");
  }
  return 1;
}
listen(str) {
  if(str == "on") listen = 1;
  else if(str == "off") listen = 0;
  ship_comm("Listen is now "+(listen?"on":"off")+".\n");
  return 1;
}
osay(str) {
  if(!str) {
    write("Usage: osay <str>\n");
    return 1;
  }
  str = this_player()->query_name()+" says: "+str+"\n";
  ship_comm(str);
  if(environment(this_object()))
    tell_room(environment(this_object()), "[Defiant] "+str);
  return 1;
}
catch_tell(str) {
  string who, what;
  if(!sscanf(str, "%s %s", who, what)) who = str;
  who = lower_case(who); 
  if(find_living(who) && environment(find_living(who)) == this_object()) return 0;
  if(sscanf(str, "[Defiant] %s", what)) return 0;
  if(sscanf(str, "The Defiant %s", what)) return 0;
  ship_comm("[external]: "+str);
}
