string race;

reset(arg){
   if (arg) return;
}


init(){
    add_action("racechange","racechange");
 }


racechange() {
this_player()->set_race("sexpot");
    return 1; }


id(str) { return (str == "racechanger"); }
