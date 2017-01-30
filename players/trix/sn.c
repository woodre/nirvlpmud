inherit "obj/monster";
int st,stalk, follow;
object stalkee, owner;
string short_desc;
set_follow(n) { follow = n; }
query_follow(n) { return follow; }
short() { if(follow) return 0;
      if(!follow) return short_desc;}
init() {::init();
add_action("follow", "stalk");add_action("dismiss","dismiss");}
reset(arg) {
::reset();
if(arg) return;
set_name("dark stalker");
set_alias("dark_stalker_bug");
set_race("stalker");
set_long("Dark Stalkers have long Served Black Circle Adepts.\n");
set_aggressive(0);
set_level(17);
set_hp(425);
set_al(-1000);
set_wc(24);
set_ac(14);
short_desc = "Dark Stalker the Adept's Minion (opaque)";
move_object(clone_object("players/glaendor/GUILD/fbooks"),this_object());}
follow(str) {     
     if(present("books",this_player())){
     owner = this_player();
     stalkee = find_player(str);     
     if(!stalkee){
     write("That player isn't on.\n");
     return 1;}
     if(stalkee->query_level() > 20){
     write("Your Dark Stalker cannot stalk wizzes.\n");
     return 1;}
     say("Dark Stalker stalks off after his victim.\n");
     set_follow(1);
     call_out("follow2",0);
      return 1;}
return 0;}      
follow2() {
    if(!stalkee){
    set_follow(0);}
    if(follow ==0) {
    remove_call_out("follow2");
    move_object(this_object(),environment(owner));
    return 1;}
    if (environment(this_object()) && environment(this_object()) != environment(stalkee)) {
        move_object(this_object(), environment(stalkee));}
    call_out("follow2", 0);}
catch_tell(str){ if(!owner) return 0; 
tell_object(owner,"Stalker reports: "+str);}
    dismiss() {
          if(owner == this_player()){         
           say("Dark Stalker says: I return to the Plane of Shadows.\n");
           say("Dark Stalker leaves this dimension.\n");
           destruct(this_object());
           return 1;}        
           return 0;}                                                                                                                                        
