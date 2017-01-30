#define TP this_player()
#define TPN capitalize(TP->query_name())
inherit "room/room";
 
reset(arg){
 
 if(!arg){
 
 set_light(1);
  short_desc="ShadowGate";
 long_desc=
 "The ShadowGate looms before you. Unheard screams echo in your ears, your heart\n"+
 "pounds in irrational fear. You have heard of the bewildering, insubstantial \n"+
 "reality that is the Plane of Shadow... this is your chance to confront your\n"+
 "darkest nightmares and test your mettle as an adventurer. All you have to do is\n"+
 "enter the Shadowgate.\n";
 
items=({
 "gate", "Faded blackness defines the ShadowGate. Darkness you will confront, \n"+
         "so be prepared.",
 "shadowgate","Faded blackness defines the ShadowGate.\n"+
              "...Darkness you will confront, so be prepared.",
});
 
  dest_dir=({
  "/players/snow/gate.c","vortex"});
  }   }
 
init() {
  ::init();
add_action("enter_gate","enter");
}
 
enter_gate(arg) {
  if(!arg) { write("Enter what?\n"); return 1; }
  if(!(arg == "gate" || arg == "shadowgate" || arg == "ShadowGate")) {
    write("Enter the ShadowGate...\n");
    return 1;
  }
  if(TP->query_level() < 10) {
    write("You freeze in fear as you try to enter the Shadowgate!\n");
  return 1;
  }
else
  say(TPN+" enters the ShadowGate and fades away...\n");
  write("You step boldy into the ShadowGate!\n"+"\n"+
        "Images flicker before your eyes... darkness overtakes you.\n");
  tell_object(TP,"\n"+"You awake and look around...\n");
  move_object(TP,"/players/snow/shadows/hilltop.c");
  write_file("/players/snow/log/shadow",ctime(time())+" "+
        TP->query_real_name()+" entered the Shadow Realm.\n");
return 1;
}
