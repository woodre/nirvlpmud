int do_know(string str) {
  if(!str) {
    cat(KNOWPATH+"general");
    return 1;
  }
  if(file_size(KNOWPATH+str)!=-1) {
    cat(KNOWPATH+str);
    return 1;
  }
  write("There is no knowledge about that.\n");
  return 1;
}
