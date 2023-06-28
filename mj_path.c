#include "main.h"

/**
 * mj_path - function to get the full path
 * @mj_cmd: the command whose path we are getting
 * Return: NULL
 */
char *mj_path(char *mj_cmd)
{
	char *path_env;
	char *path;
	char *tkn_path;
	size_t len;
	char *full_path;
	struct stat st;

	path_env = getenv("PATH");
	if (path_env == NULL)
		return (NULL);
	path = strdup(path_env);
	if (path == NULL)
		return (NULL);
	tkn_path = strtok(path, ":");
	while (tkn_path != NULL)
	{
		len = strlen(tkn_path) + strlen(mj_cmd) + 2;
		full_path = malloc(len);
		if (full_path == NULL)
		{
			free(path);
			return (NULL);
		}
		strcpy(full_path, tkn_path);
		strcat(full_path, "/");
		strcat(full_path, mj_cmd);
		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			free(path);
			return (full_path);
		}
		free(full_path);
		tkn_path = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
