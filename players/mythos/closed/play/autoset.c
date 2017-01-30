string name1, name2, name3, name4, name5, name6, name7;
static string tar;
id(str) { return str == "2set";}

init() { 
  add_action("auto","autocheck");
}

auto(str) {
  if(!str) { write("usage: autocheck<name>\n"); return 1;}
  write("oks... for "+str+"\n");
  tar = str;
  write("names: ");
  input_to("nam1");
return 1;}

nam1(str) {
object target;
  if(!str) { write("cancelled.\n"); return 1;}
  if(sscanf(str,"%s,%s,%s,%s,%s,%s,%s",name1,name2,name3,name4,name5,name6,name7) != 7) {
    write("names: ");
    input_to("nam1");
  return 1;}
  write("oks...\n");
  save_object("players/mythos/closed/play/check/"+tar);
  write("saved\n");
  target = find_player(tar);
  if(target) {
  move_object(clone_object("/players/mythos/closed/play/autocheck.c"),target);
  target->save_me();
  write("moved.\n"); }
  else { write("not here...just move object too player when see.\n"); }
return 1;}
/*
nam2(str) {
  if(!str) { write("cancelled.\n"); return 1;}
  name2 = str;
  write("name3: ");
  input_to("nam3");
return 1;}

nam3(str) {
  if(!str) { write("cancelled.\n"); return 1;}
  name3 = str;
  write("name4: ");
  input_to("nam4");
return 1;}

nam4(str) {
  if(!str) { write("cancelled.\n"); return 1;}
  name4 = str;
  write("name5: ");
  input_to("nam5");
return 1;}

nam5(str) {
  if(!str) { write("cancelled.\n"); return 1;}
  name5 = str;
  write("name6: ");
  input_to("nam6");
return 1;} 

nam6(str) {
  if(!str) { write("cancelled.\n"); return 1;}
  name6 = str;
  write("name7: ");
  input_to("nam7");
return 1;}

nam7(str) {
object target;
  if(!str) { write("cancelled.\n"); return 1;}
  name7 = str;
  write("oks...\n");
  save_object("players/mythos/closed/play/check/"+tar);
  write("saved\n");
  target = find_player(tar);
  if(target) {
  move_object(clone_object("/players/mythos/closed/play/autocheck.c"),target);
  target->save_me();
  write("moved.\n"); }
  else { write("not here...just move object too player when see.\n"); }
return 1;} 
*/
