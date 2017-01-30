#include "/players/mythos/closed/guild/def.h"
gate() {
object ob, ob3;
int num, nh, nml;
  notify_fail("sorry.. some idiot abused this power so its gone.\n"+
              "- mythos <7-22-1998>\n");
  return 0; /* So exits named 'gate' will work. -Feldegast 10-11-00 */
if(qtf < 10) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 50) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 400) { write("The darkness calls for a sacrifice.\n"); return 1;}
if(!creator(environment(tp))) { write("You can not cast that here.\n"); return 1;}
  num = 0;
  ob3 = users();
  for(nml=0;nml<sizeof(ob3);nml++) {
   if(environment(ob3[nml])) {
  if(present("nexus_gate",environment(ob3[nml]))){
  nh = present("nexus_gate",environment(ob3[nml]))->query_num();
  if(num < nh) { num = nh; }
    }
  }}
ob = clone_object("/players/mythos/closed/guild/spells/gate.c");
ob->set_num(num+1);
ob->set_time(qtf);
move_object(ob,environment(tp));
tp->add_spell_point(-50);
pp->add_sacrifice(-400);
tell_room(environment(tp),HIR+"\n             {[  [    [   FLASH   ]   ]  ]}\n\n"+NORM);
write("You open up a gate to the NEXUS!\n");
say("A gate to the NEXUS has opened!\n");
return 1;}
