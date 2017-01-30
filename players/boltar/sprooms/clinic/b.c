inherit "obj/weapon.c";
int qu,cup,bust;
string adj,cuplet;
reset(arg) {
set_alias("breasts");
set_alt_name("boobs");
set_class(2);
set_no_clean(1);
set_long("Usage: setboobs adj bust(in) cup example: setboobs large 36 D\n       setboobs remove\n       breastfeed <kidname>\n");
   set_weight(0);
set_hit_func(this_object());
cuplet=allocate(26);
cuplet[0]="AAA";
cuplet[1]="AA";
cuplet[2]="A";
cuplet[3]="B";
cuplet[4]="C";
cuplet[5]="D";
cuplet[6]="DD";
cuplet[7]="DDD";
cuplet[8]="E";
cuplet[9]="EE";
cuplet[10]="F";
cuplet[11]="FF";
cuplet[12]="G";
cuplet[13]="H";
cuplet[14]="HH";
cuplet[15]="I";
cuplet[16]="II";
cuplet[17]="J";
cuplet[18]="JJ";
cuplet[19]="K";
cuplet[20]="KK";
cuplet[21]="L";
cuplet[22]="LL";
qu = 1;
if(!cup && !bust)
set_boobs("non-existant 28 AAA");
qu = 0;
}
string extra_look () {
string blah;
blah=environment()->query_name()+" has "+this_object()->query_adj()+" "+this_object()->query_bust()+" "+this_object()->query_cup()+" breasts";
return blah;
 }
string query_auto_load () {
return "players/boltar/sprooms/clinic/boobs:"+adj+" "+bust+" "+cup;
}
weapon_hit(attacker) {
int hurt;
string blah;
blah=this_object()->query_bust()+" "+this_object()->query_cup()+" breasts";
hurt=random(10);
if(hurt < 5) {
tell_object(attacker, environment()->query_name()+" smacks you with her "+blah+"\n");
write("You thwap "+attacker->query_name()+" with your breasts.\n");
say(environment()->query_name()+" smacks "+attacker->query_name()+" with her "+blah+".\n");
 }
}
query_bust() { return bust;}
query_cup(){ return cuplet[cup]; }
query_cup_num() { return cup; }
query_adj(){return adj;}
set_boobs(str) {
  string tadj,tlet;
  int i,tbust;
  if(!str) return 0;
  if(!this_player()) return 0;
  if(str == "remove") {
    if(wielded) { 
      write("You must unwield them first.\n");
      return 1;
     }
    if(this_player()->query_pregnancy()) {
      write("You cannot seem to dispel Dr. Bob's magic while pregnant.\n");
      return 1;
    }
    write("You dispel Dr. Bob's magical work and return to normal.\n");
    destruct(this_object());
    return 1;
  }
  if(sscanf(str,"%s %d %s",tadj,tbust,tlet) != 3) {
   write("Usage: setboobs adj bust(in) cup  example: setboobs large 36 DD\n");
   write("Usage: setboobs remove\n");
   return 1;
  }
  if(this_player()->query_pregnancy() && cup && bust) {
    adj = tadj;
    write("You cannot alter your breasts durring pregnancy.\n");
    return 1;
  }
  i=0;
  while(i<19) {
    if(cuplet[i]==tlet) { 
      cup = i;
      i = 25;
      }
    i+=1;
  }
  if(i < 23) {
  write("Invalid cup size. Use AAA,AA,A,B,C,D,DD,DDD,E,EE,F,FF,G,HH,I,II,J,JJ,K\n");
  return 1;
  }
  bust=tbust;
  adj=tadj;
if(!qu)
write("Boobs set to "+adj+" "+bust+" "+tlet+"\n");
return 1;
}
init() {
  ::init();
  add_action("set_boobs","setboobs");
  add_action("feed","breastfeed");
}
init_arg(arg) {
  if(arg){
   sscanf(arg,"%s %d %d",adj,bust,cup);
   }
}
add_cup(arg) {
  cup += arg;
  if(cup > 22) cup = 22;
  if(cup < 0) cup = 0;
  return;
  }
add_bust(arg) {
  bust+=arg;
  if(bust < 20) bust = 20;
  return;
}
drop(str){return 1;}
feed(str) {
object hh;
   if(!str) return 0;
  hh=present(str,this_player());
  if(!hh) return 0;
  if(!hh->is_kid()) return 0;
  if(hh->query_kidage() > 16000) {
   write(str+" is too old to be breast fed.\n");
   return 1;
   }
  if(environment(hh) != this_player()) {
    write(str+" is not in your arms.\n");
    return 1;
   }
  tell_room(environment(this_player()),this_player()->query_name()+" descreetly breasts feeds her child.\n");
  write("You descreetly move your breast out and start feeding your child.\n");
  return 1;
}
