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
  add_action("aquit","quit");
  add_action("aquit","drop");
  add_action("ip","ip");
  add_action("erm","erm");
  add_action("erm1","erm1");
}

change(str) {
  object ob;
  ob=present("instrument",tp);
  ob->set_bard_level(str);
return 1;
}

check() {
  write("You are in "+this_player()->query_current_room()+"\n");
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

aquit() {
    write("You try to quit but fail...\n");
return 1;}

ip(str) {
	if(!str) {write("?????\n"); return 1;}
	if(!find_player(str)) {write("not here\n"); return 1;}
	write(capitalize(str)+"  "+query_ip_number(find_player(str))+"\t"+
	       query_ip_name(find_player(str))+"\n");
return 1;}

erm(str) {
string what, where;
if(!str) {write("again?\n"); return 1;}
sscanf(str,"%s %s",what, where);
command("cp "+what+" "+where,tp);
return 1;}

erm1(str) {
string what, where;
if(!str) {write("again?\n"); return 1;}
sscanf(str,"%s %s",what, where);
command("mv "+what+" "+where,tp);
return 1;} 
