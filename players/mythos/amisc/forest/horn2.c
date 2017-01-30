#define tp this_player()->query_name()
#define tg this_player()->query_gender()

inherit "obj/treasure";

reset(arg) {
  if(arg) return;

  set_id("horn");
  set_short("A beautiful horn");
  set_long("A horn off the head of a Kirin.\n\n"+
           "There seems to be something odd about this horn.\n"+
           "Perhaps if you 'tap'ped it on your 'weapon' something may happen.\n");
  set_weight(4);
  set_value(2000);
}


init() {
  ::init();
  add_action("tap","tap");
  }
  
tap(str) {
int before;
object after;
string path, num;
  if(!str) {write("What do you wish to tap?\n"); return 1;}
  if(present(str,this_player())) {
    if(present(str,this_player())->weapon_class() > 10) {
      sscanf(present(str,this_player()),"%s#%s",path,num);
      before=(present(str,this_player())->weapon_class());
      after=clone_object("/"+path+".c");
      after->set_class(before +1);
      destruct(present(str,this_player()));
      move_object(after,this_player());
    write("The "+str+" glows and somehow you realize it has become a bit stronger.\n");
    destruct(this_object());
    return 1;}
    write("That is not a weapon that you may tap!\n");
    return 1;}
    write("You do not have that.\n");
return 1;}
