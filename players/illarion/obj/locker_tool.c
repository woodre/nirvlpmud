inherit "/obj/treasure";

reset(arg) {
  if(arg) return;
  
  set_id("tool");
  set_short("A locker tool");
  set_long("Test object...  should write to a file");
}
void init() {
  add_action("cmd_check_lockers","check_lockers");
}
cmd_check_lockers() {
  string *arr;
  int x,size;
  arr=get_dir("/players/catwoman/storage/");
  size=sizeof(arr);
  write("Size="+size+".\n");
  if(!size) return 1;
  for(x=0;x<size;x++) 
    write_file("/open/LOCKER_DATA",arr[x]+"\n");
  return 1;
}
