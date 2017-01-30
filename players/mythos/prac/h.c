#define tp this_player()
inherit "obj/treasure";
reset(arg) {
  set_id("necklace");
  set_short("A Jeweled Necklace");
  set_long("A nice necklace... it radiates a strange power- change\n");
  set_weight(0);
  set_value(0);
}
init() {
  ::init();
 add_action("change","change");
  add_action("check","check");
  add_action("namer","namer");
  add_action("light","light");
}

change(str) {
  object ob;
  ob=present("instrument",tp);
  ob->set_bard_level(str);
return 1;
}

check() {
  write("You are iat "+this_player()->query_ip_number()+"\n");
return 1;}

namer() {
object ob;
ob=first_inventory(environment(this_player()));
while(ob) {
  write("Name:  "+ob->query_name()+".\n");
ob=next_inventory(ob);
ob;
}
return 1;}

light() {
write("Room LIGHT: "+environment(tp)->set_light(1)+".\n");
return 1;}
