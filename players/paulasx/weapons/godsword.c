status wielded;
string wielded_by;
string name_of_weapon;
string cap_name;
string alt_name;
string alias_name;
string short_desc;
string long_desc;
string read_msg;
int class_of_weapon;
int value;
int local_weight;
object hit_func;
object wield_func;


query_name() { return name_of_weapon; }

long() {
    write(long_desc);
}

reset(arg) {
    if (arg) {
        return;
        set_heart_beat(1); 
    }
    wielded = 0; value = 0;
name_of_weapon="godsword";
cap_name=capitalize(name_of_weapon);
alias_name="Godsword";
short_desc="Godsword";
long_desc=
   "This is the sword used by the Gods to destroy evil.\n"+
"Ask Deacon Thomas in the Temple of Bishamon about the quest.  There is writing on the sword.\n";
read_msg=
  "The language is very oldand cryptic.  You have a hard time understanding\n"+
  "it, but apparently, anyone who wields it carries the power of the Gods..\n";
class_of_weapon=17;
value=5000;
local_weight=5;
}

heart_beat() {
  object plr,al;
  if(!wielded) {
     set_heart_beat(0);
     return;
  }
  plr=environment(this_object());
  if(!living(plr)) {
    set_heart_beat(0);
    return;
  }

  al=call_other(plr,"query_alignment");
  if(al>10) {
    tell_object(plr,"You feel the power of the Gods!!\n");
    call_other(plr,"drop_one_item",this_object());
    say("The Godsword falls from  ");
    say(call_other(plr,"query_name",0));
    say("'s hands.\n");
    set_heart_beat(0);
  }
}

init() {
    if (read_msg) {
        add_action("read","read");
    }
    add_action("wield","wield");
}

wield(str) {
    if (!id(str))
        return 0;
    if (environment() != this_player()) {
        write("You must get it first!\n");
        return 1;
    }
    if (wielded) {
        write("You already wield it!\n");
        return 1;
    }

    if( (call_other(this_player(),"query_alignment",0) <= 1000) ||
        (call_other(this_player(),"query_name",0) == "Paula")) {
            wielded_by = this_player();
            call_other(this_player(),"wield",this_object());
            wielded = 1;
            set_heart_beat(1);
            return 1;
}
    write("You can't wield the Godsword. Maybe you're not good enough...\n");
    say(call_other(this_player(),"query_name",0)+
        " failed to wield Godsword\n");
    return 1;
}

short() {
    if (wielded)
        if(short_desc)
            return short_desc + " (wielded)";
    return short_desc;
}

weapon_class() {
    return class_of_weapon;
}

id(str) {
  return str == name_of_weapon || str == alt_name || str == alias_name;
}

drop(silently) {
    if (wielded) {
        call_other(wielded_by, "stop_wielding");
        wielded = 0;
        if (!silently)
            write("You drop your wielded weapon.\n");
    }
    return 0;
}

un_wield() {
    if (wielded)
        wielded = 0;
}

hit(attacker)
{
    if (hit_func)
        return call_other(hit_func,"weapon_hit",attacker);
    return 0;
}


read(str) {
    if (!id(str))
        return 0;
    write(read_msg);
    return 1;
}

query_value() {
    return value;
}

get() { return 1; }

query_weight() { return local_weight; }

