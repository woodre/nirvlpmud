#include "../DEFS.h"


status main(string str)
{
/* takes str and refers to files in fax directory */
  string tmp1, tmp2, fileName, *fileInfo;
  int i, fileInfoSize;

  if (!call_other(OFFICED,"checkStone",TP,"diamond sapphire pearl ruby emerald onyx"))
    return 0;

  if (!str)
  {
    cat(FAXDIR+"/fax_menu.txt");
    return 1; 
  }

  fileInfo = explode(str, " ");
  fileInfoSize = sizeof(fileInfo);
  if (fileInfoSize >= 1)
  {
    fileName = fileInfo[0];
  }
  else
  {
    fileName = str;
  }

  if (file_size(FAXDIR + "/" + fileName + "_restricted.txt") >= 0 ||
      file_size(FAXDIR + "/" + fileName + "_restrictedshort.txt") >= 0)
  {
    if (!IPTP->guild_wiz())
    {
      write("The fax comes back all shredded up.\n");
      return 1;
    }

    /* had to reconstruct fileName, so reconstruct str */
    fileName = fileName + "_restricted";
    if (fileInfoSize > 1)
    {
      str = "";
      for (i=1; i < fileInfoSize; i++)
      {
        str += fileInfo[i];
        if (i+1 < fileInfoSize)
        {
          str += " ";
        }
      }
      str = fileName + " " + str;
    }
    else
    {
      str = fileName;
    }
  }

  if (!call_other(MORED, "view_doc", str, FAXDIR))
    write("You have requested a fax of a non-existant document.\n");

  return 1;
}
