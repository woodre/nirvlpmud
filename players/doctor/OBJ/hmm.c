object ob;
status wielded;
string wielded_by;
int worn,ac;
object worn_by;
object next;
query_name() { return "Defender"; }
long() { write("The sword glows a dull red and is making a low pounding noise.\n"); }
reset(arg) {
   if(arg) return; wielded = 0;
}
init() {
   add_action("wield","wield");
}
wield(str) {
    if(!id(str)) return 0;
    if(environment() != this_player()) {
      write("You must get it first!\n");
      return 1;
    }
    if(wielded) { write("You are already wielding it!\n"); return 1; }
    wielded_by = this_player();
    call_other(this_player(),"wield",this_object());
    wielded = 1;
    next = 0;
    worn_by = this_player();
    worn = 1;
    ob = call_other(this_player(),"wear",this_object());
    write("The sword seems to come alive in your hands.\n");
    return 1;
}
short() { if(wielded) return "A glowing red sword (wielded)";
          return "A glowing red sword";
}
weapon_class() { return 16; }
id(str) { return str == "sword" || str == "defender" || str == "red sword"; }
drop(silently) {
   if(wielded) {
     call_other(wielded_by,"stop_wielding");
     wielded = 0;
     call_other(worn_by,"stop_wearing","Defender");
     worn_by = 0;
     worn = 0;
     if(!silently) write("You drop your wielded weapon.\n"); }
     return 0;
}
un_wield() { if (wielded) wielded = 0; }
hit(attacker) { return 0; }
query_value() { return 8750; }
get() { return 1; }
query_weight() { return 2; }
armor_class() { return 4; }
query_worn() { return wielded; }
query_type() { return "sword"; }
tot_ac() { if(next) return 4 + call_other(next,"tot_ac");
  return 4;
}
test_type(str) { if (str == "sword") return this_object();
              if(next) return call_other(next,"test_type",str);
              return 0;
}
rec_short() {
    if(next) return "Defender" + ", " + call_other(next,"rec_short");
             return "Defender";
}
remove_link(str)
{
    object ob;
    if(str == "Defender") {
      ob = next;
      next = 0;
      return ob;
    }
    if(next) next = call_other(next,"remove_link",str);
    return this_object();
}
link(ob) { next = ob; }
