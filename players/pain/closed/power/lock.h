#define LOCK "/obj/locklist.c"

lock(str) {
LOCK->add_locklist(str); return 1;
}

check(str) {
LOCK->check_locklist(str); return 1;
}

clear(str) {
LOCK->clear_locklist(str); return 1;
}