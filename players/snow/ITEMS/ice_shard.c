id(str) { return str == "shard"; }
 
reset() {}
 
long() { write("A shard of living ice crystal. Perhaps you could 'apply' it.\n"); }
 
short() { return "An ice shard"; }
 
init() {
  add_action("apply", "apply");
  add_action("shard", "shard");
}
 
apply(arg) {
    if (arg=="shard") {
        heal();
        return 1;
    } else {
        return 0;
    }
}
 
heal(arg) {
  write_file("/players/snow/log/heals",ctime(time())+" "+
        this_player()->query_real_name()+" applied an ice shard.\n");
    say(call_other(this_player(),"query_name") +
" is infused with living ice crystals.\n");
    write("You apply the shard to your wounds and are healed somewhat.\n");
    call_other(this_player(),"heal_self",35);
    write(
"The living crystals infuse into your skin and the shard dissapates.\n");
  destruct(this_object());
    return 1;
}
 
get() { return 1; }
 
query_weight() { return 1; }
 
query_value() { return 0; }
 
