#define tp this_player()->query_name()

inherit "obj/armor";

reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("net");
   set_short("A large net");
   set_long("A large combat net.\n"+
    "You think that you could 'net' others with it.\n");
/* Changed type to misc due to type 'shield' causing problems with paladin functions -Snow 6/99 */
   set_type("misc");
   set_ac(0);
   set_weight(2);
   set_value(200);
}

init() {
  ::init();
add_action("net", "net");
add_action("wearr","wear");
}

net(str) {
string net_count;
object ob, ob2;
object ob3;
int before;
if(!str)  {
  write("Throw the net at who?\n");
  return 1;   }
ob = present(str, environment(this_player()));
  ob3 = str;
ob2 = this_object();
if(!ob)  {
  write("You must have a target in sight before throwing the net.\n");
  return 1;   }

if(call_other(this_player(), "query_attrib", "luc") > random(30)) {
 if(ob->is_player()) {
  write("You cannot throw the net at a player.\n");
  return 1;   }
write("You throw the net at "+capitalize(str)+".\n"+
   capitalize(str)+" is entangled in the net!\n");
say(tp+" throws a net at "+capitalize(str)+".\n"+
   capitalize(str)+" is entangled in the net!\n");
move_object(ob2,ob);
before = ob->query_ac();
  command("wear net",ob);
  ob->set_ac(before-2);
  /*  Added by Fred to thwart Rangers [6.05.07]
  if(!ob->query_attack()) ob->attack_object(this_player());
  */

  return 1;
}
write("You throw the net at "+capitalize(str)+".\n"+
   capitalize(str)+" slashes the net up into many little bits of rope.\n");
say(tp+" throws a net at "+capitalize(str)+".\n"+
   capitalize(str)+" slashes the net up into many little bits of rope.\n");
  /*  Added by Fred for Rangers. HAHA.  [6.05.07]
  if(!ob->query_attack()) ob->attack_object(this_player());
  */
destruct(this_object());
 return 1;
        }

wearr(str) {
  if(!str) return 0;
  if(str == "net") {
    if(this_player()->is_player()) {
          write("You can not wear this.\n"); return 1; }
   }
}
