#include "/players/vertebraker/define.h"

id(str) { return str == "KnightInvite"; }
drop() { destruct(TO); return 1; }
