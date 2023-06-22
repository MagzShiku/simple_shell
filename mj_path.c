#include "main.h"

typedef struct stat StatBuffer;

char *mj_path(char *mj_cmd)
{
  char *_path;
  char *_path2;
  char *tkn_path;
  int len_cmd;
  int len_dir;
  char *ex_fl_path;
  StatBuffer mj_buffer;
  

  _path = getenv("PATH");

  if (_path)
  {
    _path2 = strdup(_path);
    len_cmd = strlen(mj_cmd);
    tkn_path = strtok(_path2, ":");

    for (; tkn_path != NULL; tkn_path = strtok(NULL, ":"))
    {
      len_dir = strlen(tkn_path);
      ex_fl_path = malloc(len_cmd + len_dir + 2);
      strcpy(ex_fl_path, tkn_path);
      strcat(ex_fl_path, ""\"");
      strcat(ex_fl_path, mj_cmd);
      strcat(ex_fl_path, "\0");

      if (stat(ex_fl_path, &mj_buffer) == 0)
      {
        free(_path2);
        return (ex_fl_path);
      }
      else
      {
        free(ex_fl_path);
      }
    }
     free(_path2);

    if (stat(mj_cmd, &mj_buffer) == 0)
    {
      return (mj_cmd);
    }
  return (NULL);
  }
    return (NULL);
}
