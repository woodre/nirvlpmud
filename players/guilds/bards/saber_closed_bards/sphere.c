#define tp this_player()->query_name()
string charges_count, player_info;
inherit "obj/armor";
int n, ahp;

init() {
  ::init();
add_action("sphere","orb");
add_action("globe","globe");
add_action("slarf","slarf");
        }

reset(arg){
  ::reset(arg);
  charges_count = 0;
  player_info = 0;
 count();
   set_name("sphere");
   set_short("A globe of chromatic spheres");
   set_alias("globe");
   set_long("A hazy globe filled with chromatic spheres.\n"+
       "You think the you could use it as a shield.\n"+
       "To use the chromatic sphere, type <orb monster>.\n"+
       "To destruct the globe, type <slarf>.\n"+
       "To check the number of spheres left, type <globe>.\n");
   set_type("shield");
   set_ac(1);
   set_weight(0);
   set_value(0);
}

sphere(str) {
object ob;
  if(!str)  {  write("Sphere what?\n");  return 1;  }
ob = present(str,environment(this_player()));
if(!ob || !living(ob)) {
write("To use 'sphere <monster>'.\n");
return 1;  }
if (ob->query_npc()){
this_player()->attack_object(ob);
if(living(ob))  ob->attack_object(this_player());
n = random(20)+10;
ahp = ob->query_hp();
if(n>ahp) { n = ahp - 1; }
  ob->hit_player(n);
count();
str = capitalize(str);
write("You hurl a chromatic sphere at "+str+".\n"+
   str+" is blasted by a burst of chromatic colors.\n");
say(tp+" hurls a chromatic sphere at "+str+".\n"+
  str+" is blasted by a burst of chromatic colors.\n");
if (charges_count > 4 ) {
command("drop sphere",this_player());
  write("The chromatic sphere fades back into the chaos from which it was formed.\n");
 say(tp+"'s chromatic sphere fades back into the chaos from which it was formed.\n");
destruct(this_object());
return 1;
}
return 1;
}
write("You cannot attack players with this.\n");
  return 1;
}

drop() { return 1; }
get()  { return 1; }

slarf()  {
write("The colors of the globe fade back into the streams of chaos.\n");
destruct(this_object());
  return 1;
        }
can_put_and_get()  { return 0; }

count()  {
charges_count = charges_count + 1;
player_info = 5 - charges_count;
        }

query_count()  {
  return player_info;        }

globe()  {
  write("You have "+query_count()+" spheres left.\n");
   return 1;
        }
