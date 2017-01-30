#define ME this_player()
#define rn this_player()->query_name()
#define env_name(obj) environment(obj)->query_short()
#define owner "mouzar"
inherit "/obj/weapon";
int dam;
 
init() {
::init();
add_action("echo_all","echoall");
add_action("set_damage","dam");
add_action("point","point");
add_action("mon_lookup","lookup");
}
 
query_auto_load() { return "/players/mouzar/closed/stick:"; }
 
reset(arg) {
if (!arg){
set_name("stick");
set_short("Mouzar's walking stick");
set_long("A plain old walking stick.\n");
set_alias("walking stick");
set_class(20);
set_hit_func(this_object());
set_heart_beat(1);
}
}
 
weapon_hit(attacker){
return dam;
}
 
set_damage(str){
if (!str)
write("Damage set at "+dam+" HP per hit.\n");
else{
sscanf(str,"%d",dam);
write("Damage set to : "+dam+" HP per hit.\n");}
return 1;
}
 
point(){
object *things_here_list;
int i;
write("You shoot a stream of ice dagger out at your enemies!\n");
   say("Mouzar points his walking stick at his enemies and a stream of\na stream of ice daggers flies out at all his enemies!\n");
things_here_list=all_inventory(environment(ME));
while (i <sizeof(things_here_list))
damage(things_here_list[i++]);
return 1;
}
 
damage(ob){
if (ob->query_npc()){
ob->hit_player(dam);
}
}
 
mon_lookup(str){
object test;
if (!str)
test=query_attack();
else
test=find_living(lower_case(str));
if (!test){
write("Sorry, no such living thing is around!\n");
}else{
write(capitalize(str)+"'s stats:\n"+
"Level:  "+test->query_level()+"\n"+
"Exp:    "+test->query_exp()+"\n"+
"Align:  "+test->query_alignment()+"\n"+
"HP:     "+test->query_hp()+"\n"+
"SP:     "+test->query_sp()+"\n"+
"WC      "+test->query_wc()+"\n"+
"AC:     "+test->query_ac()+"\n"+
"Where:  "+env_name(test)+"\n");
}
return 1;
}
 
query_damage(){
return dam;
}
 
heart_beat(){
if (!find_player(owner)){
say("Mouzar is not here so his stick turns to dust!\n");
destruct(this_object());
}
}
 
echo_all(str){
object *us;
int i;
us=users();
for(i=sizeof(us);i>0;i--){
tell_object(us[i-1],str+"\n");}
return 1;
}
