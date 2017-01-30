int worn;
short() {
  return 0;
   if(random(100) < 30) restb();
  if(worn) return "A figurine on a chain (worn)"; 
  return "A figurine on a chain";
}
long() { write("This small statue is of a large pregant woman with wide\n"+
               "hips and very large breasts. A real person of these\n"+
               "proportions would be quite a sight and weigh around 400lbs\n"+
               "She is carries 2 babies in each arm and is smiling.\n");
          write("The chain allows the amulet to be worn around one's neck.\n");
}
query_auto_load() {if(worn) return "players/boltar/things/amulet.c:"+worn; }
init_arg(arg) {
  sscanf(arg, "%d", worn);
}
id(str) {
if(worn)
   return str=="amulet" || str == "figurine" || str == "chain" || str == "fertility";
if(!worn)
   return str=="amulet" || str == "figurine" || str == "chain";
}
wear(arg) {
string gend;
int qq;
   if(!id(arg)) return 0;
   if(environment() !=this_player()) {
     write("You must get it first!\n");
     return 1;
   }
   if(worn) {
     write("You already wear it.\n");
     return 1;
   }
   gend=this_player()->query_gender();
   if(gend=="male") {
     write("You wear the amulet\n");
     say(this_player()->query_name()+" wears an amulet.\n");
     worn = 1;
     return 1;
   }
  if(gend=="female") {
    log_file("b_amulet"," Worn by "+this_player()->query_real_name()+"\n");
    if(this_player()->query_pregnancy()) {
      write("The amulet glows brightly as you wear it.\n");
      qq=this_player()->query_phys_at(4);
      this_player()->add_phys_at(4,-qq);
      this_player()->add_phys_at(4,9);
    }
    if(present("boobs",this_player())) {
      object boobq;
      int bef,aft;
         boobq=present("boobs",this_player());
      bef=boobq->query_cup_num();
      if(bef< 6) boobq->add_cup(6-bef);
      if(bef> 5) boobq->add_cup(random(3)+1);
      write("You notice your breasts grow larger.\n");
    }
    if(!present("boobs",this_player())) {
      object bb;
      bb=clone_object("/players/boltar/sprooms/clinic/boobs");
      bb->set_boobs("huge 38 DD");
      move_object(bb,this_player());
      write("You notice your breasts grow larger.\n");
    }
    worn = 1;
     say(this_player()->query_name()+" wears a figurine.\n");
     write("You wear the figurine.\n");
    return 1;
    }
return 1;
}
get() { return 1; }
init() {
add_action("wear","wear");
add_action("rub","rub");
add_action("remove","remove");
}
drop(str) {
if(worn)
return 1;
if(environment(this_object())) 
  if(environment(this_object())->query_gender() == "male") return 0;
}
remove(arg) {
   if(!id(arg)) return 0;
   if(!worn) {
      write("You are not wearing it.\n");
      return 1;
   }
/*
   if(this_player()->query_gender() == "female") {
*/
     write("You find that it is impossible to remove the amulet from around your neck.\n");
     return 1;
/*
   }
   write("You remove the amulet.\n");
   say(this_player()->query_name()+" removes an amulet.\n");
   worn = 0;
   return 1;
*/
}
restb() {
    if(!worn) return 0;
   if(environment(this_object()))
    if(!present("boobs",environment(this_object()))) {
      object bb;
      if(environment(this_object())->query_gender() != "female") return 0;
      bb=clone_object("/players/boltar/sprooms/clinic/boobs");
      worn = 0;
      bb->set_boobs("huge 38 DD");
      worn = 1;
      move_object(bb, environment(this_object()));
    }
}
rub(arg) {
object tpu;
int chk,prg,chg,new;
   if(!id(arg)) return 0;
   if(environment() !=this_player()) {
     write("You must get it first!\n");
     return 1;
   }
   if(!worn || !this_player()->query_pregnancy()) {
     write("You rub the figurine.\n");
     say(this_player()->query_name()+ " rubs a small figurine.\n");
     return 1;
   }
tpu = this_player();
prg = tpu->query_pregnancy();
chg = random(500) - random(475);
if(random(50) < 10) chg = -300-random(200);
new = prg + chg;
chk = this_player()->query_age() - new;
if(chk < 1) chk = 76000;
if(chk > 16200) chk = 76000;
if(chk !=76000)
tpu->set_preg_num(new);
     say(this_player()->query_name()+ " rubs a small figurine.\n");
     write("You rub the figurine.\n");
     write("You feel oddly sick as a tingle runs from your hands to your belly.\n");
if(chg < 0) tpu->add_phys_at(3,random(3));
return 1;
}
