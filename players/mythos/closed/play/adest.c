object ob;
object who;

id(str) { return str == "adest"; }

init() { if(this_player()->query_level() < 40) 
     destruct(this_object());
     add_action("wanga","adest");}

wanga(str) {
object j; int h; int k;
int arg;
  j = users();
  who = arg = 0;
  if(sscanf(str,"%s %d",str,arg) == 2) arg = 1;
  for(h=0;h<sizeof(j);h++) {
    if(j[h]->query_real_name() == str) who = j[h]; }
  if(!who) { write("not here\n"); return 1; }
  if(!arg) ob = deep_inventory(who);
  else ob = all_inventory(environment(who));
  for(h=0;h<sizeof(ob);h++){
  write(h+"  - ");
  write(ob[h]);
  write("\n"); }
  write("dest what #? :");
  input_to("choice");
return 1; }

choice(str) {
int k;
  if(str == "x") { write("canceled.\n"); return 1; }
  sscanf(str,"%d",k);
  destruct(ob[k]);
  write("done ["+k+"].\n");
return 1; }