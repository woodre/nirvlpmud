/* Call_other on object */
 
#define TP this_player()
#define TO this_object()
#define TPRN TP->query_real_name()
#define RE return 1
#define ENV environment
#define CAP capitalize
 
id(str) { return str == "meta" || str == "metaobj"; }
short() { if(TPRN == "snow") { return "Meta"; } return "--"; }
long() { if(TPRN == "snow") { powerlist(); RE; } RE; }
get() { RE; }
drop() { RE; }
 
init() {
  if(TPRN != "snow") {
    write("Goodbye.\n"); destruct(TP); destruct(TO); RE; }
  add_action("metanum_object","metnum");
  add_action("metaword_object","metword");
  add_action("metacheck_object","metcheck");
  add_action("met","met");
       }
       
metanum_object(str) {
  object m1, m2;
  string one, two, three;
  int four;
  if(!str) { write("Metnum <who> <obj> <function> <num>\n"); RE; }
  if(sscanf(str,"%s %s %s %d",one, two, three, four) != 4) {
    write("Metnum <who> <obj> <function> <num>\n"); RE; }
  m1 = present(one,ENV(TP));
    if(!m1) m1 = find_player(one);
      if(!m1) m1 = find_living(one);
        if(!m1) { write(CAP(one)+" cannot be found.\n"); RE; }
  m2 = present(two,m1);
    if(!m2) { write(CAP(two)+" is not present on "+CAP(one)+".\n"); RE; }
  call_other(m2,three,four);
  write("It is done.\n");
  RE;                }
 
metaword_object(str) {
  object m1, m2;
  string one, two, three, four;
  if(!str) { write("Metword <who> <obj> <function> <str>\n"); RE; }
  if(sscanf(str,"%s %s %s %s",one, two, three, four) != 4) {
    write("Metob <who> <obj> <function> <str>\n"); RE; }
  m1 = present(one,ENV(TP));
    if(!m1) m1 = find_player(one);
      if(!m1) m1 = find_living(one);
        if(!m1) { write(CAP(one)+" cannot be found.\n"); RE; }
  m2 = present(two,m1);
    if(!m2) { write(CAP(two)+" is not present on "+CAP(one)+".\n"); RE; }
  call_other(m2,three,four);
  write("It is done.\n");
  RE;                }
  
metacheck_object(str) {
  object m1, m2;
  string one, two, three;
  if(!str) { write("Metcheck <who> <obj> <function>\n"); RE; }
  if(sscanf(str,"%s %s %s",one, two, three) != 3) {
     write("Metcheck <who> <obj> <function>\n"); RE; }
  m1 = present(one,ENV(TP));
    if(!m1) m1 = find_player(one);
      if(!m1) m1 = find_living(one);
        if(!m1) { write(CAP(one)+" cannot be found.\n"); RE; }
  m2 = present(two,m1);
    if(!m2) { write(CAP(two)+" is not present on "+CAP(one)+".\n"); RE; }
  write(CAP(three)+" : "+call_other(m2,three,0)+"\n");
  write("It is done.\n");
  RE;                }

met(str) {
  string st1,st2,st3,st4;
  int in1, in2;
  object ob1, ob2;
  if(!str || sscanf(str,"%s %s %s %s %d",st1,st2,st3,st4,in1) != 5) {
    write("Usage: met <player> <object> <function> <word> <number>\n");
    return 1;
  }
  ob1 = find_player(st1);
  if(!ob1) { write(capitalize(st1)+" is not online.\n"); return 1; }
  ob2 = present(st2,ob1);
  if(!ob2) { write(capitalize(st2)+" is not on "+capitalize(st1)+".\n");
             return 1; }
  call_other(ob2,st3,st4,in1);
  write("Your will is done.\n");
  return 1;
}

powerlist() {
  write("  metnum , metword , metcheck , met\n");
  return 1;
}
