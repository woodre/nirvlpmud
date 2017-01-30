#define LOGPATH "/players/languilen/log/"
#define TP this_player()
#define TPN TP->query_real_name()
inherit "/obj/monster";

  string log_file;
  string owner_name;
  object follow;
  int snooping;
  int invis,abrief;
  int muffled;
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("An astral body");
  set_alt_name("projection");
  set_long(
"    An etherial whisp in the form of "+owner_name+".\n");
  set_gender("male");
  set_race("spirit");
  set_level(3);
  set_wc(1);
  set_ac(3);
  set_hp(60);
  snooping=0;
  abrief=0;
  set_al(0);
  set_heal(5,2);
  set_aggressive(0); 
  enable_commands();
}

catch_tell(str) {
  out_put("~"+str);
}

set_snooping() {
  snooping=!snooping;
  write("The projection says: "+(snooping?"on":"off")+"\n");
}
heart_beat() {
  ::heart_beat();
  if(!find_player(owner_name)) destruct(this_object());
}

set_brief(){
     abrief=!abrief;
}

go_invis() {
  invis=!invis;
}

set_owner(str){
     owner_name=str;
}

short() {
  if(invis) return 0;
  if(owner_name) return owner_name+"'s astral body";
  else return 0;
}
query_invis() {
  return invis;
}
init() {
  add_action("snoop");add_xverb("");
}
snoop(str) {
  if(snooping) {
    out_put("~"+TPN+"~"+str+"\n");
  }
}
set_follow(ob) {
  remove_call_out("follow");
  if(!ob) return;
  follow=ob;
  call_out("follow",1);
}
follow() {
  if(follow && !present(follow,environment())) {
    move_object(this_object(),environment(follow));
    ast_look();
  }
  remove_call_out("follow");
  call_out("follow",3);
}

set_muffle(int x) {
  muffled=!muffled;
  write("You "+(muffled?"ignore":"listen to")+" the Projection.\n");
}
set_file(str) {
  if(!str) log_file=0;
  else log_file=str;
}
ast_look(){
     object ob;
     out_put("~"+environment()->short()+"\n");
     if(!abrief){
        out_put("~"+environment()->long()+"\n");
     }
     ob = first_inventory(environment());
     while(ob) {
          if (ob != this_object()) {
              string short_str;
              short_str = call_other(ob, "short");
              if (short_str){
                  out_put(short_str + ".\n");
              }
          }
     ob = next_inventory(ob);
     }
     return 1;
}

out_put(str) {
  if(log_file) {
    write_file(LOGPATH+log_file,str);
  }
  if(!muffled) {
    tell_object(find_player(owner_name),str);
  }
}
