int main(string str){
  if(str) return 0;

  write("Rehashing commands...\n");
  previous_object()->init();
  write("Ok.\n");
  return 1;
}
