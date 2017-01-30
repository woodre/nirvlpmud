#define tp this_player()->query_name()
inherit "obj/armor";

init() {
  ::init();
add_action("blast","blast");
}
reset (arg) {
  ::reset (arg);
set_name("circlet of power");
set_long(
"This is the fabled circlet of power. A golden ring that fits on the head,\n"+
"you feel that you could 'blast' your opponents with it.\n");
set_alias("circlet");
set_type("misc");
set_ac(2);
set_value(5000);
}

blast(str){
string gender;
object ob;
int dam;
if (!str)
write(
"Blast what?\n");
else
ob = present(str,environment(this_player()));
if(!ob || !living(ob)) {
write(
"The circlet tells you:\n"+"\n"+"<blast> <opponent>\n");
  return 1;
        }
if (ob->query_npc()){
  dam = random(15)+5;
str = capitalize(str);
  ob->hit_player(dam);
write(
"You concentrate and a stream of mentally charged fire streams from the\n"+
"circlet, engulfing the "+str+".\n"+
"The "+str+" screams and is severely fried.\n");
say(
tp+" sends a stream of mental fire blasting into the "+str+".\n");
  call_other(this_player(),"add_spell_point",-35);
this_player()->attack_object(ob);
if(living(ob)) ob->attack_object(this_player());
  return 1;
        }
write("The circlet cannot be used against players!\n");
return  1;
}

