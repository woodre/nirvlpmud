
int charges, local_weight, value, save_flag;
string full_name, alias_name, short_desc, long_desc, info, spell_mess1;
string spell_mess2, spell_dam;

set_name(str) { full_name=str; }
set_alias(str) { alias_name=str; }
set_short(str) {
     short_desc=str;
     if(!long_desc)
          long_desc="You see nothing special.\n";
}
set_long(str) { long_desc=str; }
set_info(str) { info=str; }
set_spell_mess1(str) { spell_mess1=str; }
set_spell_mess2(str) { spell_mess2=str; }
set_spell_dam(d) { spell_dam=d; }
set_charges(c) { charges=c; }
set_weight(w) { local_weight=w; }
set_value(v) { value=v; }
set_save_flag() { save_flag=1; }

id(str) { return str==full_name || str==alias_name; }
short() { return short_desc; }
long() { write(long_desc); }
get() { return 1; }

query_local_weight() { return local_weight; }
query_name() { return full_name; }
query_alias() { return alias_name; }
query_info() { return info; }
query_spell_mess1() { return spell_mess1; }
query_spell_mess2() { return spell_mess2; }
query_spell_dam() { return spell_dam; }
query_charges() { return charges; }
query_value() { return value; }
query_save_flag() { return save_flag; }

init() { add_action("use", "use"); }

use(str) {
     string what, who;
     object ob;
     if(!str) return 0;
     if(sscanf(str, "%s on %s", what, who)!=2) {
          return 0; }
     ob=present(who, environment(this_player()));
     if(!ob) {
          write("Use wand on whom?\n");
          return 1; }
     if(ob==this_player()) {
          write("You realize the foolishness of this action and cease.\n");
          return 1; }
     if(!living(ob)) {
          write("You can only use it on living things.\n");
          return 1; }
     if(!charges) {
          write("The wand seems to have fizzled out.\n");
          return 1; }
     charges-=1;
     write(spell_mess2 + "\n");
     say(spell_mess1 + "\n");
     ob->attacked_by(this_player());
     ob->hit_player(spell_dam);
     return 1;
}
