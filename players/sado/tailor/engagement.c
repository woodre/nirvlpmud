id(str) { return str == "sadoengagementring" || str == "ring"; }
short() { return "A small platinum ring, with a beautiful diamond set in it"; }
long() { write("An enscription reads: \"Never think noone cares\".\n"); }
drop() { return 1; }
get() { return 1; }
query_auto_load() { return "/players/sado/tailor/engagement.c:"; }
