// Who wrote this? And when?  Not even a changelog entry exists. 
// please address hints to Coogan (who added this comment on 21-Oct-2009)

private string region;

string query_region() {
  string temp;
  if (region)
    return region;
  temp = creator_file(object_name(this_object()));
  if (stringp(temp))
    region = "/"+temp;
  else
    region = "/MAIN";
  return region;
}

void set_region(string reg) {
  if (reg[0] == '/')
    region = reg;
  else {
    region = 0;
    region = query_region()+"/"+reg;
  }
}

