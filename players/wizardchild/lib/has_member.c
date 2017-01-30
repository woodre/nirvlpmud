has_member(mem, arr) {
  int i, so;
  for(i = 0, so = sizeof(arr); i < so; i++) 
    if(arr[i] == mem)
      return i;
  return -1;
}
