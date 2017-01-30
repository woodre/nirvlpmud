inherit "obj/monster.c";

int visi;
string owner, name;
reset(arg) {
::reset(arg);

if(arg) return;
   owner = "nobody";
set_name("morph");
set_short("A Bat");
set_alias("bat");
set_aggressive(0);
set_level(19);
set_ac(999);
set_wc(-999);
}
query_local_weight() { return 1; }
invis(str) {
   visi=str;
   if(str==0) {
      is_invis=0;
   return 0; }
   if(str==1) {
      is_invis=10;
   return 1; }
}
init() {
   if(present(this_player(),this_object()) && owner!=this_player()->query_real_name()) move_object(this_player(),environment(this_object()));
   add_action("drop","drop");
   ::init();
}
can_put_and_get() { return 0; }
drop(str) {
   if(this_player()->query_real_name()!=owner) return;
   write("You can't drop things while in this form!\n");
return 1; 
}
catch_tell(str) {
   if(visi==1) return;
   if (!find_player(owner)) return;
   tell_object(find_player(owner),str);
}
heart_beat() {
   object ob1, ob2;
   string ob3;
   if(this_object()->query_attack()) {
      ob1 = find_player(owner);
      ob2 = this_object()->query_attack();
      ob3 = ob2->query_name();
      if(ob2->valid_attack(ob1)) {
        ob2->stop_fight();
        this_object()->stop_fight();
        command("change",ob1);
        command("fang "+ob3,ob1);
      }
      else {
        tell_object(ob2,"As you attack the "+name+" its eyes burn into your"+
                        "skull.  Fearing for your life you stop the attack!\n");
        ob2->stop_fight();
        this_object()->stop_fight();
      }
   }
  if(owner != "nobody" && !present(owner,this_object()) && environment(this_object()->short()) != "holding bin") {
    move_object(this_object(),"players/grimm/object/morphroom");
    name("nobody");
   }
   :: heart_beat();
}
name(str) {
   owner = str;
   set_long("The "+name+" appears to be a rather evil creature in search of blood.\n");
   return owner;
}
morph_name(str) {
  set_short("An evil "+str);
  set_alias(lower_case(str));
  name = lower_case(str);
}
realm() { return "NT"; }
