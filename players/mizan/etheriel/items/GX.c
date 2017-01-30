#define MASTER_R "/players/mizan/closed/GuideDM.c"
string messages, new_hd, new_body;
int num_messages;
int muffle;
object who;

query_auto_load() { return "/players/mizan/etheriel/items/guide2.c:"; }

id(str) { return str == "guide" || str == "Mizan-Guide" || str == "computer"; }

short() { return ("A copy of the HitchHiker's Guide to Galaxy"); }

get() { return 1; }
drop() { return 1; }
query_value() { return 0; }

query_muf() { return muffle; }

long() { MASTER_R->long(); return 1; }

muffle_tells() {
  if(muffle) muffle=0;
  else
  muffle=1;
}

display_files() { MASTER_R->display_files(); return 1; }

init() {
    add_action("new", "edit");
    add_action("read", "view");
    add_action("display_files", "files");
    add_action("remove", "remove");
    add_action("guide_tell", "gt");
    add_action("guide_who", "gw");
    add_action("guide_emote", "ge");
    add_action("enrich", "enrich");
    add_action("drop_the_guide", "chuck");
    add_action("destroy_guide", "smash");
    add_action("update_guide", "download");
    add_action("muffle_tells", "gts");
}

headers() { MASTER_R->headers(); return 1; }

new(hd) { MASTER_R->new(hd); return 1; }

get_body(str) { MASTER_R->get_body(str); return 1; }

read(str) { MASTER_R->read(str); return 1; }

remove(str) { MASTER_R-remove(str); return 1; }

guide_shout(str) { MASTER_R->guide_shout(str); }

guide_tell(str) { MASTER_R->guide_tell(str); return 1; }

guide_emote(str) { MASTER_R->guide_emote(str); return 1; }

guide_who() { MASTER_R->guide_who(); return 1; }

enrich(arg) { MASTER_R->enrich(arg); return 1; }

update_guide() { MASTER_R->update_guide(); return 1; }

drop_the_guide() { MASTER_R->drop_the_guide(); return 1; }

destroy_guide() { MASTER_R->destroy_guide(); return 1; }
