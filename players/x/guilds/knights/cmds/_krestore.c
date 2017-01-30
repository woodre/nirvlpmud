int main(string str){
  if(str) return 0;
  write("Restoring guild statistics...\n");
  previous_object()->restore_me();
  write("Ok.\n");
  return 1;
}
