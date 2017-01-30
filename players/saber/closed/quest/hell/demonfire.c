#define tp this_player()->query_name()
int w;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("demonfire sword");
    set_alias("sword");
    set_short("The Demonfire sword");
    set_long("A huge sword with a blade forged from liquid fire.\n"+
              "It is covered with unholy crimson runes.\n");
    set_read("You do not know the language in which the runes are written.\n");
    set_class(19);
    set_weight(2);
    set_value(5000);
    set_hit_func(this_object());
}
weapon_hit(attacker){
if(call_other(this_player(), "query_attrib", "str") > random (75))
 {
  say("The unholy runes on the Demonfire Sword glow an evil crimson.\n"+
    attacker->query_name()+" bursts into flames.\n");
  write("The unholy runes of the Demonfire Sword glow an evil crimson.\n"+
    attacker->query_name()+" bursts into flames.\n");

if(call_other(attacker,"id","priest") || call_other(attacker,"id","priestess"))  {
if(call_other(this_player(), "query_attrib", "str") > random(40)) {
write("\nAn unholy fire bursts from the ground around "+attacker->query_name()+".\n");
say("\nAn unholy fire bursts from the ground around "+attacker->query_name()+".\n");
    attacker->heal_self(-13);
    }
     }
  return 7;
    }
    return;
}

query_save_flag()  { return 1; }
