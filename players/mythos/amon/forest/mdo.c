object drakes;
int h;

id(str) { return str == "master_drake_object" || str == "drake_object"; }

short() { return "Master Drake Object"; }
long() { if(this_player()->query_level() > 100) {
          write("survey_on\ndestdrakes\n"); } }

reset(arg) {
  if(arg) return;
  drakes = allocate(10);
  h = 0;
  while(h<10) { produce(h); h++; }
  call_out("survey",100);
}

init() { if(this_player()->query_level() < 100) return 1;
         add_action("survey","survey_on");
         add_action("dest_array","destdrakes");
       }

produce(n) {
object drake;
h = n; 
  if(drakes[h]) drakes[h] = 0;
  drake = clone_object("/players/mythos/amon/forest/firedrake.c");
  drakes[h] = drake;
}

survey() {
object ob,eob,att;
int i,j,t;
string null,null2;
ob = users();
j = t = i = 0;
att = 0;
while(j < 10) {
  if(drakes[j]) {
    if(!drakes[j]->query_attack()) {
         att = drakes[j];
         j = 12; 
     }
  }
  else { produce(j); }
  j++;
}
if(att) {
  while(i<sizeof(ob)) {
    if(ob[i]->query_level() < 20) {
     if(environment(ob[i])) {
      eob = environment(ob[i]);
      if(creator(eob) == "mythos") {
        if(!sscanf(eob,"%sclosed%s",null,null2) &&
           !sscanf(eob,"%slroom%s",null,null2) &&
           !sscanf(eob,"%sprac%s",null,null2)) {
             if(random(100) < ob[i]->query_level()) {
               tell_room(eob,"A drake flies in.\nIt lands.\n");
               move_object(att,eob);
               tell_room(eob,"Suddenly it attacks!\n");
               att->attack_object(ob[i]);
               t = 1;
               i = sizeof(ob) + 666;
             }
           }
      }
    }
  }
  i++;
}
}
if(t) call_out("survey",10);
else call_out("survey",100 + random(1000));
return 1; }

dest_array() {
int j;
j = 0;
  while(j<10) {
    if(drakes[j]) {
     if(environment(drakes[j])) { write(environment(drakes[j])); write("\n"); }
     destruct(drakes[j]);}
    drakes[j] = 0;
    j++;
  } 
  write("done- cleared.\n");
return 1; }
