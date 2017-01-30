#define check this_player()->query_ac()
inherit "/players/mythos/aarmor/armor1.c";
reset(arg){
  ::reset(arg);
  set_name("field");
  set_short();
  set_type("field");
  set_long("A shimmering field of protection.\n"+
    "Some spell's energizes may be absorbed.\n");
  set_weight(0);
  set_ac(1);
  set_arm_light(1);
  set_value(0);
}

init() {
  ::init();
  call_out("acheck",10);
}

acheck() {
int n, m;
  command("remove field",this_player());
m=random(10);
n=7-check;
  if(check == 7) {
    this_object()->set_ac(0);
  command("wear field",this_player());
call_out("acheck",10);
  return 1; }
  else {
    this_object()->set_ac(n);
  command("remove field",this_player());
call_out("acheck",10);
  return 1;}
return 1;}

