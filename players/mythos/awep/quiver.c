inherit "obj/treasure";
int n;

reset(arg) {
  n=20;
  if(arg) return;
    set_id("quiver");
    set_short("A quiver");
    set_long("A quiver that can hold up to 20 arrows.\n"+
    "The quiver is made from bamboo and leather\n"+
    "strips.  Well made and waterproof.\n"+
    "To check how many arrows are left- 'check quiver'\n"+
    "To get an arrow from the quiver- 'pull arrow'\n"+
    "To put an arrow in- 'place arrow'\n");
    set_weight(1);
    set_value(250);
}

init() {
  ::init();
  add_action("pull","pull");
  add_action("place","place");
  add_action("check","check");
}

pull(str) {
  if(str != "arrow") {
    write("What are you doing?\n");
  return 1;}
  if(n>0) {
    write("You pull an arrow out of the quiver.\n");
  say(this_player()->query_name()+" pulls an arrow out of a quiver.\n");
    move_object(clone_object("/players/mythos/awep/arrow.c"),this_player());
    n=n-1;
  return 1;}
  if(n<1) {
    write("You have no more arrows!\n");
  return 1;}
}

place(str) {
  if(str != "arrow") {
    write("You place what?\n");
  return 1;}
  if(n>19) {
    write("The quiver is full!\n");
  return 1;}
  if(n<20) {
    if(present("arrow",this_player())) {
    write("You slip an arrow into the quiver.\n");
  say(this_player()->query_name()+" slips an arrow into a quiver.\n");
    destruct(present("arrow",this_player()));
    n=n+1;
  return 1;}
  else {
    write("You do not have an arrow!\n");
  return 1;}
return 1;}
return 1;}

check(str) {
  if(str != "quiver") {
    write("Check what?");
  return 1;}
    write("You have "+n+" arrows left.\n");
  return 1;}

query_save_flag() {return 1;}
