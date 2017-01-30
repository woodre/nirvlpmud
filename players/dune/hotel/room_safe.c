/* 
 * Hotel guest variable save object, by Dune at Nirvana (6/18/97)
 * std_room.c does not use save_object/restore_object itself
 *   because #defines in def.h tended to save also
 */

#define SAVEPATH "players/dune/hotel/save/"

string owner;
string roomdesc;
string* storage;

store(string name, string* new_storage, 
      string new_owner, string new_roomdesc) {
  storage = new_storage;
  owner = new_owner;
  roomdesc = new_roomdesc;
  save_object(SAVEPATH + name);
  }

int restore_safe(string name) {
  int x;
  x = restore_object(SAVEPATH + name);
  return x;
}

string* get_storage()  { return storage; }
string  get_owner()    { return owner; }
string  get_roomdesc() { return roomdesc; }
