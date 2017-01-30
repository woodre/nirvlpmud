/* Battery tester */
 
#define TP this_player()
#define TO this_object()
#define ENV environment
#define TR tell_room
#define TPN capitalize(TP->query_name())
 
int battery_power, allocate_number;
 
id(str) { return str == "battery" || str == "powerob"; }
short() { return "Battery"; }
long() {
   write("Battery device testing for enhancement use.\n"+
         "'bcheck' shows battery power units left\n"+
         "'bcharge' stores corpse energy \n"+
         "'binfuse <number>' gives <number> of stored energy\n"+
         "'ballocate <num>' allocates <num> stored energy per 5secs\n");
return 1;
}
get() { return 1; }
drop() { return 1; }

reset() {
  battery_power = 0;
}
 
init() {
  if(present("CyberNinja Implants",TP)) {
    if(TP->query_level() > 21) {
      add_action("add_energy","badd");
    }
     add_action("bcheck","bcheck");
    add_action("bcharge","bcharge");
    add_action("binfuse","binfuse");
    add_action("ballocate","ballocate");
  }
}
 
 
bcharge(arg) {
  int hv;
  string cor;
  object cor2;
cor = "corpse";
cor2 = present(cor,ENV(TP));
  if(arg) {
    cor = "corpse "+arg;
    cor2 = present(cor,ENV(TP));
  }
  if(!cor2) {
    write("There is no '"+cor+"' here!\n");
  return 1;
  }
  hv = cor2->heal_value();
  TR(ENV(TP),TPN+" seems to glow and a corpse turns to dust.\n");
  write("Your battery glows with power!\n");
  battery_power = battery_power + (hv * 2);
  destruct(cor2);
return 1;
}
 
 
binfuse(arg) {
  int amt, maxsp, cursp;
amt = arg;
maxsp = TP->query_msp();
cursp = TP->query_sp();
  if(!arg) notify_fail("Usage: binfuse <amount>\n");
  if(battery_power < amt) {
    write("Your battery does not have that much power to give!\n");
  return 1;
  }
  write("You infuse yourself with battery power!\n");
  if(maxsp <= (cursp + amt)) {
    amt = maxsp - cursp;
    write("The battery charges you to full energy!\n");
  }
  battery_power -= amt;
  TP->add_spell_point(amt);
  write("~~~Battery contains ["+battery_power+"] energy units~~~\n");
return 1;
}
 
ballocate(arg) {
  int alnum, maxsp, cursp;
alnum = allocate_number;
maxsp = ENV(TO)->query_msp();
cursp = ENV(TO)->query_sp();
  call_out("ballocate",5);
  if(arg) {
    if(arg < 1) {
      write("Must allocate a positive number!\n");
    return 1;
    }
    write("Allocating ["+arg+"] energy per cycle.\n");
    allocate_number = arg;
  return 1;
  }
  if(!allocate_number) alnum = 1;
  if(battery_power < alnum) {
    alnum = battery_power;
    if(battery_power < 1) {
      say("~~~BATTERY DRAIN OVERLOAD: SHUTTING DOWN ALLOCATION~~~\n");
      remove_call_out("ballocate");
    return 1;
    }
  }
  if(maxsp <= (cursp + alnum)) alnum = maxsp - cursp;
  if(alnum == 0) {
    say("~~~MASTER ENERGY FULL: SHUTTING DOWN ALLOCATION~~~\n");
    remove_call_out("ballocate");
  return 1;
  }
  say("~~~~~~Battery allocation ["+alnum+"]\n");
  ENV(TO)->add_spell_point(alnum);
return 1;
}

bcheck() {
  write("The battery is storing ["+battery_power+"] energy units.\n");
return 1;
}

add_energy(arg) {
  if(!arg) notify_fail("Usage: badd <amount>\n");
  battery_power = battery_power + arg;
  write("Battery now has ["+battery_power+"] energy units.\n");
return 1;
}
