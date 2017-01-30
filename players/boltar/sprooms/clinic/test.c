inherit "/obj/treasure";
string id_str;
string sample1a,sample1b,sample1c;
string sample2a,sample2b,sample2c;
int teststatus;

set_ident(str) { id_str = str;}
short() {
   return short_desc;
   }
long() { 
  write(long_desc + "\n");
  if(!teststatus) write("No samples have been taken.\n");
  if(teststatus == 1) write("One sample of two has been taken.\n");
  if(teststatus == 2) write("Both samples have been taken.\n");
  write("Take samples with: prick <name>.\n");
  write("Once two samples are taken, please return the test kit to lab\n"+
        "in the Big House.\n"); 
  }

prick (str) {
   object target;
   if(!str) {
     write("You must prick someone.\n");
     return 1;
   }
   target=present(str,environment(this_player()));
   if(!target) target=present(str,this_player());
   if(!target) {
      write(str+" is not here!\n");
      return 1;
      }
   if(teststatus > 1) {
      write("Both samples have already been taken!\n");
      return 1;
      }
   teststatus += 1;
   if(teststatus == 1) {
     sample1a = target->query_real_name();
     sample1b = target->query_name();
     sample1c = target->query_nparents();
     str = sample1b;
   }
   if(teststatus == 2) {
     sample2a = target->query_real_name();
     if(sample2a == sample1a) {
       write("It's pointless to compare DNA from the same person.\n");
       teststatus -= 1;
       return 1;
    }
     sample2b = target->query_name();
     sample2c = target->query_nparents();
     str = sample2b;
   }

   write("You prick "+str+"\n");
   say(this_player()->query_name() + " pricks "+str+" and gets a blood sample.\n");
   tell_object(target,this_player()->query_name() + " pricks you, taking a blood sample.\n");
   return 1;
}
results() { 
  string res,a,b,c,d;
  int pos;
  pos = 0;
  if(!sample1b || !sample2b) {
    res = "Incomplete sample.";
  } 
  if(sample1c) {
    sscanf(sample1c,"%s#%s",a,b);
    if(a == sample2a) pos = 8;
    if(b == sample2a) pos = 8;
  }
  if(sample2c) {
    sscanf(sample2c,"%s#%s",c,d);
    if(c == sample1a) pos = 8;
    if(d == sample1a) pos = 8;
  }
if (pos == 8) res = sample1b +" and "+ sample2b + " are blood relatives.";
if (!res) res = sample1b +" and "+ sample2b + " are not blood relatives.";

log_file("Clinic2",this_player()->query_real_name()+" -- "+res+"\n");
return res;
}

init() {
   add_action("prick","prick");
   add_action("remove","remove");
}
reset(arg) {
if(arg) return;
short_desc="paternity test kit";
long_desc="A paternity test kit";
id_str="kit";
}
query_value() { return 500; }
query_weight() { return 0; }

drop(silently) {
     return 0;
}
id(str) { return str == id_str || str == short_desc || str == "test";
  }
generic_object() { return 1; }
restore_thing(str){
      restore_object(str);
      return 1;
   }
save_thing(str){
      save_object(str);
      return 1;
   }
query_teststatus() { return teststatus;}
