
#define MAKE_DOORS(dest1, destdir1, dest2, destdir2, key_desc, short_desc, long_desc, is_closed, is_locked) \
door1=clone_object("players/bastion/obj/door"); \
door2=clone_object("players/bastion/obj/door"); \
door1->set_dest_dir(dest1); \
door2->set_dest_dir(dest2); \
door1->set_dest(dest1); \
door2->set_dest(dest2); \
door1->set_key_desc(key_desc); \
door2->set_key_desc(key_desc); \
door1->set_is_closed(is_closed); \
door2->set_is_closed(is_closed); \
door1->set_is_locked(is_locked); \
door2->set_is_locked(is_locked); \
door1->set_short(short_desc); \
door2->set_short(short_desc); \
door1->set_long(long_desc); \
door2->set_long(long_desc); \
door1->set_partner(door2); \
door2->set_partner(door1);

