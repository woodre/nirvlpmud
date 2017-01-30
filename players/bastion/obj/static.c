string full_name, alias_name, short_desc, long_desc;
object summon_ob;
object chats;
string summon_func;
int frequency, chat_chance;
int summon_go, num_chats;

id(str) { return str==full_name || str==alias_name; }

short() { return short_desc; }

long() { write(long_desc); }

get() { return 0; }

set_name(str) { full_name=str; }
set_alias(str) { alias_name=str; }
set_short(str) {
      short_desc=str;
      if(!long_desc)
           long_desc="You see nothing of interest.\n";
}
set_long(str) { long_desc=str; }
set_object(ob) { summon_ob=ob; } 
set_summon(str) { summon_func=str; }
set_beat(i) { frequency=i; }
set_chat_chance(n) { chat_chance=n; }

load_chat(str) {
     object old;
     num_chats+=1;
     if(chats)
          old=chats;
     chats=clone_object("obj/chat");
     move_object(chats, this_object());
     chats->load_chat(str);
     chats->set_monster(this_object());
     if(old)
          chats->link(old);
     if(!chat_chance)
          chat_chance=40;
}

start_check() { call_out("check_for", frequency); }

load_summon() { summon_go=1; }

unload_summon() { summon_go=0; }

shut_down() { remove_call_out("check_for"); }

reset(arg) {
     if(arg) return;
     summon_ob=0;
     summon_func="summon";
     chats=0;
     frequency=3;
     chat_chance=0;
     short_desc="Unnamed terrain feature";
     full_name="feature";
     num_chats=0;
     unload_summon();
}

check_for() {
     object ob;
     call_out("check_for", frequency);
     ob=first_inventory(summon_ob);
     while(ob) {
          if(ob->is_player()) {
               someone_here(ob);
               return; }
          ob=next_inventory(ob); 
          }
}

someone_here(found) {
     if(!summon_ob) return;
     if(num_chats) {
          int n;
          if(random(100) < chat_chance)
  if(chats)
               chats->chat(random(num_chats)); }
     if(summon_go)
          call_other(summon_ob, summon_func, found);
}

query_summon_ob() {
     write(summon_ob); write("\n");
     return 1;
}
query_summon_func() { return summon_func; }
query_summon_go() { return summon_go; }
